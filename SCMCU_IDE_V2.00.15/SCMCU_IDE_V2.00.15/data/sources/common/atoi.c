#include	<ctype.h>
#include	<stdlib.h>

int
atoi(register const char * s)
{
	register int	a;
	register unsigned char	sign;

	while(*s == ' ' || *s == '\t')
		s++;
	a = 0;
	sign = 0;
	if(*s == '-') {
		sign++;
		s++;
	} else if(*s == '+')
		s++;
	while(isdigit(*s))
		a = a*10 + (*s++ - '0');
	if(sign)
		return -a;
	return a;
}
