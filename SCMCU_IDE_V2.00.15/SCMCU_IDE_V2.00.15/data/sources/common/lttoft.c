/*	Floating point routines.

	Copyright (c) 2012 Microchip Technology Inc. All rights reserved.
*/

// this is bigendian code right now. Need to parameterise it.

#include	"ftarith.h"


// Convert unsigned long int to float

#ifdef _OLDLIB
#define	f1_as_mant1	(*(unsigned short long *)&f1)
float
__lttoft(unsigned short long int c)
{
	float	f1;
	unsigned char	exp;
	
	if(c == 0)
		return 0.0;
	exp = 127+15;
	f1_as_mant1 = c;
	__ftpack(&f1_as_mant1, exp);
	return f1;
}
#else
float
__lttoft(unsigned short long int c)
{
	return __ftpack(c, 127+15, 0);
}
#endif
