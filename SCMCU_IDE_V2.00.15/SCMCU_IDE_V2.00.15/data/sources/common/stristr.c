#include	<string.h>

 char *
stristr(register const char * s1, register const char * s2)
{
	while(s1 && *s1) {
		if(strnicmp(s1, s2, strlen(s2)) == 0)
			return ( char *)s1;
		s1 = strichr(s1+1, *s2);
	}
	return NULL;
}
