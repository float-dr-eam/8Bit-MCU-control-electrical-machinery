#ifdef __18CXX
#include <string.h>
#include <ctype.h>

char *
strupr(char * s)
{
	char * tmp = s;
	while(*s != '\0') {
		*s = toupper(*s);
		s++;
	}
	return tmp;
}

#endif
