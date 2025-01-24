#include	<math.h>
#include	<limits.h>
#include	<float.h>

double
round(double x)
{
	double	f;

	f = x-trunc(x);
	x += f;
	return trunc(x);
}
