#include	<string.h>

#ifdef _PIC16
far void *
memset(far void * p1, int c, register size_t n)
#else /*  _PIC16 */
void *
memset(void * p1, int c, register size_t n)
#endif /* _PIC16 */
{

#ifdef _PIC16
	register far char *	p;
#else /*  _PIC16 */
	register char *		p;
#endif /* _PIC16 */

	p = p1;
	while(n--)
		*p++ = c;
	return p1;
}
