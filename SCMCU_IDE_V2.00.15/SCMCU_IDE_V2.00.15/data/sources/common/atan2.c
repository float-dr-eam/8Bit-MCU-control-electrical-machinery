#include	<math.h>
#include	<errno.h>

#define PI	3.14159265358979
#define HALF_PI	1.57079632679489

double
atan2(double y,double  x)
{
	double	v;

	if (x == 0) {
		if (y == 0) {
			errno = EDOM;
			return 0;
		}
		if (y > 0) {
			  return HALF_PI;
		}
		else {
			  return -HALF_PI;
		}
	}
	if (y == 0) {
		if (x > 0) {
			  return 0;
		}
		else {
			  return PI;
		}
	}
	if(fabs(x) >= fabs(y)) {
		v = atan(y/x);
		if( x < 0.0)
			if(y >= 0.0)
				v += PI;
			else
				v -= PI;
		return v;
	}
	v = -atan(x/y);
	if(y < 0.)
		v -= HALF_PI;
	else
		v += HALF_PI;
	return v;
}
