#include	<ctype.h>

#ifndef isalnum

#ifdef _CTYPE_BIT_FUNCS_

bit
isalnum(char c)
#else
int
isalnum(int c)
#endif
{
	return c <= '9' && c >= '0' || isalpha(c);
}

#endif
