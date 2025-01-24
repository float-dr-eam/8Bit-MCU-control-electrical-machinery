#include	<math.h>

double fmod(double x, double y)
{
	double	n = x/y;
	n = trunc(n);
	return x-n*y;
}
