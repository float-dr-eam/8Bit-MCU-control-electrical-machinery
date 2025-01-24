#include	<math.h>

double
eval_poly(double x, const double * d, int n)
{
	double	res;

	res = d[n];
	while(n)
		res = x * res + d[--n];
	return res;
}
