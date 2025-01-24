#include	<ctype.h>

#ifndef isprint

#ifdef _CTYPE_BIT_FUNCS_

bit
isprint(char c)
#else
int
isprint(int c)
#endif
{
	return c <= 126 && c >= ' ';
}

#endif
