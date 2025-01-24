#ifndef	_TIME_H_
#define	_TIME_H_

#include <__unsupported.h>
#include <__size_t.h>
#include <__null.h>

typedef	long	time_t;		/* for representing times in seconds */
struct tm {
	int	tm_sec;
	int	tm_min;
	int	tm_hour;
	int	tm_mday;
	int	tm_mon;
	int	tm_year;
	int	tm_wday;
	int	tm_yday;
	int	tm_isdst;
};

#define	CLOCKS_PER_SEC	1
#define	clock()	(-1L)
#define	difftime(t1, t0)	((double)((time_t)(t1)-(time_t)(t0)))

extern int	time_zone;	/* minutes WESTWARD of Greenwich */
				/* this value defaults to 0 since with
				   operating systems like MS-DOS there is
				   no time zone information available */

extern time_t	time(time_t *);	/* seconds since 00:00:00 Jan 1 1970 */
extern int	stime(time_t *);	/* set time */

#ifdef _PIC12
#define __strftime_support	__unsupported(strftime)
#define __asctime_support	__unsupported(asctime)
#define __ctime_support		__unsupported(ctime)
#define __gmtime_support	__unsupported(gmtime)
#define __localtime_support	__unsupported(localtime)
#else
#define __strftime_support
#define __asctime_support
#define __ctime_support	
#define __gmtime_support
#define __localtime_support	
#endif

extern char *	asctime(const struct tm *) __asctime_support;	/* converts struct tm to ascii time */
extern char *	ctime(const time_t *) __ctime_support;	/* current local time in ascii form */
extern struct tm *	gmtime(const time_t *) __gmtime_support;	/* Universal time */
extern struct tm *	localtime(const time_t *) __localtime_support;	/* local time */
extern size_t		strftime(char *, size_t, const char *, const struct tm *) __strftime_support;
extern time_t		mktime(struct tm *);

#endif	/* _TIME_H_ */
