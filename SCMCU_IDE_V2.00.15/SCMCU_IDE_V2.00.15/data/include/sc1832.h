
#ifndef	_HTC_H_
#warning Header file sc1832.h included directly. Use #include <cms.h> instead.
#endif

 /* header file for the cms microcontroller
	SC1832
	SC1834
 */

#ifndef	__SC1832_H
#define	__SC1832_H

// Special function register definitions

volatile       unsigned char	INDF		@ 0x000;
volatile       unsigned char	TMR0		@ 0x001;
volatile       unsigned char	PCL		    @ 0x002;
volatile       unsigned char	STATUS		@ 0x003;
volatile	   unsigned char	FSR		    @ 0x004;
volatile       unsigned char	PORTA		@ 0x005;
volatile       unsigned char	PORTB		@ 0x006;
volatile       unsigned char	PORTC		@ 0x007;

volatile       unsigned char	PCLATH		@ 0x00A;
volatile       unsigned char	INTCON		@ 0x00B;
volatile       unsigned char	PIR1		@ 0x00C;
volatile       unsigned char	PIR2		@ 0x00D;
volatile       unsigned char	TMR1L		@ 0x00E;
volatile       unsigned char	TMR1H		@ 0x00F;
volatile	   unsigned char	T1CON		@ 0x010;
volatile       unsigned char	TMR2		@ 0x011;
volatile	   unsigned char	T2CON		@ 0x012;
volatile	   unsigned char	PR2			@ 0x013;
volatile       unsigned char	CCPR1L		@ 0x015;
volatile       unsigned char	CCPR1H		@ 0x016;
volatile       unsigned char	CCP1CON		@ 0x017;

volatile       unsigned char	CCPR2L		@ 0x01B;
volatile       unsigned char	CCPR2H		@ 0x01C;
volatile       unsigned char	CCP2CON		@ 0x01D;
volatile       unsigned char	ADRESH		@ 0x01E;
volatile       unsigned char	ADCON0		@ 0x01F;

volatile	   unsigned char	OPTION_REG	@ 0x081;
volatile       unsigned char	TRISA		@ 0x085;
volatile       unsigned char	TRISB		@ 0x086;
volatile       unsigned char	TRISC		@ 0x087;
volatile       unsigned char	PIE1		@ 0x08C;
volatile	   unsigned char	PIE2		@ 0x08D;
volatile	   unsigned char	WDTCON		@ 0x08E;
volatile       unsigned char	OSCCON		@ 0x08F;
volatile	   unsigned char	OSCTUNE		@ 0x090;
volatile	   unsigned char	KEYCON0		@ 0x091;
volatile	   unsigned char	KEYCON1		@ 0x092;
volatile	   unsigned char	KEYDATAL	@ 0x093;
volatile	   unsigned char	KEYDATAH	@ 0x094;
volatile	   unsigned char	WPUA		@ 0x095;
volatile	   unsigned char	WPUB		@ 0x096;
volatile	   unsigned char	WPUC		@ 0x097;
volatile	   unsigned char	IOCA		@ 0x098;
volatile	   unsigned char	TABLE_SPH	@ 0x099;
volatile	   unsigned char	TABLE_SPL	@ 0x09A;
volatile	   unsigned char	TABLE_DATAL	@ 0x09B;
volatile       unsigned char	LCDCON		@ 0x09C;
volatile       unsigned char	ADRESL		@ 0x09E;
volatile	   unsigned char	ADCON1		@ 0x09F;


/* Definitions for STATUS register */
volatile       bit	CARRY	@ ((unsigned)&STATUS*8)+0;
volatile       bit	DC		@ ((unsigned)&STATUS*8)+1;
volatile       bit	ZERO	@ ((unsigned)&STATUS*8)+2;
volatile       bit	PD		@ ((unsigned)&STATUS*8)+3;
volatile       bit	TO		@ ((unsigned)&STATUS*8)+4;
volatile	   bit	IRP		@ ((unsigned)&STATUS*8)+7;

/* Definitions for PORTA register */
volatile	   bit	RA0		@ ((unsigned)&PORTA*8)+0;
volatile       bit	RA1		@ ((unsigned)&PORTA*8)+1;
volatile       bit	RA2		@ ((unsigned)&PORTA*8)+2;
volatile       bit	RA3		@ ((unsigned)&PORTA*8)+3;
volatile       bit	RA4		@ ((unsigned)&PORTA*8)+4;
volatile       bit	RA5		@ ((unsigned)&PORTA*8)+5;
volatile       bit	RA6		@ ((unsigned)&PORTA*8)+6;
volatile       bit	RA7		@ ((unsigned)&PORTA*8)+7;

/* Definitions for PORTB register */
volatile       bit	RB1		@ ((unsigned)&PORTB*8)+1;
volatile       bit	RB2		@ ((unsigned)&PORTB*8)+2;
volatile       bit	RB3		@ ((unsigned)&PORTB*8)+3;
volatile       bit	RB4		@ ((unsigned)&PORTB*8)+4;
volatile       bit	RB5		@ ((unsigned)&PORTB*8)+5;
volatile       bit	RB6		@ ((unsigned)&PORTB*8)+6;
volatile       bit	RB7		@ ((unsigned)&PORTB*8)+7;

/* Definitions for PORTC register */
volatile       bit	RC0		@ ((unsigned)&PORTC*8)+0;
volatile       bit	RC1		@ ((unsigned)&PORTC*8)+1;
volatile       bit	RC2		@ ((unsigned)&PORTC*8)+2;
volatile       bit	RC3		@ ((unsigned)&PORTC*8)+3;
volatile       bit	RC4		@ ((unsigned)&PORTC*8)+4;
volatile       bit	RC5		@ ((unsigned)&PORTC*8)+5;
volatile       bit	RC6		@ ((unsigned)&PORTC*8)+6;


/* Definitions for INTCON register */
volatile       bit	RBIF	@ ((unsigned)&INTCON*8)+0;
// Alternate definition for backward compatibility
volatile       bit	RABIF	@ ((unsigned)&INTCON*8)+0;
volatile       bit	T0IF	@ ((unsigned)&INTCON*8)+2;
volatile	   bit	RBIE	@ ((unsigned)&INTCON*8)+3;
// Alternate definition for backward compatibility
volatile	   bit	RABIE	@ ((unsigned)&INTCON*8)+3;
volatile	   bit	T0IE	@ ((unsigned)&INTCON*8)+5;
volatile	   bit	PEIE	@ ((unsigned)&INTCON*8)+6;
volatile       bit	GIE		@ ((unsigned)&INTCON*8)+7;

/* Definitions for PIR1 register */
volatile       bit	TMR1IF	@ ((unsigned)&PIR1*8)+0;
volatile       bit	TMR2IF	@ ((unsigned)&PIR1*8)+1;
volatile       bit	CCP1IF	@ ((unsigned)&PIR1*8)+2;
volatile       bit	SSPIF	@ ((unsigned)&PIR1*8)+3;
volatile       bit	ADIF	@ ((unsigned)&PIR1*8)+6;

/* Definitions for PIR2 register */
volatile       bit	CCP2IF	@ ((unsigned)&PIR2*8)+0;
volatile       bit	C1IF	@ ((unsigned)&PIR2*8)+5;
volatile       bit	C2IF	@ ((unsigned)&PIR2*8)+6;

/* Definitions for T1CON register */
volatile	   bit	TMR1ON	@ ((unsigned)&T1CON*8)+0;
volatile	   bit	TMR1CS	@ ((unsigned)&T1CON*8)+1;
volatile	   bit	T1SYNC	@ ((unsigned)&T1CON*8)+2;
volatile	   bit	T1OSCEN	@ ((unsigned)&T1CON*8)+3;
volatile	   bit	T1CKPS0	@ ((unsigned)&T1CON*8)+4;
volatile	   bit	T1CKPS1	@ ((unsigned)&T1CON*8)+5;
volatile	   bit	TMR1GE	@ ((unsigned)&T1CON*8)+6;
volatile	   bit	T1GINV	@ ((unsigned)&T1CON*8)+7;

/* Definitions for T2CON register */
volatile	   bit	T2CKPS0	@ ((unsigned)&T2CON*8)+0;
volatile	   bit	T2CKPS1	@ ((unsigned)&T2CON*8)+1;
volatile	   bit	TMR2ON	@ ((unsigned)&T2CON*8)+2;
volatile	   bit	TOUTPS0	@ ((unsigned)&T2CON*8)+3;
volatile	   bit	TOUTPS1	@ ((unsigned)&T2CON*8)+4;
volatile	   bit	TOUTPS2	@ ((unsigned)&T2CON*8)+5;
volatile	   bit	TOUTPS3	@ ((unsigned)&T2CON*8)+6;


/* Definitions for CCP1CON register */
volatile	   bit	CCP1M0	@ ((unsigned)&CCP1CON*8)+0;
volatile	   bit	CCP1M1	@ ((unsigned)&CCP1CON*8)+1;
volatile	   bit	CCP1M2	@ ((unsigned)&CCP1CON*8)+2;
volatile	   bit	CCP1M3	@ ((unsigned)&CCP1CON*8)+3;
volatile	   bit	DC1B0	@ ((unsigned)&CCP1CON*8)+4;
volatile	   bit	DC1B1	@ ((unsigned)&CCP1CON*8)+5;
volatile	   bit	P1M0	@ ((unsigned)&CCP1CON*8)+6;
volatile	   bit	P1M1	@ ((unsigned)&CCP1CON*8)+7;

/* Definitions for CCP2CON register */
volatile	   bit	CCP2M0	@ ((unsigned)&CCP2CON*8)+0;
volatile	   bit	CCP2M1	@ ((unsigned)&CCP2CON*8)+1;
volatile	   bit	CCP2M2	@ ((unsigned)&CCP2CON*8)+2;
volatile	   bit	CCP2M3	@ ((unsigned)&CCP2CON*8)+3;
volatile       bit	CCP2Y	@ ((unsigned)&CCP2CON*8)+4;
volatile       bit	CCP2X	@ ((unsigned)&CCP2CON*8)+5;

/* Definitions for ADCON0 register */
volatile	   bit	ADON	@ ((unsigned)&ADCON0*8)+0;
volatile       bit	GODONE	@ ((unsigned)&ADCON0*8)+1;
volatile	   bit	CHS0	@ ((unsigned)&ADCON0*8)+2;
volatile	   bit	CHS1	@ ((unsigned)&ADCON0*8)+3;
volatile	   bit	CHS2	@ ((unsigned)&ADCON0*8)+4;
volatile	   bit	CHS3	@ ((unsigned)&ADCON0*8)+5;
volatile	   bit	ADCS0	@ ((unsigned)&ADCON0*8)+6;
volatile	   bit	ADCS1	@ ((unsigned)&ADCON0*8)+7;

/* Definitions for OPTION_REG register */
volatile	   bit	PS0		@ ((unsigned)&OPTION_REG*8)+0;
volatile	   bit	PS1		@ ((unsigned)&OPTION_REG*8)+1;
volatile	   bit	PS2		@ ((unsigned)&OPTION_REG*8)+2;
volatile	   bit	PSA		@ ((unsigned)&OPTION_REG*8)+3;
volatile	   bit	T0SE	@ ((unsigned)&OPTION_REG*8)+4;
volatile	   bit	T0CS	@ ((unsigned)&OPTION_REG*8)+5;
volatile	   bit	RBPU	@ ((unsigned)&OPTION_REG*8)+7;
// Alternate definition for backward compatibility
volatile	   bit	RABPU	@ ((unsigned)&OPTION_REG*8)+7;

/* Definitions for TRISA register */
volatile	   bit	TRISA0	@ ((unsigned)&TRISA*8)+0;
volatile	   bit	TRISA1	@ ((unsigned)&TRISA*8)+1;
volatile	   bit	TRISA2	@ ((unsigned)&TRISA*8)+2;
volatile	   bit	TRISA3	@ ((unsigned)&TRISA*8)+3;
volatile	   bit	TRISA4	@ ((unsigned)&TRISA*8)+4;
volatile	   bit	TRISA5	@ ((unsigned)&TRISA*8)+5;
volatile	   bit	TRISA6	@ ((unsigned)&TRISA*8)+6;
volatile	   bit	TRISA7	@ ((unsigned)&TRISA*8)+7;

/* Definitions for TRISB register */
volatile       bit	TRISB1	@ ((unsigned)&TRISB*8)+1;
volatile       bit	TRISB2	@ ((unsigned)&TRISB*8)+2;
volatile       bit	TRISB3	@ ((unsigned)&TRISB*8)+3;
volatile       bit	TRISB4	@ ((unsigned)&TRISB*8)+4;
volatile       bit	TRISB5	@ ((unsigned)&TRISB*8)+5;
volatile       bit	TRISB6	@ ((unsigned)&TRISB*8)+6;
volatile       bit	TRISB7	@ ((unsigned)&TRISB*8)+7;

/* Definitions for TRISC register */
volatile       bit	TRISC0	@ ((unsigned)&TRISC*8)+0;
volatile       bit	TRISC1	@ ((unsigned)&TRISC*8)+1;
volatile       bit	TRISC2	@ ((unsigned)&TRISC*8)+2;
volatile       bit	TRISC3	@ ((unsigned)&TRISC*8)+3;
volatile       bit	TRISC4	@ ((unsigned)&TRISC*8)+4;
volatile       bit	TRISC5	@ ((unsigned)&TRISC*8)+5;
volatile       bit	TRISC6	@ ((unsigned)&TRISC*8)+6;


/* Definitions for PIE1 register */
volatile	   bit	TMR1IE	@ ((unsigned)&PIE1*8)+0;
volatile	   bit	TMR2IE	@ ((unsigned)&PIE1*8)+1;
volatile	   bit	CCP1IE	@ ((unsigned)&PIE1*8)+2;
volatile	   bit	SSPIE	@ ((unsigned)&PIE1*8)+3;
volatile	   bit	ADIE	@ ((unsigned)&PIE1*8)+6;

/* Definitions for PIE2 register */
volatile	   bit	CCP2IE	@ ((unsigned)&PIE2*8)+0;
volatile	   bit	C1IE	@ ((unsigned)&PIE2*8)+5;
volatile	   bit	C2IE	@ ((unsigned)&PIE2*8)+6;


/* Definitions for OSCCON register */
volatile	   bit	SCS		@ ((unsigned)&OSCCON*8)+0;
volatile	   bit	IRCF0	@ ((unsigned)&OSCCON*8)+4;
volatile	   bit	IRCF1	@ ((unsigned)&OSCCON*8)+5;
volatile	   bit	IRCF2	@ ((unsigned)&OSCCON*8)+6;

/* Definitions for OSCTUNE register */
volatile	   bit	TUN0	@ ((unsigned)&OSCTUNE*8)+0;
volatile	   bit	TUN1	@ ((unsigned)&OSCTUNE*8)+1;
volatile	   bit	TUN2	@ ((unsigned)&OSCTUNE*8)+2;
volatile	   bit	TUN3	@ ((unsigned)&OSCTUNE*8)+3;
volatile	   bit	TUN4	@ ((unsigned)&OSCTUNE*8)+4;


/* Definitions for WPUB register */
volatile	   bit	WPUB1	@ ((unsigned)&WPUB*8)+1;
volatile	   bit	WPUB2	@ ((unsigned)&WPUB*8)+2;
volatile	   bit	WPUB3	@ ((unsigned)&WPUB*8)+3;
volatile	   bit	WPUB4	@ ((unsigned)&WPUB*8)+4;
volatile	   bit	WPUB5	@ ((unsigned)&WPUB*8)+5;
volatile	   bit	WPUB6	@ ((unsigned)&WPUB*8)+6;
volatile	   bit	WPUB7	@ ((unsigned)&WPUB*8)+7;


/* Definitions for ADCON1 register */
volatile	   bit	ADFM	@ ((unsigned)&ADCON1*8)+7;

/* Definitions for WDTCON register */
volatile	   bit	WDTPS0	@ ((unsigned)&WDTCON*8)+1;
volatile	   bit	WDTPS1	@ ((unsigned)&WDTCON*8)+2;
volatile	   bit	WDTPS2	@ ((unsigned)&WDTCON*8)+3;
volatile	   bit	WDTPS3	@ ((unsigned)&WDTCON*8)+4;



#endif
