#include "inline.h"

extern float __ftmul(float, float);

float _INLINE
__asftmul(float * f1p, float f2)
{
	return *f1p = __ftmul(*f1p, f2);
}

