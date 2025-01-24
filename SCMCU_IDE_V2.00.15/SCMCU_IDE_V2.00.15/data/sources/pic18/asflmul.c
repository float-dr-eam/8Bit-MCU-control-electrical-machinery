#include "inline.h"

extern double __flmul(double, double);

double _INLINE
__asflmul(double * mp, double multiplicand)
{
	return *mp = __flmul(*mp, multiplicand);
}

