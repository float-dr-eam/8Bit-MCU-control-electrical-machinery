#ifndef	_MATH_H_
#define	_MATH_H_

#include <__unsupported.h>

#ifdef _PIC12
#define __exp_support	__unsupported(exp)
#define __sin_support	__unsupported(sin)
#define __cos_support	__unsupported(cos)
#define __tan_support	__unsupported(tan)
#define __asin_support	__unsupported(asin)
#define __acos_support	__unsupported(acos)
#define __atan2_support	__unsupported(atan2)
#define __pow_support	__unsupported(pow)
#define __cosh_support	__unsupported(cosh)
#define __sinh_support	__unsupported(sinh)
#else
#define __exp_support
#define __sin_support
#define __cos_support
#define __tan_support
#define __asin_support
#define __acos_support
#define __atan2_support
#define __pow_support
#define __cosh_support
#define __sinh_support
#endif

extern double fabs(double);
extern double floor(double);
extern double ceil(double);
extern double modf(double, double *);
extern double sqrt(double);
extern double atof(const char *);
extern double sin(double) __sin_support;
extern double cos(double) __cos_support;
extern double tan(double) __tan_support;
extern double asin(double) __asin_support;
extern double acos(double) __acos_support;
extern double atan(double);
extern double atan2(double, double) __atan2_support;
extern double log(double);
extern double log10(double);
extern double pow(double, double) __pow_support;
extern double exp(double) __exp_support;
extern double sinh(double) __sinh_support;
extern double cosh(double) __cosh_support;
extern double tanh(double);
extern double eval_poly(double, const double *, int);
extern double frexp(double, int *);
extern double ldexp(double, int);
extern double fmod(double, double);
extern double trunc(double);
extern double round(double);

// Microchip equivalent definitions 
#define	M_E		2.7182818284590452354
#define	M_LOG2E		1.4426950408889634074
#define	M_LOG10E	0.43429448190325182765
#define	M_LN2		0.69314718055994530942
#define	M_LN10		2.30258509299404568402
#define	M_PI		3.14159265358979323846
#define	M_PI_2		1.57079632679489661923
#define	M_PI_4		0.78539816339744830962
#define	M_1_PI		0.31830988618379067154
#define	M_2_PI		0.63661977236758134308
#define	M_2_SQRTPI	1.12837916709551257390
#define	M_SQRT2		1.41421356237309504880
#define	M_SQRT1_2	0.70710678118654752440

#ifdef __18CXX
unsigned long ieeetomchp(double v);
double mchptoieee(unsigned long v);
#endif

#endif	/* _MATH_H_ */
