#ifndef _HTC_H_
#warning Header file sc8f3113.h included directly. Use #include <htc.h> instead.
#endif

 /* header file for the cms microcontroller. Base on Datasheet V1.0
    SC8F3113
 */

#ifndef __SC8F3113_H
#define __SC8F3113_H_
		
volatile unsigned char	    INDF	     @   0x0000;
volatile unsigned char	    TMR0	     @   0x0001;
volatile unsigned char	    PCL	     @   0x0002;
volatile unsigned char	    STATUS	     @   0x0003;
volatile unsigned char	    FSR	     @   0x0004;
volatile unsigned char	    PORTA	     @   0x0005;
volatile unsigned char	    PORTB	     @   0x0006;
volatile unsigned char	    WPUA	     @   0x0007;
volatile unsigned char	    WPUB	     @   0x0008;
volatile unsigned char	    IOCA	     @   0x0009;
volatile unsigned char	    PCLATH	     @   0x000A;
volatile unsigned char	    INTCON	     @   0x000B;
volatile unsigned char	    PIR1	     @   0x000C;
volatile unsigned char	    ANSEL0	     @   0x000D;
volatile unsigned char	    TMR1L	     @   0x000E;
volatile unsigned char	    TMR1H	     @   0x000F;
volatile unsigned char	    T1CON	     @   0x0010;
volatile unsigned char	    PWMCON0	     @   0x0011;
volatile unsigned char	    PWMTL	     @   0x0012;
volatile unsigned char	    PWMTH	     @   0x0013;
volatile unsigned char	    PWMD0L	     @   0x0014;
volatile unsigned char	    PWMD1L	     @   0x0015;
volatile unsigned char	    PWMD2L	     @   0x0016;
volatile unsigned char	    PWMD3L	     @   0x0017;
volatile unsigned char	    PWMD4L	     @   0x0018;
volatile unsigned char	    PWMD01H	     @   0x0019;
volatile unsigned char	    PWMD23H	     @   0x001A;
volatile unsigned char	    CMPCON0	     @   0x001B;
volatile unsigned char	    CMPCON1	     @   0x001C;
volatile unsigned char	    OSCCON	     @   0x001D;
volatile unsigned char	    LVDCON	     @   0x001E;
volatile unsigned char	    WDTCON	     @   0x001F;
volatile unsigned char	    OPTION_REG	     @   0x0081;
volatile unsigned char	    TRISA	     @   0x0085;
volatile unsigned char	    TRISB	     @   0x0086;
volatile unsigned char	    WPDA	     @   0x0087;
volatile unsigned char	    WPDB	     @   0x0088;
volatile unsigned char	    IOCB	     @   0x0089;
volatile unsigned char	    PIE1	     @   0x008C;
volatile unsigned char	    TABLE_SPH	     @   0x008D;
volatile unsigned char	    TABLE_SPL	     @   0x008E;
volatile unsigned char	    TABLE_DATAH	     @   0x008F;
		
		
		
		
/* Definitions for STATUS register */		
volatile       bit  	RP1	   @ ((unsigned)&STATUS*8)+6;
volatile       bit  	RP0	   @ ((unsigned)&STATUS*8)+5;
volatile       bit  	TO	   @ ((unsigned)&STATUS*8)+4;
volatile       bit  	PD	   @ ((unsigned)&STATUS*8)+3;
volatile       bit  	Z	   @ ((unsigned)&STATUS*8)+2;
volatile       bit  	DC	   @ ((unsigned)&STATUS*8)+1;
volatile       bit  	C	   @ ((unsigned)&STATUS*8)+0;
		
		
/* Definitions for PORTA register */		
volatile       bit  	RA6	   @ ((unsigned)&PORTA*8)+6;
volatile       bit  	RA5	   @ ((unsigned)&PORTA*8)+5;
volatile       bit  	RA4	   @ ((unsigned)&PORTA*8)+4;
volatile       bit  	RA3	   @ ((unsigned)&PORTA*8)+3;
volatile       bit  	RA2	   @ ((unsigned)&PORTA*8)+2;
volatile       bit  	RA1	   @ ((unsigned)&PORTA*8)+1;
volatile       bit  	RA0	   @ ((unsigned)&PORTA*8)+0;
		
		
/* Definitions for PORTB register */		
volatile       bit  	RB6	   @ ((unsigned)&PORTB*8)+6;
volatile       bit  	RB5	   @ ((unsigned)&PORTB*8)+5;
volatile       bit  	RB4	   @ ((unsigned)&PORTB*8)+4;
volatile       bit  	RB3	   @ ((unsigned)&PORTB*8)+3;
volatile       bit  	RB2	   @ ((unsigned)&PORTB*8)+2;
volatile       bit  	RB1	   @ ((unsigned)&PORTB*8)+1;
volatile       bit  	RB0	   @ ((unsigned)&PORTB*8)+0;
		
		
/* Definitions for WPUA register */		
volatile       bit  	WPUA6	   @ ((unsigned)&WPUA*8)+6;
volatile       bit  	WPUA5	   @ ((unsigned)&WPUA*8)+5;
volatile       bit  	WPUA4	   @ ((unsigned)&WPUA*8)+4;
volatile       bit  	WPUA3	   @ ((unsigned)&WPUA*8)+3;
volatile       bit  	WPUA2	   @ ((unsigned)&WPUA*8)+2;
volatile       bit  	WPUA1	   @ ((unsigned)&WPUA*8)+1;
volatile       bit  	WPUA0	   @ ((unsigned)&WPUA*8)+0;
		
		
/* Definitions for WPUB register */		
volatile       bit  	WPUB6	   @ ((unsigned)&WPUB*8)+6;
volatile       bit  	WPUB5	   @ ((unsigned)&WPUB*8)+5;
volatile       bit  	WPUB4	   @ ((unsigned)&WPUB*8)+4;
volatile       bit  	WPUB3	   @ ((unsigned)&WPUB*8)+3;
volatile       bit  	WPUB2	   @ ((unsigned)&WPUB*8)+2;
volatile       bit  	WPUB1	   @ ((unsigned)&WPUB*8)+1;
volatile       bit  	WPUB0	   @ ((unsigned)&WPUB*8)+0;
		
		
/* Definitions for IOCA register */		
volatile       bit  	IOCA6	   @ ((unsigned)&IOCA*8)+6;
volatile       bit  	IOCA5	   @ ((unsigned)&IOCA*8)+5;
volatile       bit  	IOCA4	   @ ((unsigned)&IOCA*8)+4;
volatile       bit  	IOCA3	   @ ((unsigned)&IOCA*8)+3;
volatile       bit  	IOCA2	   @ ((unsigned)&IOCA*8)+2;
volatile       bit  	IOCA1	   @ ((unsigned)&IOCA*8)+1;
volatile       bit  	IOCA0	   @ ((unsigned)&IOCA*8)+0;
		
		
/* Definitions for INTCON register */		
volatile       bit  	GIE	   @ ((unsigned)&INTCON*8)+7;
volatile       bit  	PEIE	   @ ((unsigned)&INTCON*8)+6;
volatile       bit  	T0IE	   @ ((unsigned)&INTCON*8)+5;
volatile       bit  	INTE	   @ ((unsigned)&INTCON*8)+4;
volatile       bit  	RBIE	   @ ((unsigned)&INTCON*8)+3;
volatile       bit  	T0IF	   @ ((unsigned)&INTCON*8)+2;
volatile       bit  	INTF	   @ ((unsigned)&INTCON*8)+1;
volatile       bit  	RBIF	   @ ((unsigned)&INTCON*8)+0;
		
		
/* Definitions for PIR1 register */		
volatile       bit  	CMPIF	   @ ((unsigned)&PIR1*8)+4;
volatile       bit  	LVDIF	   @ ((unsigned)&PIR1*8)+3;
volatile       bit  	PWMIF	   @ ((unsigned)&PIR1*8)+2;
volatile       bit  	RACIF	   @ ((unsigned)&PIR1*8)+1;
volatile       bit  	TMR1IF	   @ ((unsigned)&PIR1*8)+0;
		
		
/* Definitions for ANSEL0 register */		
volatile       bit  	ANS6	   @ ((unsigned)&ANSEL0*8)+6;
volatile       bit  	ANS5	   @ ((unsigned)&ANSEL0*8)+5;
volatile       bit  	ANS4	   @ ((unsigned)&ANSEL0*8)+4;
		
		
/* Definitions for T1CON register */		
volatile       bit  	T1GINV	   @ ((unsigned)&T1CON*8)+7;
volatile       bit  	TMR1GE	   @ ((unsigned)&T1CON*8)+6;
volatile       bit  	T1CKPS1	   @ ((unsigned)&T1CON*8)+5;
volatile       bit  	T1CKPS0	   @ ((unsigned)&T1CON*8)+4;
volatile       bit  	T1SYNC	   @ ((unsigned)&T1CON*8)+2;
volatile       bit  	TMR1CS	   @ ((unsigned)&T1CON*8)+1;
volatile       bit  	TMR1ON	   @ ((unsigned)&T1CON*8)+0;
		
		
/* Definitions for PWMCON0 register */		
volatile       bit  	CLKDIV2	   @ ((unsigned)&PWMCON0*8)+7;
volatile       bit  	CLKDIV1	   @ ((unsigned)&PWMCON0*8)+6;
volatile       bit  	CLKDIV0	   @ ((unsigned)&PWMCON0*8)+5;
volatile       bit  	PWM4EN	   @ ((unsigned)&PWMCON0*8)+4;
volatile       bit  	PWM3EN	   @ ((unsigned)&PWMCON0*8)+3;
volatile       bit  	PWM2EN	   @ ((unsigned)&PWMCON0*8)+2;
volatile       bit  	PWM1EN	   @ ((unsigned)&PWMCON0*8)+1;
volatile       bit  	PWM0EN	   @ ((unsigned)&PWMCON0*8)+0;
		
		
/* Definitions for PWMTH register */		
volatile       bit  	PWMD49	   @ ((unsigned)&PWMTH*8)+5;
volatile       bit  	PWMD48	   @ ((unsigned)&PWMTH*8)+4;
volatile       bit  	PWMT9	   @ ((unsigned)&PWMTH*8)+1;
volatile       bit  	PWMT8	   @ ((unsigned)&PWMTH*8)+0;
		
		
/* Definitions for PWMD01H register */		
volatile       bit  	PWMD19	   @ ((unsigned)&PWMD01H*8)+5;
volatile       bit  	PWMD18	   @ ((unsigned)&PWMD01H*8)+4;
volatile       bit  	PWMD09	   @ ((unsigned)&PWMD01H*8)+1;
volatile       bit  	PWMD08	   @ ((unsigned)&PWMD01H*8)+0;
		
		
/* Definitions for PWMD23H register */		
volatile       bit  	PWMD39	   @ ((unsigned)&PWMD23H*8)+5;
volatile       bit  	PWMD38	   @ ((unsigned)&PWMD23H*8)+4;
volatile       bit  	PWMD29	   @ ((unsigned)&PWMD23H*8)+1;
volatile       bit  	PWMD28	   @ ((unsigned)&PWMD23H*8)+0;
		
		
/* Definitions for CMPCON0 register */		
volatile       bit  	CMPO	   @ ((unsigned)&CMPCON0*8)+7;
volatile       bit  	CMP_EDGE	   @ ((unsigned)&CMPCON0*8)+2;
volatile       bit  	SLP_CMPEN	   @ ((unsigned)&CMPCON0*8)+1;
volatile       bit  	CMPEN	   @ ((unsigned)&CMPCON0*8)+0;
		
		
/* Definitions for CMPCON1 register */		
volatile       bit  	CMP_PSEL1	   @ ((unsigned)&CMPCON1*8)+7;
volatile       bit  	CMP_PSEL0	   @ ((unsigned)&CMPCON1*8)+6;
volatile       bit  	CMP_CRVO5	   @ ((unsigned)&CMPCON1*8)+5;
volatile       bit  	CMP_CRVO4	   @ ((unsigned)&CMPCON1*8)+4;
volatile       bit  	CMP_CRVO3	   @ ((unsigned)&CMPCON1*8)+3;
volatile       bit  	CMP_CRVO2	   @ ((unsigned)&CMPCON1*8)+2;
volatile       bit  	CMP_CRVO1	   @ ((unsigned)&CMPCON1*8)+1;
volatile       bit  	CMP_CRVO0	   @ ((unsigned)&CMPCON1*8)+0;
		
		
/* Definitions for OSCCON register */		
volatile       bit  	IRCF2	   @ ((unsigned)&OSCCON*8)+6;
volatile       bit  	IRCF1	   @ ((unsigned)&OSCCON*8)+5;
volatile       bit  	IRCF0	   @ ((unsigned)&OSCCON*8)+4;
		
		
/* Definitions for LVDCON register */		
volatile       bit  	LVD_RES	   @ ((unsigned)&LVDCON*8)+7;
volatile       bit  	LVD_SEL2	   @ ((unsigned)&LVDCON*8)+3;
volatile       bit  	LVD_SEL1	   @ ((unsigned)&LVDCON*8)+2;
volatile       bit  	LVD_SEL0	   @ ((unsigned)&LVDCON*8)+1;
volatile       bit  	LVDEN	   @ ((unsigned)&LVDCON*8)+0;
		
		
/* Definitions for WDTCON register */		
volatile       bit  	SWDTEN	   @ ((unsigned)&WDTCON*8)+0;
		
		
/* Definitions for OPTION_REG register */		
volatile       bit  	INTEDG	   @ ((unsigned)&OPTION_REG*8)+6;
volatile       bit  	T0CS	   @ ((unsigned)&OPTION_REG*8)+5;
volatile       bit  	T0SE	   @ ((unsigned)&OPTION_REG*8)+4;
volatile       bit  	PSA	   @ ((unsigned)&OPTION_REG*8)+3;
volatile       bit  	PS2	   @ ((unsigned)&OPTION_REG*8)+2;
volatile       bit  	PS1	   @ ((unsigned)&OPTION_REG*8)+1;
volatile       bit  	PS0	   @ ((unsigned)&OPTION_REG*8)+0;
		
		
/* Definitions for TRISA register */		
volatile       bit  	TRISA6	   @ ((unsigned)&TRISA*8)+6;
volatile       bit  	TRISA5	   @ ((unsigned)&TRISA*8)+5;
volatile       bit  	TRISA4	   @ ((unsigned)&TRISA*8)+4;
volatile       bit  	TRISA3	   @ ((unsigned)&TRISA*8)+3;
volatile       bit  	TRISA2	   @ ((unsigned)&TRISA*8)+2;
volatile       bit  	TRISA1	   @ ((unsigned)&TRISA*8)+1;
volatile       bit  	TRISA0	   @ ((unsigned)&TRISA*8)+0;
		
		
/* Definitions for TRISB register */		
volatile       bit  	TRISB6	   @ ((unsigned)&TRISB*8)+6;
volatile       bit  	TRISB5	   @ ((unsigned)&TRISB*8)+5;
volatile       bit  	TRISB4	   @ ((unsigned)&TRISB*8)+4;
volatile       bit  	TRISB3	   @ ((unsigned)&TRISB*8)+3;
volatile       bit  	TRISB2	   @ ((unsigned)&TRISB*8)+2;
volatile       bit  	TRISB1	   @ ((unsigned)&TRISB*8)+1;
volatile       bit  	TRISB0	   @ ((unsigned)&TRISB*8)+0;
		
		
/* Definitions for WPDA register */		
volatile       bit  	WPDA6	   @ ((unsigned)&WPDA*8)+6;
volatile       bit  	WPDA5	   @ ((unsigned)&WPDA*8)+5;
volatile       bit  	WPDA4	   @ ((unsigned)&WPDA*8)+4;
volatile       bit  	WPDA3	   @ ((unsigned)&WPDA*8)+3;
volatile       bit  	WPDA2	   @ ((unsigned)&WPDA*8)+2;
volatile       bit  	WPDA1	   @ ((unsigned)&WPDA*8)+1;
volatile       bit  	WPDA0	   @ ((unsigned)&WPDA*8)+0;
		
		
/* Definitions for WPDB register */		
volatile       bit  	WPDB6	   @ ((unsigned)&WPDB*8)+6;
volatile       bit  	WPDB5	   @ ((unsigned)&WPDB*8)+5;
volatile       bit  	WPDB4	   @ ((unsigned)&WPDB*8)+4;
volatile       bit  	WPDB3	   @ ((unsigned)&WPDB*8)+3;
volatile       bit  	WPDB2	   @ ((unsigned)&WPDB*8)+2;
volatile       bit  	WPDB1	   @ ((unsigned)&WPDB*8)+1;
volatile       bit  	WPDB0	   @ ((unsigned)&WPDB*8)+0;
		
		
/* Definitions for IOCB register */		
volatile       bit  	IOCB6	   @ ((unsigned)&IOCB*8)+6;
volatile       bit  	IOCB5	   @ ((unsigned)&IOCB*8)+5;
volatile       bit  	IOCB4	   @ ((unsigned)&IOCB*8)+4;
volatile       bit  	IOCB3	   @ ((unsigned)&IOCB*8)+3;
volatile       bit  	IOCB2	   @ ((unsigned)&IOCB*8)+2;
volatile       bit  	IOCB1	   @ ((unsigned)&IOCB*8)+1;
volatile       bit  	IOCB0	   @ ((unsigned)&IOCB*8)+0;
		
		
/* Definitions for PIE1 register */		
volatile       bit  	CMPIE	   @ ((unsigned)&PIE1*8)+4;
volatile       bit  	LVDIE	   @ ((unsigned)&PIE1*8)+3;
volatile       bit  	PWMIE	   @ ((unsigned)&PIE1*8)+2;
volatile       bit  	RACIE	   @ ((unsigned)&PIE1*8)+1;
volatile       bit  	TMR1IE	   @ ((unsigned)&PIE1*8)+0;

#endif
