/*	Floating point routines.

	Copyright (c) 2012 Microchip Technology Inc. All rights reserved.
*/

// this is bigendian code right now. Need to parameterise it.

#include	"ftarith.h"

#define	f1_as_mant1	(*(unsigned short long *)&f1)
#define	f2_as_mant2	(*(unsigned short long *)&f2)

// floating addition
#ifdef _OLDLIB
float
__ftadd(float f1, float f2)
{
	unsigned char	exp1, exp2, sign1, sign2, cntr;
	
	if(sizeof(f1_as_mant1) != 3)
		return 0;
	sign1 = __ftunpack(&f1_as_mant1, &exp1);
	if(exp1 == 0)
		return f2;
	sign2 = __ftunpack(&f2_as_mant2, &exp2);
	if(exp2 != 0) {
		cntr = 6;
		// determine the smaller number. 
		if(exp1 < exp2) {
			if((unsigned char)(exp2-exp1) > sizeof(f1)*8) {
				// return f2
				f1_as_mant1 = 0;
				exp1 = exp2;
				sign1 = sign2;
			} else {
				// f1 has the smaller exponent - we can shift f2_as_mant2 up to 6 bits
				// left, decrementing exp2.
				do {
					f2_as_mant2 <<= 1;
					exp2--;
				} while(exp2 != exp1 && --cntr != 0);
				while(exp1 != exp2) {
					f1_as_mant1 >>= 1;
					exp1++;
				}
			}
		} else if(exp1 != exp2) {
			if((unsigned char)(exp1-exp2) > sizeof(f1)*8)
				f2_as_mant2 = 0;
			else {
				// f2 has the smaller exponent - we can shift f1_as_mant1 up to 6 bits
				// left, decrementing exp2.
				do {
					f1_as_mant1 <<= 1;
					exp1--;
				} while(exp2 != exp1 && --cntr != 0);
				while(exp1 != exp2) {
					f2_as_mant2 >>= 1;
					exp2++;
				}
			}
		}
		if(sign1 != 0) { 
			f1_as_mant1 ^= 0xFFFFFF;
			f1_as_mant1++;
		}
		if(sign2 != 0) {
			f2_as_mant2 ^= 0xFFFFFF;
			f2_as_mant2++;
		}
		sign1 = 0;
		f1_as_mant1 += f2_as_mant2;
		if(f1_as_mant1 & 0x800000) {
			f1_as_mant1 ^= 0xFFFFFF;
			f1_as_mant1++;
			sign1 = 1;
		}
	}
	__ftpack(&f1_as_mant1, exp1);
	if(sign1)
		f1_as_mant1 ^= 0x800000;
	return f1;
}
#else
float
__ftadd(float f1, float f2)
{
	unsigned char	exp1, exp2, sign;

	exp1 = f1_as_mant1 >> 15;
	exp2 = f2_as_mant2 >> 15;
	if(exp1 == 0 || exp1 < exp2  && (unsigned char)(exp2-exp1) > sizeof(f1)*8)
		return f2;
	if(exp2 == 0 || exp1 > exp2  && (unsigned char)(exp1-exp2) > sizeof(f1)*8)
		return f1;
	sign = 6;
	if(f1_as_mant1 & 0x800000L)
		sign |= 0x80;
	if(f2_as_mant2 & 0x800000L)
		sign |= 0x40;
	f1_as_mant1 |= 0x8000UL;
	f1_as_mant1 &= 0xFFFFUL;
	f2_as_mant2 |= 0x8000UL;
	f2_as_mant2 &= 0xFFFFUL;
	// determine the smaller number. 
	if(exp1 < exp2) {
		// f1 has the smaller exponent - we can shift f2_as_mant2 up to 6 bits
		// left, decrementing exp2.
		do {
			f2_as_mant2 <<= 1;
			exp2--;
		} while(exp2 != exp1 && --sign & 7);
		while(exp1 != exp2) {
			f1_as_mant1 >>= 1;
			exp1++;
		}
	} else if(exp1 > exp2) {
		// f2 has the smaller exponent - we can shift f1_as_mant1 up to 6 bits
		// left, decrementing exp2.
		do {
			f1_as_mant1 <<= 1;
			exp1--;
		} while(exp2 != exp1 && --sign & 7);
		while(exp1 != exp2) {
			f2_as_mant2 >>= 1;
			exp2++;
		}
	}
	if(sign & 0x80) { 
		// complement and add 1
		f1_as_mant1 ^= 0xFFFFFFUL;
		f1_as_mant1++;
	}
	if(sign & 0x40) {
		// complement and add 1
		f2_as_mant2 ^= 0xFFFFFFUL;
		f2_as_mant2++;
	}
	sign = 0;
	f2_as_mant2 += f1_as_mant1;
	if(f2_as_mant2 & 0x800000UL) {
		f2_as_mant2 ^= 0xFFFFFFUL;
		f2_as_mant2++;
		sign = 1;
	}
	return __ftpack(f2_as_mant2, exp1, sign);

}
#endif
