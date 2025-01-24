#ifndef	_STDIO_H_
#define	_STDIO_H_

#include <__size_t.h>
#include <__null.h>

#define	BUFSIZ		1024
#define	_NFILE		20

#ifndef	_STDARG
#include	<stdarg.h>
#endif

#ifndef FILE

#if	_HOSTED
extern	struct	_iobuf {
	char *		_ptr;
	int		_cnt;
	char *		_base;
	unsigned short	_flag;
	short		_file;
	size_t		_size;
} _iob[_NFILE];

#define	FILE		struct _iobuf

#define	L_tmpnam	81		/* max length of temporary names */
#define	_MAXTFILE	8		/* max number of temporary files */

#if	DOS
#define	FILENAME_MAX	81		/* max length of a pathname */
#define	FOPEN_MAX	5
#endif

extern struct _tfiles {
	char	tname[L_tmpnam];
	FILE *	tfp;
}	* _tfilesptr;

#else	/* _HOSTED */

struct __prbuf
{
	char *		ptr;
	void (*		func)(char);
};
#endif	/* _HOSTED */
#endif	/* FILE */

#define	_IOFBF		0
#define	_IOREAD		01
#define	_IOWRT		02
#define	_IORW		03
#define	_IONBF		04
#define	_IOMYBUF	010
#define	_IOEOF		020
#define	_IOERR		040
#define	_IOSTRG		0100
#define	_IOBINARY	0200
#define	_IOLBF		0400
#define	_IODIRN		01000	/* true when file is in write mode */
#define	_IOAPPEND	02000	/* file was opened in append mode */
#define	_IOSEEKED	04000	/* a seek has occured since last write */
#define	_IOTMPFILE	010000	/* this file is a temporary */

#define	EOF		(-1)
#define	_IOSTRING	(-67)

#define	SEEK_SET	0
#define	SEEK_CUR	1
#define	SEEK_END	2
#define	TMP_MAX		255

#if	_HOSTED
#define	stdin		(&_iob[0])
#define	stdout		(&_iob[1])
#define	stderr		(&_iob[2])
#ifdef	DOS
#define	stdprn		(&_iob[3])
#endif
#define	getchar()	getc(stdin)
#define	putchar(x)	putc(x,stdout)
#else	/* _HOSTED */
#include	<conio.h>
#define	getchar()	getche()
#define	putchar(x)	putch(x)
extern int	cprintf(char *, ...);
#pragma printf_check(cprintf)
#if	defined(_MPC_) && !defined(_PIC18) && !defined(__DSPICC__) && !defined(__PICCPRO__) && !defined(__18CXX)
extern void	_doprnt(char *, const register char *, ...);
#else
extern int	_doprnt(struct __prbuf *, const register char *, register va_list);
#endif	/* _MPC_ */
#endif	/* _HOSTED */

/*	getc() and putc() must be functions for CP/M to allow the special
 *	handling of '\r', '\n' and '\032'. The same for MSDOS except that
 *	it at least knows the length of a file.
 */

#define	getc(p)		fgetc(p)
#define	putc(x,p)	fputc(x,p)

#define	feof(p)		(((p)->_flag&_IOEOF)!=0)
#define	ferror(p)	(((p)->_flag&_IOERR)!=0)
#define	fileno(p)	((unsigned short)p->_file)
#define	clrerr(p)	p->_flag &= ~_IOERR
#define	clreof(p)	p->_flag &= ~_IOEOF
#define	clearerr(p)	p->_flag &= ~(_IOERR|_IOEOF)


#if	_HOSTED
extern int	_flsbuf(char, FILE *);
extern int	_filbuf(FILE *);
extern int	fclose(FILE *);
extern int	fflush(FILE *);
extern int	fgetc(FILE *);
extern int	ungetc(int, FILE *);
extern int	fputc(int, FILE *);
extern int	getw(FILE *);
extern int	putw(int, FILE *);
extern int	fputs(const char *, FILE *);
extern int	fread(void *, size_t, size_t, FILE *);
extern int	fwrite(const void *, size_t, size_t, FILE *);
extern int	fseek(FILE *, long, int);
extern int	rewind(FILE *);
extern void	setbuf(FILE *, char *);
extern int	setvbuf(FILE *, char *, int, size_t);
extern int	fprintf(FILE *, const char *, ...);
extern int	fscanf(FILE *, const char *, ...);
extern int	vfprintf(FILE *, const char *, va_list);
extern int	vfscanf(FILE *, const char *, va_list);
extern int	remove(const char *);
extern int	rename(const char *, const char *);
extern FILE *	fopen(const char *, const char *);
extern FILE *	freopen(const char *, const char *, FILE *);
extern FILE *	fdopen(int, const char *);
extern long	ftell(FILE *);
extern char *	fgets(char *, int, FILE *);
extern void	perror(const char *);
extern char *	_bufallo(void);
extern void	_buffree(char *);
extern char *	tmpnam(char *);
extern FILE *	tmpfile(void);

#if	unix
extern FILE *	popen(char *, char *);
extern int	pclose(FILE *);
#endif
extern void	(*_atexitptr)(void);

#pragma	printf_check(fprintf)
#pragma	printf_check(vfprintf)

#endif	/* __HOSTED */

#if	defined(_MPC_) && !defined(_PIC18) && !defined(__DSPICC__) && !defined(__PICCPRO__) && !defined(__18CXX)
extern int	_doscan(const char *, const char *, va_list);
//#define vprintf(s, l)		_doprnt(0, (s), (l))
//#define vsprintf(b, s, l)	_doprnt((b), (s), (l))
//#define vscanf(s, l)		_doscan(0, (s), (l))
//#define vsscanf(b, s, l)	_doscan((b), (s), (l))
#pragma	printf_check(printf) const
#pragma	printf_check(sprintf) const
#pragma	printf_check(vsprintf) const

#if defined(_PIC16)
extern unsigned char 	sprintf(far char *, const char *, ...);
#else	/* _PIC16 */
extern unsigned char 	sprintf(char *, const char *, ...);
#endif
#if	defined(_PIC18)
extern int	printf(const char *, ...);
#else
extern unsigned char	printf(const char *, ...);
#endif
#else /* _MPC_ */

#pragma	printf_check(vprintf) const
#pragma	printf_check(vsprintf) const

extern char *	gets(char *);
extern int	puts(const char *);
extern int	scanf(const char *, ...)  __attribute__((unsupported("scanf() is not supported by this compiler")));
extern int	sscanf(const char *, const char *, ...)  __attribute__((unsupported("sscanf() is not supported by this compiler")));
extern int 	vprintf(const char *, va_list) __attribute__((unsupported("vprintf() is not supported by this compiler")));
extern int	vsprintf(char *, const char *, va_list) __attribute__((unsupported("vsprintf() is not supported by this compiler")));
extern int	vscanf(const char *, va_list ap)  __attribute__((unsupported("vscanf() is not supported by this compiler")));
extern int	vsscanf(const char *, const char *, va_list)  __attribute__((unsupported("vsscanf() is not supported by this compiler")));

#pragma	printf_check(printf) const
#pragma	printf_check(sprintf) const
extern int sprintf(char *, const char *, ...);
extern int printf(const char *, ...);

#endif	/* _MPC_ */

#endif	/* _STDIO_H_ */
