#include	<stdio.h>
#include	<stdarg.h>

#if	defined(_MPC_) && !defined(_OMNI_CODE_) && !defined(__DSPICC__)
sprintf(char * wh, const char * f, ...)
{
	va_list	ap;

	va_start(ap, f);
	_doprnt(wh, f, ap);
}
#else
sprintf(char * wh, const char * f, ...)
{
#ifdef	_HOSTED
	FILE	spf;
	va_list	ap;

	va_start(ap, f);
	spf._size = 32767;
	spf._cnt = 0;
	spf._base = spf._ptr = wh;
	spf._flag = _IOWRT|_IOBINARY|_IOSTRG;
	vfprintf(&spf, f, ap);
	*spf._ptr = 0;
	return spf._ptr - wh;
#else
	va_list	ap;
	struct	__prbuf	pb;
	
	pb.ptr = wh;
	pb.func = (void (*)(char))NULL;
	va_start(ap, f);
	_doprnt(&pb, f, ap);
	*pb.ptr = 0;
	return pb.ptr - wh;
#endif
}
#endif
