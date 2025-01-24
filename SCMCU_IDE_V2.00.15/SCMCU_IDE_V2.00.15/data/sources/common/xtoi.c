#include	<ctype.h>
#include	<stdlib.h>

unsigned
xtoi(register const char * s)
{
	char		sign, c;
	unsigned	val;

	sign = 0;
	val = 0;
	while(isspace(*s))
		s++;
	if(*s == '-') {
		sign++;
		s++;
	} else if(*s == '+')
		s++;
	while(isxdigit(c = *s++)) {
		if(isupper(c))
			c = tolower(c);
		if(isdigit(c))
			c -= '0';
		else
			c -= 'a' - 10;
		val *= 16;
		val += (unsigned char)c;
	}
	if(sign)
		return -val;
	return val;
}
