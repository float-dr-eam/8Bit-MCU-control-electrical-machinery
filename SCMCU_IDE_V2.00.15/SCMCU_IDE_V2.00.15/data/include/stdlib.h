/*	Standard utility functions */
#ifndef _STDLIB_H_
#define _STDLIB_H_

#include <__size_t.h>
#include <__null.h>
typedef unsigned short	wchar_t;	/* wide char type */

#define	RAND_MAX	32767		/* max value returned by rand() */
#define	EXIT_SUCCESS	0
#define	EXIT_FAILURE	1

#ifndef	_DIVTYPES
#if	(defined(_MPC_) && !defined(__DSPICC__)) || defined(i8051) || defined(__18CXX)
typedef struct {
	int	rem;	/* remainder */		/* PIC version returns remainder here */
	int	quot;	/* quotient */
} div_t;				/* div() return type */
typedef struct {
	unsigned	rem;	/* remainder */		/* PIC version returns remainder here */
	unsigned	quot;	/* quotient */
} udiv_t;				/* div() return type */
typedef struct {
	long 	quot;	/* quotient */
	long 	rem;	/* remainder */
} ldiv_t;				/* ldiv() return type */
typedef struct {
	unsigned long 	quot;	/* quotient */
	unsigned long 	rem;	/* remainder */
} uldiv_t;				/* ldiv() return type */
#else
typedef struct {
	int	quot;	/* quotient */
	int	rem;	/* remainder */
} div_t;				/* div() return type */
typedef struct {
	unsigned	quot;	/* quotient */
	unsigned	rem;	/* remainder */
} udiv_t;				/* div() return type */
typedef struct {
	long 	quot;	/* quotient */
	long 	rem;	/* remainder */
} ldiv_t;				/* ldiv() return type */
typedef struct {
	unsigned long 	quot;	/* quotient */
	unsigned long 	rem;	/* remainder */
} uldiv_t;				/* ldiv() return type */
#endif	/* _MPC_ */

#define	_DIVTYPES
#endif

extern double		atof(const char *);
extern double		strtod(const char *, const char **);
extern int			atoi(const char *);
extern unsigned		xtoi(const char *);
extern long			atol(const char *);
extern long			strtol(const char *, char **, int);
#define	strtoul(a,b,c)	((unsigned long)strtol((a),(b),(c)))
extern int			rand(void);
extern void			srand(unsigned int);
extern void *		calloc(size_t, size_t);
extern div_t		div(int numer, int denom);
extern udiv_t		udiv(unsigned numer, unsigned denom);
extern ldiv_t		ldiv(long numer, long denom);
extern uldiv_t		uldiv(unsigned long numer,unsigned  long denom);
extern unsigned long	_lrotl(unsigned long value, unsigned int shift);
extern unsigned long	_lrotr(unsigned long value, unsigned int shift);
extern unsigned int	_rotl(unsigned int value, unsigned int shift);
extern unsigned int	_rotr(unsigned int value, unsigned int shift);

#define	max(a,b)	(((a) > (b)) ? (a) : (b))
#define	min(a,b)	(((a) < (b)) ? (a) : (b))

extern void *		malloc(size_t);
extern void		free(void *);
extern void *		realloc(void *, size_t);

#if	defined(__XC8)
/* abort and exit are defined as a macro included in xc8debug.h */
#include <xc8debug.h>
#else
extern void	abort(void);
extern void	exit(int);
#endif
extern int	atexit(void (*)(void));
extern char *	getenv(const char *);
extern char **	environ;
extern int	system(char *);
extern void	qsort(void *, size_t, size_t, int (*)(const void *, const void *));
extern void *	bsearch(const void *, void *, size_t, size_t, int(*)(const void *, const void *));
extern int	abs(int);
extern long	labs(long);

extern char *	itoa(char * buf, int val, int base);
extern char *	utoa(char * buf, unsigned val, int base);
#ifdef __18CXX
extern char *	ltoa(long val, char * buf);
extern char *	ultoa(unsigned long val, char * buf);
#else
extern char *	ltoa(char * buf, long val, int base);
extern char *	ultoa(char * buf, unsigned long val, int base);
#endif
extern char *	ftoa(float f, int * status);

#ifdef __18CXX
#define atob(a)		((signed char)atoi(a))
#define atoul(a)	((unsigned long)atol(a))
#define btoa(a,b)	itoa((signed char)(a),b)
#endif

#endif // _STDLIB_H_
