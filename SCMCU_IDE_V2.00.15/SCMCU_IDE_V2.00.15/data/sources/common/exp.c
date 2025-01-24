#include	<math.h>
#include	<float.h>
#include	<errno.h>

#if	sizeof(double)<=4
#define EXP_MAX		7.09782712893383973096e+02
#define EXP_MIN		-7.45133219101941108420e+02
#endif


double
exp(double x)
{
	int	exponent;
	char	sign;

	const static double coeff[] =
	{
		1.0000000000e+00,
		6.9314718056e-01,
		2.4022650695e-01,
		5.5504108945e-02,
		9.6181261779e-03,
		1.3333710529e-03,
		1.5399104432e-04,
		1.5327675257e-05,
		1.2485143336e-06,
		1.3908092221e-07,
	};

	if(x == 0.0)
		return 1.0;
#if	sizeof(double)<=4
	if (x > EXP_MAX) {	//too big?
		errno = ERANGE;
		return DBL_MAX;
	}
	if (x < EXP_MIN) {	//too small?
		errno = ERANGE;
		return 0.0;
	}
#endif
	sign = x < 0.0;
	if(sign)
		x = -x;
	x *= 1.4426950409;		/* convert to log2 */
	exponent = (int)floor(x);
	x -= (double)exponent;
	x = ldexp(eval_poly(x, coeff, sizeof coeff/sizeof coeff[0] - 1), exponent);
	if(sign)
	{
		if (x == DBL_MAX)
			return 0.0;
		return 1.0/x;
	}
	return x;
}
