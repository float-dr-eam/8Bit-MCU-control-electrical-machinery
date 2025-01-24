#include	<ctype.h>

char
#ifdef _CTYPE_CHAR_PARAM_
toupper(register char c)
#else
toupper(register int c)
#endif
{
	if((char)c <= 'z' && (char)c >= 'a')
		c &= ~('a' - 'A') & 0xFF;
	return (char)c;
}
