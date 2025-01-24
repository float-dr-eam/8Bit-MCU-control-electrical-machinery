/*	Characteristics of integral types */

#define	CHAR_BIT	8			/* bits per char */
#define	CHAR_MAX	127			/* max value of a char */
#define	CHAR_MIN	-128			/* min value of a char */
#define	SCHAR_MAX	CHAR_MAX		/* chars are signed */
#define	SCHAR_MIN	CHAR_MIN
#define	UCHAR_MAX	255			/* max value of an unsigned char */
#define	SHRT_MAX	32767			/* max value of a short */
#define	SHRT_MIN	(int)-32768		/* min value of a short */
#define	USHRT_MAX	65535			/* max value of an unsigned short */
#define	INT_MAX		32767			/* max value of an int */
#define	INT_MIN		(int)-32768		/* min value of an int */
#define	UINT_MAX	65535			/* max value of an unsigned int */
#define	SHRTLONG_MAX	8388607			/* max value of short long (non-Standard) */
#ifdef __CCI__
#define	SHRTLONG_MIN	(long)-8388608	/* min value of a short long (non-Standard) */
#else
#define	SHRTLONG_MIN	(short long)-8388608	/* min value of a short long (non-Standard) */
#endif
#define	USHRTLONG_MAX	16777215		/* max value of an unsigned short long (non-Standard) */
#define	LONG_MAX	2147483647		/* max value of long */
#define	LONG_MIN	(long)-2147483648	/* min value of a long */
#define	ULONG_MAX	4294967295		/* max value of an unsigned long */
#define	LLONG_MAX	2147483647		/* max value of long long (C99 Standard) */
#define	LLONG_MIN	(long long)-2147483648	/* min value of a long long (C99 Standard) */
#define	ULLONG_MAX	4294967295		/* max value of an unsigned long long (C99 Standard) */
