#ifdef __18CXX
#include <math.h>

#define IEEE_SIGN_MASK	0x80000000UL
#define IEEE_EXP_MASK	0x7F800000UL
#define IEEE_MANT_MASK	0x007FFFFFUL

/*
                      +-----------+-----------+-----------+-----------+
                      |    eb     |    f0     |    f1     |    f2     |
   +------------------+-----------+-----------+-----------+-----------+
   | IEEE754 32-bit   | seee eeee | emmm mmmm | mmmm mmmm | mmmm mmmm |
   +------------------+-----------+-----------+-----------+-----------+
   | Microchip 32-bit | eeee eeee | smmm mmmm | mmmm mmmm | mmmm mmmm |
   +------------------+-----------+-----------+-----------+-----------+
 */
unsigned long ieeetomchp (double v)
{
	unsigned long l_v = *((unsigned long *)&v);

	return ((l_v & IEEE_EXP_MASK) << 1) | ((l_v & IEEE_SIGN_MASK) >> 8) | (l_v & IEEE_MANT_MASK);
}

#endif
