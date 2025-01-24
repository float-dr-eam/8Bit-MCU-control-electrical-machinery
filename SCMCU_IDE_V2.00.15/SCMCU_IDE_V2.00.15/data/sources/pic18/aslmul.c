#include "inline.h"

extern unsigned long __lmul(unsigned long, unsigned long);

unsigned long _INLINE
__aslmul(unsigned long * mp, unsigned long multiplicand)
{
	return *mp = __lmul(*mp, multiplicand);
}
