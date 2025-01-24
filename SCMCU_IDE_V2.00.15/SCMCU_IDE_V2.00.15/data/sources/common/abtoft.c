/*	Floating point routines.

	Copyright (c) 2012 Microchip Technology Inc. All rights reserved.
*/

// this is bigendian code right now. Need to parameterise it.

#include	"ftarith.h"


// Convert byte to float

#ifdef _OLDLIB
#define	mant1	(*(unsigned short long *)&f1)
float
__abtoft(signed  char c)
{
	float	f1;
	
	if(c == 0)
		return 0.0;
	if(c < 0)
		mant1 = (unsigned char)-c;
	else
		mant1 = (unsigned char)c;
	__ftpack(&mant1, 127+15);
	if(c < 0)
		f1 = -f1;
	return f1;
}
#else
float
__abtoft(signed  char c)
{
	float	f1;
	unsigned char	sign;
	
	sign = 0;
	if (c < 0) {
		c = -c;
		sign = 1;
	}	
	return __ftpack((unsigned char) c, 127+15, sign);
}
#endif
