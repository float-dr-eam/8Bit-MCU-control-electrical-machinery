#include	<stdlib.h>

ldiv_t
ldiv(long number, long denom)
{
	ldiv_t	rv;

	rv.quot = number/denom;
	rv.rem = number%denom;
	return rv;
}
