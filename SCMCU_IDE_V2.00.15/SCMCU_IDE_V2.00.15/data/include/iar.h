#ifndef _IAR_H_
#define _IAR_H_

#ifdef __IAR__

#include <xc.h>
#include <__at.h>
#include <__size_t.h>

/* IAR Support Macros */

#define	__arm			__attribute__((unsupported("__arm is not defined on this architecture")))
#define	__thumb			__attribute__((unsupported("__thumb is not defined on this architecture")))
#define __task			__attribute__((unsupported("the __task attribute is not supported by this compiler")))
#define	__swi			__attribute__((unsupported("__swi is not defined on this architecture")))
#define	__interwork		__attribute__((unsupported("__interwork is not defined on this architecture")))
#define __little_endian	__attribute__((unsupported("the __big_little attribute is not supported by this compiler")))
#define __intrinsic		__attribute__((unsupported("the __intrinsic attribute is not supported by this compiler")))
#define __nested		__attribute__((unsupported("the __nested attribute is not supported by this compiler")))
#define __ramfunc		__attribute__((unsupported("the __ramfunc attribute is not supported by this compiler")))
#define __noreturn		__attribute__((unsupported("the __noreturn attribute is not supported by this compiler")))
#define __root			__attribute__((unsupported("the __root attribute is not supported by this compiler")))
#define __weak			__attribute__((unsupported("the __weak attribute is not supported by this compiler")))
#define __farfunc		__attribute__((unsupported("the __farfunc attribute is not supported by this compiler")))
#define __nearfunc		__attribute__((unsupported("the __nearfunc attribute is not supported by this compiler")))
#define __huge			__attribute__((unsupported("the __huge attribute is not supported by this compiler")))
#define __intrinsic		__attribute__((unsupported("the __intrinsic attribute is not supported by this compiler")))
#define __packed


#define __disable_fiq()			di()
#define __disable_interrupt()	di()
#define __disable_irq()			di()	
#define __enable_fiq()			ei()
#define __enable_interrupt()	ei()
#define __enable_irq()			ei()


/* IAR Support Functions */

extern void * 	__section_begin(const char * s) __attribute__((unsupported("__section_begin is not supported by this compiler")));
extern void *	__section_end(const char * s) __attribute__((unsupported("__section_end is not supported by this compiler")));
extern size_t *	__section_size(const char * s) __attribute__((unsupported("__section_size is not supported by this compiler")));
extern void * 	__segment_begin(const char * s) __attribute__((unsupported("__segment_begin is not supported by this compiler")));
extern void *	__segment_end(const char * s) __attribute__((unsupported("__segment_end is not supported by this compiler")));
extern size_t *	__segment_size(const char * s) __attribute__((unsupported("__segment_size is not supported by this compiler")));
extern void * 	__sfb(const char * s) __attribute__((unsupported("__sfb is not supported by this compiler")));
extern void * 	__sfe(const char * s) __attribute__((unsupported("__sfe is not supported by this compiler")));
extern size_t *	__sfs(const char * s)  __attribute__((unsupported("__sfs is not supported by this compiler")));
typedef unsigned char __istate_t;
extern __istate_t	__get_interrupt_state(void) __attribute__((unsupported("__get_interrupt_state() is not supported by this compiler")));
extern void		__set_interrupt_state(__istate_t i) __attribute__((unsupported("__set_interrupt_state() is not supported by this compiler")));

#endif // __IAR__

#endif // _IAR_H_
