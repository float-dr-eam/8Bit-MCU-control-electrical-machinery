#ifndef BATCH_DEBUG_H
#define BATCH_DEBUG_H

#define	___mkstr1(x)	#x
#define	___mkstr(x)	___mkstr1(x)

/*************************************************************************/
/*  				PIC Midrange				 */
/*************************************************************************/
#if defined(_PIC14)
#define _EXIT_SIM(exitCode)	do { \
					asm("dw " ___mkstr(0x3000 \
						+ (exitCode & 0xff))); \
					asm("dw 0Fh"); \
				} while(0);

#endif	/* PIC Midrange */

/*************************************************************************/
/*  				PIC18					 */
/*************************************************************************/
#if defined(_PIC18) || defined(__18CXX)
#define _EXIT_SIM(exitCode)	do { \
					asm("dw " ___mkstr(0xE00 \
						+ (exitCode & 0xff))); \
					asm("dw 01h"); \
				} while(0);
#endif	/* PIC 18 */

/*************************************************************************/
/*  				dsPIC					 */
/*************************************************************************/
#if defined(__DSPICC__)
#define _EXIT_SIM(exitCode)	do { \
					asm("movf #" ___mkstr(exitCode & 0xff)) ",WREG"; \
					asm("ddw 00030000h"); \
				} while(0);
#endif	/* dsPIC */

/*************************************************************************/
/*  				PIC32                                                */
/*************************************************************************/
#if defined(__PICC32__)

// mips32
// addiu s0, zero, exitCode
// sdbbp 0
#define _EXIT_SIM32(exitCode)	do { \
					asm("dw " ___mkstr(0x24100000 \
						+ (exitCode & 0xffff))); \
					asm("dw 0x7000003f"); \
				} while(0);

// mips16
// li s0, exitCode 
// sdbbp 0
#define _EXIT_SIM16(exitCode)	do { \
					asm("dh " ___mkstr(0x6800 \
						+ (exitCode & 0xff))); \
					asm("dh 0xE801"); \
				} while(0);

#ifdef _DEFAULT_ISA_MIPS32R2
#	define _EXIT_SIM _EXIT_SIM32
#elif defined _DEFAULT_ISA_MIPS16E
#	define _EXIT_SIM _EXIT_SIM16
#else
#	error No deault ISA has been defined
#endif

#endif	/* PIC 32 */

/*************************************************************************/
/*  				Common					 */
/*************************************************************************/

#if defined(_PIC18) || defined(_PIC14) || defined(__PICC32__) || defined(__dsPIC30F__) || defined(__PIC24__)

#define _PASSED_TESTS()	_EXIT_SIM(0);
#define _FAILED_TEST()	_EXIT_SIM(1);

#endif

#endif /* BATCH_DEBUG_H */
