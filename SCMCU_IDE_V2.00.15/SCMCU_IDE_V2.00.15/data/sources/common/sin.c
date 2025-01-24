#include	<math.h>

#define	PI	3.14159265358979
#define	TWO_PI	6.28318530717958
#define	HALF_PI	1.570796326794895

#ifdef	i8086
extern int	_use8087;
extern double	_sin87(double);
#endif

double
sin(double f)
{
	const static double	coeff_a[] =
	{
		 207823.68416961012,
		-76586.415638846949,
		 7064.1360814006881,
		-237.85932457812158,
		 2.8078274176220686
	};
	const static double	coeff_b[] =
	{
		 132304.66650864931,
		 5651.6867953169177,
		 108.99981103712905,
		 1.0
	};
	double	x2, y;
	unsigned char	sgn;

#ifdef	i8086
	if(_use8087)
		return _sin87(f);
#endif
	sgn = 0;
	if(f < 0.0) {
		f = -f;
		sgn = 1;
	}
	f *= 1.0/TWO_PI;
	f -= floor(f);
	f *= 4.0;
	if(f > 2.0) {
		f -= 2.0;
		sgn = !sgn;
	}
	if( f > 1.0)
		f = 2.0 - f;
	x2 = f * f;
	y = eval_poly(x2, coeff_b, 3);
	f *= eval_poly(x2, coeff_a, 4) / y; 
	if(sgn)
		return -f;
	return f;
}


