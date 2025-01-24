#include	<string.h>
#include	<ctype.h>

 char *
strichr(register const char * ptr, int chr)
{
	chr = toupper(chr);
	while(*ptr) {
		if(toupper(*ptr) == (char)chr)
			return ( char *)ptr;
		ptr++;
	}
	return 0;
}
