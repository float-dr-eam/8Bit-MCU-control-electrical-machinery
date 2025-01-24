
#include	<string.h>

#ifdef _PIC16
far char *
strncat(register far char * to, register const char * from, register size_t size)
#else /* _PIC16 */
char *
strncat(register char * to, register const char * from, register size_t size)
#endif /* _PIC16 */
{

#ifdef _PIC16
	register far char *	cp;
#else /* _PIC16 */
	register char *	cp;
#endif /* _PIC16 */

	cp = to;
	while(*cp)
		cp++;

	while (size && (*cp = *from)) {
		size--;
		cp++;
		from++;
	}
	if(size == 0)
		*cp = 0;
	return to;
}
