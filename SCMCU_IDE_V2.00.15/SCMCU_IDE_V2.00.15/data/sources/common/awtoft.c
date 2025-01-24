/*	Floating point routines.

	Copyright (c) 2012 Microchip Technology Inc. All rights reserved.
*/

// this is bigendian code right now. Need to parameterise it.

#include	"ftarith.h"


// Convert signed int to float

#ifdef _OLDLIB
#define	f1_as_mant1	(*(unsigned short long *)&f1)
float
__awtoft(signed int c)
{
	float	f1;
	
	if(c == 0)
		return 0.0;
	f1_as_mant1 = (signed short long)c;
	if(c < 0)
		f1_as_mant1 = -f1_as_mant1;
	__ftpack(&f1_as_mant1, 127+15);
	if(c < 0)
		f1 = -f1;
	return f1;
}
#else
float
__awtoft(signed int c)
{
	unsigned char sign;

	sign = 0;
	if (c < 0) {
		c = -c;
		sign = 1;
	}
	return __ftpack((unsigned int)c, 127+15, sign);
}
#endif
