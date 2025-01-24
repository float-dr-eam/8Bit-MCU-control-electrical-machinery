#include	<stdlib.h>
#include	<stdio.h>

// quick and dirty ftoa for legacy code
char *
ftoa(float f, int * status)
{
	static char		buf[17];
	char *			cp = buf;
	unsigned long	l, rem;

	if(f < 0) {
		*cp++ = '-';
		f = -f;
	}
	l = (unsigned long)f;
	f -= (float)l;
	rem = (unsigned long)(f * 1e6);
	sprintf(cp, "%lu.%6.6lu", l, rem);
	return buf;
}
