#include	<stdlib.h>

uldiv_t
uldiv(unsigned long number, unsigned long denom)
{
	uldiv_t	rv;

	rv.quot = number/denom;
	rv.rem = number%denom;
	return rv;
}
