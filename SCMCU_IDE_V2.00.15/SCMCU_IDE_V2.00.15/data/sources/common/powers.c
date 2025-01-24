/*
 *	Tables of powers of 10, for use in atof and doprnt.
 */
 
#include	<float.h>
 
const double	_powers_[] =
{
	1e0,
	1e1,
	1e2,
	1e3,
	1e4,
	1e5,
	1e6,
	1e7,
	1e8,
	1e9,
	1e10,
#if	DBL_MAX_10_EXP >= 20
	1e20,
	1e30,
#endif
#if	DBL_MAX_10_EXP >= 40
	1e40,
	1e50,
	1e60,
	1e70,
	1e80,
	1e90,
#endif
#if	DBL_MAX_10_EXP >= 100
	1e100,
	1e200,
	1e300,
#endif
};

const double	_npowers_[] =
{
	1e-0,
	1e-1,
	1e-2,
	1e-3,
	1e-4,
	1e-5,
	1e-6,
	1e-7,
	1e-8,
	1e-9,
	1e-10,
#if	DBL_MIN_10_EXP <= -20
	1e-20,
	1e-30,
#endif
#if	DBL_MIN_10_EXP <= -40
	1e-40,
	1e-50,
	1e-60,
	1e-70,
	1e-80,
	1e-90,
#endif
#if	DBL_MIN_10_EXP <= -100
	1e-100,
	1e-200,
	1e-300,
#endif
};
