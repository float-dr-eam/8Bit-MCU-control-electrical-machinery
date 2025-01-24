#ifndef	_CMS_H_
#define	_CMS_H_

#ifndef _HTC_H_
#include <htc.h>
#endif

#ifdef _HAS_OSCVAL_
extern unsigned char __osccal_val(void);
#endif

#include <sc_chip_select.h>

/* MPLAB REAL-ICE related macros & includes (currently enhanced PICs only) */
#if defined(__DISABLE_REALICE_IT) || !defined(__MPLAB_REALICE__) || !defined(_PIC14E)
	#define __TRACE(id)         /* TRACE disabled */
	#define __LOG(id,value)     /* LOG disabled */
#else
	#if defined(__MPLAB_REALICE__)
		#include <trace16.h>
	#endif
#endif

#define	CLRWDT()	asm("clrwdt")
#define	SLEEP()		asm("sleep")
// function version of nop
#pragma intrinsic(__nop)
extern void __nop(void);
#define NOP()		__nop()

/* _nop() has been deprecated; use __nop() */
#define _nop()		__nop()

#define	ASMOPT_ON()		asm("opt asmopt_on")
#define	ASMOPT_OFF()	asm("opt asmopt_off")

//
// Legacy Programming Macro Functions
//
#define	__CONFIG(x) \
			__config(___mkstr(__CONFIG), ___mkstr(pic), ___mkstr(x))
// Programs the lower 4 bits per ID location
#define __IDLOC(w) \
			__config(___mkstr(__IDLOC), ___mkstr(pic), ___mkstr(w))
// Variant of IDLOC for those devices that permit programming of the lower 7 bits per ID location
#define __IDLOC7(a,b,c,d) \
			__config(___mkstr(__IDLOC7), ___mkstr(pic), a, b, c, d)
#define	__PROG_CONFIG(a, x)	\
			__config(___mkstr(__PROG_CONFIG), ___mkstr(pic), a, x)


#if !defined(_PIC14E) && !defined(_EEADRL)
#define _EEADRL EEADR
#else
#define _EEADRL EEADRL
#endif
#if	EEPROM_SIZE > 0
#define __EEPROM_DATA(a, b, c, d, e, f, g, h) \
			 asm("\tpsect eeprom_data,class=EEDATA,delta=2,space=3,noexec"); \
			 asm("\tdb\t" ___mkstr(a) "," ___mkstr(b) "," ___mkstr(c) "," ___mkstr(d) "," \
				      ___mkstr(e) "," ___mkstr(f) "," ___mkstr(g) "," ___mkstr(h))
#endif

/***********************************************************************
 **** FLASH memory read/write/erase macros and function definitions ****
 ***********************************************************************
 * Notes:
 *	__FLASHTYPE == 0 defined in devices that can only read flash memory - cannot write eg. 16F777
 *	__FLASHTYPE == 1 defined in traditional devices that can write 1 word at a time eg. 16F877
 *	__FLASHTYPE == 2 defined in devices that can only write in 4 word blocks eg. 16F877A
 *	__FLASHTYPE == 3 defined in devices requiring 32-word block erasure before writing eg. 16F87
 *	__FLASHTYPE == undefined if device can neither read nor write program memory
 */
// macro FLASH_READ returns a word stored at a flash address
#if defined(__FLASHTYPE)
extern unsigned int flash_read(unsigned short addr);
#if	EEPROM_SIZE > 0
#define FLASH_READ(addr) \
	(_EEADRL=(addr)&0xff,	\
	EEADRH=(addr)>>8,	\
	WREN=0,			\
	EECON1 |= 0x80,		\
	RD=1,			\
	NOP(),			\
	NOP(),			\
	(EEDATH << 8) | EEDATA)
#else	// FLASH_READ without EEPROM
#define FLASH_READ(addr) \
	(_EEADRL=(addr)&0xff,	\
	EEADRH=(addr)>>8,	\
	RD=1,			\
	NOP(),			\
	NOP(),			\
	(EEDATH << 8) | EEDATA)
#endif
#endif	// end FLASH_READ

// macro FLASH_WRITE used when writing only one word of data
#if	__FLASHTYPE==2 || __FLASHTYPE==3
/*
 * This is not available in this version. Contact HI-TECH support for more information.
#define FLASH_WRITE(addr,data)	\
	do{	\
	unsigned short x=data;	\
	flash_copy((const unsigned short *)&x,1,addr);	\
	}while(0)

extern void flash_copy(const unsigned short * source_addr,unsigned char length,unsigned short dest_addr);
*/
#elif	__FLASHTYPE==1
#define FLASH_WRITE(addr, value) \
	_EEADRL=((addr)&0xff);	\
	EEADRH=((addr)>>8);	\
	EEDATH=((value)>>8);	\
	EEDATA=((value)&0xff);	\
	EECON1 |= 0x80;		\
	WREN=1;			\
	EECON2 = 0x55;		\
	EECON2 = 0xaa;		\
	WR=1;			\
	NOP();		\
	NOP();		\
	WREN=0
//extern void flash_copy(const unsigned short * source_addr,unsigned char length,unsigned short dest_addr);
#endif	// end FLASH_WRITE

// macro FLASH_ERASE used to clear a 32-Byte sector of flash
#if	__FLASHTYPE==3
#define FLASH_ERASE(addr) \
       	while(WR)continue; \
	_EEADRL=((addr)&0xFF); \
	EEADRH=((addr>>8)&0xFF); \
	EECON1=0x94; \
	CARRY=0;if(GIE)CARRY=1;GIE=0;\
	EECON2=0x55;EECON2=0xAA;WR=1; \
	NOP(); \
	if(CARRY)GIE=1 

	// library function version
extern void flash_erase(unsigned short addr);
#endif	// end FLASH_ERASE

#include <eeprom_routines.h>

#ifdef __PICCPRO__
/****************************************************************/
/* Built-in delay routine					*/
/****************************************************************/
#pragma intrinsic(_delay)
extern __nonreentrant void _delay(unsigned long);
// NOTE: To use the macros below, YOU must have previously defined _XTAL_FREQ
#define __delay_us(x) _delay((unsigned long)((x)*(_XTAL_FREQ/4000000.0)))
#define __delay_ms(x) _delay((unsigned long)((x)*(_XTAL_FREQ/4000.0)))
#endif

/****************************************************************/
/****** Global interrupt enable/disable macro definitions *******/
/****************************************************************/
#if defined(_PIC14) || defined(_PIC14E)
	
#ifndef	ei
#define	ei()	(GIE = 1)	// interrupt enable bit
#endif  

#if defined(_14000) ||  defined(_16C61) || defined(_16C62) ||\
	defined(_16C63) || defined(_16C63A) || defined(_16C64) ||\
	defined(_16C65) || defined(_16C65B) || defined(_16C71) ||\
	defined(_16C73) || defined(_16C73B) || defined(_16C74) ||\
	defined(_16C74B) || defined(_16C84) || defined(_16C745) ||\
	defined(_16C765) || defined(_16LC74B)
	#ifndef	di
		#define di()	{ do { GIE = 0; } while ( GIE == 1 ); }	// disable interrupt bit
	#endif  
#else
	#ifndef	di
		#define	di()	(GIE = 0)	// interrupt enable bit
	#endif  
#endif

#endif

/* The below reflect the state of TO and PD, respectively, which would otherwise
   be trashed by startup code. */
extern unsigned char __resetbits;
extern __bit __powerdown;
extern __bit __timeout;
#endif	/* _CMS_H */
