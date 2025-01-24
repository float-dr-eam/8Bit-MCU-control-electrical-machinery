#include "inline.h"

extern float __ftsub(float, float);

float _INLINE
__asftsub(float * f1p, float f2)
{
	return *f1p = __ftsub(*f1p, f2);
}

