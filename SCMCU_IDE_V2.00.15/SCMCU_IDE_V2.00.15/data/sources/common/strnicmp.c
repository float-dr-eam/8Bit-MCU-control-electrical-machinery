#include	<string.h>
#include	<ctype.h>

int
strnicmp(register const char * s1, register const char * s2, size_t len)
{
	register signed char	r;

	while(len--) {
		if((r = toupper(*s1) - toupper(*s2)) || *s1 == 0)
			return r;
		s1++;
		s2++;
	}
	return 0;
}
