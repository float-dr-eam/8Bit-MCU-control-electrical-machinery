/*
 *	gets and fgets for XC8 stdio
 */

#include	<stdio.h>
#include	<string.h>
#include	<conio.h>

char *
gets(char * s)
{
	return cgets(s);
}
