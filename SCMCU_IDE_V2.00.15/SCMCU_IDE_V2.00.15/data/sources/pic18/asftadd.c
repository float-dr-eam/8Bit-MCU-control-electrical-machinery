#include "inline.h"

extern float __ftadd(float, float);

float _INLINE
__asftadd(float * f1p, float f2)
{
	return *f1p = __ftadd(*f1p, f2);
}

