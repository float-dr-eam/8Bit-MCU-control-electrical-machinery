
/*
 *	$Header$
 *
 *	$Log$
 *	Revision 1.2  1995/10/18 15:36:17  clyde
 *	64 bit mods
 *
 * Revision 1.1  95/10/08  22:07:30  clyde
 * Initial revision
 * 
 */

#if	sizeof(double) == 8
extern double	_dto64i(double), _64itod(double);
double
_frndint(double f)
{
	f = _dto64i(f);
	return _64itod(f);
}
#else
float
_frndint(double f)
{
	return (float)(long)f;
}
#endif
