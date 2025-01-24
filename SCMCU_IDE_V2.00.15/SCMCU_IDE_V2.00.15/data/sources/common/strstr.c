#include	<string.h>

 char *
strstr(register const char * s1, register const char * s2)
{
	while(s1 && *s1) {
		if(strncmp(s1, s2, strlen(s2)) == 0)
			return ( char *)s1;
		s1 = strchr(s1+1, *s2);
	}
	return NULL;
}
