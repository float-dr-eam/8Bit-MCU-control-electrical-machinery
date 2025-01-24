#ifdef __18CXX
#include <math.h>

#define MCHP_SIGN_MASK	0x00800000UL
#define MCHP_EXP_MASK	0xFF000000UL
#define MCHP_MANT_MASK	0x007FFFFFUL

/*
                      +-----------+-----------+-----------+-----------+
                      |    eb     |    f0     |    f1     |    f2     |
   +------------------+-----------+-----------+-----------+-----------+
   | IEEE754 32-bit   | seee eeee | emmm mmmm | mmmm mmmm | mmmm mmmm |
   +------------------+-----------+-----------+-----------+-----------+
   | Microchip 32-bit | eeee eeee | smmm mmmm | mmmm mmmm | mmmm mmmm |
   +------------------+-----------+-----------+-----------+-----------+
 */
double mchptoieee (unsigned long v)
{
	v = ((v & MCHP_SIGN_MASK) << 8) | ((v & MCHP_EXP_MASK) >> 1) | (v & MCHP_MANT_MASK);
	return *(double *)&v;
}

#endif
