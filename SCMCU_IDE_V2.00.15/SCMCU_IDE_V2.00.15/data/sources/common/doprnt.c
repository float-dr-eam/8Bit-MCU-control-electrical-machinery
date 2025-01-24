#include	<stdio.h>
#include	<ctype.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdarg.h>
#include	<conio.h>
#include	<sys.h>
#include	<math.h>
#include	<float.h>

// disable unused variable warnings
// the compiler will optimize them away, so no harm is done
#pragma warning disable 350

/*
 *	doprnt - versions depends on conditional compilation.
 *	Can be customized with defines.
 *
 *	Copyright (c) 2012 Microchip Technology Inc. All rights reserved.
 *
 *	$Header$
 *
 */

#ifndef	CUSTOM_PRINTF

 // define all flags, thus enabling all features

#define	BASEM	0xC0
#define	OPTSIGN	0x00
#define	SPCSIGN	0x01
#define	MANSIGN	0x02
#define	NEGSIGN	0x03
#define	FILL	0x04
#define	LEFT	0x08
#define	LONG	0x10
#define	UPCASE	0x20
#define	TEN		0x00
#define	EIGHT	0x40
#define	SIXTEEN	0x80
#define	UNSIGN	0xC0
#ifdef	__FLOAT
#define	EFMT	0x100
#define	GFMT	0x200
#define	FFMT	0x400
#endif	// __FLOAT
#define	ALTERN	0x800
#define POINTER	0x2000
#define HEXUPCASE
#define HEXLOWCASE

 // defines for ifdef only, not used as flags
#define	WIDTH	1		// width used
#define	STAR	1		// width or precision as an arg
#define	STRING	1		// %s used
#define	CHAR	1		// %c used
#define	PERCPERC	1	// %% used
#define	SPRINTF	1		// sprintf is used
#define	PRINTF	1		// printf is used
#define	MULTRAD	1		// handle multiple radices
#define	RETVALUE	1	// return value is needed

#else	// CUSTOM_PRINTF

#if	defined(HEXUPCASE) || defined(HEXLOWCASE)
#define	SIXTEEN
#endif

#if	defined(HEXUPCASE) && defined(HEXLOWCASE)
#ifndef UPCASE
#define	UPCASE
#endif
#endif

 // make sure we have the right values for each define
#ifdef	OPTSIGN
#undef	OPTSIGN
#define	OPTSIGN	0x00
#endif
#ifdef	SPCSIGN
#undef	SPCSIGN
#define	SPCSIGN	0x01
#endif
#ifdef	MANSIGN
#undef	MANSIGN
#define	MANSIGN	0x02
#define	SPCSIGN	0x01
#endif
#ifdef	NEGSIGN
#undef	NEGSIGN
#define	NEGSIGN	0x03
#endif
#ifdef	FILL
#define	WIDTH	1
#undef	FILL
#define	FILL	0x04
#endif
#ifdef	LEFT
#undef	LEFT
 // LEFT without WIDTH is meaningless
#ifdef	WIDTH
#define	LEFT	0x08
#endif
#endif
#ifdef	LONG
#undef	LONG
#define	LONG	0x10
#define	__LONG	1
#endif
#ifdef	UPCASE
#undef	UPCASE
#define	UPCASE	0x20
#endif
#ifdef	TEN	
#undef	TEN	
#define	TEN		0x00
#endif
#ifdef	EIGHT
#undef	EIGHT
#define	EIGHT	0x40
#endif
#ifdef	SIXTEEN
#undef	SIXTEEN
#define	SIXTEEN	0x80
#endif
#ifdef	UNSIGN
#undef	UNSIGN
#define	UNSIGN	0xC0
#endif
#ifdef	EFMT
#undef	EFMT
#define	EFMT	0x100
#endif
#ifdef	GFMT
#undef	GFMT
#define	GFMT	0x200
#endif
#ifdef	FFMT
#undef	FFMT
#define	FFMT	0x400
#endif
#ifdef	ALTERN
#undef	ALTERN
#define	ALTERN	0x800
#endif
#ifdef	POINTER
#undef	POINTER
#define POINTER	0x2000
#ifndef	SIXTEEN
#define	SIXTEEN	0x80
#endif
#endif
#ifdef	PRECISION
#undef	PRECISION
#define PRECISION	0x4000
#endif

#if	defined(TEN) && !defined(EIGHT) && !defined(SIXTEEN) && defined(UNSIGN)
#undef	UNSIGN
#define	UNSIGN	0x40
#define	BASEM	UNSIGN
#endif
#if	defined(UNSIGN) && (defined(EIGHT) || defined(SIXTEEN))
#define	MULTRAD	1
#define	BASEM	(UNSIGN)
#endif
#if	defined(TEN) && !defined(SIXTEEN) && defined(EIGHT) && !defined(UNSIGN)
#define	BASEM	EIGHT
#define	MULTRAD	1
#endif
#if	defined(TEN) && defined(SIXTEEN) && !defined(EIGHT) && !defined(UNSIGN)
#define	BASEM	SIXTEEN
#define	MULTRAD	1
#endif
#if	defined(SIXTEEN) && defined(EIGHT) && !defined(BASEM)
#define	BASEM	(SIXTEEN|EIGHT)
#define	MULTRAD	1
#endif

#endif

 // float code needs these flags
#if	defined(EFMT) || defined(GFMT) || defined(FFMT)
#ifndef	__FLOAT
#define	__FLOAT	1
#endif
#define	FLOATFORMAT	0x700
#ifdef	PRECISION
#define	DEFPREC	0x1000
#endif
#endif

#ifdef	__FLOAT
//#ifndef	MANSIGN
//#define	MANSIGN	0x02
//#endif
//#ifndef	SPCSIGN
//#define	SPCSIGN	0x01
//#endif
#ifndef	NEGSIGN
#define	NEGSIGN	0x03
#endif
//#ifndef	WIDTH
//#define	WIDTH	1
//#endif
#endif

#ifdef	SPCSIGN
#define	putsign()	pputc(flag & SPCSIGN ? '-' : '+')
#else
#define	putsign()	pputc('-')
#endif	// SPCSIGN

// were there ANY % formats defined?
#if	defined(FLOATFORMAT) || defined(TEN) || defined(EIGHT) || defined(SIXTEEN) || \
	defined(CHAR) || defined(POINTER) || defined(STRING) || defined(UNSIGN) || defined(PERCPERC)
#define	ANYFORMAT
#else
#undef	ANYFORMAT
#endif

#ifdef	CHAR
#ifndef	PERCPERC
#define	PERCPERC
#endif
#endif

#if	!defined(PRINTF) && !defined(VPRINTF) && !defined(SPRINTF) && !defined(VSPRINTF)
#error	Must define at least one of PRINTF SPRINTF or VSPRINTF
#endif

#if	i8086 && SMALL_DATA
#define	CONST	far
#else
#define	CONST	const
#endif

 /* we don't need plus signs, use minus signs only if we have floats or signed ints */

#if	!defined(NEGSIGN) && defined(TEN)
#define	NEGSIGN	0x03
#endif

#ifndef	RETVALUE
#define	INCR_CNT	/*nix */
#else
#define	INCR_CNT	,(++ccnt)
#endif

#if	defined(EFMT) || defined(GFMT) || defined(FFMT) || defined(ALTERN) || defined(DEFPREC) || defined(POINTER)
#define	FLAG_SIZE	unsigned short
#else
#define	FLAG_SIZE	unsigned char
#endif


#if	(sizeof(long) == sizeof(int) || defined(__FLOAT)) && !defined(__LONG)
#define	__LONG	1
#endif

#if	sizeof(double) == sizeof(long) && DBL_MAX_EXP == 128
#undef	frexp
#define	frexp(val, ptr) (void)(*(ptr) = (unsigned char)((*(unsigned long *)&val >> 23) & 255) - 126)
#elif	defined(_PSOC_)
#undef	frexp
#define	frexp(val, ptr) (void)(*(ptr) = ((unsigned char)(*(unsigned short long *)&val >> 15)) - 126)
#elif	sizeof(double) == 3 && DBL_MAX_EXP == 128
#undef	frexp
#define	frexp(val, ptr) (void)(*(ptr) = ((*(unsigned long *)&val >> 15) & 255) - 126)
#endif

#if	defined(__FLOAT) && sizeof(double) == 8
#define	DOUBLE	1

extern double	_dto64i(double);
extern double	_64itod(double);
extern double	_div64(double, double);
extern double	_divto64i(double, double);
extern unsigned	_div64ir(double, double);
extern unsigned	_mod64i10(double);

#else
#define	DOUBLE	0
#endif

#ifdef	__LONG
#define	value	long
#define	NDIG	12		/* max number of digits to be printed */
#else
#define	value	int
#define	NDIG	6		/* max number of digits to be printed */
#endif

#if	DOUBLE
union {
	unsigned long	ul[40];
	double		db[20];
}	_fdp =
{
#if	!defined(BIG_ENDIAN) && !defined(LITTLE_ENDIAN)
#error Neither BIG_ENDIAN or LITTLE_ENDIAN has been set
#endif
#if	BIG_ENDIAN
	0x00000000,0x00000001,
	0x00000000,0x0000000A,
	0x00000000,0x00000064,
	0x00000000,0x000003E8,
	0x00000000,0x00002710,
	0x00000000,0x000186A0,
	0x00000000,0x000F4240,
	0x00000000,0x00989680,
	0x00000000,0x05F5E100,
	0x00000000,0x3B9ACA00,
	0x00000002,0x540BE400,
	0x00000017,0x4876E800,
	0x000000E8,0xD4A51000,
	0x00000918,0x4E72A000,
	0x00005AF3,0x107A4000,
	0x00038D7E,0xA4C68000,
	0x002386F2,0x6FC10000,
	0x01634578,0x5D8A0000,
	0x0DE0B6B3,0xA7640000,
	0x8AC72304,0x89E80000,
#else
	0x00000001,0x00000000,
	0x0000000A,0x00000000,
	0x00000064,0x00000000,
	0x000003E8,0x00000000,
	0x00002710,0x00000000,
	0x000186A0,0x00000000,
	0x000F4240,0x00000000,
	0x00989680,0x00000000,
	0x05F5E100,0x00000000,
	0x3B9ACA00,0x00000000,
	0x540BE400,0x00000002,
	0x4876E800,0x00000017,
	0xD4A51000,0x000000E8,
	0x4E72A000,0x00000918,
	0x107A4000,0x00005AF3,
	0xA4C68000,0x00038D7E,
	0x6FC10000,0x002386F2,
	0x5D8A0000,0x01634578,
	0xA7640000,0x0DE0B6B3,
	0x89E80000,0x8AC72304,
#endif
};

#define	fdpowers	_fdp.db

#else
#define	fdpowers	dpowers
#endif
#if defined(TEN) || defined(__FLOAT) || defined (UNSIGN)
const static unsigned value	dpowers[] =	{1, 10, 100, 1000, 10000,
#ifdef	__LONG
						 100000, 1000000, 10000000, 100000000,
						 1000000000
#endif
							 };
#endif
#ifdef	SIXTEEN
const static unsigned value	hexpowers[] =	{1, 0x10, 0x100, 0x1000,
#if	__LONG
						 0x10000, 0x100000, 0x1000000, 0x10000000
#endif
							};
#endif
#ifdef	EIGHT
const static unsigned value	octpowers[] =	{1, 010, 0100, 01000, 010000, 0100000,
#ifdef	__LONG
						01000000,
						 010000000, 0100000000, 01000000000, 010000000000,
						 0100000000000
#endif
							};
#endif

#ifdef	__FLOAT

#define	NDDIG	(sizeof fdpowers/sizeof fdpowers[0])

#if	DBL_MAX_10_EXP > 120
#define	expon	int
#else
#define	expon	signed char
#endif

extern const double	_powers_[], _npowers_[];
#ifdef	z80
#define	_div_to_l_(a, b)	((unsigned long)((a)/(b)))
#else
extern unsigned long	_div_to_l_(double, double);
#ifdef	_OMNI_CODE_
extern unsigned long	_tdiv_to_l_(float, float);
#ifdef	_HTKC_
#pragma callname _div_to_l_ double
#pragma callname _tdiv_to_l_ float
#endif
#define	div_to_l_(a,b)	((sizeof(double)== 3) ? _tdiv_to_l_(a,b) : _div_to_l_(a,b))
#else
#define	div_to_l_	_div_to_l_
#endif
#endif

/* this routine returns a value to round to the number of decimal
	places specified */
#if __FLOAT
static double
fround(unsigned char prec)
{
	/* prec is guaranteed to be less than NDIG */

	if(prec>=110)
		return 0.5 * _npowers_[prec/100+18] * _npowers_[(prec%100)/10+9] * _npowers_[prec%10];
	else if(prec > 10)
		return 0.5 * _npowers_[prec/10+9] * _npowers_[prec%10];
	return 0.5 * _npowers_[prec];
}
#endif

/* this routine returns a scaling factor equal to 1 to the decimal
   power supplied */

static double
scale(expon scl)
{

	if(scl < 0) {
		scl = -scl;
		if(scl>=110)
			return _npowers_[scl/100+18] * _npowers_[(scl%100)/10+9] * _npowers_[scl%10];
		else if(scl > 10)
			return _npowers_[scl/10+9] * _npowers_[scl%10];
		return _npowers_[scl];
	}
	if(scl>=110)
		return _powers_[scl/100+18] * _powers_[(scl%100)/10+9] * _powers_[scl%10];
	else if(scl > 10)
		return _powers_[scl/10+9] * _powers_[scl%10];
	return _powers_[scl];
}


#endif	/* __FLOAT */



#ifdef	_HOSTED
#define	pputc(c)	(putc(c, fp) != EOF && ++ccnt)
int
vfprintf(FILE * fp, register const  char * f, register va_list ap)
{
	char		cbuf[2];
#else	/* _HOSTED */
int
#if	defined(VPRINTF) || (defined(PRINTF) && (defined(SPRINTF) || defined(VSPRINTF)))
#define	pputc(c)	if(pb->func) (pb->func(c))INCR_CNT; else ((*pb->ptr++ = c)INCR_CNT)
_doprnt(struct __prbuf * pb, register const  char * f, register va_list ap)
{
#endif

#if	defined(PRINTF) && !(defined(SPRINTF) || defined(VSPRINTF))
#define	pputc(c)	(putch(c) INCR_CNT)
printf(const char * f, ...)
{
	va_list	ap;
#define	NEED_START
#endif

#if	!defined(PRINTF) && defined(VSPRINTF)

#ifdef	SPRINTF
sprintf(char * sp, const char * f, ...)
{
	va_list	ap;

	va_start(ap, f);
	vsprintf(sp, f, ap);
	va_end(ap);
}
int
#endif	// SPRINTF

#define	pputc(c)	((*sp++ = (c))INCR_CNT)
vsprintf(char * sp, register const  char * f, register va_list ap)
{
#define NEED_START
#endif	// VSPRINTF

#if	!defined(PRINTF) && defined(SPRINTF) && !defined(VSPRINTF)
#define	pputc(c)	((*sp++ = (c))INCR_CNT)
sprintf(char * sp, const  char * f, ...)
{
	va_list	ap;
#define	NEED_START
#endif
#endif	// HOSTED

	signed char		c;
#if	defined(WIDTH) || defined(__FLOAT)
	int		width;
#endif
#ifdef	__LONG
	int		prec;
#else
	signed char	prec;
#endif
	FLAG_SIZE	flag;
#ifdef	RETVALUE
	int		ccnt = 0;
#else
#define	ccnt	0
#endif
#ifdef	__FLOAT
	char	d;
	double	fval; 
	int		exp;
#if DOUBLE
	double		ival;
#endif
#endif
#if ! DOUBLE || __FLOAT
	union {
		unsigned long vd;
		double integ;
	} tmpval;
#endif
	unsigned value	val;
	unsigned	len;
	CONST char *	cp;
	
#ifdef	NEED_START
	va_start(ap, f);
#endif

	while(c = *f++) {
#ifdef	ANYFORMAT
		if(c != '%')
#endif	//ANYFORMAT
		{
			pputc(c);
			continue;
		}
#ifdef	ANYFORMAT
#ifdef	WIDTH
		width = 0;
#endif
		flag = 0;
#if	defined(LEFT) || defined(SPCSIGN) || defined(MANSIGN) || defined(ALTERN) || defined(FILL)
		for(;;) {
			switch(*f) {
#ifdef	LEFT
			case '-':
				flag |= LEFT;
				f++;
				continue;
#endif

#ifdef	SPCSIGN
			case ' ':
				flag |= SPCSIGN;
				f++;
				continue;
#endif

#ifdef	MANSIGN
			case '+':
				flag |= MANSIGN;
				f++;
				continue;
#endif
#ifdef	ALTERN
			case '#':
				flag |= ALTERN;
				f++;
				continue;
#endif
#ifdef	FILL
			case '0':
				flag |= FILL;
				f++;
				continue;
#endif
			}
			break;
		}
#endif
#if	defined(MANSIGN) && defined(SPCSIGN)
		if(flag & MANSIGN)
			flag &= ~SPCSIGN;
#endif
#if	defined(LEFT) && defined(FILL)
		if(flag & LEFT)
			flag &= ~FILL;
#endif
#ifdef	WIDTH
		if(isdigit((unsigned)*f)) {
			width = 0;
			do {
				width *= 10;
			   	width += *f++ - '0';
			} while(isdigit((unsigned)*f));
#ifdef	STAR
		} else if(*f == '*') {
			width = va_arg(ap, int);
			f++;
#endif
		}
#endif
#ifdef	PRECISION
		if(*f == '.') {
			flag |= PRECISION;
			f++;
#ifdef	STAR
			if(*f == '*') {
				prec = va_arg(ap, int);
				f++;
			} else
#endif
			{
				prec = 0;
				while(isdigit((unsigned)*f))
					prec = prec*10 + *f++ - '0';
			}
		} else {
			prec = 0;
#ifdef	DEFPREC
			flag |= DEFPREC;
#endif	// DEFPREC
		}
#endif	// PRECISION
#if	defined(__LONG) && defined(LONG)
loop:
#endif
		switch(c = *f++) {

		case 0:
			goto alldone;

#ifdef	LONG
		case 'l':
#ifdef	__LONG
			flag |= LONG;
			goto loop;
#else
			cp = "(non-long printf)";
			goto strings;
#endif
#endif

#ifdef	FLOATFORMAT
#ifndef	__FLOAT
		case 'E':
		case 'f':
		case 'e':
		case 'G':
		case 'g':
			cp = "(non-float printf)";
			goto strings;
#else
#ifdef	FFMT
		case 'f':
			flag |= FFMT;
			break;
#endif

#ifdef	EFMT
#ifdef	UPCASE
		case 'E':
			flag |= UPCASE;
#endif
		case 'e':
			flag |= EFMT;
			break;
#endif

#ifdef	GFMT
#ifdef	UPCASE
		case 'G':
			flag |= UPCASE;
#endif
		case 'g':
			flag |= GFMT;
			break;
#endif	// GFMT
#endif
#endif	// FLOATFORMAT
#ifdef	EIGHT
		case 'o':
#ifdef	MULTRAD
			flag |= EIGHT;
#endif
			break;
#endif

#ifdef	TEN
		case 'd':
		case 'i':
			break;
#endif

#ifdef	POINTER
		case 'p':
#if	i8086 && LARGE_DATA
			flag |= LONG;
#elif	_PIC18
			flag |= POINTER;
#endif
#endif	// POINTER
#ifdef	SIXTEEN
#ifdef	HEXUPCASE
		case 'X':
#ifdef	UPCASE
			flag |= UPCASE;
#endif
#endif
#if	defined(HEXLOWCASE) || !defined(UPCASE)
		case 'x':
#endif
#ifdef	MULTRAD
			flag |= SIXTEEN;
#endif
			break;
#endif	// SIXTEEN

#if	defined(STRING) || defined(PERCPERC)
#ifdef	STRING
		case 's':
#if	i8086 && SMALL_DATA
			if(flag & LONG)
				cp = va_arg(ap, far char *);
			else
#endif
				cp = va_arg(ap, const char *);
#endif	// STRING
#if	!defined(__FLOAT) && !defined(CUSTOM_PRINTF)
strings:
#endif
#ifdef	STRING
			if(!cp)
				cp = "(null)";
#endif
#if	defined(WIDTH) || defined(PRECISION)
#if	defined(STRING)
			len = 0;
			while(cp[len])
				len++;
#endif
#ifdef	PERCPERC
dostring:
#endif
#ifdef	PRECISION
			if(prec && prec < len)
				len = prec;
#endif	// PRECISION
#ifdef	WIDTH
			if(width > len)
				width -= len;
			else
				width = 0;
#ifdef	LEFT
			if(!(flag & LEFT))
#endif	// LEFT
				while(width--)
					pputc(' ');
#endif	// WIDTH
			while(len--)
				pputc(*cp++);
#ifdef	LEFT
			if(flag & LEFT)
				while(width--)
					pputc(' ');
#endif	// LEFT
			continue;
#else	// WIDTH || PRECISION
#if	defined(STRING)
			while(*cp)
				pputc(*cp++);
			continue;
#endif
#endif	// WIDTH || PRECISION
#endif	// defined(STRING) || defined(PERCPERC)
#ifdef	CHAR
		case 'c':
#if	_HOSTED
			val = va_arg(ap, int);
			c = val >> 8;
			if(flag & LONG && c && (unsigned char)c != 0xFF) {
				cbuf[0] = c;
				cbuf[1] = val;
				len = 2;
			} else {
				cbuf[0] = val;
				len = 1;
			}
			cp = cbuf;
			goto dostring;
#else
			c = va_arg(ap, int);
#endif	// _HOSTED
#endif	// CHAR
		default:
#ifdef	PERCPERC
#if	defined(WIDTH) || defined(PRECISION)
			cp = (char *)&c;
			len = 1;
			goto dostring;
#else
			pputc(c);
			continue;
#endif
#else	// PERCPERC
			continue;
#endif

#ifdef	UNSIGN
		case 'u':
			flag |= UNSIGN;
			break;
#endif

		}
#endif	// ANYFORMAT
#ifdef	__FLOAT
		if(flag & (FLOATFORMAT)) {
#ifdef	DEFPREC
			if(flag & DEFPREC)
#endif
				prec = 6;
			fval = va_arg(ap, double);	// source the floating point value
			if(fval < 0.0) {
				fval = -fval;		// get the absolute value
				flag |= NEGSIGN;
			}
			exp = 0;		/* If the number is zero, the exponent is zero. */
			if( fval!=0) {		/* If the number is non-zero, find the exponent. */
				frexp(fval, &exp);		/* get binary exponent */
				exp--;				/* adjust 0.5 -> 1.0 */
				exp *= 3;
				exp /= 10;			/* estimate decimal exponent */
				if(exp < 0)
					exp--;
				// the following line can cause "recursive call" errors because scale calls
				// ftmul, and is used when evaluating an argument to ftmul
				//integ = fval * scale(-exp);
				tmpval.integ = scale(-exp);		// replaced with this
				tmpval.integ *= fval;
				if(tmpval.integ < 1.0)
					exp--;
				else if(tmpval.integ >= 10.0)
					exp++;
			}
#if	defined(EFMT) || defined(GFMT)
			if(exp <= 0)	// value is 0.??? (neg expnt) whole characters = 1 (allow zero)
				c = 1;
			else
				c = exp;
			if(
#ifdef	EFMT
					flag & EFMT
#ifdef	GFMT
					||
#endif
#endif
#ifdef	GFMT
					flag & GFMT && (exp < -4 || exp >= (int)prec)
#endif
				) {	/* use e format */
#ifdef	GFMT
				if(prec && flag & GFMT)
					prec--;		/* g format precision includes integer digit */
#endif
				if((unsigned)prec > NDDIG - 2)
					c = NDDIG - 2;
				else
					c = prec;
				if( fval!=0) {	/* Normalise only if the number is non-zero. */
					fval /= scale(exp-c);
#if	DOUBLE
					ival = _dto64i(fval);
					if(fval - _64itod(ival) >= 0.5) {
						fval += 0.5;
						ival = _dto64i(fval);
					}
					if(ival >= fdpowers[c+1]) {
						fval *= 1e-1;
						exp++;
					} else if(ival < fdpowers[c]) {
						fval *= 10.0;
						exp--;
					}
#else	
					if(fval - (double)(unsigned long)fval >= 0.5)
						fval += 0.5;
					if((unsigned long)fval >= fdpowers[c+1]) {
						fval *= 1e-1;
						exp++;
					} else if((unsigned long)fval < fdpowers[c]) {
						fval *= 10.0;
						exp--;
					}
#endif
				}
#if defined(GFMT) && defined(ALTERN)
				if(flag & GFMT && !(flag & ALTERN)) {		/* g format, precision means something different */
					if(prec > (int)(NDDIG))
						prec = NDDIG;
#if	DOUBLE
					ival = _dto64i(fval);
					while(ival != 0.0 && _mod64i10(ival) == 0) {
						prec--;
						ival = _div64(ival, fdpowers[1]);
					}
#else
					val = (unsigned long)fval;
					while(val && val % 10 == 0) {
						prec--;
						val /= 10;
					}
#endif
					if(prec < c) {
						fval /= scale(c-prec);
						c = prec;
					}

				}
#endif
#ifdef	WIDTH
				width -=  prec + 5;
#ifdef	ALTERN
				if(prec || flag & ALTERN)
					width--;
#endif
				if(flag & NEGSIGN)
					width--;
#if	DBL_MAX_10_EXP >= 100
#if	DBL_MAX_10_EXP >= 1000
				if(exp >= 1000 || exp <= -1000)	/* 4 digit exponent */
					width--;
#endif
				if(exp >= 100 || exp <= -100)	/* 3 digit exponent */
					width--;
#endif
#endif	// WIDTH
#ifdef	FILL
				if(flag & FILL) {
#if defined(MANSIGN) && defined(SPCSIGN)
					if(flag & MANSIGN)
						pputc(flag & SPCSIGN ? '-' : '+');
					else if(flag & SPCSIGN)
						pputc(' ');
#endif
					while(width > 0) {
						pputc('0');
						width--;
					}
				} else
#endif	// FILL
				{
#ifdef	WIDTH
#ifdef	LEFT
					if(!(flag & LEFT))
#endif
						while(width > 0) {
							pputc(' ');
							width--;
						}
#endif	// WIDTH
#ifdef	MANSIGN
					if(flag & MANSIGN)
						putsign();
#else
					if(flag & NEGSIGN)
						pputc('-');
#endif	// MANSIGN
#ifdef	SPCSIGN
					else if(flag & SPCSIGN)
						pputc(' ');
#endif	// SPCSIGN
				}
#if	DOUBLE
				ival = _dto64i(fval);
				pputc(_div64ir(ival, fdpowers[c]) + '0');
#else
				val = (unsigned long)fval;
				pputc(val/dpowers[c] + '0');
				val %= dpowers[c];
#endif
#ifdef	ALTERN
				if(prec || flag & ALTERN)
#else
				if(prec)
#endif
				{
					pputc('.');
					prec -= c;
					while(c--) {
#if	DOUBLE
						pputc('0' + _mod64i10(_div64(ival, fdpowers[c])));
#else
#ifdef	GFMT
						if(flag & GFMT && val == 0) {
							prec = c = 0;
							break;
						}
#endif
						pputc('0' + (val/dpowers[c]));
						val %= dpowers[c];
#endif
					}
					while(prec) {
						pputc('0');
						prec--;
					}
				}
#ifdef	UPCASE
				if(flag & UPCASE)
					pputc('E');
				else
#endif
					pputc('e');
				if(exp < 0) {
					exp = -exp;
					pputc('-');
				} else
					pputc('+');
#if	DBL_MAX_10_EXP >= 100
#if	DBL_MAX_10_EXP >= 1000
				if(exp >= 1000) {
					pputc(exp / 1000 + '0');
					exp %= 1000;
				}
#endif
				if(exp >= 100) {
					pputc(exp / 100 + '0');
					exp %= 100;
				}
#endif
				pputc(exp / 10 + '0');
				pputc(exp % 10 + '0');
#ifdef	LEFT
				if((flag & LEFT) && width > 0)
					do
						pputc(' ');
					while(--width);
#endif	// LEFT
					continue;
				}
#endif	// EFMT || GFMT
				/* here for f format */
#if	DOUBLE
#ifdef	GFMT
				if(flag & GFMT) {
					if(exp < 0)	// fractional part only
						prec -= exp-1;
					ival = _dto64i(fval);
					for(c = 1 ; c != NDDIG ; c++)
						if(ival < fdpowers[c])
							break;
					if(prec > NDDIG)
						prec = NDDIG;
					prec -= c;
					ival = _dto64i((fval - _64itod(ival)) * scale(prec)+0.5);
					// see how many zeros are at the end of the fractional part
					while(prec && _mod64i10(ival) == 0) {
						prec--;
						ival = _div64(ival, fdpowers[1]);
					}
				}
#endif	// GFMT
				if(prec <= (int)NDDIG)
					fval += fround(prec);
				if(exp > (int)(NDDIG)-2) {
					exp -= NDDIG-2;
					ival = _divto64i(fval, scale(exp));
					fval = 0.0;
				} else {
					ival = _dto64i(fval);
					fval -= _64itod(ival);
					exp = 0;
				}
				for(c = 1 ; c != NDDIG ; c++)
					if(ival < fdpowers[c])
						break;
#else	// DOUBLE
#ifdef	GFMT
				if(flag & GFMT) {
					if(exp < 0)	// fractional part only
						prec -= (exp+1);
					// count number of digits in the integral part (this is for %g)
					val = (unsigned long)fval;
					for(c = 0 ; c != NDDIG ; c++)
						if(val < fdpowers[c])
							break;
					prec -= c;		// reduce precision by this
					if(prec <= NDIG)
						fval += fround(prec);
					// get fractional part and count trailing zeros - reduce
					// prec as required
					{
						double	temp;
						temp = scale(prec);
						temp *= fval - (double)val;
						val = (unsigned long)temp;
					}
					while(prec && val % 10 == 0) {
						val /= 10;
						prec--;
					}
				} else
#endif	//GFMT
					if(prec <= NDIG)
						fval += fround(prec);

				/* ~4.2e9 is the largest float that will fit into a 32-bit long */
				if((exp > 9)||(fval != 0 && (unsigned long)fval == 0 && exp > 1)) {
					// fval is > 4.2e9
					// new exp must be such that div_to_l() is < 4.2e9
					// OLD CODE:	if(fval / scale(exp) < 4.294967296){
					if(tmpval.integ < 4.294967296){
						exp -= NDDIG-1;
					}else{
						exp -= NDDIG-2;
					}
					tmpval.integ = scale(exp);
					val = div_to_l_(fval, tmpval.integ);
 					//val = _div_to_l_(integ, fval);
					//val = (long)(integ * fval);	// fit as much signifigant data into the long as it can hold
					fval = 0.0;	// There will be no fractional component
				} else {
					val = (unsigned long)fval;
					fval -= (double)val;
					exp = 0;
				}
				// count digits in integral part
				for(c = 1 ; c != NDDIG ; c++)
					if(val < fdpowers[c])
						break;
#endif	// DOUBLE
#ifdef	WIDTH
				// at this point, c contains the number of whole-number digits to print
				width -= prec + c + exp;
				if(
#ifdef	ALTERN
						flag & ALTERN ||
#endif
						prec)
					width--;		// allow for decimal point
				if(flag & NEGSIGN)
					width--;
#endif	// WIDTH
#ifdef	FILL
				if(flag & FILL) {
#ifdef	MANSIGN
					if(flag & MANSIGN)
#else
					if(flag & NEGSIGN)
#endif	// MANSIGN
						putsign();
#if defined(MANSIGN) && defined(SPCSIGN)
					else
#endif
#ifdef	SPCSIGN
					if(flag & SPCSIGN)
						pputc(' ');
#endif	// SPCSIGN
#ifdef	WIDTH
					while(width > 0) {
						pputc('0');
						width--;
					}
#endif	// WIDTH
				} else
#endif	// FILL
				{
#ifdef	LEFT
					if(!(flag & LEFT))
#endif
#ifdef	WIDTH
					while(width > 0) {
						pputc(' ');
						width--;
					}
#endif	// WIDTH
#ifdef	MANSIGN
				if(flag & MANSIGN)
#else
				if(flag & NEGSIGN)
#endif	// MANSIGN
					putsign();
#ifdef	SPCSIGN
				else if(flag & SPCSIGN)
					pputc(' ');
#endif	// SPCSIGN
			}
			while(c--) {
#if	DOUBLE
				pputc('0' + _mod64i10(_div64(ival, fdpowers[c])));
#else
				{
					tmpval.vd = val/dpowers[c];
					tmpval.vd %= 10;
					pputc('0' + tmpval.vd);
				}
#endif	// DOUBLE
			}
			while(exp > 0) {
				pputc('0');
				exp--;
			}
			if(prec > (int)(NDDIG-2))
				c = NDDIG-2;
			else
				c = prec;
			prec -= c;
#ifdef	ALTERN
			if(c || flag & ALTERN)
#else
			if(c)
#endif
				pputc('.');
#if	DOUBLE
			ival = _dto64i(fval * scale(c));
			while(c)
				pputc('0' + _mod64i10(_div64(ival, fdpowers[--c])));
#else	// DOUBLE
			val = (long)(fval * scale(c));
			while(c--) {
				tmpval.vd = val/dpowers[c];
				tmpval.vd %= 10;
				pputc('0' + tmpval.vd);
				val %= dpowers[c];
			}
#endif	// DOUBLE
			while(prec) {
				pputc('0');
				prec--;
			}
#ifdef	LEFT
			if((flag & LEFT) && width > 0)
				do
					pputc(' ');
				while(--width);
#endif
			continue;
		}
#endif	/* __FLOAT */

#if	defined(TEN)
#ifdef	BASEM
		if((flag & BASEM) == TEN)
#endif	//BASEM
		{
#ifdef	LONG
			if(flag & LONG)
				val = va_arg(ap, long);
			else
#endif	// LONG
				val = (value)va_arg(ap, int);
#ifdef	NEGSIGN
			if((value)val < 0) {
				flag |= NEGSIGN;
				val = -val;
			}
#endif
		}
#ifdef	BASEM
		else
#endif
#endif	// TEN

#if	defined(EIGHT) || defined(SIXTEEN) || defined(UNSIGN)
		{
#ifdef	__LONG
#if	defined(_PIC18) && defined(POINTER)
			if(flag & POINTER)
				val = (unsigned long)va_arg(ap, far char *);
			else
#endif
#ifdef	LONG
				if(flag & LONG)
				val = va_arg(ap, unsigned long);
			else
#endif	// LONG
#endif	// __LONG
				val = va_arg(ap, unsigned);
		}
#endif	// EIGHT or SIXTEEN or UNSIGN
#ifdef	PRECISION
		if(prec == 0 && val == 0)
			prec++;
#endif
#ifdef	MULTRAD
		switch((unsigned char)(flag & BASEM)) {
#endif
#if	defined(TEN) || defined(UNSIGN)
#ifdef	MULTRAD
#ifdef	TEN
		case TEN:
#endif
#ifdef	UNSIGN
		case UNSIGN:
#endif
#endif	// MULTRAD
			for(c = 1 ; c != sizeof dpowers/sizeof dpowers[0] ; c++)
				if(val < dpowers[c])
					break;
#ifdef	MULTRAD
			break;
#endif
#endif	// TEN || UNSIGN
#ifdef	SIXTEEN
#ifdef	MULTRAD
		case SIXTEEN:
#endif	// MULTRAD
			for(c = 1 ; c != sizeof hexpowers/sizeof hexpowers[0] ; c++)
				if(val < hexpowers[c])
					break;
#ifdef	MULTRAD
			break;
#endif
#endif

#ifdef	EIGHT
#ifdef	MULTRAD
		case EIGHT:
#endif	// MULTRAD
			for(c = 1 ; c != sizeof octpowers/sizeof octpowers[0] ; c++)
				if(val < octpowers[c])
					break;
#ifdef	MULTRAD
			break;
#endif
#endif
#ifdef	MULTRAD
		}
#endif
#ifdef	PRECISION
		if(c < prec)
			c = prec;
		else if(prec < c)
			prec = c;
#endif
#if	defined(WIDTH) && defined(NEGSIGN)
		if(width && flag & NEGSIGN)
			width--;
#ifdef	PRECISION
		if(flag & PRECISION) {
			if(width > prec)
				width -= prec;
			else
				width = 0;
		}
#endif
#ifdef	ALTERN
#ifdef	EIGHT
		if((flag & (
#ifdef	FILL
						FILL|
#endif
							BASEM|ALTERN)) == (EIGHT|ALTERN)) {
			if(width)
				width--;
		} else
#endif	// EIGHT
#if	defined(SIXTEEN)
#ifdef	BASEM
		if((flag & (BASEM|ALTERN)) == (SIXTEEN|ALTERN)) {
#else
		if(flag & ALTERN) {
#endif
			if(width > 2)
				width -= 2;
			else
				width = 0;
		}
#endif	// SIXTEEN
#endif	// ALTERN
#endif	// WIDTH
#ifdef	WIDTH
		if(width > c)
			width -= c;
		else
			width = 0;
#endif
#ifdef	FILL
		if(flag & FILL) {
#ifdef	MANSIGN
			if(flag & MANSIGN)
				putsign();
#elif defined(NEGSIGN)
			if(flag & NEGSIGN)
				pputc('-');
#endif
#if defined(MANSIGN) || defined(NEGSIGN) && defined(SPCSIGN)
			else
#endif	// MANSIGN
#ifdef	SPCSIGN
			if(flag & SPCSIGN)
				pputc(' ');
#endif
#if defined(ALTERN) && defined(SIXTEEN)
			else if((flag & (BASEM|ALTERN)) == (SIXTEEN|ALTERN)) {
				pputc('0');
#if	defined(HEXUPCASE) && defined(HEXLOWCASE)
				pputc(flag & UPCASE ? 'X' : 'x');
#elif defined(HEXUPCASE)
				pputc('X');
#else
				pputc('x');
#endif	// HEXUPCASE
			}
#endif	// ALTERN
#ifdef	WIDTH
			if(width)
				do
					pputc('0');
				while(--width);
#endif	// WIDTH
		} else
#endif	//FILL
		{
#ifdef	WIDTH
			if(width
#ifdef	LEFT
					&& !(flag & LEFT)
#endif
					)
				do
					pputc(' ');
				while(--width);
#endif	// WIDTH
#ifdef	MANSIGN
			if(flag & MANSIGN)
				putsign();
#else
#ifdef	NEGSIGN
			if(flag & NEGSIGN)
				pputc('-');
#endif
#endif	// MANSIGN
#ifdef	SPCSIGN
			else if(flag & SPCSIGN)
				pputc(' ');
#endif
#ifdef	ALTERN
#ifdef	EIGHT
			if((flag & (BASEM|ALTERN)) == (EIGHT|ALTERN))
				pputc('0');
			else
#endif	// EIGHT
#ifdef	SIXTEEN
#ifdef	BASEM
			if((flag & (BASEM|ALTERN)) == (SIXTEEN|ALTERN)) {
#else
			if(flag & ALTERN) {
#endif
				pputc('0');
#if	defined(HEXUPCASE) && defined(HEXLOWCASE)
				pputc(flag & UPCASE ? 'X' : 'x');
#elif defined(HEXUPCASE)
				pputc('X');
#else
				pputc('x');
#endif
			}
#endif	// SIXTEEN
#endif	// ALTERN
		}
#if	defined(SIXTEEN) || defined(TEN) || defined(EIGHT) || defined(UNSIGN)
#ifndef	PRECISION
		prec = c;
#endif
		while(prec--) {
#ifdef	MULTRAD
			switch((unsigned char)(flag & BASEM))
#endif
			{

#if	defined(TEN) || defined(UNSIGN)
#ifdef	MULTRAD
#ifdef	TEN
		case TEN:
#endif
#ifdef	UNSIGN
		case UNSIGN:
#endif
#endif	// MULTRAD
				c = (val / dpowers[prec]) % 10 + '0';
#ifdef	MULTRAD
				break;
#endif
#endif	// TEN || UNSIGN

#ifdef	SIXTEEN
#ifdef	MULTRAD
			case SIXTEEN:
#endif
			{
				unsigned char idx = (val / hexpowers[prec]) & 0xF;
#if	defined(HEXLOWCASE) && defined(HEXUPCASE)
				c = (flag & UPCASE ? "0123456789ABCDEF" : "0123456789abcdef")[idx];
#elif	defined(HEXUPCASE)
				c = "0123456789ABCDEF"[idx];
#else
				c = "0123456789abcdef"[idx];
#endif	//HEXCASE
			}
#ifdef	MULTRAD
				break;
#endif
#endif

#ifdef	EIGHT
#ifdef	MULTRAD
			case EIGHT:
#endif	// MULTRAD
				c = ((val / octpowers[prec]) & 07) + '0';
#ifdef	MULTRAD
				break;
#endif	// MULTRAD
#endif	// EIGHT
			}
			pputc(c);
		}
#endif	// 16 or 10 or 8
#ifdef	LEFT
		if((flag & LEFT) && width > 0)
			do
				pputc(' ');
			while(--width);
#endif	// LEFT
	}
#ifdef	ANYFORMAT
alldone:
#endif	// ANYFORMAT
#if	!defined(PRINTF) && (defined(SPRINTF) || defined(VSPRINTF))
	*sp = 0;
#endif
	return ccnt;
}

