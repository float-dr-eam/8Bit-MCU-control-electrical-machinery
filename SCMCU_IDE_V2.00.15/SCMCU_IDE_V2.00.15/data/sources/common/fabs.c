#include	<math.h>

double
fabs(double d)
{
	if(d < 0.0)
		return -d;
	return d;
}
