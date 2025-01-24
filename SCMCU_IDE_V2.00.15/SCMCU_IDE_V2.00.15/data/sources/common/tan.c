#include	<math.h>

#ifdef	i8086
extern int	_use8087;
extern double	_tan87(double);
#endif

double
tan(double x)
{
#ifdef	i8086
	if(_use8087)
		return _tan87(x);
#endif
	return sin(x)/cos(x);
}
