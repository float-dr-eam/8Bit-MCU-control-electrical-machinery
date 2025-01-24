#include	<math.h>
#include	<limits.h>
#include	<float.h>

extern double	_frndint(double);

double
modf(double value, double * iptr)
{
#if	sizeof(double) == sizeof(long) && DBL_MAX_EXP == 128

	unsigned	expon;

	if(value >= 0.0 && value < 1.0 || value > -1.0 && value <= 0.0) {
		*iptr = 0;
		return value;
	}
	expon = ((*(unsigned long *)&value >> 23) & 255) - 126;
	if(expon > sizeof(double) * CHAR_BIT - 4) {
		*iptr = value;
		return 0.0;		/* already an integer */
	}
	*iptr = (double)(long)value;
	return value - *iptr;
#elif	sizeof(double) == sizeof(short long)
	*iptr = (double)(short long)value;
	return value - *iptr;
#else
	*iptr = _frndint(value);
	return value - *iptr;
#endif
}
