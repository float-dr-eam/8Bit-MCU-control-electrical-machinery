#include <time.h>
#include <stdlib.h>
#include <string.h>

static int
isleap(unsigned yr)
{
   return yr % 400 == 0 || (yr % 4 == 0 && yr % 100 != 0);
}

static unsigned
months_to_days(unsigned month)
{
   return (month * 3057 - 3007) / 100;
}

static long
years_to_days (unsigned yr)
{
#if _PIC18
	long ret;
	ret = (yr * 365L);
	ret += (yr / 4) - (yr / 100);
	ret += yr/400;
	return ret;
#else
   return yr * 365L + yr / 4 - yr / 100 + yr / 400;
#endif
}

/*
 * Return the number of days. The function takes
 * into account leap years.
 *
 * yr : must be greater than 0
 * mo : must be between 1 and 12
 * day: must be between 1 and 32
 * */
static long
ymd_to_scalar(unsigned yr, unsigned mo, unsigned day)
{
   long scalar;
   scalar = day + months_to_days(mo);
   if ( mo > 2 )                         /* adjust if past February */
      scalar -= isleap(yr) ? 1 : 2;
   yr--;
   scalar += years_to_days(yr);
   return scalar;
}

time_t
mktime(struct tm *timeptr)
{
    time_t tt;
    
    if ((timeptr->tm_year < 70) || (timeptr->tm_year > 138))
    {
        tt = (time_t)-1;
    }
    else
    {
        tt = ymd_to_scalar(timeptr->tm_year + 1900, 
                           timeptr->tm_mon + 1, 
                           timeptr->tm_mday);
		tt -= ymd_to_scalar(1970, 1, 1);
        tt = tt * 24 + timeptr->tm_hour;
        tt = tt * 60 + timeptr->tm_min;
        tt = tt * 60 + timeptr->tm_sec;
    }
    return tt;
}

