/*	Floating point routines.

	Copyright (c) 2012 Microchip Technology Inc. All rights reserved.
*/

// this is bigendian code right now. Need to parameterise it.

#include	"ftarith.h"

#define	f1_as_dividend	(*(unsigned short long *)&f1)
#define	f2_as_divisor	(*(unsigned short long *)&f2)
#define	f3_as_quot	(*(unsigned short long *)&f3)

// floating addition
#ifdef _OLDLIB
#define	cntr		sign2
float
#ifdef _PIC18
__ftdiv(float f1, float f2)
#else
__ftdiv(float f2, float f1)
#endif
{
	unsigned char	exp1, exp2, sign1, sign2;
	float	f3;
	
	f3_as_quot = 0;
	sign1 = __ftunpack(&f1_as_dividend, &exp1);
	if(exp1 == 0)
		return f3;
	sign2 = __ftunpack(&f2_as_divisor, &exp2);
	if(exp2 == 0)
		return f3;
	exp1 -= exp2-127+8;	// compute new exponent
	sign1 ^= sign2;
	cntr = 16+8;
	do {
		f3_as_quot <<= 1;
		if(f1_as_dividend >= f2_as_divisor) {
			f1_as_dividend -= f2_as_divisor;
			f3_as_quot |= 1;
		}
		f1_as_dividend <<= 1;
	} while(--cntr != 0);
	__ftpack(&f3_as_quot, exp1);
	if(sign1)
		f3_as_quot |= 0x800000;
	return f3;
}
#else
#define	exp2	sign
float
#ifdef _PIC18
__ftdiv(float f1, float f2)
#else
__ftdiv(float f2, float f1)
#endif
{
	unsigned char	exp, sign, cntr;
	float	f3;
	
	// unpack the operands
	if((exp = f1_as_dividend >> 15) == 0)
		return 0.0;
	if((exp2 = f2_as_divisor >> 15) == 0)
		return 0.0;
	f3_as_quot = 0;
	exp -= exp2-127+8;	// compute new exponent
	sign = f1_as_dividend >> 16;
	sign ^= (unsigned char)(f2_as_divisor >> 16);
	sign &= 0x80;
	f1_as_dividend |= 0x8000UL;
	f1_as_dividend &= 0xFFFFUL;
	f2_as_divisor |= 0x8000UL;
	f2_as_divisor &= 0xFFFFUL;
	cntr = 16+8;
	do {
		f3_as_quot <<= 1;
		if(f1_as_dividend >= f2_as_divisor) {
			f1_as_dividend -= f2_as_divisor;
			f3_as_quot |= 1;
		}
		f1_as_dividend <<= 1;
	} while(--cntr != 0);
	return __ftpack(f3_as_quot, exp, sign);
}
#endif	
