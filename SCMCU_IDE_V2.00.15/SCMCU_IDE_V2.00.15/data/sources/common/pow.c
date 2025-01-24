#include	<math.h>
#include	<errno.h>

double
pow(double x, double y)
{
	unsigned char	sign = 0;
	unsigned long	yi;
	
	if(x == 0.0) {
		if (y <= 0.0) {
			errno = EDOM;
		}
		return 0.0;
	}
	if(y == 0.0)
		return 1.0;
	if(x < 0.0) {
		yi = (unsigned long)y;
		if(yi != y) {
			errno = EDOM;
			return 0.0;
		}
		sign = yi & 1;
		x = -x;
	}
	x = exp(log(x) * y);
	if(sign)
		return -x;
	return x;
}
