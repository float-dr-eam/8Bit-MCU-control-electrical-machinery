#include	<ctype.h>

#ifndef isxdigit

#ifdef _CTYPE_BIT_FUNCS_

bit
isxdigit(char c)
#else
int
isxdigit(int c)
#endif
{
	return c <= 'f' && c >= 'a' || c <= 'F' && c >= 'A' || isdigit(c);
}

#endif
