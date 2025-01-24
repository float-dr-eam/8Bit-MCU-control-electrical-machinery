/*	Floating point routines.

	Copyright (c) 2012 Microchip Technology Inc. All rights reserved.	
*/

// this is bigendian code right now. Need to parameterise it.

#include	"ftarith.h"


// Convert signed int to float

#ifdef _OLDLIB
#define	f1_as_mant1	(*(unsigned short long *)&f1)
float
__altoft(signed long int c)
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
	// normalize 32 bits to 24 first
	while(c & ~0xFFFFFFUL) {
		*(unsigned long int *)&c >>= 1;
		exp++;
	}
	f1_as_mant1 = c;
	__ftpack(&f1_as_mant1, exp);
	if(sign)
		f1 = -f1;
	return f1;
}
#else
float
__altoft(signed long int c)
{
	unsigned char exp, sign;
	sign = 0;
	exp = 127+15;
	if (c < 0) {
		c = -c;
		sign = 1;
	}
	// normalize 32 bits to 24 first
	while(c & ~0xFFFFFFUL) {
		*(unsigned long int *)&c >>= 1;
		exp++;
	}
	return __ftpack((unsigned short long)c, exp, sign); 
}
#endif
