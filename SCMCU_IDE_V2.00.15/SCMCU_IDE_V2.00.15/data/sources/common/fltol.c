/*	Floating point routines.

	Copyright (c) 2012 Microchip Technology Inc. All rights reserved.
*/

// this is bigendian code right now. Need to parameterise it.

#include	"flarith.h"

#define	f1_as_mant1	(*(unsigned long *)&f1)

// Convert float to long
#ifdef _OLDLIB
long
__fltol(double f1)
{
	unsigned char	sign1, exp1;
	unsigned long	lval;

	sign1 = __flunpack(&f1_as_mant1, &exp1);
	lval = f1_as_mant1;
	exp1 -= 127+23;
	if((signed char)exp1 < 0) {
		if((signed char)exp1 < -23)
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
__fltol(double f1)
{
	unsigned char	sign1, exp1;

	if((exp1 = f1_as_mant1 >> 23) == 0)
		return 0;
	sign1 = f1_as_mant1 >> 31;
	f1_as_mant1 |= 0x800000UL;
	f1_as_mant1 &= 0xFFFFFFUL;
	exp1 -= 127+23;
	if((signed char)exp1 < 0) {
		if((signed char)exp1 < -23)
			return 0;
		do
			f1_as_mant1 >>= 1;
		while(++exp1 != 0);
	} else {
		if(exp1 >= 32)
			return 00;
		while(exp1 != 0) {
			f1_as_mant1 <<= 1;
			exp1--;
		}
	}
	if(sign1)
		f1_as_mant1 = -f1_as_mant1;
	return f1_as_mant1;
}
#endif
