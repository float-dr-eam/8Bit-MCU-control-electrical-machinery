#include	<string.h>

#ifdef __OPTIMIZE_SPEED__
int
strcmp(register const char * s1, register const char * s2)
{
	char t0, t1, t2;

	t0 = s1[0];

	while(1) {
		t1 = s2[0];
		if (t0 == 0)
			break;
		s1 += 2;
		if (t0 != t1)
			break;

		t2 = s1[-1];
		t1 = s2[1];

		if (t2 == 0)
			return t2 - t1;
		s2 += 2;
		if(t1 != t2)
			return t2 - t1;
		t0 = s1[0];
	}
	return t0 - t1;
}
#else
int
strcmp(register const char * s1, register const char * s2)
{
	register signed char	r;

	while (!(r = (unsigned char)*s1 - (unsigned char)*s2) && *s1) {
		s1++;
		s2++;
	}
	return r;
}
#endif
