#include	<math.h>

#ifdef	i8086
extern int	_use8087;
extern double	_cos87(double);
#endif

#define	PI	3.14159265358979
#define	TWO_PI	6.28318530717958
#define	HALF_PI	1.570796326794895

double
cos(double f)
{
#ifdef	i8086
	if(_use8087)
		return _cos87(f);
#endif
	/* cos is pi/2 out of phase with sin, so ... */

	if(f > PI)
		return sin(f - (PI+HALF_PI));
	return sin(f + HALF_PI);
}
