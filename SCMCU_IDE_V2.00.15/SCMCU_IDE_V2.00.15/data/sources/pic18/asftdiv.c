#include "inline.h"

extern float __ftdiv(float, float);

float _INLINE
__asftdiv(float * f1p, float f2)
{
	return *f1p = __ftdiv(*f1p, f2);
}

