#include	<htc.h>
#include <setjmp.h>

typedef char    jmp_buf[4];

/* setjmp/longjmp for PIC18 series; all that is required is to
 * reload the stack pointer then return
 */

#ifdef __STACK
__nonreentrant 
#endif
int 
setjmp(jmp_buf jp)
{
	/* save the stack level and location */
	jp[0] = STKPTR;
	jp[1] = TOSL;
	jp[2] = TOSH;
	jp[3] = TOSU;
	return 0;
}

#ifdef __STACK
__nonreentrant 
#endif
void 
longjmp(jmp_buf jp, int retval)
{
	/* can't use return here cause this is a void function! */
	/* restore the stack level and location */
	STKPTR = jp[0];
	TOSL = jp[1];
	TOSH = jp[2];
	TOSU = jp[3];

	/* If retval is non-zero, setjmp will return it, 
	 * else setjmp will return 1.
	 */
	if(retval)	{
		asm("movff longjmp@retval,?_setjmp");
		asm("movff longjmp@retval+1,?_setjmp+1");
	} else {
		asm("movlw 1");
		asm("movff wreg,?_setjmp");
		asm("movlw 0");
		asm("movff wreg,?_setjmp+1");
	}
}
