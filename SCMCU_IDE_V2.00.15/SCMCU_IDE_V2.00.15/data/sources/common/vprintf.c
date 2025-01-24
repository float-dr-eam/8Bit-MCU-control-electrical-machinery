#include	<stdio.h>
#include	<stdarg.h>

vprintf(const char * f, va_list ap)
{
#ifdef	_HOSTED
	return(vfprintf(stdout, f, ap));
#else
	struct	__prbuf	pb;

	pb.ptr = 0;
	pb.func = putch;
	_doprnt(&pb, f, ap);
#endif
}
