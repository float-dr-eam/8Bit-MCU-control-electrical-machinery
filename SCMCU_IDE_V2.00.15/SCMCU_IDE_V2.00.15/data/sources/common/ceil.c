#include	<math.h>
#include	<limits.h>
#include	<float.h>

#if	sizeof(double) <= sizeof(long)
#define	_frndint(x)	((double)(long)(x))
#else
extern double	_frndint(double);
#endif


double
ceil(double x)
{
	double	i;
	int	expon;

	frexp(x, &expon);
	if(expon < 0)
		if(x <= 0)
			return 0.0;
		else
			return 1.0;
	if((unsigned)expon > sizeof(double) * CHAR_BIT - 4)
		return x;		/* already an integer */
	i = _frndint(x);
	if(i < x)
		return i + 1.0;
	return i;
}
