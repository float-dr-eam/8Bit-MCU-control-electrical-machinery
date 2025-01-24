#include	<conio.h>

void
cputs(const char * s)
{
	while(*s)
		putch(*s++);
}
