/*	Floating point routines.

	Copyright (c) 2012 Microchip Technology Inc. All rights reserved.
*/

#include	"ftarith.h"


//	unpack the operand pointed to. Store the exponent into the location pointed to by exp,
//	and return the sign (zero is positive)

#ifdef _OLDLIB

unsigned char
__ftunpack(unsigned short long * arg, unsigned char * exp)
{
	unsigned char	sign;

	*exp = sign = *arg >> 15;
	if(sign == 0) {
		*arg = 0;
		return 0;
	}
	sign = 0;
	*arg |= 0x8000;
	if(*arg & 0x800000)
		sign++;
	*arg &= 0xFFFF;
	return sign;
}

// normalize and pack the supplied argument into floating point format

void
__ftpack(unsigned short long * arg, unsigned char exp)
{
	if(exp == 0 || *arg == 0) {
		*arg = 0;
		return;
	}
	while(*arg & 0xFE0000UL) {
		exp++;
		*arg >>= 1;
	}
	while(*arg & 0xFF0000UL) {
		exp++;
		(*arg)++;
		*arg >>= 1;
	}
	while(!(*arg & 0x8000UL)) {
		exp--;
		*arg <<= 1;
	}
	if(!(exp & 1))
		*arg &= ~0x8000L;
	exp >>= 1;
	*arg |= (unsigned short long)exp << 16;
}

#else
float
__ftpack(unsigned short long arg, unsigned char exp, unsigned char sign)
{
	if(exp == 0 || arg == 0)
		return 0.0;
	while(arg & 0xFE0000UL) {
		exp++;
		arg >>= 1;
	}
	while(arg & 0xFF0000UL) {
		exp++;
		(arg)++;
		arg >>= 1;
	}
	while(!(arg & 0x8000UL) && exp > 1) {
		exp--;
		arg <<= 1;
	}
	if(!(exp & 1))
		arg &= ~0x8000L;
	exp >>= 1;
	arg |= (unsigned short long)exp << 16;
	if (sign)
		arg |= 0x800000UL;
   return *(float*)&arg;	
}

#endif
