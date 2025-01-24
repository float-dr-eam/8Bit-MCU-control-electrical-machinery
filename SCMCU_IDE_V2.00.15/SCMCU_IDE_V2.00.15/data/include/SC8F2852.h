
#ifndef	_HTC_H_
#warning Header file sc8f2852.h included directly. Use #include <sc.h> instead.
#endif

 /* header file for the cms microcontroller
	SC8F2852
	SC8F2850
 */

#ifndef	__SC8F2852_H
#define	__SC8F2852_H

// Special function register definitions
//----- BANK0 Register -----------------------------------------------------
volatile		unsigned char	INDF		@ 0x000;
volatile		unsigned char	TMR0		@ 0x001;
volatile		unsigned char	PCL			@ 0x002;
volatile		unsigned char	STATUS		@ 0x003;
volatile		unsigned char	FSR			@ 0x004;
volatile		unsigned char	PORTA		@ 0x005;
volatile		unsigned char	PORTB		@ 0x006;
volatile		unsigned char	WPUA		@ 0x007;
volatile		unsigned char	WPUB		@ 0x008;
volatile		unsigned char	IOCB		@ 0x009;
volatile		unsigned char	PCLATH		@ 0x00A;
volatile		unsigned char	INTCON		@ 0x00B;
volatile		unsigned char	PIR1		@ 0x00C;
volatile		unsigned char	PIE1		@ 0x00D;
volatile		unsigned char	PWMD23H		@ 0x00E;
volatile		unsigned char	PWM01DT		@ 0x00F;
volatile		unsigned char	PWM23DT		@ 0x010;
volatile		unsigned char	TMR2		@ 0x011;
volatile		unsigned char	T2CON		@ 0x012;
volatile		unsigned char	PWMCON0		@ 0x013;
volatile		unsigned char	PWMCON1		@ 0x014;
volatile		unsigned char	PWMTL		@ 0x015;
volatile		unsigned char	PWMTH		@ 0x016;
volatile		unsigned char	PWMD0L		@ 0x017;
volatile		unsigned char	PWMD1L		@ 0x018;
volatile		unsigned char	PWMD2L		@ 0x019;
volatile		unsigned char	PWMD3L		@ 0x01A;
volatile		unsigned char	PWMD4L		@ 0x01B;
volatile		unsigned char	PWMD01H		@ 0x01C;
volatile		unsigned char	PWMCON2		@ 0x01D;

//----- BANK0 Register -----------------------------------------------------
//volatile		unsigned char	INDF		@ 0x080;
volatile		unsigned char	OPTION_REG	@ 0x081;
//volatile		unsigned char	PCL			@ 0x082;
//volatile		unsigned char	STATUS		@ 0x083;
//volatile		unsigned char	FSR			@ 0x084;
volatile		unsigned char	TRISA		@ 0x085;
volatile		unsigned char	TRISB		@ 0x086;
volatile		unsigned char	WPDB		@ 0x087;
volatile		unsigned char	OSCCON		@ 0x088;

//volatile		unsigned char	PCLATH		@ 0x08A;
//volatile		unsigned char	INTCON		@ 0x08B;

volatile		unsigned char	PR2			@ 0x091;
volatile		unsigned char	KEYCON0		@ 0x092;
volatile		unsigned char	KEYCON1		@ 0x093;
volatile		unsigned char	KEYDATAL	@ 0x094;
volatile		unsigned char	KEYDATAH	@ 0x095;
volatile		unsigned char	EEADRH		@ 0x096;


volatile		unsigned char	ADCON1		@ 0x09C;
volatile		unsigned char	ADCON0		@ 0x09D;
volatile		unsigned char	ADRESL		@ 0x09E;
volatile		unsigned char	ADRESH		@ 0x09F;

//**************************************************************************
//----- BANK0 Register -----------------------------------------------------
/* Definitions for STATUS register */
volatile		bit	IRP		@ ((unsigned)&STATUS*8)+7;
volatile		bit	RP1		@ ((unsigned)&STATUS*8)+6;
volatile		bit	RP0		@ ((unsigned)&STATUS*8)+5;
volatile		bit	TO		@ ((unsigned)&STATUS*8)+4;
volatile		bit	PD		@ ((unsigned)&STATUS*8)+3;
volatile		bit	Z		@ ((unsigned)&STATUS*8)+2;
volatile		bit	DC		@ ((unsigned)&STATUS*8)+1;
volatile		bit	C		@ ((unsigned)&STATUS*8)+0;

/* Definitions for PORTA register */
volatile		bit	RA5		@ ((unsigned)&PORTA*8)+5;
volatile		bit	RA4		@ ((unsigned)&PORTA*8)+4;
volatile		bit	RA3		@ ((unsigned)&PORTA*8)+3;
volatile		bit	RA2		@ ((unsigned)&PORTA*8)+2;
volatile		bit	RA1		@ ((unsigned)&PORTA*8)+1;
volatile		bit	RA0		@ ((unsigned)&PORTA*8)+0;

/* Definitions for PORTB register */
volatile		bit	RB7		@ ((unsigned)&PORTB*8)+7;
volatile		bit	RB6		@ ((unsigned)&PORTB*8)+6;
volatile		bit	RB5		@ ((unsigned)&PORTB*8)+5;
volatile		bit	RB4		@ ((unsigned)&PORTB*8)+4;
volatile		bit	RB3		@ ((unsigned)&PORTB*8)+3;
volatile		bit	RB2		@ ((unsigned)&PORTB*8)+2;
volatile		bit	RB1		@ ((unsigned)&PORTB*8)+1;
volatile		bit	RB0		@ ((unsigned)&PORTB*8)+0;

/* Definitions for WPUA register */
volatile		bit	WPUA5		@ ((unsigned)&WPUA*8)+5;
volatile		bit	WPUA4		@ ((unsigned)&WPUA*8)+4;
volatile		bit	WPUA3		@ ((unsigned)&WPUA*8)+3;
volatile		bit	WPUA2		@ ((unsigned)&WPUA*8)+2;
volatile		bit	WPUA1		@ ((unsigned)&WPUA*8)+1;
volatile		bit	WPUA0		@ ((unsigned)&WPUA*8)+0;

/* Definitions for WPUB register */
volatile		bit	WPUB7		@ ((unsigned)&WPUB*8)+7;
volatile		bit	WPUB6		@ ((unsigned)&WPUB*8)+6;
volatile		bit	WPUB5		@ ((unsigned)&WPUB*8)+5;
volatile		bit	WPUB4		@ ((unsigned)&WPUB*8)+4;
volatile		bit	WPUB3		@ ((unsigned)&WPUB*8)+3;
volatile		bit	WPUB2		@ ((unsigned)&WPUB*8)+2;
volatile		bit	WPUB1		@ ((unsigned)&WPUB*8)+1;
volatile		bit	WPUB0		@ ((unsigned)&WPUB*8)+0;

/* Definitions for IOCB register */
volatile		bit	IOCB7		@ ((unsigned)&IOCB*8)+7;
volatile		bit	IOCB6		@ ((unsigned)&IOCB*8)+6;
volatile		bit	IOCB5		@ ((unsigned)&IOCB*8)+5;
volatile		bit	IOCB4		@ ((unsigned)&IOCB*8)+4;
volatile		bit	IOCB3		@ ((unsigned)&IOCB*8)+3;
volatile		bit	IOCB2		@ ((unsigned)&IOCB*8)+2;
volatile		bit	IOCB1		@ ((unsigned)&IOCB*8)+1;
volatile		bit	IOCB0		@ ((unsigned)&IOCB*8)+0;


/* Definitions for INTCON register */
volatile		bit	GIE		@ ((unsigned)&INTCON*8)+7;
volatile		bit	PEIE	@ ((unsigned)&INTCON*8)+6;
volatile		bit	T0IE	@ ((unsigned)&INTCON*8)+5;
volatile		bit	INTE	@ ((unsigned)&INTCON*8)+4;

volatile		bit	RABIE	@ ((unsigned)&INTCON*8)+3;
volatile		bit	RBIE	@ ((unsigned)&INTCON*8)+3;

volatile		bit	T0IF	@ ((unsigned)&INTCON*8)+2;
volatile		bit	INTF	@ ((unsigned)&INTCON*8)+1;

volatile		bit	RBIF	@ ((unsigned)&INTCON*8)+0;
volatile		bit	RABIF	@ ((unsigned)&INTCON*8)+0;

/* Definitions for PIR1 register */
volatile		bit	PWMIF	@ ((unsigned)&PIR1*8)+2;
volatile		bit	TMR2IF	@ ((unsigned)&PIR1*8)+1;
volatile		bit	ADIF	@ ((unsigned)&PIR1*8)+0;

/* Definitions for PIE1 register */
volatile		bit	PWMIE	@ ((unsigned)&PIE1*8)+2;
volatile		bit	TMR2IE	@ ((unsigned)&PIE1*8)+1;
volatile		bit	ADIE	@ ((unsigned)&PIE1*8)+0;

/* Definitions for PWMD23H register */
volatile		bit	PWMD39	@ ((unsigned)&PWMD23H*8)+5;
volatile		bit	PWMD38	@ ((unsigned)&PWMD23H*8)+4;

volatile		bit	PWMD29	@ ((unsigned)&PWMD23H*8)+1;
volatile		bit PWMD28	@ ((unsigned)&PWMD23H*8)+0;

/* Definitions for T2CON register */
volatile		bit	CLK_SEL	@ ((unsigned)&T2CON*8)+7;
volatile		bit	TOUTPS3	@ ((unsigned)&T2CON*8)+6;
volatile		bit	TOUTPS2	@ ((unsigned)&T2CON*8)+5;
volatile		bit	TOUTPS1	@ ((unsigned)&T2CON*8)+4;
volatile		bit	TOUTPS0	@ ((unsigned)&T2CON*8)+3;
volatile		bit	TMR2ON	@ ((unsigned)&T2CON*8)+2;
volatile		bit	T2CKPS1	@ ((unsigned)&T2CON*8)+1;
volatile		bit	T2CKPS0	@ ((unsigned)&T2CON*8)+0;

/* Definitions for PWMCON0 register */
volatile		bit	CLKDIV2	@ ((unsigned)&PWMCON0*8)+7;
volatile		bit	CLKDIV1	@ ((unsigned)&PWMCON0*8)+6;
volatile		bit	CLKDIV0	@ ((unsigned)&PWMCON0*8)+5;
volatile		bit	PWM4EN	@ ((unsigned)&PWMCON0*8)+4;
volatile		bit	PWM3EN	@ ((unsigned)&PWMCON0*8)+3;
volatile		bit	PWM2EN	@ ((unsigned)&PWMCON0*8)+2;
volatile		bit	PWM1EN	@ ((unsigned)&PWMCON0*8)+1;
volatile		bit PWM0EN	@ ((unsigned)&PWMCON0*8)+0;

/* Definitions for PWMCON1 register */
volatile		bit	PWMIO_SEL1	@ ((unsigned)&PWMCON1*8)+7;
volatile		bit	PWMIO_SEL0	@ ((unsigned)&PWMCON1*8)+6;
volatile		bit	PWM2DTEN	@ ((unsigned)&PWMCON1*8)+5;
volatile		bit	PWM0DETN	@ ((unsigned)&PWMCON1*8)+4;

volatile		bit	DT_DIV1		@ ((unsigned)&PWMCON1*8)+1;
volatile		bit DT_DIV0		@ ((unsigned)&PWMCON1*8)+0;


/* Definitions for PWMD01H register */
volatile		bit	PWMD19	@ ((unsigned)&PWMD01H*8)+5;
volatile		bit	PWMD18	@ ((unsigned)&PWMD01H*8)+4;

volatile		bit	PWMD09	@ ((unsigned)&PWMD01H*8)+1;
volatile		bit PWMD08	@ ((unsigned)&PWMD01H*8)+0;

/* Definitions for PWMCON2 register */
volatile		bit	PWM4DIR	@ ((unsigned)&PWMCON2*8)+4;
volatile		bit PWM3DIR	@ ((unsigned)&PWMCON2*8)+3;
volatile		bit	PWM2DIR	@ ((unsigned)&PWMCON2*8)+2;
volatile		bit	PWM1DIR	@ ((unsigned)&PWMCON2*8)+1;
volatile		bit PWM0DIR	@ ((unsigned)&PWMCON2*8)+0;

//**************************************************************************
//----- BANK1 Register -----------------------------------------------------
/* Definitions for OPTION_REG register */
volatile		bit	RBPU	@ ((unsigned)&OPTION_REG*8)+7;
volatile		bit	INTEDG	@ ((unsigned)&OPTION_REG*8)+6;
volatile		bit	T0CS	@ ((unsigned)&OPTION_REG*8)+5;
volatile		bit	T0SE	@ ((unsigned)&OPTION_REG*8)+4;
volatile		bit	PSA 	@ ((unsigned)&OPTION_REG*8)+3;
volatile		bit	PS2 	@ ((unsigned)&OPTION_REG*8)+2;
volatile		bit	PS1 	@ ((unsigned)&OPTION_REG*8)+1;
volatile		bit	PS0 	@ ((unsigned)&OPTION_REG*8)+0;


/* Definitions for TRISA register */
volatile		bit	TRISA5	@ ((unsigned)&TRISA*8)+5;
volatile		bit	TRISA4	@ ((unsigned)&TRISA*8)+4;
volatile		bit	TRISA3	@ ((unsigned)&TRISA*8)+3;
volatile		bit	TRISA2	@ ((unsigned)&TRISA*8)+2;
volatile		bit	TRISA1	@ ((unsigned)&TRISA*8)+1;
volatile		bit	TRISA0	@ ((unsigned)&TRISA*8)+0;

/* Definitions for TRISB register */
volatile		bit	TRISB7	@ ((unsigned)&TRISB*8)+7;
volatile		bit	TRISB6	@ ((unsigned)&TRISB*8)+6;
volatile		bit	TRISB5	@ ((unsigned)&TRISB*8)+5;
volatile		bit	TRISB4	@ ((unsigned)&TRISB*8)+4;
volatile		bit	TRISB3	@ ((unsigned)&TRISB*8)+3;
volatile		bit	TRISB2	@ ((unsigned)&TRISB*8)+2;
volatile		bit	TRISB1	@ ((unsigned)&TRISB*8)+1;
volatile		bit	TRISB0	@ ((unsigned)&TRISB*8)+0;

/* Definitions for WPDB register */
volatile		bit	WPDB7	@ ((unsigned)&WPDB*8)+7;
volatile		bit	WPDB6	@ ((unsigned)&WPDB*8)+6;
volatile		bit	WPDB5	@ ((unsigned)&WPDB*8)+5;
volatile		bit	WPDB4	@ ((unsigned)&WPDB*8)+4;
volatile		bit	WPDB3	@ ((unsigned)&WPDB*8)+3;
volatile		bit	WPDB2	@ ((unsigned)&WPDB*8)+2;
volatile		bit	WPDB1	@ ((unsigned)&WPDB*8)+1;
volatile		bit	WPDB0	@ ((unsigned)&WPDB*8)+0;

/* Definitions for OSCCON register */
volatile		bit	IRCF2	@ ((unsigned)&OSCCON*8)+6;
volatile		bit	IRCF1	@ ((unsigned)&OSCCON*8)+5;
volatile		bit	IRCF0	@ ((unsigned)&OSCCON*8)+4;
volatile		bit	SWDTEN	@ ((unsigned)&OSCCON*8)+1;

/* Definitions for KEYCON0 register */
volatile		bit	KDONE	@ ((unsigned)&KEYCON0*8)+7;

volatile		bit	CAPK2	@ ((unsigned)&KEYCON0*8)+5;
volatile		bit	CAPK1	@ ((unsigned)&KEYCON0*8)+4;
volatile		bit	CAPK0	@ ((unsigned)&KEYCON0*8)+3;
volatile		bit	KTOUT	@ ((unsigned)&KEYCON0*8)+2;
volatile		bit	KCAP	@ ((unsigned)&KEYCON0*8)+1;
volatile		bit	KEN		@ ((unsigned)&KEYCON0*8)+0;

/* Definitions for KEYCON1 register */
volatile		bit	KVREF1	@ ((unsigned)&KEYCON1*8)+7;
volatile		bit	KVREF0	@ ((unsigned)&KEYCON1*8)+6;
volatile		bit	KCLK1	@ ((unsigned)&KEYCON1*8)+5;
volatile		bit	KCLK0	@ ((unsigned)&KEYCON1*8)+4;
volatile		bit	KCHS3	@ ((unsigned)&KEYCON1*8)+3;
volatile		bit	KCHS2	@ ((unsigned)&KEYCON1*8)+2;
volatile		bit	KCHS1	@ ((unsigned)&KEYCON1*8)+1;
volatile		bit	KCHS0	@ ((unsigned)&KEYCON1*8)+0;

/* Definitions for ADCON1 register */
volatile		bit	ADFM	@ ((unsigned)&ADCON1*8)+7;
volatile		bit	LDO_EN	@ ((unsigned)&ADCON1*8)+2;
volatile		bit	LDO_SEL1	@ ((unsigned)&ADCON1*8)+1;
volatile		bit	LDO_SEL0	@ ((unsigned)&ADCON1*8)+0;

/* Definitions for ADCON0 register */
volatile		bit	ADCS1	@ ((unsigned)&ADCON0*8)+7;
volatile		bit	ADCS0	@ ((unsigned)&ADCON0*8)+6;
volatile		bit	CHS3	@ ((unsigned)&ADCON0*8)+5;
volatile		bit	CHS2	@ ((unsigned)&ADCON0*8)+4;
volatile		bit	CHS1	@ ((unsigned)&ADCON0*8)+3;
volatile		bit	CHS0	@ ((unsigned)&ADCON0*8)+2;
volatile		bit	GODONE	@ ((unsigned)&ADCON0*8)+1;
volatile		bit	ADON	@ ((unsigned)&ADCON0*8)+0;

#endif
