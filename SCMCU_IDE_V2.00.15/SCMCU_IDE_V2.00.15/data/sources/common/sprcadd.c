/* SP relaxed compliance floating point add intrinsic function */
#include <stdint.h>
#include "fpform.h"


// single monlithic add function

/* SP Add */
SP
SPADD(SP b, SP a) {
#define A_FRACTION    (*(SFP *)&a)
#define B_FRACTION    (*(SFP *)&b)
	unsigned char signs;	/* leftmost bit stores sign of b, next bit stores
				   0 if and only if a and b have the same sign  */
	unsigned char bexp;	/* Dst exponent */
	unsigned char aexp;	/* Src exponent */
	unsigned char grs;	/* Guard, round, sticky */


	/* Unpack and check operands */
	signs = B_FRACTION.fAsBytes.d & 0x80;
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

	aexp = A_FRACTION.fAsBytes.d & 0x80;
	// sign of a different from sign of b?
	if (aexp != signs) {
		signs |= 0x40;
	}
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

	/* Add */

	/* Get smaller operand in b */

	if (aexp < bexp) {
		// do I need to reverse the sign?
		if (signs & 0x40) {
			signs ^= 0x80;
		}
		// use  grs as swap space
		grs = bexp;
		bexp = aexp;
		aexp = grs;
		grs = B_FRACTION.fAsBytes.a;
		B_FRACTION.fAsBytes.a = A_FRACTION.fAsBytes.a;
		A_FRACTION.fAsBytes.a = grs;
		grs = B_FRACTION.fAsBytes.b;
		B_FRACTION.fAsBytes.b = A_FRACTION.fAsBytes.b;
		A_FRACTION.fAsBytes.b = grs;
		grs = B_FRACTION.fAsBytes.c;
		B_FRACTION.fAsBytes.c = A_FRACTION.fAsBytes.c;
		A_FRACTION.fAsBytes.c = grs;
		grs = B_FRACTION.fAsBytes.d;
		B_FRACTION.fAsBytes.d = A_FRACTION.fAsBytes.d;
		A_FRACTION.fAsBytes.d = grs;
	}

	grs = 0;
	/* If all ones will shift through G,R, then S = significand nonzero */
	if ((aexp - bexp) > (SPFRCB + 2)) {
		grs = B_FRACTION.i ? 1 : 0;
		B_FRACTION.i = 0;
		bexp = aexp;
	}
	else {
		while (bexp < aexp) {
			/* Shift smaller operand right until exponents equal */
			/* save the bits shifted out in grs    */
			if (grs & 1) {
				grs = (grs >> 1) | 0x1;
			}
			else {
				grs >>= 1;
			}
			if (B_FRACTION.i & 0x1) {
				grs |= 0x80;
			}
			B_FRACTION.i >>= 1;
			bexp++;
		}
	}

	/* Add or subtract magnitude ? */
	if (!(signs & 0x40)) {

		/* Quick exit for 0 + 0, same sign */
		if (!bexp) {
			return 0.0;
		}

		/* Add magnitude */
		B_FRACTION.i += A_FRACTION.i;
		// did it overflow?
		if (B_FRACTION.i & ((int32_t) 1 << (SPFRCB + 1))) {
			if (grs & 1) {
				grs = (grs >>= 1) | 0x1;
			}
			else {
				grs >>= 1;
			}
			if (B_FRACTION.i & 1) {
				grs |= 0x80;
			}
			B_FRACTION.i >>= 1;
			++bexp;
		}

	}
	else {

		/* Subtract magnitude */

		if (B_FRACTION.i < A_FRACTION.i) {
			B_FRACTION.i = A_FRACTION.i - B_FRACTION.i - 1;
			signs ^= 0x80;
			grs = ~grs + 1;
			if (!grs) {
				++B_FRACTION.i;
			}
		}
		else {
			B_FRACTION.i -= A_FRACTION.i;
		}

		/* True zero ? */
		if (!B_FRACTION.i && !grs) {
			return 0.0;
		}

		/* Renormalize */
		while (!(B_FRACTION.i & ((int32_t) 1 << SPFRCB))) {
			B_FRACTION.i <<= 1;
			if (grs & 0x80) {
				B_FRACTION.i |= 0x1;
			}
			if (grs & 1) {
				grs = (grs << 1) | 0x1;
			}
			else {
				grs <<= 1;
			}
			if (bexp) {
				--bexp;
			}
		}
	}

	/* Round, check overflow, underflow */

	/* Round */
	// reuse aexp as the rounding flag ...
	aexp = 0;
	if (grs & 0x80) {
		if (grs & 0x7f) {
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
			if (!(bexp == 0xFF)) {
				++bexp;
			}
		}
	}

	/* Overflow ? Return infinity */
	/* Underflow ? Flush to zero */
	if (bexp == 0xFF || bexp == 0) {
		B_FRACTION.i = 0;
                // no negative 0 for now
                if (bexp == 0) {
		        signs=0;
                }
	}

	/* Pack and return result */
	// set the low bit of the exponent ...
	if (bexp & 0x1) {
		B_FRACTION.fAsBytes.c |= 0x80;
	}
	// AND out the leading 1
	else {
		B_FRACTION.fAsBytes.c &= 0x7F;
	}
	B_FRACTION.fAsBytes.d = bexp >> 1;
	if (signs & 0x80) {
		B_FRACTION.fAsBytes.d |= 0x80;
	}
	return b;
}

/* SP Subtract */
#ifdef __PICC__
SP
SPSUB(SP a, SP b)
#else
SP
SPSUB(SP b, SP a)
#endif
{
	((*(SFP *) & a).i ^= 0x80000000; 
	return __fladd(b, a);
}

