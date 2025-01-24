/*
 *	puts and fputs for XC8 stdio
 */

#include	<stdio.h>
#include	<conio.h>

puts(const char * s)
{
	cputs(s);
	putch('\n');
}
