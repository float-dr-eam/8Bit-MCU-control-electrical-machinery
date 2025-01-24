#include	<string.h>

 char *
strpbrk(register const char * s1, register const char * s2)
{
	while(*s1) {
		if(strchr(s2, *s1))
			return ( char *)s1;
		s1++;
	}
	return NULL;
}
