/*
 * memchr: find a char in a block of memory
 */

#include <string.h>

 void *
memchr(const void *p, int n, size_t v)
{
	register  unsigned char *s = p;

	while (v--)
		if (*s == (unsigned char)n)
			return s;
		else
			++s;
	
	return 0;
}
