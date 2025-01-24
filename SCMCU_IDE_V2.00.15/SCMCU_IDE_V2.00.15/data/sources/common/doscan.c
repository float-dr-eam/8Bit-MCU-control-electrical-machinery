/*
 *	_doscan - implement scanf, fscanf, sscanf
 */

#include	<stdio.h>
#include 	<ctype.h>
#include	<stdlib.h>
#include	<stdarg.h>
#include	<conio.h>
#include	<string.h>
#include	<hitech.h>

#if	defined(i8051) && defined(SMALL_MODEL)
#define	STATIC	static idata
#define	EXTERN	extern idata
#else
#define	STATIC	static
#define	EXTERN	extern
#endif

STATIC const char *	ptr;
EXTERN char		_scanf_buf_[];
STATIC uchar		flag;

#if	defined(i8086)
STATIC unsigned int	boffs;
#else
STATIC uchar		boffs;
#endif

static void
ungetchl()
{
	if(ptr)
		ptr--;
	if(!flag)
		boffs = ptr-_scanf_buf_;
}

static uchar
getchl()
{
	uchar	c;

	if(flag)
		if(ptr && *ptr)
			return *ptr++;
		else
			return 0;
	if(!ptr || *ptr == 0) {
		cgets(_scanf_buf_);
		strcat(_scanf_buf_, "\n");
		ptr = _scanf_buf_;
	}
	c = *ptr++;
	boffs = ptr-_scanf_buf_;
	return c;
}

static uchar
range(uchar c, uchar base)
{
	if(isdigit(c))
		c -= '0';
	else
		{
		if (isupper(c))
			c = tolower(c) ;
		if (isalpha(c))
			c = c - 'a' + 10 ;
		else
			return 255;
		}
	if (c >= base)
		return 255;
	return c;
}

static
wspace()
{
	uchar	c;

	while(isspace(c = getchl()))
		continue;
	if(c != 0)
		ungetchl();
}

_doscan(const char * str, const char * fmt, va_list ap)
{
	uchar	c, sign, base, n, noass,len;
	char	width ;
	char *	sptr;
	uchar	ch;
	long	val;

	if(str) {
		flag = 1;
		ptr = str;
	} else {
		flag = 0;
		ptr = _scanf_buf_+boffs;
	}
	n = 0;
	while(c = *fmt++) {

		len = sizeof(int);
		if(isspace(c)) {
			wspace();
			continue;
		}
		if(c == '%') {
			noass = 0;
			width = 0;
loop:
			switch(c = *fmt++) {

			case '\0':
				return n;

			case '*':
				noass++;
				goto loop;

			case 'l':
			case 'L':
				len = sizeof(long);
				goto loop;

			case 'h':
				len = sizeof(short);
				goto loop;

			case 'd':
			case 'u':
				base = 10;
				break;

			case 'o':
				base = 8;
				break;

			case 'X':
			case 'x':
				base = 16;
				break ;

			case 's':
				wspace();
				if ( !noass )
					sptr = va_arg(ap, char *);
				if ((ch = getchl()) == 0)
					return n ? n : EOF;
				while(ch && !isspace(ch)) {
					if(ch == *fmt) {
						fmt++;
						break;
					}
					if ( !noass ) 
						*sptr++ = ch;
					if(--width == 0)
						break;
					ch = getchl();
				}
				if(!noass) {
					n++;
					*sptr = 0;
				}
				continue;

			case 'c':
				if ( !noass ) {
					n++;
					sptr = va_arg(ap, char *);
				}
				do {
					if ((ch = getchl()) == 0) 
						return n ? n : EOF;
					if ( !noass )
						*sptr++ = ch;
				} while(width && --width > 0);
				continue;
			default:
				if(isdigit(c)) {
					width = atoi(fmt-1);
					while(isdigit(*fmt))
						fmt++;
					goto loop;
				}
				if(c != (ch = getchl()))
					if(ch == 0)
						return n ? n : EOF;
					else {
						ungetchl();
						return n;
					}
				continue;
			}
			wspace();
			val = 0;
			sign = 0;
			ch = getchl();
			if(ch == '-') {
				sign++;
				ch = getchl();
			}
			if(ch == '+')
				ch = getchl();
			if(range(ch, base) == 255) {
				if(ch != 0)
					ungetchl();
				return n;
			}
			do {
				uchar	x;

				x = range(ch, base);
				val = val * base + x;
			} while (( --width != 0 ) && ( range(ch = getchl(),base) != 255 )) ;
			if (ch != 0 && range(ch,base) == 255)
				ungetchl();
			if(sign)
				val = -val;
			if ( !noass ) {
				n++;
				if(len == sizeof(long))
					*va_arg(ap, long *) = val;
				else if(len == sizeof(short))
					*va_arg(ap, short *) = val;
				else
					*va_arg(ap, int *) = val;
			}
			continue;
		} else if(c != (ch = getchl())) {
			if(ch != 0) {
				ungetchl();
				return n;
			} else
				return n ? n : EOF;
		}
	}
	return n;
}
