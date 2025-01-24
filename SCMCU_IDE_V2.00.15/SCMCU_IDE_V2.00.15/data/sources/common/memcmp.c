#include	<string.h>

memcmp(const void *s1, const void *s2, size_t n)
{
	while(n-- != 0)  {
		if(*((const unsigned char *)s1) != *((const unsigned char *)s2))
			return *((const unsigned char *)s1) - *((const unsigned char *)s2);
		(*(const unsigned char **)&s1)++;
		(*(const unsigned char **)&s2)++;
	}
	return 0;
}
