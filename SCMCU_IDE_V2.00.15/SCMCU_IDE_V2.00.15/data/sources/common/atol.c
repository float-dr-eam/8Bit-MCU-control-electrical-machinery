#include	<ctype.h>
#include	<stdlib.h>

long
atol(register const char * s)
{
	long	a;
	unsigned char	sign, c;

	do
		c = *s++;
	while(c == ' ' || c == '\t');
	a = 0;
	sign = 0;
	if(c == '-') {
		sign++;
		c = *s++;
	} else if(c == '+')
		c = *s++;
	while(isdigit(c)) {
		a = a*10L + (unsigned char)(c - '0');
		c = *s++;
	}
	if(sign)
		return -a;
	return a;
}
