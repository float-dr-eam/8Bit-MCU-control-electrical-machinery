#include	<string.h>

size_t
strcspn(register const char * s1, register const char * s2)
{
	register size_t	i;

	i = 0;
	while(*s1 && !strchr(s2, *s1)) {
		s1++;
		i++;
	}
	return i;
}
