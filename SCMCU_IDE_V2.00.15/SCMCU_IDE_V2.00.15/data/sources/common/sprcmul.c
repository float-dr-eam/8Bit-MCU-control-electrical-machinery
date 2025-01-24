/* SP relaxed compliance floating point multiply intrinsic function */
#include <stdint.h>
#include "fpform.h"

/* SP Multiply */
/* single monolithic routine */
SP
SPMUL(SP b, SP a) {
	unsigned char sign;	/* sign of result */
	unsigned char bexp;	/* Dst exponent */
	unsigned char aexp;	/* Src exponent */
	uint32_t grs;		/* Guard, round, sticky */
	SFP prod;
	wordProduct temp;	/* intermediate mult results ; exponent of result */

	/* Unpack and check operands */
	sign = (*(SFP *) & b).fAsBytes.d & 0x80;
	bexp = ((*(SFP *) & b).fAsBytes.d) << 1;
	if ((*(SFP *) & b).fAsBytes.c & 0x80) {
		bexp |= 0x1;
	}

	/* Destination normal ? */
	if (bexp) {
		/* Destination inf or NaN ? */
		if (bexp == 0xFF) {
			/* Make it inf */
			b = 0;
		}
		// and in the implied 1-bit to b's fraction
		(*(SFP *) & b).i |= (int32_t) 1 << SPFRCB;

	}
	else {
		/* Make it zero */
		b = 0;
	}

	sign ^= (*(SFP *) & a).fAsBytes.d & 0x80;
	aexp = ((*(SFP *) & a).fAsBytes.d) << 1;
	if ((*(SFP *) & a).fAsBytes.c & 0x80) {
		aexp |= 0x1;
	}
	/* Destination normal ? */
	if (aexp) {

		/* Destination inf or NaN ? */
		if (aexp == 0xFF) {
			/* Make it inf */
			a = 0;
		}
		// and in the implied 1-bit to a's fraction
		(*(SFP *) & a).i |= (int32_t) 1 << SPFRCB;
	}
	else {
		/* Make it zero */
		a = 0;
	}

	/* Multiply */

	/* Special operand check */

	/* Source or destination zero ? Result zero */
	if (aexp == 0 || bexp == 0) {
		return 0.0;
	}

//    we decompose a 24 bit multiply into 9 8 bit multiplies as follows:
//
//    b's fraction is b1|b2|b3 and a's fraction is a1|a2|a3
//
//    then ab is the (48 bit) sum of these 9 16 bit intermediate products shifted appropriately
//
//
//                                     a3b3
//                                   a2b3
//                                   a3b2
//                                 a1b3
//                                 a2b2
//                                 a3b1
//                               a1b2
//                               a2b1
//                             a1b1
//
//   in this algorithm we compute the product to be the upper 24 bits of the sum and grs to be the lower 24 bits
//   shifted 8 to the left     then we renormalize and round as usual.
//

#define LOWBYTE(x)  (*(unsigned char *)(&x))
#define MIDBYTE(x)  (*(((unsigned char *)(&x))+1))
#define HIGHBYTE(x) (*(((unsigned char *)(&x))+2))

#ifdef _PIC18
	temp.n = HIGHBYTE(a) * LOWBYTE(b);
	grs = temp.nAsBytes.a;
	prod.i = temp.nAsBytes.b;
	temp.n = MIDBYTE(a) * MIDBYTE(b);
	grs += temp.nAsBytes.a;
	prod.i += temp.nAsBytes.b;
	temp.n = LOWBYTE(a) * HIGHBYTE(b);
	grs += temp.nAsBytes.a;
	prod.i += temp.nAsBytes.b;
	grs <<= 8;
	temp.n = LOWBYTE(a) * MIDBYTE(b);
	grs += (unsigned long)temp.n;
	temp.n = MIDBYTE(a) * LOWBYTE(b);
	grs += (unsigned long)temp.n;
	grs <<= 8;
	temp.n = LOWBYTE(a) * LOWBYTE(b);
	grs += (unsigned long)temp.n;
	temp.n = HIGHBYTE(a) * MIDBYTE(b);
	prod.i += (unsigned long)temp.n;
	temp.n = MIDBYTE(a) * HIGHBYTE(b);
	prod.i += (unsigned long)temp.n;
	temp.n = HIGHBYTE(a) * HIGHBYTE(b);
	prod.i += (((unsigned long)temp.n) << 8);
#else
	temp.n = _Umul8_16(HIGHBYTE(a), LOWBYTE(b));
	grs = temp.nAsBytes.a;
	prod.i = temp.nAsBytes.b;
	temp.n = _Umul8_16(MIDBYTE(a), MIDBYTE(b));
	grs += temp.nAsBytes.a;
	prod.i += temp.nAsBytes.b;
	temp.n = _Umul8_16(LOWBYTE(a), HIGHBYTE(b));
	grs += temp.nAsBytes.a;
	prod.i += temp.nAsBytes.b;
	grs <<= 8;
	temp.n = _Umul8_16(LOWBYTE(a), MIDBYTE(b));
	grs += (unsigned long)temp.n;
	temp.n = _Umul8_16(MIDBYTE(a), LOWBYTE(b));
	grs += (unsigned long)temp.n;
	grs <<= 8;
	temp.n = _Umul8_16(LOWBYTE(a), LOWBYTE(b));
	grs += (unsigned long)temp.n;
	temp.n = _Umul8_16(HIGHBYTE(a), MIDBYTE(b));
	prod.i += (unsigned long)temp.n;
	temp.n = _Umul8_16(MIDBYTE(a), HIGHBYTE(b));
	prod.i += (unsigned long)temp.n;
	temp.n = _Umul8_16(HIGHBYTE(a), HIGHBYTE(b));
	prod.i += (((unsigned long)temp.n) << 8);
#endif

	// first add the overflow bit from the lower half to the upper half
	prod.i += (grs >> 24);
	grs <<= 8;

	/* Add source exponent, minus (bias - 1) */
	temp.i = bexp + aexp - 126;

	/* Renormalize  */
	while (!(prod.i & ((int32_t) 1 << SPFRCB))) {
		prod.i <<= 1;
		if (grs & 0x80000000) {
			prod.i |= 0x1;
		}
		grs <<= 1;
		--temp.i;
	}

	/* Round, check overflow, underflow */
	// reuse aexp as round up flag
	aexp = 0;
	if (grs & 0x80000000) {
		if (grs & 0x7FFFFFFF) {
			aexp = 1;
		}
		else {
			if (prod.i & 1) {
				aexp = 1;
			}
		}
	}
	if (aexp) {
		++prod.i;
		if (prod.i & ((int32_t) 1 << (SPFRCB + 1))) {
			prod.i = prod.i >> 1;
			++temp.i;
		}
	}

	/* Overflow ? Return infinity */
	if (!(temp.i < SPEXPM)) {
		prod.i = 0x7F800000;
	}
	/* Underflow ? Flush to zero */
	else if (!(0 < temp.i)) {
		prod.i = 0;
                // no negative 0 for now
                sign=0;
	}
	else {
		/* Pack and return result */
		bexp = temp.i;	// it fits in 8 bits !
		prod.i &= SPFRCM;	// trim away the leading 1
		if (bexp & 0x1) {
			prod.fAsBytes.c |= 0x80;
		}
		prod.fAsBytes.d = bexp >> 1;
	}
	prod.fAsBytes.d |= sign;

	return prod.f;

}

