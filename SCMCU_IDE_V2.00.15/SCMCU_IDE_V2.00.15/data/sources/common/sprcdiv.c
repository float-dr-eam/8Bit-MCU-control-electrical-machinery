/* SP relaxed compliance floating point divide intrinsic function */
#include <stdint.h>
#include "fpform.h"

/* SP Divide */
#ifdef __PICC__
SP
SPDIV(SP a, SP b)
#else
SP
SPDIV(SP b, SP a)
#endif
{
#define A_FRACTION    (*(SFP *)&a)
#define B_FRACTION    (*(SFP *)&b)
	unsigned char sign;	/* sign of result */

	unsigned char bexp;	/* Dst exponent */
	unsigned char aexp;	/* Src exponent */
	int16_t new_exp;
	uint32_t grs;		/* Guard, round, sticky */
	uint32_t rem;

	/* Unpack and check operands */
	// put b's sign as the result sign ...
	sign = B_FRACTION.fAsBytes.d & 0x80;
	bexp = B_FRACTION.fAsBytes.d << 1;
	if (B_FRACTION.fAsBytes.c & 0x80) {
		bexp |= 0x1;
	}

	/* Destination normal ? */
	if (bexp) {
		/* Destination inf or NaN ? */
		if (bexp == 0xFF) {
			/* Make it inf */
			b = 0;
		}
		// OR in the hidden 1-bit to b's fraction
		B_FRACTION.i |= (int32_t) 1 << SPFRCB;
		// and zero out the upper byte so we can safely shift
		B_FRACTION.fAsBytes.d = 0;
	}
	else {
		/* Make it zero */
		b = 0;
	}
	// xor a's sign into the result sign
	sign ^= A_FRACTION.fAsBytes.d & 0x80;
	aexp = A_FRACTION.fAsBytes.d << 1;
	if (A_FRACTION.fAsBytes.c & 0x80) {
		aexp |= 0x1;
	}

	/* Destination normal ? */
	if (aexp) {
		/* Destination inf or NaN ? */
		if (aexp == 0xFF) {
			/* Make it inf */
			a = 0;
		}
		// OR in the hidden 1-bit to a's fraction
		A_FRACTION.i |= (int32_t) 1 << SPFRCB;
		// and zero out the upper bits so we can safely shift
		A_FRACTION.fAsBytes.d = 0;
	}
	else {
		/* Make it zero */
		a = 0;
	}

	/* Special operand check */

	/* Denominator zero ? Result infinity */
	if (A_FRACTION.i == 0) {
		B_FRACTION.i = 0;
		B_FRACTION.fAsWords.wordB |= (SPEXPM << 7);
		return b;
	}

	/* Numerator zero ? Result zero */
	if (!bexp) {
		B_FRACTION.i = 0;
		return b;
	}

	/* Subtract denominator exponent, minus bias */
	new_exp = bexp - aexp + 127;

	/* Divide loop */
	rem = B_FRACTION.i;
	B_FRACTION.i = 0;
	grs = 0;
	// reuse aexp as the loop counter ...
	aexp = 0;
	while (aexp < 26) {

		/* Shift remainder, quotient left */
		if (aexp) {
			rem <<= 1;
			B_FRACTION.i <<= 1;
			if (grs & 0x80000000) {
				B_FRACTION.i |= 0x1;
			}
			grs <<= 1;
		}

		/* Restoring divide */

		/* Remainder not less than divisor ? */
		if (!(rem < A_FRACTION.i)) {

			/* Set quotient bit, subtract divisor */
			grs |= 0x40000000;
			rem -= A_FRACTION.i;
		}
		++aexp;
	}

	/* Sticky bit is nonzero remainder */
	if (rem) {
		grs |= 1;
	}

	/* Renormalize */
	while (!(B_FRACTION.i & ((int32_t) 1 << SPFRCB))) {
		B_FRACTION.i <<= 1;
		if (grs & 0x80000000) {
			B_FRACTION.i |= 0x1;
		}
		grs <<= 1;
		--new_exp;
	}

	/* Round result and check overflow, underflow */
	/* Round */
	// reuse aexp again as the round-up flag ...
	aexp = 0;
	if (grs & ((uint32_t) 1 << 31)) {
		if (grs & (((uint32_t) 1 << 31) - 1)) {
			aexp = 1;
		}
		else {
			if (B_FRACTION.i & 1) {
				aexp = 1;
			}
		}
	}
	if (aexp) {
		++B_FRACTION.i;
		if (B_FRACTION.i & ((int32_t) 1 << (SPFRCB + 1))) {
			B_FRACTION.i = B_FRACTION.i >> 1;
			++new_exp;
		}
	}

	/* Overflow ? Return infinity */
	if (!(new_exp < SPEXPM)) {
		new_exp = SPEXPM;
		B_FRACTION.i = 0;
	}

	/* Underflow ? Flush to zero */
	if (!(0 < new_exp)) {
		new_exp = 0;
		B_FRACTION.i = 0;
                // no negative fp 0 for now
                sign = 0;
	}

	/* Pack and return result */
	bexp = new_exp;
	// set the low bit of the exponent ...
	if (bexp & 0x1) {
		B_FRACTION.fAsBytes.c |= 0x80;
	}
	// AND out the leading 1
	else {
		B_FRACTION.fAsBytes.c &= 0x7F;
	}
	B_FRACTION.fAsBytes.d = bexp >> 1;
	B_FRACTION.fAsBytes.d |= sign;
	return b;
}

