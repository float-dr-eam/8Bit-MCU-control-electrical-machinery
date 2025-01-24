#include	<string.h>

size_t
strlen(const char * s)
{
	register const char *	cp;

	cp = s;
	while(*cp) {
		cp++;
	}
	return cp-s;
}

