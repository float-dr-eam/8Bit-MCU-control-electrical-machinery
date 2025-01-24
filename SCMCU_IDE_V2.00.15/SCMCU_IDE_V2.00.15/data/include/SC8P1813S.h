
#ifndef	_HTC_H_
#warning Header file SC8P1813S.h included directly. Use #include <sc.h> instead.
#endif

#ifndef	__SC8P1813S_H
#define	__SC8P1813S_H

// Special function register definitions

volatile       unsigned char	INDF		@ 0x000;
volatile       unsigned char	TMR0		@ 0x001;
volatile       unsigned char	PCL		    @ 0x002;
volatile       unsigned char	STATUS		@ 0x003;
volatile       unsigned char	FLAGS		@ 0x003;
volatile	   unsigned char	FSR		    @ 0x004;
volatile       unsigned char	PORTA		@ 0x005;
volatile       unsigned char	PORTB		@ 0x006;
volatile       unsigned char	PORTC		@ 0x007;


volatile       unsigned char	PORTE		@ 0x009;
volatile       unsigned char	PCLATH		@ 0x00A;
volatile       unsigned char	INTCON		@ 0x00B;
volatile       unsigned char	PIR1		@ 0x00C;
volatile       unsigned char	PIR2		@ 0x00D;
volatile       unsigned char	TMR1L		@ 0x00E;
volatile       unsigned char	TMR1H		@ 0x00F;
volatile	   unsigned char	T1CON		@ 0x010;
volatile       unsigned char	TMR2		@ 0x011;
volatile	   unsigned char	T2CON		@ 0x012;
//volatile       unsigned char	SSPBUF		@ 0x013;
//volatile       unsigned char	SSPCON		@ 0x014;
volatile       unsigned char	CCPR1L		@ 0x015;
volatile       unsigned char	CCPR1H		@ 0x016;
volatile       unsigned char	CCP1CON		@ 0x017;

volatile       unsigned char	COMPCON		@ 0x018;
volatile       unsigned char	COMPCON1	@ 0x019;
//volatile       unsigned char	RCREG		@ 0x01A;

volatile       unsigned char	CCPR2L		@ 0x01B;
volatile       unsigned char	CCPR2H		@ 0x01C;
volatile       unsigned char	CCP2CON		@ 0x01D;
volatile       unsigned char	ADRESH		@ 0x01E;
volatile       unsigned char	ADCON0		@ 0x01F;

//---------------------
volatile	   unsigned char	OPTION_REG	@ 0x081;
volatile       unsigned char	TRISA		@ 0x085;
volatile       unsigned char	TRISB		@ 0x086;
volatile       unsigned char	TRISC		@ 0x087;
volatile       unsigned char	TRISE		@ 0x089;
volatile       unsigned char	PIE1		@ 0x08C;
volatile	   unsigned char	PIE2		@ 0x08D;
//volatile	   unsigned char	PCON		@ 0x08E;
volatile       unsigned char	OSCCON		@ 0x08F;
volatile	   unsigned char	OSCTUNE		@ 0x090;
//volatile	   unsigned char	SSPCON2		@ 0x091;
volatile	   unsigned char	PR2		    @ 0x092;
//volatile	   unsigned char	SSPADD		@ 0x093;
//volatile       unsigned char	SSPSTAT		@ 0x094;
volatile	   unsigned char	WPUB		@ 0x095;
volatile	   unsigned char	IOCB		@ 0x096;
//volatile	   unsigned char	VRCON		@ 0x097;
//volatile	   unsigned char	TXSTA		@ 0x098;
//volatile	   unsigned char	SPBRG		@ 0x099;
//volatile	   unsigned char	SPBRGH		@ 0x09A;


volatile       unsigned char	ADRESL		@ 0x09E;
volatile	   unsigned char	ADCON1		@ 0x09F;


//-----------------------------
volatile       unsigned char	WDTCON		@ 0x105;
//volatile       unsigned char	CM1CON0		@ 0x107;
//volatile       unsigned char	CM2CON0		@ 0x108;
//volatile       unsigned char	CM2CON1		@ 0x109;

//volatile       unsigned char	EEDAT		@ 0x10C;
//volatile       unsigned char	EEDATA		@ 0x10C;
//volatile       unsigned char	EEADR		@ 0x10D;
//volatile       unsigned char	EEADRL		@ 0x10D;
//volatile       unsigned char	EEDATH		@ 0x10E;
//volatile       unsigned char	EEADRH		@ 0x10F;

volatile        unsigned char	TABLE_SPH	@ 0x110;
volatile        unsigned char	TABLE_SPL	@ 0x111;
volatile        unsigned char	TABLE_DATAH	@ 0x112;
volatile        unsigned char	KEYCON0		@ 0x113;
volatile        unsigned char	KEYCON1		@ 0x114;
volatile        unsigned char	KEYDATAL	@ 0x115;
volatile        unsigned char	KEYDATAH	@ 0x116;
//volatile        unsigned char	C1ADJ		@ 0x117;
//volatile        unsigned char	C2ADJ		@ 0x118;
//volatile        unsigned char	OPA0CON		@ 0x11C;
//volatile        unsigned char	OPA0ADJ		@ 0x11D;
volatile       unsigned char	WPUE		@ 0x11A;
volatile       unsigned char	OPA0CON		@ 0x11C;
volatile       unsigned char	OPA0ADJ		@ 0x11D;

//----------------------------
//volatile		unsigned char	BAUDCTL		@ 0x187;
volatile	    unsigned char	ANSEL		@ 0x188;
volatile	    unsigned char	ANSELH		@ 0x189;

//volatile		unsigned char	EECON1		@ 0x18C;
//volatile		unsigned char	EECON2		@ 0x18D;
volatile		unsigned char	WPUA		@ 0x18E;
volatile		unsigned char	WPUC		@ 0x18F;

//volatile        unsigned char	LEDCON0		@ 0x190;
//volatile        unsigned char	LEDCON1		@ 0x191;
//volatile        unsigned char	LEDADD		@ 0x192;
//volatile        unsigned char	LEDDATA		@ 0x193;
volatile        unsigned char	LCDCON0		@ 0x190;
volatile        unsigned char	LCDCON1		@ 0x191;
//volatile        unsigned char	LCDADD		@ 0x192;
//volatile        unsigned char	LCDDATA		@ 0x193;
//volatile        unsigned char	SEGEN2		@ 0x194;
//volatile        unsigned char	SEGEN1		@ 0x195;
//volatile        unsigned char	SEGEN0		@ 0x196;
volatile        unsigned char	COMEN		@ 0x197;


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
volatile       bit	RB0		@ ((unsigned)&PORTB*8)+0;
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
volatile       bit	RC7		@ ((unsigned)&PORTC*8)+7;

/* Definitions for PORTE register */
volatile       bit	RE0		@ ((unsigned)&PORTE*8)+0;
volatile       bit	RE1		@ ((unsigned)&PORTE*8)+1;
volatile       bit	RE2		@ ((unsigned)&PORTE*8)+2;
volatile       bit	RE3		@ ((unsigned)&PORTE*8)+3;

/* Definitions for INTCON register */
volatile       bit	RBIF	@ ((unsigned)&INTCON*8)+0;
// Alternate definition for backward compatibility
volatile       bit	RABIF	@ ((unsigned)&INTCON*8)+0;
volatile	   bit	INTF	@ ((unsigned)&INTCON*8)+1;
volatile       bit	T0IF	@ ((unsigned)&INTCON*8)+2;
volatile	   bit	RBIE	@ ((unsigned)&INTCON*8)+3;
// Alternate definition for backward compatibility
volatile	   bit	RABIE	@ ((unsigned)&INTCON*8)+3;
volatile	   bit	INTE	@ ((unsigned)&INTCON*8)+4;
volatile	   bit	T0IE	@ ((unsigned)&INTCON*8)+5;
volatile	   bit	PEIE	@ ((unsigned)&INTCON*8)+6;
volatile       bit	GIE		@ ((unsigned)&INTCON*8)+7;

/* Definitions for PIR1 register */
volatile       bit	TMR1IF	@ ((unsigned)&PIR1*8)+0;
volatile       bit	TMR2IF	@ ((unsigned)&PIR1*8)+1;
volatile       bit	CCP1IF	@ ((unsigned)&PIR1*8)+2;
volatile       bit	SSPIF	@ ((unsigned)&PIR1*8)+3;
volatile       bit	TXIF	@ ((unsigned)&PIR1*8)+4;
volatile       bit	RCIF	@ ((unsigned)&PIR1*8)+5;
volatile       bit	ADIF	@ ((unsigned)&PIR1*8)+6;

/* Definitions for PIR2 register */
volatile       bit	CCP2IF	@ ((unsigned)&PIR2*8)+0;
volatile       bit	BCLIF	@ ((unsigned)&PIR2*8)+3;
volatile       bit	EEIF	@ ((unsigned)&PIR2*8)+4;
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
volatile       bit	DC2B0	@ ((unsigned)&CCP2CON*8)+4;
volatile       bit	DC2B1	@ ((unsigned)&CCP2CON*8)+5;
volatile       bit	CCP2IN0	@ ((unsigned)&CCP2CON*8)+6;
volatile       bit	CCP2IN1	@ ((unsigned)&CCP2CON*8)+7;

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
volatile	   bit	INTEDG	@ ((unsigned)&OPTION_REG*8)+6;
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
volatile       bit	TRISB0	@ ((unsigned)&TRISB*8)+0;
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
volatile       bit	TRISC7	@ ((unsigned)&TRISC*8)+7;


/* Definitions for TRISE register */
volatile       bit	TRISE0	@ ((unsigned)&TRISE*8)+0;
volatile       bit	TRISE1	@ ((unsigned)&TRISE*8)+1;
volatile       bit	TRISE2	@ ((unsigned)&TRISE*8)+2;
volatile       bit	TRISE3	@ ((unsigned)&TRISE*8)+3;

/* Definitions for PIE1 register */
volatile	   bit	TMR1IE	@ ((unsigned)&PIE1*8)+0;
volatile	   bit	TMR2IE	@ ((unsigned)&PIE1*8)+1;
volatile	   bit	CCP1IE	@ ((unsigned)&PIE1*8)+2;
volatile	   bit	SSPIE	@ ((unsigned)&PIE1*8)+3;
volatile	   bit	TXIE	@ ((unsigned)&PIE1*8)+4;
volatile	   bit	RCIE	@ ((unsigned)&PIE1*8)+5;
volatile	   bit	ADIE	@ ((unsigned)&PIE1*8)+6;

/* Definitions for PIE2 register */
volatile	   bit	CCP2IE	@ ((unsigned)&PIE2*8)+0;
volatile	   bit	BCLIE	@ ((unsigned)&PIE2*8)+3;
volatile	   bit	EEIE	@ ((unsigned)&PIE2*8)+4;
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

/* Definitions for WPUA register */
volatile	   bit	WPUA0	@ ((unsigned)&WPUA*8)+0;
volatile	   bit	WPUA1	@ ((unsigned)&WPUA*8)+1;
volatile	   bit	WPUA2	@ ((unsigned)&WPUA*8)+2;
volatile	   bit	WPUA3	@ ((unsigned)&WPUA*8)+3;
volatile	   bit	WPUA4	@ ((unsigned)&WPUA*8)+4;
volatile	   bit	WPUA5	@ ((unsigned)&WPUA*8)+5;
volatile	   bit	WPUA6	@ ((unsigned)&WPUA*8)+6;
volatile	   bit	WPUA7	@ ((unsigned)&WPUA*8)+7;

/* Definitions for WPUB register */
volatile	   bit	WPUB0	@ ((unsigned)&WPUB*8)+0;
volatile	   bit	WPUB1	@ ((unsigned)&WPUB*8)+1;
volatile	   bit	WPUB2	@ ((unsigned)&WPUB*8)+2;
volatile	   bit	WPUB3	@ ((unsigned)&WPUB*8)+3;
volatile	   bit	WPUB4	@ ((unsigned)&WPUB*8)+4;
volatile	   bit	WPUB5	@ ((unsigned)&WPUB*8)+5;
volatile	   bit	WPUB6	@ ((unsigned)&WPUB*8)+6;
volatile	   bit	WPUB7	@ ((unsigned)&WPUB*8)+7;

/* Definitions for WPUC register */
volatile	   bit	WPUC0	@ ((unsigned)&WPUC*8)+0;
volatile	   bit	WPUC1	@ ((unsigned)&WPUC*8)+1;
volatile	   bit	WPUC2	@ ((unsigned)&WPUC*8)+2;
volatile	   bit	WPUC3	@ ((unsigned)&WPUC*8)+3;
volatile	   bit	WPUC4	@ ((unsigned)&WPUC*8)+4;
volatile	   bit	WPUC5	@ ((unsigned)&WPUC*8)+5;
volatile	   bit	WPUC6	@ ((unsigned)&WPUC*8)+6;

/* Definitions for WPUE register */
volatile	   bit	WPUE0	@ ((unsigned)&WPUE*8)+0;
volatile	   bit	WPUE1	@ ((unsigned)&WPUE*8)+1;
volatile	   bit	WPUE2	@ ((unsigned)&WPUE*8)+2;
volatile	   bit	WPUE3	@ ((unsigned)&WPUE*8)+3;

/* Definitions for IOCB register */
volatile	   bit	IOCB0	@ ((unsigned)&IOCB*8)+0;
volatile	   bit	IOCB1	@ ((unsigned)&IOCB*8)+1;
volatile	   bit	IOCB2	@ ((unsigned)&IOCB*8)+2;
volatile	   bit	IOCB3	@ ((unsigned)&IOCB*8)+3;
volatile	   bit	IOCB4	@ ((unsigned)&IOCB*8)+4;
volatile	   bit	IOCB5	@ ((unsigned)&IOCB*8)+5;
volatile	   bit	IOCB6	@ ((unsigned)&IOCB*8)+6;
volatile	   bit	IOCB7	@ ((unsigned)&IOCB*8)+7;

/* Definitions for VRCON register */
/*
volatile	   bit	VR0		@ ((unsigned)&VRCON*8)+0;
volatile	   bit	VR1		@ ((unsigned)&VRCON*8)+1;
volatile	   bit	VR2		@ ((unsigned)&VRCON*8)+2;
volatile	   bit	VR3		@ ((unsigned)&VRCON*8)+3;
volatile	   bit	VRSS	@ ((unsigned)&VRCON*8)+4;
volatile	   bit	VRR		@ ((unsigned)&VRCON*8)+5;
volatile	   bit	VROE	@ ((unsigned)&VRCON*8)+6;
volatile	   bit	VREN	@ ((unsigned)&VRCON*8)+7;
*/


/* Definitions for ADCON1 register */
volatile	   bit	ADFM	@ ((unsigned)&ADCON1*8)+7;

/* Definitions for WDTCON register */
volatile	   bit	WDTPS0	@ ((unsigned)&WDTCON*8)+1;
volatile	   bit	WDTPS1	@ ((unsigned)&WDTCON*8)+2;
volatile	   bit	WDTPS2	@ ((unsigned)&WDTCON*8)+3;
volatile	   bit	WDTPS3	@ ((unsigned)&WDTCON*8)+4;



/* Definitions for ANSEL register */
volatile	   bit	ANS0	@ ((unsigned)&ANSEL*8)+0;
volatile	   bit	ANS1	@ ((unsigned)&ANSEL*8)+1;
volatile	   bit	ANS2	@ ((unsigned)&ANSEL*8)+2;
volatile	   bit	ANS3	@ ((unsigned)&ANSEL*8)+3;
volatile	   bit	ANS4	@ ((unsigned)&ANSEL*8)+4;
volatile	   bit	ANS5	@ ((unsigned)&ANSEL*8)+5;
volatile	   bit	ANS6	@ ((unsigned)&ANSEL*8)+6;
volatile	   bit	ANS7	@ ((unsigned)&ANSEL*8)+7;

/* Definitions for ANSELH register */
volatile	   bit	ANS8	@ ((unsigned)&ANSELH*8)+0;
volatile	   bit	ANS9	@ ((unsigned)&ANSELH*8)+1;
volatile	   bit	ANS10	@ ((unsigned)&ANSELH*8)+2;
volatile	   bit	ANS11	@ ((unsigned)&ANSELH*8)+3;
volatile	   bit	ANS12	@ ((unsigned)&ANSELH*8)+4;
volatile	   bit	ANS13	@ ((unsigned)&ANSELH*8)+5;

/* Definitions for KEYCON0 register */
volatile		bit KEN		@ ((unsigned)&KEYCON0*8)+0;
volatile		bit KCAP	@ ((unsigned)&KEYCON0*8)+1;
volatile		bit KTOUT	@ ((unsigned)&KEYCON0*8)+2;
volatile		bit CAPK0	@ ((unsigned)&KEYCON0*8)+3;
volatile		bit CAPK1	@ ((unsigned)&KEYCON0*8)+4;
volatile		bit CAPK2	@ ((unsigned)&KEYCON0*8)+5;
volatile		bit KDONE	@ ((unsigned)&KEYCON0*8)+7;

/* Definitions for KEYCON1 register */
volatile		bit KCHS0	@ ((unsigned)&KEYCON0*8)+0;
volatile		bit KCHS1	@ ((unsigned)&KEYCON0*8)+1;
volatile		bit KCHS2	@ ((unsigned)&KEYCON0*8)+2;
volatile		bit KCHS3	@ ((unsigned)&KEYCON0*8)+3;
volatile		bit KCLK0	@ ((unsigned)&KEYCON0*8)+4;
volatile		bit KCLK1	@ ((unsigned)&KEYCON0*8)+5;
volatile		bit KVREF0	@ ((unsigned)&KEYCON0*8)+6;
volatile		bit KVREF1	@ ((unsigned)&KEYCON0*8)+7;


#endif
