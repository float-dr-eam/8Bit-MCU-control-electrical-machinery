#include "inline.h"

extern double __flsub(double, double);

double _INLINE
__asflsub(double * f1p, double f2)
{
	return *f1p = __flsub(*f1p, f2);
}

