#include	<string.h>

int
strncmp(register const char * s1, register const char * s2, size_t len)
{
	while(len--) {
		if(*s1 == 0 || *s1 != *s2)
			return (unsigned char)*s1 - (unsigned char)*s2;
		
		s1++;
		s2++;
	}
	return 0;
}
