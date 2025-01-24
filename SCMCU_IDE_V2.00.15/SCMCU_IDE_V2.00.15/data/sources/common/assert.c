#include	<assert.h>
#include	<stdio.h>
#include	<stdlib.h>

/* The default implementation of _fassert */

void
_fassert(int line, const char * file, const char *exp)
{
	printf("Assertion failed: %s line %d: \"%s\"\n", file, line, exp);
	abort();
}
