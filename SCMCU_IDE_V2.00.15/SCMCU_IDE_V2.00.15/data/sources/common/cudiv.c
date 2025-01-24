#include	<stdlib.h>

udiv_t
udiv(unsigned number, unsigned denom)
{
	udiv_t	rv;

	rv.quot = number/denom;
	rv.rem = number%denom;
	return rv;
}
