#include	<ctype.h>

#ifndef iscntrl

#ifdef _CTYPE_BIT_FUNCS_

bit
iscntrl(char c)
#else
int
iscntrl(int c)
#endif
{
	return c < ' ';
}

#endif
