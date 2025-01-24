#include	<stdlib.h>

div_t
div(int number, int denom)
{
	div_t	rv;

	rv.quot = number/denom;
	rv.rem = number%denom;
	return rv;
}
