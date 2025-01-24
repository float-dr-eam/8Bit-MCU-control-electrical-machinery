#include	<string.h>
#include	<ctype.h>

 char *
strrichr(register const char * ptr, int chr)
{
	register const char *	cp;

	cp = ptr;
	while(*ptr)
		ptr++;
	chr = toupper(chr);
	while(ptr != cp) {
		ptr--;
		if(toupper(*ptr) == (char)chr)
			return ( char *)ptr;
	}
	return 0;
}
