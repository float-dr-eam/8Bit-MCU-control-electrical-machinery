/*
 *	Fake routines for getchar and putchar
 */

#include	<stdio.h>
#include	<conio.h>

#undef	getchar
#undef	putchar
int getchar(void)
{
	return getche();
}

int putchar(int c)
{
	putch(c);
	return c;
}
