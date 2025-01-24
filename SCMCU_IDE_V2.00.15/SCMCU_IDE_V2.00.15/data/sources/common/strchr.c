#include	<string.h>

 char *
strchr(register const char * ptr, int chr)
{
	do
		if(*ptr == (char)chr)
			return ( char *)ptr;
	while(*ptr++);
	return 0;
}
