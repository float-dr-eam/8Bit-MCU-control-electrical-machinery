#ifdef __18CXX
#include <string.h>
#include <ctype.h>

char *
strlwr(char * s)
{
	char * tmp = s;
	while(*s != '\0') {
		*s = tolower(*s);
		s++;
	}
	return tmp;
}

#endif
