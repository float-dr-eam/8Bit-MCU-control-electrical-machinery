#include	<stdlib.h>

static	long	randx = 1;

void
srand(unsigned x)
{
	randx = x;
}

int
rand(void)
{
	randx = randx*1103515245L;
	randx += 12345;
	return (int)((randx >> 16) & 0x7FFF);
}
