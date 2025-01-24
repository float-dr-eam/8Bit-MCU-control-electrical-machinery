#include	<ctype.h>
#include	<stdlib.h>

long
strtol(const char * s, char ** endptr, int base)
{
	long			a;
	char			c, sign;

	do 
		c = *s++;
	while(isspace(c));
	a = 0;
	sign = 0;
	if(c == '-') {
		sign = 1;
		c = *s++;
	} else if(c == '+')
		c = *s++;
	if(c == '0') {
	   c = *s++;
	   if((base == 0 || base == 16) && (c == 'x' || c == 'X')) {
		   base = 16;
		   c = *s++;
	   } else if(base == 0)
		   base = 8;
	}
	if(base == 0)
		base = 10;
	for(;;) {
		if(isalpha(c))
			c = toupper(c)-'A' + 10;
		else if(isdigit(c))
			c -= '0';
		else
			break;
		if(c >= base)
			break;
		a = a*base + c;
		c = *s++;
	}
	if(endptr)
		*endptr = (char *)(s-1);
	if(sign)
		return -a;
	return a;
}
