/****************************************************************************/
/*                                                                          */
/*  Copyright 2006 Microchip Technology Inc                                 */
/*                                                                          */
/****************************************************************************/

	#ifndef	__TRACE18_H
	#define	__TRACE18_H



/* IT data formats */

#define __IT_FMT_MASK   0xFF00
#define __IT_FMT_DFLT   0x0100  /* 64 trace and 128 log IDs */
#define __IT_FMT_PC     0x0200  /* original testing format */
#define __IT_FMT_RAW7   0x0300  /* generic 7-bit data */
#define __IT_FMT_RAW8   0x0400  /* generic 8-bit data */
#define __IT_FMT_RAW16  0x0500  /* generic 16-bit data */
#define __IT_FMT_RAW32  0x0600  /* generic 32-bit data */


/* IT primary transport facilities */

#define __IT_XMT_MASK       0x00FF
#define __IT_PORT_MASK      0x0010
#define __IT_SPI_MASK       0x0020
#define __IT_UART_MASK      0x0040

#define __IT_XMT_DC             0x0001
#define __IT_XMT_PORTA          (__IT_PORT_MASK | 1)
#define __IT_XMT_PORTB          (__IT_PORT_MASK | 2)
/* reserve 16-bit PORTB_HI */
#define __IT_XMT_PORTC		    (__IT_PORT_MASK | 4)
#define __IT_XMT_PORTD          (__IT_PORT_MASK | 5)
/* reserve 16-bit PORTD_HI */
#define __IT_XMT_PORTE          (__IT_PORT_MASK | 7)
#define __IT_XMT_PORTF          (__IT_PORT_MASK | 8)
#define __IT_XMT_PORTG		    (__IT_PORT_MASK | 9)
/* reserve 16-bit PORTG_TRIHI */
#define __IT_XMT_PORTH			(__IT_PORT_MASK | 0x0B)
#define __IT_XMT_PORTJ			(__IT_PORT_MASK | 0x0C)
#define __IT_XMT_SPI1           (__IT_SPI_MASK | 1)
#define __IT_XMT_SPI2           (__IT_SPI_MASK | 2)
#define __IT_XMT_SPI1_RC75      (__IT_SPI_MASK | 3)
#define __IT_XMT_SPI2_RD20      (__IT_SPI_MASK | 4)
#define __IT_XMT_SPI2_F6C       (__IT_SPI_MASK | 5)
#define __IT_XMT_UART1          (__IT_UART_MASK | 1)
#define __IT_XMT_UART2          (__IT_UART_MASK | 2)


/* /d__IT= values */

#define off         0
#define dc_pc       (__IT_XMT_DC | __IT_FMT_PC)
#define dc          (__IT_XMT_DC | __IT_FMT_DFLT)
#define porta       (__IT_XMT_PORTA | __IT_FMT_DFLT)
/* No portb. Lines used for PGC and PGD. */
/* reserved portbhi */
#define portc       (__IT_XMT_PORTC | __IT_FMT_DFLT)
#define portd       (__IT_XMT_PORTD | __IT_FMT_DFLT)
/* reserved portdhi */
#define porte       (__IT_XMT_PORTE | __IT_FMT_DFLT)
#define portf       (__IT_XMT_PORTF | __IT_FMT_DFLT)
#define portg       (__IT_XMT_PORTG | __IT_FMT_DFLT)
/* reserved portghi */
#define porth       (__IT_XMT_PORTH | __IT_FMT_DFLT)
#define portj       (__IT_XMT_PORTJ | __IT_FMT_DFLT)
#define spi1        (__IT_XMT_SPI1 | __IT_FMT_DFLT)
#define spi2        (__IT_XMT_SPI2 | __IT_FMT_DFLT)
#define spi1rc75    (__IT_XMT_SPI1_RC75 | __IT_FMT_DFLT)
#define spi2rd20    (__IT_XMT_SPI2_RD20 | __IT_FMT_DFLT)
#define spi2f6c     (__IT_XMT_SPI2_F6C | __IT_FMT_DFLT)
#define uart1       (__IT_XMT_UART1 | __IT_FMT_DFLT)
#define uart2       (__IT_XMT_UART2 | __IT_FMT_DFLT)

#define porta_7     (__IT_XMT_PORTA | __IT_FMT_RAW7)
/* No portb. Lines used for PGC and PGD. */
#define portc_7     (__IT_XMT_PORTC | __IT_FMT_RAW7)
#define portd_7     (__IT_XMT_PORTD | __IT_FMT_RAW7)
#define porte_7     (__IT_XMT_PORTE | __IT_FMT_RAW7)
#define portf_7     (__IT_XMT_PORTF | __IT_FMT_RAW7)
#define portg_7     (__IT_XMT_PORTG | __IT_FMT_RAW7)
#define porth_7     (__IT_XMT_PORTH | __IT_FMT_RAW7)
#define portj_7     (__IT_XMT_PORTJ | __IT_FMT_RAW7)

#define porta_8     (__IT_XMT_PORTA | __IT_FMT_RAW8)
/* No portb. Lines used for PGC and PGD. */
#define portc_8     (__IT_XMT_PORTC | __IT_FMT_RAW8)
#define portd_8     (__IT_XMT_PORTD | __IT_FMT_RAW8)
#define porte_8     (__IT_XMT_PORTE | __IT_FMT_RAW8)
#define portf_8     (__IT_XMT_PORTF | __IT_FMT_RAW8)
#define portg_8     (__IT_XMT_PORTG | __IT_FMT_RAW8)
#define porth_8     (__IT_XMT_PORTH | __IT_FMT_RAW8)
#define portj_8     (__IT_XMT_PORTJ | __IT_FMT_RAW8)

#define spi1_8      (__IT_XMT_SPI1 | __IT_FMT_RAW8)
#define spi2_8      (__IT_XMT_SPI2 | __IT_FMT_RAW8)
#define spi1rc75_8  (__IT_XMT_SPI1_RC75 | __IT_FMT_RAW8)
#define spi2rd20_8  (__IT_XMT_SPI2_RD20 | __IT_FMT_RAW8)
#define spi2f6c_8  (__IT_XMT_SPI2_RD20 | __IT_FMT_RAW8)
#define uart1_8     (__IT_XMT_UART1 | __IT_FMT_RAW8)
#define uart2_8     (__IT_XMT_UART2 | __IT_FMT_RAW8)




#ifndef __IT
#define __TRACE(id)         /* TRACE disabled */
#define __LOG(id,value)     /* LOG disabled */
#else



/* Function Equates */

#if ((__IT & __IT_XMT_MASK) == __IT_XMT_DC)
#define __IT_TRACEFUNC	__it_trace_dc
#define __IT_LOGFUNC	__it_log_dc
#endif

#if ((__IT & __IT_XMT_MASK) == __IT_XMT_PORTA)
#define __IT_TRACEFUNC	__it_trace_porta
#define __IT_LOGFUNC	__it_log_porta
#endif

#if ((__IT & __IT_XMT_MASK) == __IT_XMT_PORTC)
#define __IT_TRACEFUNC	__it_trace_portc
#define __IT_LOGFUNC	__it_log_portc
#endif

#if ((__IT & __IT_XMT_MASK) == __IT_XMT_PORTD)
#define __IT_TRACEFUNC	__it_trace_portd
#define __IT_LOGFUNC	__it_log_portd
#endif

#if ((__IT & __IT_XMT_MASK) == __IT_XMT_PORTE)
#define __IT_TRACEFUNC	__it_trace_porte
#define __IT_LOGFUNC	__it_log_porte
#endif

#if ((__IT & __IT_XMT_MASK) == __IT_XMT_PORTF)
#define __IT_TRACEFUNC	__it_trace_portf
#define __IT_LOGFUNC	__it_log_portf
#endif

#if ((__IT & __IT_XMT_MASK) == __IT_XMT_PORTG)
#define __IT_TRACEFUNC	__it_trace_portg
#define __IT_LOGFUNC	__it_log_portg
#endif

#if ((__IT & __IT_XMT_MASK) == __IT_XMT_PORTH)
#define __IT_TRACEFUNC	__it_trace_porth
#define __IT_LOGFUNC	__it_log_porth
#endif

#if ((__IT & __IT_XMT_MASK) == __IT_XMT_PORTJ)
#define __IT_TRACEFUNC	__it_trace_portj
#define __IT_LOGFUNC	__it_log_portj
#endif

#if ((__IT & __IT_XMT_MASK) == __IT_XMT_SPI1)
#define __IT_TRACEFUNC	__it_trace_spi1
#define __IT_LOGFUNC  	__it_log_spi1
#endif

#if ((__IT & __IT_XMT_MASK) == __IT_XMT_SPI2)
#define __IT_TRACEFUNC	__it_trace_spi2
#define __IT_LOGFUNC  	__it_log_spi2
#endif

#if ((__IT & __IT_XMT_MASK) == __IT_XMT_SPI1_RC75)
#define __IT_TRACEFUNC	__it_trace_spi1_rc75
#define __IT_LOGFUNC  	__it_log_spi1_rc75
#endif

#if ((__IT & __IT_XMT_MASK) == __IT_XMT_SPI2_RD20)
#define __IT_TRACEFUNC	__it_trace_spi2_rd20
#define __IT_LOGFUNC  	__it_log_spi2_rd20
#endif

#if ((__IT & __IT_XMT_MASK) == __IT_XMT_SPI2_F6C)
#define __IT_TRACEFUNC	__it_trace_spi2_f6c
#define __IT_LOGFUNC  	__it_log_spi2_f6c
#endif

/* Technically, you do not have to save the WREG, STATUS, and
* BSR registers in a "C" program. You do, however, have to save 
* the INTCON GIEH/GIEL states. The functions below were written
* for all-assembly programs. Re-using them here reduces overall
* code size for mixed "C" and assembly programs. You could strip 
* out the save/restore of the WREG, STATUS, and BSR regs if the
* application is written entirely in "C". The savings, however, 
* will not be large as the majority of the code is spent on 
* saving/restoring the GIEH/GIEL states.
*/

#ifndef __ITINT
#define __ITINT 2
#endif

/* __ITINT=0 for polling apps. No int save/restore necessary */

#if (__ITINT == 1)
#define __IT_SAVE_CONTEXT       _IT_SAVE_ASM_INTNORM
#define __IT_RESTORE_CONTEXT    _IT_RESTORE_ASM_INTNORM
#endif

#if (__ITINT == 2)
#define __IT_SAVE_CONTEXT       _IT_SAVE_ASM_INTPRI
#define __IT_RESTORE_CONTEXT    _IT_RESTORE_ASM_INTPRI
#endif



/***************************************************************
* LOG AND TRACE MACROS
****************************************************************/

#if (__IT == off)
#define __TRACE(id)         /* TRACE disabled */
#define __LOG(id,value)     /* LOG disabled */
#else

#ifndef __IT_INTERNAL
extern void __IT_TRACEFUNC(char id);
extern void __IT_LOGFUNC(char id, char type, ...);

#if (__ITINT != 0)
extern void __IT_SAVE_CONTEXT(void);
extern void __IT_RESTORE_CONTEXT(void);
#endif

#endif


#if (__ITINT == 0)
#define __TRACE(id)     __builtin_enum_label("__TRACE_",id); \
                        __IT_TRACEFUNC(id)

#define __LOG(id,value) __builtin_enum_label("__LOG_",id); \
                        __IT_LOGFUNC(id,__builtin_ittype(value),(value))
#else

#define __TRACE(id)     __builtin_enum_label("__TRACE_",id); \
                        __IT_SAVE_CONTEXT(); \
                        __IT_TRACEFUNC(id); \
                        __IT_RESTORE_CONTEXT()

#define __LOG(id,value) __builtin_enum_label("__LOG_",id); \
                        __IT_SAVE_CONTEXT(); \
                        __IT_LOGFUNC(id,__builtin_ittype(value),(value)); \
                        __IT_RESTORE_CONTEXT()

#endif      /* __ITINT != 0 */
#endif      /* __IT != off */


	#endif		/* __IT defined */
	#endif		/* TRACE18_H defined */
