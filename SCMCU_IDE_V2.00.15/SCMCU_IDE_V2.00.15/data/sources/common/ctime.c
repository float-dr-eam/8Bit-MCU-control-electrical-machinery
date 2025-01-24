/*
 *	Ctime - no daylight saving
 */

#include	<time.h>

const unsigned char	moninit[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


static
dylen(unsigned yr)
{
	if(yr%4 || (yr % 100) == 0 && ((yr+300)%400) != 0)
		return(365);
	return(366);
}

struct tm *
localtime(const time_t * tp)
{
	time_t	t;

	t = *tp - time_zone*60L;
	return gmtime(&t);
}

struct tm *
gmtime(const time_t * tp)
{
	union {
		time_t		t;
		struct {
			unsigned char	b, d;
		}	cs;
	}	tc;
	static struct tm	tim;

	tc.t = *tp;
	tim.tm_sec = tc.t % 60L;
	tc.t /= 60L;
	tim.tm_min = tc.t % 60L;
	tc.t /= 60L;
	tim.tm_hour = tc.t % 24L;
	tim.tm_mday = tc.t / 24L;
	tim.tm_wday = (tim.tm_mday + 4) % 7;
	tim.tm_year = 70;
	while(tim.tm_mday >= dylen(tim.tm_year)) {
		tim.tm_mday -= dylen(tim.tm_year);
		tim.tm_year++;
	}
	/* this value will be 2 for a leap year, 0 otherwise */
	tc.cs.b = (unsigned char)dylen(tim.tm_year) & 2;
	tim.tm_yday = tim.tm_mday;
	tim.tm_mon = 0;
	while(tim.tm_mday >= (tc.cs.d = moninit[tim.tm_mon] | tc.cs.b)) {
		tim.tm_mday -= tc.cs.d;
		tim.tm_mon++;
		tc.cs.b >>= 1;
	}
	tim.tm_mday++;
	return &tim;
}

char *
ctime(const time_t * tp)
{
	return asctime(localtime(tp));
}

