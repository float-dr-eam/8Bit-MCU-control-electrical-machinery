/*
 *	Low-level console I/O functions
 */

#ifndef _CONIO_H_
#define _CONIO_H_

#include <errno.h>
#include <__null.h>

#if	!_HOSTED
extern void	init_uart(void);
#endif
extern char	getch(void);
extern char	getche(void);
extern void	putch(char);
extern void	ungetch(char);
#if (defined(_MPC_) && !defined(__DSPICC__)) || defined(__18CXX)
extern __bit	kbhit(void);
#else
extern int	kbhit(void);
#endif
extern char *	cgets(char *);
extern void	cputs(const char *);

#endif // _CONIO_H_
