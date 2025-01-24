#include	<ctype.h>

#ifndef islower

#ifdef _CTYPE_BIT_FUNCS_

bit
islower(char c)
#else
int
islower(int c)
#endif
{
	return c <= 'z' && c >= 'a';
}

#endif
