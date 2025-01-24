#include	<string.h>

 char *
strrchr(register const char * ptr, int chr)
{
	register const char *	cp;

	cp = ptr+strlen(ptr);
	do
		if(*cp == (char)chr)
			return ( char *)cp;
	while(cp-- != ptr);
	return 0;
}
