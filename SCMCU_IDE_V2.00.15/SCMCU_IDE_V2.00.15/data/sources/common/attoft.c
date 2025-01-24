/*	Floating point routines.

	Copyright (c) 2012 Microchip Technology Inc. All rights reserved.
*/

// this is bigendian code right now. Need to parameterise it.

#include	"ftarith.h"


// Convert signed short long int to float

#ifdef _OLDLIB
#define	f1_as_mant1	(*(unsigned short long *)&f1)
float
__attoft(signed short long int c)
{
	float	f1;
	unsigned char	exp, sign;
	
	if(c == 0)
		return 0.0;
	sign = 0;
	if(c < 0) {
		c = -c;
		sign = 1;
	}
	exp = 127+15;
	f1_as_mant1 = c;
	__ftpack(&f1_as_mant1, exp);
	if(sign)
		f1 = -f1;
	return f1;
}
#else
float
__attoft(signed short long int c)
{
	unsigned char sign;

	sign = 0;
	if (c < 0) {
		c = -c;
		sign = 1;
	}
	return __ftpack((unsigned short long) c, 127+15, sign);
}
#endif
