
#ifndef	_HTC_H_
#warning Header file SC8P1715.h included directly. Use #include <sc.h> instead.
#endif

#ifndef	__SC8P1715_H
#define	__SC8P1715_H

		
volatile unsigned char	    INDF	     @   0x0000;
volatile unsigned char	    TMR0	     @   0x0001;
volatile unsigned char	    PCL	     @   0x0002;
volatile unsigned char	    STATUS	     @   0x0003;
volatile unsigned char	    FSR	     @   0x0004;
volatile unsigned char	    PORTA	     @   0x0005;
volatile unsigned char	    PORTB	     @   0x0006;
volatile unsigned char	    WPUA	     @   0x0007;
volatile unsigned char	    WPDA	     @   0x0008;
volatile unsigned char	    IOCA	     @   0x0009;
volatile unsigned char	    PCLATH	     @   0x000A;
volatile unsigned char	    INTCON	     @   0x000B;
volatile unsigned char	    PIR1	     @   0x000C;
volatile unsigned char	    TMR2	     @   0x0011;
volatile unsigned char	    T2CON	     @   0x0012;
volatile unsigned char	    LCDCON0	     @   0x0013;
volatile unsigned char	    LCDCON1	     @   0x0014;
volatile unsigned char	    LCDCON	     @   0x0015;
volatile unsigned char	    PWMD0L	     @   0x0016;
volatile unsigned char	    PWMD1L	     @   0x0017;
volatile unsigned char	    PWMD01H	     @   0x0018;
volatile unsigned char	    PWMTL	     @   0x0019;
volatile unsigned char	    PWMTH	     @   0x001A;
volatile unsigned char	    PWMCON	     @   0x001B;
volatile unsigned char	    ADRESH	     @   0x001E;
volatile unsigned char	    ADCON0	     @   0x001F;
volatile unsigned char	    OPTION_REG	     @   0x0081;
volatile unsigned char	    TRISA	     @   0x0085;
volatile unsigned char	    TRISB	     @   0x0086;
volatile unsigned char	    WPDB	     @   0x0087;
volatile unsigned char	    WDTCON	     @   0x0088;
volatile unsigned char	    PIE1	     @   0x008C;
volatile unsigned char	    OSCCON	     @   0x008F;
volatile unsigned char	    PR2	     @   0x0092;
volatile unsigned char	    ANSEL	     @   0x0093;
volatile unsigned char	    ANSELH	     @   0x0094;
volatile unsigned char	    WPUB	     @   0x0095;
volatile unsigned char	    IOCB	     @   0x0096;
volatile unsigned char	    TABLE_SPH	     @   0x0097;
volatile unsigned char	    TABLE_SPL	     @   0x0098;
volatile unsigned char	    TABLE_DATAH	     @   0x0099;
volatile unsigned char	    ADRESL	     @   0x009E;
volatile unsigned char	    ADCON1	     @   0x009F;
		
		
		
		
/* Definitions for STATUS register */		
volatile       bit  RP0   @ ((unsigned)&STATUS*8)+5;		
volatile       bit  TO   @ ((unsigned)&STATUS*8)+4;		
volatile       bit  PD   @ ((unsigned)&STATUS*8)+3;		
volatile       bit  Z   @ ((unsigned)&STATUS*8)+2;		
volatile       bit  DC   @ ((unsigned)&STATUS*8)+1;		
volatile       bit  C   @ ((unsigned)&STATUS*8)+0;	

volatile       bit	ZERO	@ ((unsigned)&STATUS*8)+2;
volatile       bit	CARRY	@ ((unsigned)&STATUS*8)+0;
		
/* Definitions for PORTA register */		
volatile       bit  RA5   @ ((unsigned)&PORTA*8)+5;		
volatile       bit  RA2   @ ((unsigned)&PORTA*8)+2;		
volatile       bit  RA1   @ ((unsigned)&PORTA*8)+1;		
volatile       bit  RA0   @ ((unsigned)&PORTA*8)+0;		
		
		
/* Definitions for PORTB register */		
volatile       bit  RB3   @ ((unsigned)&PORTB*8)+3;		
volatile       bit  RB2   @ ((unsigned)&PORTB*8)+2;		
volatile       bit  RB1   @ ((unsigned)&PORTB*8)+1;		
volatile       bit  RB0   @ ((unsigned)&PORTB*8)+0;		
		
		
/* Definitions for WPUA register */		
volatile       bit  WPUA5   @ ((unsigned)&WPUA*8)+5;		
volatile       bit  WPUA2   @ ((unsigned)&WPUA*8)+2;		
volatile       bit  WPUA1   @ ((unsigned)&WPUA*8)+1;		
volatile       bit  WPUA0   @ ((unsigned)&WPUA*8)+0;		
		
		
/* Definitions for WPDA register */		
volatile       bit  WPDA5   @ ((unsigned)&WPDA*8)+5;		
volatile       bit  WPDA2   @ ((unsigned)&WPDA*8)+2;		
volatile       bit  WPDA1   @ ((unsigned)&WPDA*8)+1;		
volatile       bit  WPDA0   @ ((unsigned)&WPDA*8)+0;		
		
		
/* Definitions for IOCA register */		
volatile       bit  IOCA5   @ ((unsigned)&IOCA*8)+5;		
volatile       bit  IOCA2   @ ((unsigned)&IOCA*8)+2;		
volatile       bit  IOCA1   @ ((unsigned)&IOCA*8)+1;		
volatile       bit  IOCA0   @ ((unsigned)&IOCA*8)+0;		
		
		
/* Definitions for INTCON register */		
volatile       bit  GIE   @ ((unsigned)&INTCON*8)+7;		
volatile       bit  PEIE   @ ((unsigned)&INTCON*8)+6;		
volatile       bit  T0IE   @ ((unsigned)&INTCON*8)+5;		
volatile       bit  INTE   @ ((unsigned)&INTCON*8)+4;		
volatile       bit  RBIE   @ ((unsigned)&INTCON*8)+3;		
volatile       bit  T0IF   @ ((unsigned)&INTCON*8)+2;		
volatile       bit  INTF   @ ((unsigned)&INTCON*8)+1;		
volatile       bit  RBIF   @ ((unsigned)&INTCON*8)+0;		
		
		
/* Definitions for PIR1 register */		
volatile       bit  RAIF   @ ((unsigned)&PIR1*8)+3;		
volatile       bit  PWMIF   @ ((unsigned)&PIR1*8)+2;		
volatile       bit  TMR2IF   @ ((unsigned)&PIR1*8)+1;		
volatile       bit  ADIF   @ ((unsigned)&PIR1*8)+0;		
		
		
/* Definitions for T2CON register */		
volatile       bit  TOUTPS3   @ ((unsigned)&T2CON*8)+6;		
volatile       bit  TOUTPS2   @ ((unsigned)&T2CON*8)+5;		
volatile       bit  TOUTPS1   @ ((unsigned)&T2CON*8)+4;		
volatile       bit  TOUTPS0   @ ((unsigned)&T2CON*8)+3;		
volatile       bit  TMR2ON   @ ((unsigned)&T2CON*8)+2;		
volatile       bit  T2CKPS1   @ ((unsigned)&T2CON*8)+1;		
volatile       bit  T2CKPS0   @ ((unsigned)&T2CON*8)+0;		
		
		
/* Definitions for LCDCON0 register */		
volatile       bit  COM5EN   @ ((unsigned)&LCDCON0*8)+5;		
volatile       bit  COM2EN   @ ((unsigned)&LCDCON0*8)+2;		
volatile       bit  COM1EN   @ ((unsigned)&LCDCON0*8)+1;		
volatile       bit  COM0EN   @ ((unsigned)&LCDCON0*8)+0;		
		
		
/* Definitions for LCDCON1 register */		
volatile       bit  COM11EN   @ ((unsigned)&LCDCON1*8)+3;		
volatile       bit  COM9EN   @ ((unsigned)&LCDCON1*8)+1;		
volatile       bit  COM8EN   @ ((unsigned)&LCDCON1*8)+0;		
		
		
/* Definitions for LCDCON register */		
volatile       bit  LCDEN   @ ((unsigned)&LCDCON*8)+7;		
volatile       bit  LCD_ISLE1   @ ((unsigned)&LCDCON*8)+1;		
volatile       bit  LCD_ISLE0   @ ((unsigned)&LCDCON*8)+0;		
		
		
/* Definitions for PWMD01H register */		
volatile       bit  PWMD19   @ ((unsigned)&PWMD01H*8)+3;		
volatile       bit  PWMD18   @ ((unsigned)&PWMD01H*8)+2;		
volatile       bit  PWMD09   @ ((unsigned)&PWMD01H*8)+1;		
volatile       bit  PWMD08   @ ((unsigned)&PWMD01H*8)+0;		
		
		
/* Definitions for PWMCON register */		
volatile       bit  CLKDIV2   @ ((unsigned)&PWMCON*8)+7;		
volatile       bit  CLKDIV1   @ ((unsigned)&PWMCON*8)+6;		
volatile       bit  CLKDIV0   @ ((unsigned)&PWMCON*8)+5;		
volatile       bit  PWM1DIR   @ ((unsigned)&PWMCON*8)+3;		
volatile       bit  PWM0DIR   @ ((unsigned)&PWMCON*8)+2;		
volatile       bit  PWM1EN   @ ((unsigned)&PWMCON*8)+1;		
volatile       bit  PWM0EN   @ ((unsigned)&PWMCON*8)+0;		
		
		
/* Definitions for ADCON0 register */		
volatile       bit  ADCS1   @ ((unsigned)&ADCON0*8)+7;		
volatile       bit  ADCS0   @ ((unsigned)&ADCON0*8)+6;		
volatile       bit  CHS3   @ ((unsigned)&ADCON0*8)+5;		
volatile       bit  CHS2   @ ((unsigned)&ADCON0*8)+4;		
volatile       bit  CHS1   @ ((unsigned)&ADCON0*8)+3;		
volatile       bit  CHS0   @ ((unsigned)&ADCON0*8)+2;		
volatile       bit  GODONE   @ ((unsigned)&ADCON0*8)+1;		
volatile       bit  ADON   @ ((unsigned)&ADCON0*8)+0;		
		
		
/* Definitions for OPTION_REG register */		
volatile       bit  INTEDG   @ ((unsigned)&OPTION_REG*8)+6;		
volatile       bit  T0CS   @ ((unsigned)&OPTION_REG*8)+5;		
volatile       bit  T0SE   @ ((unsigned)&OPTION_REG*8)+4;		
volatile       bit  PSA   @ ((unsigned)&OPTION_REG*8)+3;		
volatile       bit  PS2   @ ((unsigned)&OPTION_REG*8)+2;		
volatile       bit  PS1   @ ((unsigned)&OPTION_REG*8)+1;		
volatile       bit  PS0   @ ((unsigned)&OPTION_REG*8)+0;		
		
		
/* Definitions for TRISA register */		
volatile       bit  TRISA5   @ ((unsigned)&TRISA*8)+5;		
volatile       bit  TRISA2   @ ((unsigned)&TRISA*8)+2;		
volatile       bit  TRISA1   @ ((unsigned)&TRISA*8)+1;		
volatile       bit  TRISA0   @ ((unsigned)&TRISA*8)+0;		
		
		
/* Definitions for TRISB register */		
volatile       bit  TRISB3   @ ((unsigned)&TRISB*8)+3;		
volatile       bit  TRISB2   @ ((unsigned)&TRISB*8)+2;		
volatile       bit  TRISB1   @ ((unsigned)&TRISB*8)+1;		
volatile       bit  TRISB0   @ ((unsigned)&TRISB*8)+0;		
		
		
/* Definitions for WPDB register */		
volatile       bit  WPDB3   @ ((unsigned)&WPDB*8)+3;		
volatile       bit  WPDB1   @ ((unsigned)&WPDB*8)+1;		
volatile       bit  WPDB0   @ ((unsigned)&WPDB*8)+0;		
		
		
/* Definitions for WDTCON register */		
volatile       bit  SWDTEN   @ ((unsigned)&WDTCON*8)+0;		
		
		
/* Definitions for PIE1 register */		
volatile       bit  RAIE   @ ((unsigned)&PIE1*8)+3;		
volatile       bit  PWMIE   @ ((unsigned)&PIE1*8)+2;		
volatile       bit  TMR2IE   @ ((unsigned)&PIE1*8)+1;		
volatile       bit  ADIE   @ ((unsigned)&PIE1*8)+0;		
		
		
/* Definitions for OSCCON register */		
volatile       bit  IRCF2   @ ((unsigned)&OSCCON*8)+6;		
volatile       bit  IRCF1   @ ((unsigned)&OSCCON*8)+5;		
volatile       bit  IRCF0   @ ((unsigned)&OSCCON*8)+4;		
		
		
/* Definitions for ANSEL register */		
volatile       bit  ANSEL5   @ ((unsigned)&ANSEL*8)+5;		
volatile       bit  ANSEL2   @ ((unsigned)&ANSEL*8)+2;		
volatile       bit  ANSEL1   @ ((unsigned)&ANSEL*8)+1;		
volatile       bit  ANSEL0   @ ((unsigned)&ANSEL*8)+0;		
		
		
/* Definitions for ANSELH register */		
volatile       bit  ANSEL11   @ ((unsigned)&ANSELH*8)+3;		
volatile       bit  ANSEL9   @ ((unsigned)&ANSELH*8)+1;		
volatile       bit  ANSEL8   @ ((unsigned)&ANSELH*8)+0;		
		
		
/* Definitions for WPUB register */		
volatile       bit  WPUB3   @ ((unsigned)&WPUB*8)+3;		
volatile       bit  WPUB2   @ ((unsigned)&WPUB*8)+2;		
volatile       bit  WPUB1   @ ((unsigned)&WPUB*8)+1;		
volatile       bit  WPUB0   @ ((unsigned)&WPUB*8)+0;		
		
		
/* Definitions for IOCB register */		
volatile       bit  IOCB3   @ ((unsigned)&IOCB*8)+3;		
volatile       bit  IOCB2   @ ((unsigned)&IOCB*8)+2;		
volatile       bit  IOCB1   @ ((unsigned)&IOCB*8)+1;		
volatile       bit  IOCB0   @ ((unsigned)&IOCB*8)+0;		
		
		
/* Definitions for ADCON1 register */		
volatile       bit  ADFM   @ ((unsigned)&ADCON1*8)+7;		




#endif