#include	<ctype.h>

#ifndef isalpha

#ifdef _CTYPE_BIT_FUNCS_

bit
isalpha(char c)
#else
int
isalpha(int c)
#endif
{
	return c <= 'z' && c >= 'a' || isupper(c);
}

#endif
