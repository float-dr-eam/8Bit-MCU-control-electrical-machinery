/*	Macros for accessing variable arguments */

#ifndef	_STDARG

// all recent PRO compilers use the following
#if	defined(_OMNI_CODE_)
typedef void * va_list[1];
#define	va_start(ap, parmn)	*ap = __va_start()
#pragma intrinsic(__va_start)
extern void *		__va_start(void);
#define	va_arg(ap, type)	(*(type *)__va_arg((*(type **)ap), (type)0))
#pragma intrinsic(__va_arg)
extern void *		__va_arg(void *, ...);
#define	_STDARG

#elif	defined(_MPC_) && !defined(__DSPICC__) && !defined(_OMNI_CODE_)
typedef void * va_list[1];
#define	va_start(ap, parmn)	*ap = __va_start()
#pragma intrinsic(__va_start)
extern void *		__va_start(void);
#define	va_arg(ap, type)	(*(*(type **)ap)++)
#define	_STDARG
#elif	defined(_PSOC_) || defined(__PICC32__)
typedef void * va_list[1];
#define	va_start(ap, parmn)	*ap = __va_start()
#pragma intrinsic(__va_start)
extern void *		__va_start(void);
#define	va_arg(ap, type)	(*(type *)__va_arg((*(type **)ap)))
#pragma intrinsic(__va_arg)
extern void *		__va_arg(void *);
#define	_STDARG

#else
typedef void *	va_list[1];
#endif

#ifndef	_STDARG
#define	va_start(ap, parmn)	(*ap = (void *)((&parmn)+1))
#define	va_arg(ap, type)	(*(*(type **)ap)++)
#define	_STDARG
#endif

#define	va_end(ap)


#endif	/* STDARG */
