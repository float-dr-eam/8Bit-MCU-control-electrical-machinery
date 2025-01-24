#include	<stdio.h>
#include	<stdarg.h>

#if	defined(_MPC_) && !defined(_OMNI_CODE_) && !defined(__DSPICC__)
printf(const char * f, ...)
{
	va_list	ap;

	va_start(ap, f);
	_doprnt(0, f, ap);
}
#else
printf(const char * f, ...)
{
	va_list	ap;

#ifdef	_HOSTED
	va_start(ap, f);
	return(vfprintf(stdout, f, ap));
#else
	struct	__prbuf	pb;

	pb.ptr = 0;
	pb.func = putch;
	va_start(ap, f);
	return _doprnt(&pb, f, ap);
#endif
}
#endif
