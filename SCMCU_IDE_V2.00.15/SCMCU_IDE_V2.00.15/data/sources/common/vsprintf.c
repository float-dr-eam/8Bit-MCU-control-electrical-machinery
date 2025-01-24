#include	<stdio.h>
#include	<stdarg.h>

vsprintf(char * wh, const char * f, va_list ap)
{
#if	_HOSTED
	FILE	spf;

	spf._size = 32767;
	spf._cnt = 0;
	spf._base = spf._ptr = wh;
	spf._flag = _IOWRT|_IOBINARY|_IOSTRG;
	vfprintf(&spf, f, ap);
	*spf._ptr = 0;
	return spf._ptr - wh;
#else
	struct	__prbuf	pb;

	pb.ptr = wh;
	pb.func = (void (*)(char))NULL;
	_doprnt(&pb, f, ap);
	*pb.ptr = 0;
	return pb.ptr - wh;
#endif
}
