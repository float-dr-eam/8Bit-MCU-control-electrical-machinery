#include	<ctype.h>

#ifndef isdigit

#ifdef _CTYPE_BIT_FUNCS_

bit
isdigit(char c)
#else
int
isdigit(int c)
#endif
{
	return c <= '9' && c >= '0';
}

#endif
