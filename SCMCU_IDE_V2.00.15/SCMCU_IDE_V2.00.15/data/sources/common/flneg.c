/*	Floating point routines.

	Copyright (c) 2012 Microchip Technology Inc. All rights reserved.
*/

// this is bigendian code right now. Need to parameterise it.

#include	"ftarith.h"

#define	mant1	(*(unsigned long *)&f1)

// Negate a float

double
__flneg(double f1)
{
	if(f1 != 0)
		mant1 ^= 0x80000000UL;
	return f1;
}
