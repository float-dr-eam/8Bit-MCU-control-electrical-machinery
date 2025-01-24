#ifndef	__SETJMP_H
#define	__SETJMP_H

#if	defined(_PIC18) || defined(__18CXX)
typedef	char jmp_buf[4];

#elif	defined(__DSPICC__)
typedef unsigned int jmp_buf[4];

#elif	defined(_PIC14E) || defined(_PIC14EX)
typedef char jmp_buf[3];

#else
#error	setjmp.h: Processor type not supported, or not defined.
#endif

#ifdef __STACK
extern __nonreentrant int		setjmp(jmp_buf);
extern __nonreentrant void	longjmp(jmp_buf, int);
#else
extern int	setjmp(jmp_buf);
extern void	longjmp(jmp_buf, int);
#endif

#endif	/* __SETJMP_H */
