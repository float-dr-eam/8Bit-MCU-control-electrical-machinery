
#ifndef	_HTC_H_
#warning Header file SC8P1153.h included directly. Use #include <sc.h> instead.
#endif

#ifndef	__SC8P1153_H
#define	__SC8P1153_H

// Special function register definitions
volatile unsigned char	INDF			@0x0000;
volatile unsigned char	TMR0			@0x0001;
volatile unsigned char	PCL				@0x0002;
volatile unsigned char	STATUS			@0x0003;
volatile unsigned char	FSR				@0x0004;
volatile unsigned char	PORTB			@0x0005;
volatile unsigned char	TRISB			@0x0006;
volatile unsigned char	OPTION_REG		@0x0007;
volatile unsigned char	OSCCON			@0x0008;
volatile unsigned char	INTCON			@0x0009;
volatile unsigned char	PCLATH			@0x000A;
volatile unsigned char	PDCONB			@0x000B;
volatile unsigned char	ODCONB			@0x000C;
volatile unsigned char	WPUB			@0x000D;
volatile unsigned char	IOCB			@0x000E;
volatile unsigned char	TMR0PRD			@0x000F;
volatile unsigned char	PWMCTR0			@0x0010;
volatile unsigned char	PWMCTR1			@0x0011;
volatile unsigned char	PWMCTR2			@0x0012;
volatile unsigned char	PWMR			@0x0013;
volatile unsigned char	PWM_PRD			@0x0014;
volatile unsigned char	PWMPRD			@0x0014;

#if defined(_SC8P1153) || defined(_SC8P1153A) 
volatile unsigned char	DTCON			@0x0015;
volatile unsigned char	DTREG			@0x0016;
volatile unsigned char	PORTA			@0x0017;
volatile unsigned char	TRISA			@0x0018;
volatile unsigned char	UPDOWNA			@0x0019;
#endif


/* Definitions for STATUS register */
volatile bit	TO			@ ((unsigned)&STATUS*8)+4;
volatile bit	PD			@ ((unsigned)&STATUS*8)+3;
volatile bit	ZERO		@ ((unsigned)&STATUS*8)+2;
volatile bit	Z			@ ((unsigned)&STATUS*8)+2;
volatile bit	DC			@ ((unsigned)&STATUS*8)+1;
volatile bit	CARRY		@ ((unsigned)&STATUS*8)+0;
volatile bit	C			@ ((unsigned)&STATUS*8)+0;

/* Definitions for PORTB register */
volatile bit	PB7			@ ((unsigned)&PORTB*8)+7;
volatile bit	PB6			@ ((unsigned)&PORTB*8)+6;
volatile bit	PB5			@ ((unsigned)&PORTB*8)+5;
volatile bit	PB4			@ ((unsigned)&PORTB*8)+4;
volatile bit	PB3			@ ((unsigned)&PORTB*8)+3;
volatile bit	PB2			@ ((unsigned)&PORTB*8)+2;
volatile bit	PB1			@ ((unsigned)&PORTB*8)+1;
volatile bit	PB0			@ ((unsigned)&PORTB*8)+0;

/* Definitions for PORTB register */
volatile bit	PORTB7		@ ((unsigned)&PORTB*8)+7;
volatile bit	PORTB6		@ ((unsigned)&PORTB*8)+6;
volatile bit	PORTB5		@ ((unsigned)&PORTB*8)+5;
volatile bit	PORTB4		@ ((unsigned)&PORTB*8)+4;
volatile bit	PORTB3		@ ((unsigned)&PORTB*8)+3;
volatile bit	PORTB2		@ ((unsigned)&PORTB*8)+2;
volatile bit	PORTB1		@ ((unsigned)&PORTB*8)+1;
volatile bit	PORTB0		@ ((unsigned)&PORTB*8)+0;

/* Definitions for TRISB register */
volatile bit	TRISB7		@ ((unsigned)&TRISB*8)+7;
volatile bit	TRISB6		@ ((unsigned)&TRISB*8)+6;
volatile bit	TRISB5		@ ((unsigned)&TRISB*8)+5;
volatile bit	TRISB4		@ ((unsigned)&TRISB*8)+4;
volatile bit	TRISB3		@ ((unsigned)&TRISB*8)+3;
volatile bit	TRISB2		@ ((unsigned)&TRISB*8)+2;
volatile bit	TRISB1		@ ((unsigned)&TRISB*8)+1;
volatile bit	TRISB0		@ ((unsigned)&TRISB*8)+0;

/* Definitions for OPTION_REG register */
volatile bit	XT_EN		@ ((unsigned)&OPTION_REG*8)+7;
volatile bit	T0SYNC		@ ((unsigned)&OPTION_REG*8)+6;
volatile bit	T0CS		@ ((unsigned)&OPTION_REG*8)+5;
volatile bit	T0SE		@ ((unsigned)&OPTION_REG*8)+4;
volatile bit	PSA			@ ((unsigned)&OPTION_REG*8)+3;
volatile bit	PS2			@ ((unsigned)&OPTION_REG*8)+2;
volatile bit	PS1			@ ((unsigned)&OPTION_REG*8)+1;
volatile bit	PS0			@ ((unsigned)&OPTION_REG*8)+0;

/* Definitions for OSCCON register */
volatile bit	SWDTEN		@ ((unsigned)&OSCCON*8)+7;
volatile bit	IRCF2		@ ((unsigned)&OSCCON*8)+6;
volatile bit	IRCF1		@ ((unsigned)&OSCCON*8)+5;
volatile bit	IRCF0		@ ((unsigned)&OSCCON*8)+4;
volatile bit	TMR2EN		@ ((unsigned)&OSCCON*8)+0;
volatile bit	TMR0EN		@ ((unsigned)&OSCCON*8)+0;

/* Definitions for INTCON register */
volatile bit	GIE			@ ((unsigned)&INTCON*8)+7;
volatile bit	INTEG		@ ((unsigned)&INTCON*8)+6;
volatile bit	T0IE		@ ((unsigned)&INTCON*8)+5;
volatile bit	INTE		@ ((unsigned)&INTCON*8)+4;
volatile bit	RBIE		@ ((unsigned)&INTCON*8)+3;
volatile bit	PBIE		@ ((unsigned)&INTCON*8)+3;

volatile bit	T0IF		@ ((unsigned)&INTCON*8)+2;
volatile bit	INTF		@ ((unsigned)&INTCON*8)+1;
volatile bit	RBIF		@ ((unsigned)&INTCON*8)+0;
volatile bit	PBIF		@ ((unsigned)&INTCON*8)+0;

/* Definitions for PDCONB register */
volatile bit	PDCONB7		@ ((unsigned)&PDCONB*8)+7;
volatile bit	PDCONB6		@ ((unsigned)&PDCONB*8)+6;
volatile bit	PDCONB5		@ ((unsigned)&PDCONB*8)+5;
volatile bit	PDCONB4		@ ((unsigned)&PDCONB*8)+4;
volatile bit	PDCONB2		@ ((unsigned)&PDCONB*8)+2;
volatile bit	PDCONB1		@ ((unsigned)&PDCONB*8)+1;
volatile bit	PDCONB0		@ ((unsigned)&PDCONB*8)+0;


/* Definitions for ODCONB register */
volatile bit	ODCONB7		@ ((unsigned)&ODCONB*8)+7;
volatile bit	ODCONB6		@ ((unsigned)&ODCONB*8)+6;
volatile bit	ODCONB5		@ ((unsigned)&ODCONB*8)+5;
volatile bit	ODCONB4		@ ((unsigned)&ODCONB*8)+4;
volatile bit	ODCONB2		@ ((unsigned)&ODCONB*8)+2;
volatile bit	ODCONB1		@ ((unsigned)&ODCONB*8)+1;
volatile bit	ODCONB0		@ ((unsigned)&ODCONB*8)+0;

/* Definitions for WPUB register */
volatile bit	WPUB7		@ ((unsigned)&WPUB*8)+7;
volatile bit	WPUB6		@ ((unsigned)&WPUB*8)+6;
volatile bit	WPUB5		@ ((unsigned)&WPUB*8)+5;
volatile bit	WPUB4		@ ((unsigned)&WPUB*8)+4;
volatile bit	WPUB3		@ ((unsigned)&WPUB*8)+3;
volatile bit	WPUB2		@ ((unsigned)&WPUB*8)+2;
volatile bit	WPUB1		@ ((unsigned)&WPUB*8)+1;
volatile bit	WPUB0		@ ((unsigned)&WPUB*8)+0;

/* Definitions for IOCB register */
volatile bit	IOCB7		@ ((unsigned)&IOCB*8)+7;
volatile bit	IOCB6		@ ((unsigned)&IOCB*8)+6;
volatile bit	IOCB5		@ ((unsigned)&IOCB*8)+5;
volatile bit	IOCB4		@ ((unsigned)&IOCB*8)+4;
volatile bit	IOCB3		@ ((unsigned)&IOCB*8)+3;
volatile bit	IOCB2		@ ((unsigned)&IOCB*8)+2;
volatile bit	IOCB1		@ ((unsigned)&IOCB*8)+1;
volatile bit	IOCB0		@ ((unsigned)&IOCB*8)+0;

/* Definitions for PWMCTR0 register */
volatile bit	PWMR49		@ ((unsigned)&PWMCTR0*8)+7;
volatile bit	PWMR48		@ ((unsigned)&PWMCTR0*8)+6;
volatile bit	PWM4EN		@ ((unsigned)&PWMCTR0*8)+4;
volatile bit	PWM3EN		@ ((unsigned)&PWMCTR0*8)+3;
volatile bit	PWM2EN		@ ((unsigned)&PWMCTR0*8)+2;
volatile bit	PWM1EN		@ ((unsigned)&PWMCTR0*8)+1;
volatile bit	PWM0EN		@ ((unsigned)&PWMCTR0*8)+0;

volatile bit	PWMEN4		@ ((unsigned)&PWMCTR0*8)+4;
volatile bit	PWMEN3		@ ((unsigned)&PWMCTR0*8)+3;
volatile bit	PWMEN2		@ ((unsigned)&PWMCTR0*8)+2;
volatile bit	PWMEN1		@ ((unsigned)&PWMCTR0*8)+1;
volatile bit	PWMEN0		@ ((unsigned)&PWMCTR0*8)+0;

/* Definitions for PWMCTR1 register */
volatile bit	PWMR39		@ ((unsigned)&PWMCTR1*8)+7;
volatile bit	PWMR38		@ ((unsigned)&PWMCTR1*8)+6;
volatile bit	PWMR29		@ ((unsigned)&PWMCTR1*8)+5;
volatile bit	PWMR28		@ ((unsigned)&PWMCTR1*8)+4;
volatile bit	PWMR19		@ ((unsigned)&PWMCTR1*8)+3;
volatile bit	PWMR18		@ ((unsigned)&PWMCTR1*8)+2;
volatile bit	PWMR09		@ ((unsigned)&PWMCTR1*8)+1;
volatile bit	PWMR08		@ ((unsigned)&PWMCTR1*8)+0;

/* Definitions for PWMCTR2 register */
volatile bit	PWMPRD9		@ ((unsigned)&PWMCTR2*8)+7;
volatile bit	PWMPRD8		@ ((unsigned)&PWMCTR2*8)+6;
volatile bit	T2CKPS1		@ ((unsigned)&PWMCTR2*8)+5;
volatile bit	T2CKPS0		@ ((unsigned)&PWMCTR2*8)+4;
volatile bit	SEL2		@ ((unsigned)&PWMCTR2*8)+2;
volatile bit	SEL1		@ ((unsigned)&PWMCTR2*8)+1;
volatile bit	SEL0		@ ((unsigned)&PWMCTR2*8)+0;

volatile bit	PWMCK1		@ ((unsigned)&PWMCTR2*8)+5;
volatile bit	PWMCK0		@ ((unsigned)&PWMCTR2*8)+4;
volatile bit	PWMS2		@ ((unsigned)&PWMCTR2*8)+2;
volatile bit	PWMS1		@ ((unsigned)&PWMCTR2*8)+1;
volatile bit	PWMS0		@ ((unsigned)&PWMCTR2*8)+0;

#if defined(_SC8P1153) || defined(_SC8P1153A) 
/* Definitions for DTCON register */
volatile bit	DTSEL1		@ ((unsigned)&DTCON*8)+7;
volatile bit	DTSEL0		@ ((unsigned)&DTCON*8)+6;
volatile bit	DTSEL		@ ((unsigned)&DTCON*8)+6;
volatile bit	ENDT1		@ ((unsigned)&DTCON*8)+3;
volatile bit	ENDT0		@ ((unsigned)&DTCON*8)+2;
volatile bit	ENCM1		@ ((unsigned)&DTCON*8)+1;
volatile bit	ENCM0		@ ((unsigned)&DTCON*8)+0;

/* Definitions for PORTA register */
volatile bit	PA3			@ ((unsigned)&PORTA*8)+3;
volatile bit	PA2			@ ((unsigned)&PORTA*8)+2;
volatile bit	PA1			@ ((unsigned)&PORTA*8)+1;
volatile bit	PA0			@ ((unsigned)&PORTA*8)+0;

/* Definitions for PORTA register */
volatile bit	PORTA3		@ ((unsigned)&PORTA*8)+3;
volatile bit	PORTA2		@ ((unsigned)&PORTA*8)+2;
volatile bit	PORTA1		@ ((unsigned)&PORTA*8)+1;
volatile bit	PORTA0		@ ((unsigned)&PORTA*8)+0;

/* Definitions for TRISA register */
volatile bit	TRISA3		@ ((unsigned)&TRISA*8)+3;
volatile bit	TRISA2		@ ((unsigned)&TRISA*8)+2;
volatile bit	TRISA1		@ ((unsigned)&TRISA*8)+1;
volatile bit	TRISA0		@ ((unsigned)&TRISA*8)+0;

/* Definitions for UPDOWNA register */
volatile bit	WPUA3		@ ((unsigned)&UPDOWNA*8)+7;
volatile bit	WPUA2		@ ((unsigned)&UPDOWNA*8)+6;
volatile bit	WPUA1		@ ((unsigned)&UPDOWNA*8)+5;
volatile bit	WPUA0		@ ((unsigned)&UPDOWNA*8)+4;
volatile bit	PDCONA3		@ ((unsigned)&UPDOWNA*8)+3;
volatile bit	PDCONA2		@ ((unsigned)&UPDOWNA*8)+2;
volatile bit	PDCONA1		@ ((unsigned)&UPDOWNA*8)+1;
volatile bit	PDCONA0		@ ((unsigned)&UPDOWNA*8)+0;
#endif


#endif
