#ifndef _CCI_H_
#define _CCI_H_

/* CCI Support Macros */

#include <__at.h>

#ifndef ___mkstr
#define	___mkstr1(x)	#x
#define	___mkstr(x)	___mkstr1(x)
#endif

#define	__deprecate	__attribute__((deprecated))
#define __cp0(arg)	__attribute__((unsupported("the __cp0() construct is not supported by this architecture")))
#define __cp0()		__attribute__((unsupported("the __cp0() construct is not supported by this architecture")))
#define __abi(arg)	__attribute__((unsupported("the __abi() construct is not supported by this architecture")))
#define __abi()		__attribute__((unsupported("the __abi() construct is not supported by this architecture")))
#define __align()	__attribute__((unsupported("the __align() attribute is not used by this compiler")))
#define __align(arg)	__attribute__((unsupported("the __align() attribute is not used by this compiler")))
#define	__xdata		__attribute__((unsupported("__xdata is not defined on this architecture")))
#define	__ydata		__attribute__((unsupported("__ydata in not defined on this architecture")))
#define	__interrupt(arg)	__attribute__((interrupt(___mkstr(__ ## arg))))

#if	defined(_BANKCOUNT_) && _BANKCOUNT_ <= 4
#define __bank(arg)	__bank##arg
#else
#define	__bank(arg)	__attribute__((unsupported("__bank() is not presently supported by this architecture and will be ignored")))
#endif

#endif
