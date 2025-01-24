/* SP relaxed compliance floating point square root function */
#include <errno.h>
#include <stdint.h>
#include "fpform.h"


/* SP Square root */
SP
SPSQRT(SP a) {
#if sizeof(double) == 4
	SFP root;
	unsigned char sign, p, i;
	int16_t exp;
	uint32_t frac;
	uint32_t tfrac;
	uint32_t grs;		/* Guard, round, sticky */

	/* Unpack and check operand */
	/* Sign, exponent, significand */
	sign = (*(SFP *) & a).fAsBytes.d & 0x80;
	p = ((*(SFP *) & a).fAsBytes.d) << 1;
	if ((*(SFP *) & a).fAsBytes.c & 0x80) {
		p |= 0x1;
	}

	exp = p;
	frac = (*(SFP *) & a).i & SPFRCM;

	/* Argument normal ? */
	if (exp) {
		frac |= (int32_t) 1 << SPFRCB;

		/* inf or NaN ? */
		if (exp == SPEXPM) {

			/* Make it inf */
			frac = 0;
		}
	}
	else {

		/* Make it zero */
		frac = 0;
	}

	/* Special operands */

	/* Zero returns zero */
	if (!exp) {
		return 0.0;
	}

	/* If argument less than zero, return NaN, domain error */
	if (sign) {
		root.i = (uint32_t) 1 << (SPFRCB - 1);
		//  sign and exp go to all ones
		root.fAsWords.wordB |= 0xFF80;
		errno = EDOM;
		return root.f;
	}

	/* inf or NaN returns +inf */
	if (exp == SPEXPM) {
		root.i = 0x7F800000;	//infinity
		return root.f;
	}

	/* Set result exponent - remove bias, save parity, halve, restore bias */
	exp -= SPEXPM >> 1;
	p = exp & 1;
	exp >>= 1;
	exp += SPEXPM >> 1;

	/* Initialize remainder, quotient, test bit */
	tfrac = frac << 1;	/* remainder */
	frac = 0;		/* quotient */
	grs = (uint32_t) 1 << (SPFRCB + 1);	/* test bit */

	/* Exponent parity changes remainder/test alignment */
	if (p) {
		tfrac <<= 1;
	}
	/* Compute square root, one bit at a time */
	i = 0;
	while (i < 25) {
		/* Or in prospective (test) bit */
		frac |= grs;

		/* Can we subtract ? */
		if (!(tfrac < frac)) {

			/* Subtract q + test */
			tfrac -= frac;

			/* Add bit to quotient, one position left, and take test bit out */
			frac += grs;
		}
		else {
			/* Take test bit out */
			frac &= ~grs;
		}

		/* Shift test bit right */
		grs = grs >> 1;

		/* Shift remainder left */
		tfrac <<= 1;

		++i;
	}
	/* Align result */
	frac = frac >> 1;

	/* Round result (it can never underflow, overflow, or tie) */
	grs = frac & 1;
	frac = frac >> 1;
	frac += grs;
	if (frac & ((uint32_t) 1 << (SPFRCB + 1))) {
		frac = frac >> 1;
		++exp;
	}

	/* Pack and return result */
	root.i = (frac & SPFRCM);
	p = exp;
	if (p & 0x1) {
		root.fAsBytes.c |= 0x80;
	}
	root.fAsBytes.d = p >> 1;
	root.fAsBytes.d &= 0x7F;
	return root.f;

#else				// 24bit
	double x, z, q, og;
	unsigned char i;


	if (a <= 0.0) {
		if (a < 0) {
			errno = EDOM;
		}
		return 0.0;
	}
	z = a;
	(*(unsigned short long *)&x) = 0xBE6EC8l - *(unsigned short long *)&a;
	(*(unsigned short long *)&x) >>= 1;
	*(unsigned short long *)&z -= 0x8000l;	// divide by two.
	i = 4;
	do {
		og = x;
		q = x * z;
		q *= x;
		q *= x;
		x *= 1.5;
		x -= q;
	} while (--i != 0);
	return x * a;
#endif
}

