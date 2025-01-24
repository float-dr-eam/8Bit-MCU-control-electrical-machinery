#include	<stdlib.h>

char *
#ifdef __18CXX
ltoa(long val, char * buf) 
#else
ltoa(char * buf, long val, int base) 
#endif
{
	char *	cp = buf;

	if(val < 0) {
		*buf++ = '-';
		val = -val;
	}
#ifdef __18CXX
	ultoa(val, buf);
#else
	ultoa(buf, val, base);
#endif
	return cp;
}

#ifdef __18CXX
#define base 10
#endif

char *
#ifdef __18CXX
ultoa(unsigned long val, char * buf)
#else
ultoa(char * buf, unsigned long val, int base)
#endif
{
	unsigned	long	v;
	char		c;

	v = val;
	do {
		v /= base;
		buf++;
	} while(v != 0);
	*buf-- = 0;
	do {
		c = val % base;
		val /= base;
		if(c >= 10)
			c += 'A'-'0'-10;
		c += '0';
		*buf-- = c;
	} while(val != 0);
	return buf;
}

#ifdef __18CXX
#undef base
#endif

