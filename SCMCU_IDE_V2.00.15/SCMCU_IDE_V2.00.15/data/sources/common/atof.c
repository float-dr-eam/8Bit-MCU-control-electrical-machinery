#include	<ctype.h>
#include	<float.h>
#include	<math.h>
#include	<stdlib.h>

/*
 * $Header$
 */

#define	NDIG	DBL_DIG+3 	/* Number of digits (ANSI 5.2.4.2.2) */

#if		defined(_MPC_) && !defined(__DSPICC__) 		/* If Microchip PIC */
// undefining this macro can lead to more accurate results, but at the cost of much
// increased code size.
#define	SMALLCODE
#endif

#if	sizeof(double) == 8		
extern double	_mul64i10(double, unsigned);
extern double	_64itod(double);
#endif

#ifndef	SMALLCODE
/*
 *	External table of powers of 10
 */

extern const double	_powers_[], _npowers_[];
#endif
	
/*
 *	String to double
 */
double
strtod(register const char * s, const char ** res)
{
	char	flags;
	
/*	values in flags :
 */	

#define	ISNEG	1	/* Number is negative */
#define	DIGSEEN	2	/* We saw at least one digit */
#define	EXPNEG	8	/* Exponent is negative */
#define	DOTSEEN	16	/* We have seen a dot */

#if	sizeof(double) <= 4
	signed char	expon;
	signed char	eexp;
#else
	short	expon;
	short	eexp;
#endif
	union {			/* A union to hold the integer	*/
		double	_l;	/* component and then the resultant */
#if	sizeof(double) <= 4	/* double */
		long	_v;
#define	v	_u._v
#else
#define	v	_u._l
#endif
	}	_u;

#define	l	_u._l

	if(res)
		*res = s;
	while(isspace(eexp = *s))
		s++;
	flags = 0;			/* Reset flags */
	if(eexp == '-') {		/* Check for sign */
		flags = ISNEG;
		s++;
	} else if(eexp == '+')
		s++;
	eexp = 0;			/* Clear digit count */
	v = 0;				/* Clear integer component */
	expon = 0;			/* Total exponent for integer */

	for(;;) {
		if(!(flags & DOTSEEN) && *s == '.') {
			flags |= DOTSEEN;		/* If into decimal */
			s++;				/* set flag */
			continue;
		}
		if(!isdigit(*s))			/* If end of valid */
			break;				/* sequence end */
		flags |= DIGSEEN;			/* else set flag */
		if(eexp != NDIG) {
			if(flags & DOTSEEN)		/* Count decimal */
				expon--;		/* places */
			eexp++;
#if	sizeof(double) <= 4
			v *= 10;
			v += (unsigned char)(*s - '0');	/* Convert digits to */
#else							/* integer part */
			l = _mul64i10(l, *s-'0');
#endif
		} else if(!(flags & DOTSEEN))
			expon++;
		s++;
	}
	
	eexp = 0;				/* Zero users exponent */
	if(*s == 'e' || *s == 'E') {		/* Look at exponent */
		if(*++s == '-') {		/* Check sign */
			flags |= EXPNEG;
			s++;
		} else if(*s == '+')
			s++;
		while(*s=='0')s++;		/* Skip leading zeros */
		if(isdigit(*s)) {		/* Read three digits */
			eexp = (unsigned char)(*s++ - '0');
			if(isdigit(*s)) {
				eexp = eexp*10 + (unsigned char)(*s++ - '0');
				if(isdigit(*s))
					eexp = eexp*10 + (unsigned char)(*s - '0');
			}
		}
		if(flags & EXPNEG)
			eexp = -eexp;
	}
	expon += eexp;			/* Add user and integer exponents */

	if(res && flags & DIGSEEN)
		*res = s;
#if	sizeof(double) == 8
	l = _64itod(l);			/* Convert the integer component */ 
#else					/* to a double */
	l = (double)v;
#endif
	if(l == 0.0)			/* simply return zero */
		return 0.0;
	if(expon < 0) {
		expon = -expon;
#if	DBL_MAX_10_EXP >= 100
		while(expon >= 100) {
			l /= 1e+100;
			expon -= 100;
		}
#endif
#ifdef	SMALLCODE
		while(expon >= 10) {
			l /= 1e+10;
			expon -= 10;
		}
		while(expon != 0) {
			l /= 1e+1;
			expon--;
		}
#else
		if(expon >= 10) {
			l /= _powers_[expon/10+9];
			expon %= 10;
		}
		if(expon)
			l /= _powers_[expon];
#endif	/* SMALLCODE */
		if(l < DBL_MIN) {
			if(flags & ISNEG)
				return -DBL_MIN;
			return DBL_MIN;
		}
	} else if(expon > 0) {
#if	DBL_MAX_10_EXP >= 100
		while(expon >= 100) {
			l *= 1e100;
			expon -= 100;
		}
#endif
#ifdef	SMALLCODE
		while((unsigned char)expon >= 10) {
			l *= 1e10;
			expon -= 10;
		}
		while(expon != 0) {
			l *= 1e1;
			expon--;
		}
#else
		if(expon >= 10) {
			l *= _powers_[expon/10+9];
			expon %= 10;
		}
		if(expon)
			l *= _powers_[expon];
#endif	/* SMALLCODE */
		if(l > DBL_MAX) {
			if(flags & ISNEG)
				return -DBL_MIN;
			return DBL_MIN;
		}
	}
	if(flags & ISNEG)
		l = -l;
	return l;
}

double
atof(register const char * s)
{
	return strtod(s, 0);
}
