/*	Characteristics of floating types */

#define	DBL_RADIX	2		/* radix of exponent for a double */
#define	DBL_ROUNDS	0		/* doubles don't round when converted to int */
#define	FLT_RADIX	2		/* radix of float exponent */
#define	FLT_ROUNDS	0		/* float also truncates to int */

#if defined(__DSPICC__)

#define	FLT_MANT_DIG	24
#define	FLT_EPSILON	1.19209290e-07
#define	FLT_DIG		6
#define	FLT_MIN_EXP	-125
#define	FLT_MIN		1.17549435e-38
#define	FLT_MIN_10_EXP	-37
#define	FLT_MAX_EXP	128
#define FLT_MAX         3.40282347e+38
#define	FLT_MAX_10_EXP	38
#define	DBL_MANT_DIG	24
#define	DBL_EPSILON	1.19209290e-07
#define	DBL_DIG		6
#define	DBL_MIN_EXP	-125
#define	DBL_MIN		1.17549435e-38
#define	DBL_MIN_10_EXP	-37
#define	DBL_MAX_EXP	128
#define DBL_MAX         3.40282347e+38
#define	DBL_MAX_10_EXP	38
#endif

#if	defined(__PICC32__) || defined(__PICCPRO__)
	
// more recent compilers..

#define	FLT_MIN_EXP		-125
#define	FLT_MIN_10_EXP	-37
#define	FLT_MAX_EXP		128
#define	FLT_MAX_10_EXP	38
#define	FLT_MANT_DIG	((sizeof(float)-1)*8)
#define	FLT_EPSILON		3.05176e-05
#define	FLT_DIG			5
#define	FLT_MIN			1.17549435e-38
#define FLT_MAX         3.40277e+38

#define	DBL_MIN_EXP		FLT_MIN_EXP
#define	DBL_MIN_10_EXP	FLT_MIN_10_EXP
#define	DBL_MAX_EXP		FLT_MAX_EXP
#define	DBL_MAX_10_EXP	FLT_MAX_10_EXP
#define	DBL_MANT_DIG	((sizeof(double)-1)*8)
#define	DBL_EPSILON		(sizeof(double) == sizeof(float) ? FLT_EPSILON : 1.19209290e-07)
#define	DBL_DIG			(sizeof(double) == sizeof(float) ? FLT_DIG : 6)
#define	DBL_MIN			(sizeof(double) == sizeof(float) ? FLT_MIN : 1.17549435e-38)
#define DBL_MAX         (sizeof(double) == sizeof(float) ? FLT_MAX : 3.40282347e+38)
#endif

#if	(defined(_MPC_) && !defined(__DSPICC__) && !defined(__PICCPRO__)) || defined(__18CXX)
	
/* MICROCHIP PIC */

#define	FLT_MANT_DIG	16
#define	FLT_EPSILON	3.05176e-05
#define	FLT_DIG		5
#define	FLT_MIN_EXP	-125
#define	FLT_MIN		1.17549435e-38
#define	FLT_MIN_10_EXP	-37
#define	FLT_MAX_EXP	128
#define FLT_MAX         3.40277e+38
#define	FLT_MAX_10_EXP	38
#if	sizeof(double) == 4
#define	DBL_MANT_DIG	24
#define	DBL_EPSILON	1.19209290e-07
#define	DBL_DIG		6
#define	DBL_MIN_EXP	-125
#define	DBL_MIN		1.17549435e-38
#define	DBL_MIN_10_EXP	-37
#define	DBL_MAX_EXP	128
#define DBL_MAX         3.40282347e+38
#define	DBL_MAX_10_EXP	38
#else
#define	DBL_MANT_DIG	FLT_MANT_DIG
#define	DBL_EPSILON	FLT_EPSILON
#define	DBL_DIG		FLT_DIG
#define	DBL_MIN_EXP	FLT_MIN_EXP
#define	DBL_MIN		FLT_MIN
#define	DBL_MIN_10_EXP	FLT_MIN_10_EXP
#define	DBL_MAX_EXP	FLT_MAX_EXP
#define DBL_MAX         FLT_MAX
#define	DBL_MAX_10_EXP	FLT_MAX_10_EXP
#endif
#endif

/*	long double equates to double */


#define	LDBL_MANT_DIG	DBL_MANT_DIG
#define	LDBL_EPSILON	DBL_EPSILON
#define	LDBL_DIG	DBL_DIG
#define	LDBL_MIN_EXP	DBL_MIN_EXP
#define	LDBL_MIN	DBL_MIN
#define	LDBL_MIN_10_EXP	DBL_MIN_10_EXP
#define	LDBL_MAX_EXP	DBL_MAX_EXP
#define	LDBL_MAX	DBL_MAX
#define	LDBL_MAX_10_EXP	DBL_MAX_10_EXP


#if !__STDC__
#if defined(_PIC18)

/* Floating-point overflow and underflow */
#define _FPOVER
#define _FPUNDER

/*
  These flags must be cleared by the user before any floating-point
  add, subtract, multiply, or divide operation if they are to be
  tested after that operation or sequence of operations.

  They will be set upon arithmetic overflow or underflow,
  respectively.

  The result of an overflowing or underflowing operation may not be a
  valid floating-point value.
*/
extern volatile bit _fpover;
extern volatile bit _fpunder;

/* Floating-point divide by zero */
#define _FPDIV0

/*
  This flag must be cleared by the user before any floating-point
  divide operation if it is to be tested after that operation or
  sequence of operations.

  It will be set if the divisor is zero.

  The result of an attempt to divide by zero may not be a valid
  floating-point value.
*/
extern volatile bit _fpdiv0;

#endif /* _PIC18 */
#endif /* !__STDC__ */
