/*	Floating point routines.

	Copyright (c) 2012 Microchip Technology Inc. All rights reserved.
*/

// this is bigendian code right now. Need to parameterise it.

#include	"ftarith.h"

#define	f1_as_mant1	(*(unsigned short long *)&f1)

// Convert float to long

#ifdef _OLDLIB
long
__fttol(float f1)
{
	unsigned char	sign1, exp1;
	unsigned long	lval;

	sign1 = __ftunpack(&f1_as_mant1, &exp1);
	lval = f1_as_mant1;
	exp1 -= 127+15;
	if((signed char)exp1 < 0) {
		if((signed char)exp1 < -15)
			return 0;
		do
			lval >>= 1;
		while(++exp1 != 0);
	} else {
		if(exp1 >= 32)
			return 00;
		while(exp1 != 0) {
			lval <<= 1;
			exp1--;
		}
	}
	if(sign1)
		lval = -lval;
	return lval;
}
#else
long
__fttol(float f1)
{
	unsigned char	sign1, exp1;
	unsigned long	lval;

	if((exp1 = f1_as_mant1 >> 15) == 0)
		return 0;
	sign1 = f1_as_mant1 >> 23;
	f1_as_mant1 |= 0x8000UL;
	f1_as_mant1 &= 0xFFFFUL;
	lval = f1_as_mant1;
	exp1 -= 127+15;
	if((signed char)exp1 < 0) {
		if((signed char)exp1 < -15)
			return 0;
		do
			lval >>= 1;
		while(++exp1 != 0);
	} else {
		if(exp1 >= 24)
			return 0;
		while(exp1 != 0) {
			lval <<= 1;
			exp1--;
		}
	}
	if(sign1)
		lval = -lval;
	return lval;
}
#endif
