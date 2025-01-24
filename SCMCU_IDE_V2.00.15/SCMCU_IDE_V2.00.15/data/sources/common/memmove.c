#include	<string.h>

#ifdef _PIC16
far void *
memmove(far void * d1, const void * s1, register size_t n)
#else  /* _PIC16 */
void *
memmove(void * d1, const void * s1, register size_t n)
#endif /* _PIC16 */
{

#ifdef _PIC16
	register far char *	d;
#else /*  _PIC16 */
	register char *		d;
#endif /* _PIC16 */
	register const char *	s;

	s = s1;
	d = d1;
	
#if	defined(_PIC12) || defined(_PIC14) || defined(_PIC14E) || defined(_PIC14EX)
	if((unsigned short)s < (unsigned short)d && (unsigned short)s+n > (unsigned short)d) {
#else
	if(sizeof(s) == sizeof(d) && s < d && s+n > d) {		/* overlap? */
#endif
		s += n;
		d += n;
		do			/* n != 0 */
			*--d = *--s;
		while(--n);
	} else if(n)
		do
			*d++ = *s++;
		while(--n);
	return d1;
}
