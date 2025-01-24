#include	<stdlib.h>

long
labs(long l)
{
	if(l < 0)
		return -l;
	return l;
}
