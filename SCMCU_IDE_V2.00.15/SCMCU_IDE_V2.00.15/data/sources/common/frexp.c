/*	Frexp/ldexp in C */
#include <math.h>
#include <float.h>
#include <errno.h>


/* PIC32 definition */
#ifdef __PICC32__
#if	sizeof(double) == 4
#define	EXCESS	126
#define MAX_EXPONENT 255
#define __STRUCT32
typedef union both
{
	struct flt
	{
		unsigned 	mant:16;
		unsigned	hmant:7;
		unsigned	exp:8;
		unsigned	sign:1;
	}	flt;
	double	fl;
} both_t;
#endif /* end 32-bit floating point */

#endif // __PICC32__

/* ARM-C definition */
#if defined(__ARMC__)
/* For 32-bit floating point */
#if	sizeof(double) == 4
#define	EXCESS	126
#define MAX_EXPONENT 255
#define __STRUCT32
typedef union both
{
	struct flt
	{
		unsigned	sign:1;
		unsigned	exp:8;
		unsigned	hmant:7;
		unsigned 	mant:16;
	}	flt;
	double	fl;
} both_t;
#endif /* end 32-bit floating point */
#endif /* end ARM-C */

/* PICC-18 definition */
#if defined(__PICC18__) || defined(__PICCPRO__) || defined(__18CXX)
/* For 32-bit floating point */
#if	sizeof(double) == 4
#define	EXCESS	126
#define MAX_EXPONENT 255
#define __STRUCT32
typedef union both
{
	struct flt
	{
		unsigned  char	mant[2];
		unsigned	hmant:7;
		unsigned	lexp:1;
		unsigned	hexp:7;
		unsigned	sign:1;
	}	flt;
	double	fl;
} both_t;
#endif /* end 32-bit floating point */
#if	sizeof(double) == 3
#define	EXCESS	126
#define MAX_EXPONENT 255
#define __STRUCT24
typedef union both
{
	struct flt
	{
		unsigned char 	mant[1];
		unsigned	hmant:7;
		unsigned	lexp:1;
		unsigned	hexp:7;
		unsigned	sign:1;
	}	flt;
	double	fl;
} both_t;
#endif /* end 24-bit floating point */
#endif /* end PICC-18-C / PICC PRO */

/* dsPICC definition */
#if defined(__DSPICC__)
/* For 32-bit floating point */
#if	sizeof(double) == 4
#define	EXCESS	126
#define MAX_EXPONENT 255
#define __STRUCT32
typedef union both
{
	struct flt
	{
		unsigned 	mant:16;
		unsigned	sign:1;
		unsigned	exp:8;
		unsigned	hmant:7;
	}	flt;
	double	fl;
} both_t;
#endif /* end 32-bit floating point */
#endif /* end dsPICC */

/* PSOC definition */
#if defined(_PSOC_)
/* For 32-bit floating point */
#if	sizeof(double) == 4
#define	EXCESS	126
#define MAX_EXPONENT 255
#define __STRUCT32
typedef union both
{
	struct flt
	{
		unsigned	sign:1;
		unsigned	exp:8;
		unsigned	hmant:7;
		unsigned char	mant[2];
	}	flt;
	double	fl;
} both_t;
#endif /* end 32-bit floating point */

#if	sizeof(double) == 3
#define	EXCESS	126
#define MAX_EXPONENT 255
#define __STRUCT24
typedef union both
{
	struct flt
	{
		unsigned	sign:1;
		unsigned	exp:8;
		unsigned	hmant:7;
		unsigned char	mant[1];
	}	flt;
	double	fl;
} both_t;
#endif /* end 24-bit floating point */
#endif /* end PSOC */


/* MSP430 definition */
#if defined(__MSP430C__)
/* For 32-bit floating point */
#if	sizeof(double) == 4
#define	EXCESS	126
#define MAX_EXPONENT 255
#define __STRUCT32
typedef union both
{
	struct flt
	{
		unsigned char	mant[2];
		unsigned	hmant:7;
		unsigned	exp:8;
		unsigned	sign:1;
	}	flt;
	double	fl;
} both_t;
#endif /* end 32-bit floating point */
#endif /* end MSP430 */

/* Z80 definition */
#if	z80
#if	sizeof(double) == 4
#define	EXCESS	64
#define __STRUCT32
typedef union both
{
	struct flt
	{
		unsigned char	mant[2];
		unsigned	hmant:8;
		unsigned	exp:7;
		unsigned	sign:1;
	}	flt;
	double	fl;
} both_t;
#endif
#endif	/* end Z80 */


#if	sizeof(double) == 4 && !defined(__STRUCT32)
#warning Using generic 32-bit structure definition. A compiler-specific one should be defined
#define __STRUCT32
#if	defined(_XA_) || defined(i8096) || defined(i8086)
#define	LITTLE_ENDIAN
#endif

typedef union both
{
	struct flt
	{
#define	EXCESS	126
#define MAX_EXPONENT 255
#ifdef	LITTLE_ENDIAN
		unsigned char	mant[2];
		unsigned	hmant:7;
		unsigned	exp:8;
		unsigned	sign:1;
#else
		unsigned	sign:1;
		unsigned	exp:8;
		unsigned	hmant:7;
		unsigned char	mant[2];
#endif
	}	flt;
	double	fl;
} both_t;

#endif


#if	sizeof(double) == 8 && !defined(__STRUCT64)
#warning Using generic 64-bit structure definition. A compiler-specific one should be defined
#define __STRUCT64
#if	defined(_XA_) || defined(i8096) || defined(i8086)
#define	LITTLE_ENDIAN
#endif
#define	EXCESS	1022
#define MAX_EXPONENT 2047
typedef union both
{
	struct flt
	{
#ifdef	LITTLE_ENDIAN
		unsigned char	mant[6];
		unsigned	hmant:4;
		unsigned	exp:11;
		unsigned	sign:1;
#else
		unsigned	sign:1;
		unsigned	exp:11;
		unsigned	hmant:4;
		unsigned char	mant[6];
#endif
	}	flt;
	double	fl;
} both_t;
#endif


#if	!defined(__STRUCT32) && !defined(__STRUCT64) && !defined(__STRUCT24)
#error No floating point structure definition created for this compiler
#endif

double
frexp(double value, int * eptr)
{
	if (value == 0.0) {
		*eptr = 0;
		return 0.0;
	}
#if defined(__PICC18__) || defined(__PICCPRO__) || defined(__18CXX)
	*eptr = ((both_t *)&value)->flt.hexp << 1;
	*eptr |= ((both_t *)&value)->flt.lexp;
	*eptr -= EXCESS;
#else
	*eptr = ((both_t *)&value)->flt.exp - EXCESS;
#endif
#if defined(__PICC18__) || defined(__PICCPRO__) || defined(__18CXX)
	((both_t *)&value)->flt.hexp = EXCESS >> 1;
	((both_t *)&value)->flt.lexp = EXCESS & 0x01;
#else
	((both_t *)&value)->flt.exp = EXCESS;
#endif
	return value;
}

double
ldexp(double value, int newexp)
{
	if (value == 0.0)
		return 0.0;
#if defined(__PICC18__) || defined(__PICCPRO__) || defined(__18CXX)
	newexp += ((both_t *)&value)->flt.hexp << 1;
	newexp += ((both_t *)&value)->flt.lexp;
#else
	newexp += ((both_t *)&value)->flt.exp;
#endif
	if (newexp < 0) {
		errno = ERANGE;
		return 0.0;
	}
	else if (newexp > MAX_EXPONENT) {
		errno = ERANGE;
		if (value < 0.0)
			return -DBL_MAX;
		else
			return DBL_MAX;
	}
	else {
#if defined(__PICC18__) || defined(__PICCPRO__) || defined(__18CXX)
		((both_t *)&value)->flt.hexp = newexp >> 1;
		((both_t *)&value)->flt.lexp = newexp & 0x01;
#else
		((both_t *)&value)->flt.exp = newexp;
#endif
	}
	return value;
}

