#include	<string.h>

#ifdef _PIC16
far char *
strtok(register far char * s1, register const char * s2)
#else /* _PIC16 */
char *
strtok(register char * s1, register const char * s2)
#endif /* _PIC16 */

{
#ifdef _PIC16
	static far char *	sp;
#else /* _PIC16 */
	static char *	sp;
#endif /* _PIC16 */

	if(!s1)
		s1 = sp;
	if(!s1)
		return NULL;
	s1 += strspn(s1, s2);	/* skip leading delimiters */
	if(!*s1)
		return sp = NULL;
	sp = s1 + strcspn(s1, s2);
	if(*sp)
		*sp++ = 0;
	else
		sp = 0;
	return s1;
}
