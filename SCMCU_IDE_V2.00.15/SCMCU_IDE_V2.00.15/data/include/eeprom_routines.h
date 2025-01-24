// This header file should not be included directly
// Inclusion of this file is provided indirectly by including htc.h

/***********************************************************************/
/****** EEPROM memory read/write macros and function definitions *******/
/***********************************************************************/
/* NOTE WELL:

   The macro EEPROM_READ() is NOT safe to use immediately after any
   write to EEPROM, as it does NOT wait for WR to clear.  This is by
   design, to allow minimal code size if a sequence of reads is
   desired.  To guarantee uncorrupted writes, use the function
   eeprom_read() or insert
	while(WR)continue;
   before calling EEPROM_READ().
*/
#if	EEPROM_SIZE > 0

#ifdef	__FLASHTYPE
	// macro versions of EEPROM write and read
#define	EEPROM_WRITE(addr, value) \
do{ \
	while(WR)continue;EEADR=(addr);EEDATA=(value); \
	EECON1&=0x3F;CARRY=0;if(GIE)CARRY=1;GIE=0; \
	WREN=1;EECON2=0x55;EECON2=0xAA;WR=1;WREN=0; \
	if(CARRY)GIE=1; \
}while(0)
	#define	EEPROM_READ(addr) ((EEADR=(addr)),(EECON1&=0x3F),(RD=1),EEDATA)
#else	// else doesn't write flash
#define	EEPROM_WRITE(addr, value) \
do{ \
	while(WR)continue;EEADR=(addr);EEDATA=(value); \
	CARRY=0;if(GIE)CARRY=1;GIE=0; \
	WREN=1;EECON2=0x55;EECON2=0xAA;WR=1;WREN=0; \
	if(CARRY)GIE=1; \
}while(0)
	#define	EEPROM_READ(addr) ((EEADR=(addr)),(RD=1),EEDATA)
#endif

/* library function versions */
extern void eeprom_write(unsigned char addr, unsigned char value);
extern unsigned char eeprom_read(unsigned char addr);
extern void eecpymem(volatile unsigned char *to, __eeprom unsigned char *from, unsigned char size);
extern void memcpyee(__eeprom unsigned char *to, const unsigned char *from, unsigned char size);
#endif	// end EEPROM routines


