#ifndef	_STDDEF_H_
#define	_STDDEF_H_

#include <__size_t.h>
#include <__null.h>
typedef	int		ptrdiff_t;	/* result type of pointer difference */
/* find the offset of a structure member without using a NULL pointer */
#define	offsetof(ty, mem)	(int)(((char*)&((ty *)1)->mem)-1)

#endif // _STDDEF_H_
