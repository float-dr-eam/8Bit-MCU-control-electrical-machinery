

/*	Floating point routines.
	Copyright (c) 2012 Microchip Technology Inc. All rights reserved.

	divide two floats, convert the result directly to an unsigned long

*/

// this is bigendian code right now. Need to parameterise it.

#include	"ftarith.h"

#define	f1_as_dividend	(*(unsigned short long *)&f1)
#define	f2_as_divisor	(*(unsigned short long *)&f2)
#ifdef _OLDLIB
unsigned long int
_tdiv_to_l_(float f1, float f2)
{
	unsigned char	cntr, exp1;
	unsigned long	quot;
	
	quot = 0;
	__ftunpack(&f1_as_dividend, &exp1);
	if(exp1 == 0)
		return quot;
	__ftunpack(&f2_as_divisor, &cntr);
	if(cntr == 0)
		return quot;
	exp1 -= 127;
	exp1 -= cntr-127+23;	// compute new exponent
	cntr = 32;
	do {
		quot <<= 1;
		if(f1_as_dividend >= f2_as_divisor) {
			f1_as_dividend -= f2_as_divisor;
			quot |= 1;
		}
		f1_as_dividend <<= 1;
	} while(--cntr != 0);
	if((signed char)exp1 < 0) {
		if((signed char)exp1 < -31)
			return 0;
		do
			quot >>= 1;
		while(++exp1 != 0);
	} else {
		if(exp1 >= 32)
			return 0;
		while(exp1 != 0) {
			quot <<= 1;
			exp1--;
		}
	}
	return quot;
}
#else
#define	exp2			cntr
unsigned long int
_tdiv_to_l_(float f1, float f2)
{
	unsigned char	cntr, exp1;
	unsigned long	quot;
	
	// unpack the operands
	if((exp1 = f1_as_dividend >> 15) == 0)
		return 0;
	if((exp2 = f2_as_divisor >> 15) == 0)
		return 0;
	f1_as_dividend |= 0x8000UL;
	f1_as_dividend &= 0xFFFFUL;
	f2_as_divisor |= 0x8000UL;
	f2_as_divisor &= 0xFFFFUL;
	quot = 0;
	exp1 -= 127;
	exp1 -= cntr-127+23;	// compute new exponent
	cntr = 24;
	do {
		quot <<= 1;
		if(f1_as_dividend >= f2_as_divisor) {
			f1_as_dividend -= f2_as_divisor;
			quot |= 1;
		}
		f1_as_dividend <<= 1;
	} while(--cntr != 0);
	if((signed char)exp1 < 0) {
		if((signed char)exp1 < -23)
			return 0;
		do
			quot >>= 1;
		while(++exp1 != 0);
	} else {
		if(exp1 >= 24)
			return 0;
		while(exp1 != 0) {
			quot <<= 1;
			exp1--;
		}
	}
	return quot;
}	
#endif
