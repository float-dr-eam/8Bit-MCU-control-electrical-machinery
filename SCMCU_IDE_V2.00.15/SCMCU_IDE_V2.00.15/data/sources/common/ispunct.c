#include	<ctype.h>

#ifndef ispunct

#ifdef _CTYPE_BIT_FUNCS_

bit
ispunct(char c)
#else
int
ispunct(int c)
#endif
{
	if(c >= 041 && c <= 057 || c >= 072 && c <= 0100 || c >= 0133 && c <= 0140 ||
		c >= 0173 && c <= 0176)
		return 1;
	return 0;
}

#endif
