#include "inline.h"

extern double __fldiv(double, double);

double _INLINE
__asfldiv(double * f1p, double f2)
{
	return *f1p = __fldiv(*f1p, f2);
}

