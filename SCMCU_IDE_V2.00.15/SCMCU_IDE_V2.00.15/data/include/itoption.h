	#ifndef __ITOPTION_H
	#define __ITOPTION_H

#define __IT_INTERNAL
#include "trace18.h"



#ifdef __IT


/***************************************************************
* External declarations
****************************************************************/

extern char _IT_ID;
extern char _IT_DATA;

/***************************************************************
* PORT SUPPORT
****************************************************************/

#if ((__IT & __IT_XMT_MASK) == __IT_XMT_PORTA)
#define __IT_TRIS		TRISA
#define __IT_LATCH		LATA
#endif

#if ((__IT & __IT_XMT_MASK) == __IT_XMT_PORTC)
#define __IT_TRIS		TRISC
#define __IT_LATCH		LATC
#endif

#if ((__IT & __IT_XMT_MASK) == __IT_XMT_PORTD)
#define __IT_TRIS		TRISD
#define __IT_LATCH		LATD
#endif

#if ((__IT & __IT_XMT_MASK) == __IT_XMT_PORTE)
#define __IT_TRIS		TRISE
#define __IT_LATCH		LATE
#endif

#if ((__IT & __IT_XMT_MASK) == __IT_XMT_PORTF)
#define __IT_TRIS		TRISF
#define __IT_LATCH		LATF
#endif

#if ((__IT & __IT_XMT_MASK) == __IT_XMT_PORTG)
#define __IT_TRIS		TRISG
#define __IT_LATCH		LATG
#endif

#if ((__IT & __IT_XMT_MASK) == __IT_XMT_PORTH)
#define __IT_TRIS		TRISH
#define __IT_LATCH		LATH
#endif

#if ((__IT & __IT_XMT_MASK) == __IT_XMT_PORTJ)
#define __IT_TRIS		TRISJ
#define __IT_LATCH		LATJ
#endif

#if (__IT & __IT_PORT_MASK)
#define __IT_STROBE_PORT    __IT_LATCH |= 0x80;

#define __IT_INIT_TRIS  do { __IT_TRIS = 0; __IT_LATCH = 0; } while(0) ;

#define __IT_XMT_BYTE(value)    do { _IT_ID=value;  __IT_LATCH = _IT_ID | 0x80;	} while(0);
#endif



/***************************************************************
* SPI SUPPORT
****************************************************************/

#if ((__IT & __IT_XMT_MASK) == __IT_XMT_SPI1)
extern void __IT_TRACEASM_SPI1(void);
#define __IT_XMT_BYTE(value)    _IT_ID=(value); \
                                __IT_TRACEASM_SPI1()
#endif


#if ((__IT & __IT_XMT_MASK) == __IT_XMT_SPI2)
extern void __IT_TRACEASM_SPI2(void);
#define __IT_XMT_BYTE(value)    _IT_ID=(value); \
                                __IT_TRACEASM_SPI2()
#endif


#if ((__IT & __IT_XMT_MASK) == __IT_XMT_SPI1_RC75)
extern void __IT_TRACEASM_SPI1_RC75(void);
#define __IT_XMT_BYTE(value)    _IT_ID=(value); \
                                __IT_TRACEASM_SPI1_RC75()
#endif


#if ((__IT & __IT_XMT_MASK) == __IT_XMT_SPI2_RD20)
extern void __IT_TRACEASM_SPI2_RD20(void);
#define __IT_XMT_BYTE(value)    _IT_ID=(value); \
                                __IT_TRACEASM_SPI2_RD20()
#endif


#if ((__IT & __IT_XMT_MASK) == __IT_XMT_SPI2_F6C)
extern void __IT_TRACEASM_SPI2_F6C(void);
#define __IT_XMT_BYTE(value)    _IT_ID=(value); \
                                __IT_TRACEASM_SPI2_F6C()
#endif


	#endif		/* __IT */
	#endif		/* __ITOPTION_H */
