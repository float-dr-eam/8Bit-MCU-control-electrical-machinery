#include	<ctype.h>

char
#ifdef _CTYPE_CHAR_PARAM_
tolower(char c)
#else
tolower(int c)
#endif
{
	if((char)c <= 'Z' && (char)c >= 'A')
		c |= ('a' - 'A');
	return (char)c;
}
