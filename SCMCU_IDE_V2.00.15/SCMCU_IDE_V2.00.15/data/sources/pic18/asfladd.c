#include "inline.h"

extern double __fladd(double, double);

double _INLINE
__asfladd(double * f1p, double f2)
{
	return *f1p = __fladd(*f1p, f2);
}

