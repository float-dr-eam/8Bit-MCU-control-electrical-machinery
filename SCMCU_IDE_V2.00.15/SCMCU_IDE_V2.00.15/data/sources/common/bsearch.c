/*
 *	Binary Search
 */

#include	<stdlib.h>
#include	<string.h>

void *
bsearch(const void * key, void * basep, size_t nmemb, size_t size,
	int (*compar)(const void *, const void *))
{
	register int	i,j,x;
	int		r;
	register char *	base;

	if(nmemb == 0)
		return NULL;
	base = basep;

	i = 0; j = nmemb-1;
	do {
		x = (i + j)/2;
		if((r = compar(key, base+x*size)) == 0)
			return base+x*size;
		else if(r < 0)
			j = x-1;
		else if (r > 0)
			i = x+1;
	} while(j >= 0 && i <= j);
	return NULL;
}
