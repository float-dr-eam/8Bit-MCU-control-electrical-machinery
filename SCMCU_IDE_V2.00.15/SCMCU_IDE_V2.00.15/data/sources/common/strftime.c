/*
 * strftime.c
 *
 * implements the iso c function strftime()
 *
 * written 1989-09-06 by jim nutt
 * released into the public domain by jim nutt
 *
 * modified 1989-10-21 by Rob Duff
 *
 * modified 1994-8-26 by Paul Edwards
 *
 * modified 2012-5-18 by Andrew Lanham
 */

#include	<time.h>
#include	<string.h>
#include	<stdlib.h>
#include	<stdarg.h>

static const char *aday[] = {
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};

static const char *day[] = {
    "Sunday", "Monday", "Tuesday", "Wednesday",
    "Thursday", "Friday", "Saturday"
};

static const char *amonth[] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

static const char *month[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

static const char *__tzname[2] = { "" "" };
static char buf[26];

static void strfmt(const char *fmt, ...);

/**
 *
 * size_t strftime(char *str,
 *                 size_t maxs,
 *                 const char *fmt,
 *                 const struct tm *t)
 *
 *      this functions acts much like a sprintf for time/date output.
 *      given a pointer to an output buffer, a format string and a
 *      time, it copies the time to the output buffer formatted in
 *      accordance with the format string.  the parameters are used
 *      as follows:
 *
 *          str is a pointer to the output buffer, there should
 *          be at least maxs characters available at the address
 *          pointed to by str.
 *
 *          maxs is the maximum number of characters to be copied
 *          into the output buffer, included the '\0' terminator
 *
 *          fmt is the format string.  a percent sign (%) is used
 *          to indicate that the following character is a special
 *          format character.  the following are valid format
 *          characters:
 *
 *              %A      full weekday name (Monday)
 *              %a      abbreviated weekday name (Mon)
 *              %B      full month name (January)
 *              %b      abbreviated month name (Jan)
 *              %c      standard date and time representation
 *              %d      day-of-month (01-31)
 *              %H      hour (24 hour clock) (00-23)
 *              %I      hour (12 hour clock) (01-12)
 *              %j      day-of-year (001-366)
 *              %M      minute (00-59)
 *              %m      month (01-12)
 *              %p      local equivalent of AM or PM
 *              %S      second (00-59)
 *              %U      week-of-year, first day sunday (00-53)
 *              %W      week-of-year, first day monday (00-53)
 *              %w      weekday (0-6, sunday is 0)
 *              %X      standard time representation
 *              %x      standard date representation
 *              %Y      year with century
 *              %y      year without century (00-99)
 *              %Z      timezone name
 *              %%      percent sign
 *
 *      the standard date string is equivalent to:
 *
 *          %a %b %d %Y
 *
 *      the standard time string is equivalent to:
 *
 *          %H:%M:%S
 *
 *      the standard date and time string is equivalent to:
 *
 *          %a %b %d %H:%M:%S %Y
 *
 *      strftime returns the number of characters placed in the
 *      buffer, not including the terminating \0, or zero if more
 *      than maxs characters were produced.
 *
**/

#define COPY_FROM_BUFFER()	do {						\
							  while (*r)				\
							  {							\
									if (p == q)			\
									{					\
										  *q = '\0';	\
										  return 0;		\
									}					\
									*p++ = *r++;		\
							  }							\
							} while(0)

size_t strftime(char *s, size_t maxs, const char *f, const struct tm *t)
{
      div_t w;
      char *p, *q;
	  const char * r;

      p = s;
      q = s + maxs - 1;
      while ((*f != '\0'))
      {
            if (*f++ == '%')
            {
                  r = buf;
                  switch (*f++)
                  {
                  case '%' :
                        r = "%";
                        break;

                  case 'a' :
                        r = aday[t->tm_wday];
                        break;

                  case 'A' :
                        r = day[t->tm_wday];
                        break;

                  case 'b' :
                        r = amonth[t->tm_mon];
                        break;

                  case 'B' :
                        r = month[t->tm_mon];
                        break;

                  case 'c' :
                        strfmt("%0 %0 %2 ", 
								aday[t->tm_wday], amonth[t->tm_mon], t->tm_mday);
						COPY_FROM_BUFFER();
                        strfmt("%2:%2:%2 %4",
								t->tm_hour, t->tm_min, t->tm_sec, t->tm_year+1900);
                        break;

                  case 'd' :
                        strfmt("%2",t->tm_mday);
                        break;

                  case 'H' :
                        strfmt("%2",t->tm_hour);
                        break;

                  case 'I' :
                        strfmt("%2",(t->tm_hour%12)?t->tm_hour%12:12);
                        break;

                  case 'j' :
                        strfmt("%3",t->tm_yday+1);
                        break;

                  case 'm' :
                        strfmt("%2",t->tm_mon+1);
                        break;

                  case 'M' :
                        strfmt("%2",t->tm_min);
                        break;

                  case 'p' :
                        r = (t->tm_hour>11)?"PM":"AM";
                        break;

                  case 'S' :
                        strfmt("%2",t->tm_sec);
                        break;

                  case 'U' :
                        w = div(t->tm_yday,7);
                        if (w.rem > t->tm_wday)
                              w.quot++;
                        strfmt("%2", w.quot);
                        break;

                  case 'W' :
                        w = div(t->tm_yday,7);
                        if (w.rem > t->tm_wday%7)
                              w.quot++;
                        strfmt("%2", w.quot);
                        break;

                  case 'w' :
                        strfmt("%1",t->tm_wday);
                        break;

                  case 'x' :
                        strfmt("%3s %3s %2 %4", aday[t->tm_wday],
                              amonth[t->tm_mon], t->tm_mday, t->tm_year+1900);
                        break;

                  case 'X' :
                        strfmt("%2:%2:%2", t->tm_hour,
                              t->tm_min, t->tm_sec);
                        break;

                  case 'y' :
                        strfmt("%2",t->tm_year%100);
                        break;

                  case 'Y' :
                        strfmt("%4",t->tm_year+1900);
                        break;

                  case 'Z' :
                        r = (t->tm_isdst) ? __tzname[1] : __tzname[0];
                        break;

                  default:
                        buf[0] = '%';     /* reconstruct the format */
                        buf[1] = f[-1];
                        buf[2] = '\0';
                        if (buf[1] == 0)
                              f--;        /* back up if at end of string */
                  }
				  COPY_FROM_BUFFER();
            }
            else
            {
                  if (p == q)
                  {
                        *q = '\0';
                        return 0;
                  }
                  *p++ = f[-1];
            }
      }
      *p = '\0';
      return p - s;
}

static int pow[5] = { 1, 10, 100, 1000, 10000 };

/**
 * static void strfmt(char *fmt);
 *
 * simple sprintf for strftime
 *
 * each format descriptor is of the form %n
 * where n goes from zero to four
 *
 * 0    -- string %s
 * 1..4 -- int %?.?d
 *
**/

static void strfmt(const char *fmt, ...)
{
      int ival, ilen;
      char *sval;
      va_list vp;
	  char * str = buf;

      va_start(vp, fmt);
      while (*fmt)
      {
            if (*fmt++ == '%')
            {
                  ilen = *fmt++ - '0';
                  if (ilen == 0)                /* zero means string arg */
                  {
                        sval = va_arg(vp, char*);
                        while (*sval)
                              *str++ = *sval++;
                  }
                  else                          /* always leading zeros */
                  {
                        ival = va_arg(vp, int);
                        while (ilen)
                        {
                              ival %= pow[ilen--];
                              *str++ = (char)('0' + ival / pow[ilen]);
                        }
                  }
            }
            else  *str++ = fmt[-1];
      }
      *str = '\0';
      va_end(vp);
}

