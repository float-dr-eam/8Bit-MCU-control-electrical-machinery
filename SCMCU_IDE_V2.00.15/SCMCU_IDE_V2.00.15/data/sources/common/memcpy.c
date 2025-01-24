
#if defined(__18CXX)
#include	<string.h>
#include	<htc.h>

void *
memcpy(void * d1, const void * s1, register size_t n)
{

	register char *		d;
	register const char *	s;
	volatile unsigned short long tmp = TBLPTR;

	s = s1;
	d = d1;
	while(n--)
		*d++ = *s++;
	TBLPTR = tmp;
	return d1;
}

#else

#include	<string.h>

void *
memcpy(void * d1, const void * s1, register size_t n)
{

	register char *		d;
	register const char *	s;
	register unsigned char tmp;

	s = s1;
	d = d1;
	while(n--) {
		tmp = *s++;
		*d++ = tmp;
	}
	return d1;
}

#endif

