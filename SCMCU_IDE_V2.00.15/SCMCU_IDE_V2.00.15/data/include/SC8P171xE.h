
#ifndef _HTC_H_
#warning Header file SC8P171xE.h included directly. Use #include <sc.h> instead.
#endif

#ifndef __SC8P171xE_H
#define __SC8P171xE_H


volatile  unsigned char 	INDF	@	0x00;
volatile  unsigned char 	TMR0	@	0x01;
volatile  unsigned char 	PCL  	@	0x02;
volatile  unsigned char 	STATUS	@	0x03;
volatile  unsigned char 	FSR	    @	0x04;
volatile  unsigned char 	PORTA	@	0x05;
volatile  unsigned char 	PORTB	@	0x06;
volatile  unsigned char 	WPUA	@	0x07;
volatile  unsigned char 	WPDA	@	0x08;
volatile  unsigned char 	IOCA	@	0x09;
volatile  unsigned char 	PCLATH	@	0x0A;
volatile  unsigned char 	INTCON	@	0x0B;
volatile  unsigned char 	PIR1	@	0x0C;
volatile  unsigned char 	PIR2	@	0x0D;
volatile  unsigned char 	PWMD2L	@	0x0E;
volatile  unsigned char 	PWMD3L	@	0x0F;
volatile  unsigned char 	PWMD4L	@	0x10;
volatile  unsigned char 	TMR2	@	0x11;
volatile  unsigned char 	T2CON	@	0x12;
volatile  unsigned char 	LCDCON0	@	0x13;
volatile  unsigned char 	LCDCON1	@	0x14;
volatile  unsigned char 	LCDCON	@	0x15;
volatile  unsigned char 	PWMD0L	@	0x16;
volatile  unsigned char 	PWMD1L	@	0x17;
volatile  unsigned char 	PWMD01H	@	0x18;
volatile  unsigned char 	PWMTL	@	0x19;
volatile  unsigned char 	PWMTH	@	0x1A;
volatile  unsigned char 	PWMCON	@	0x1B;
volatile  unsigned char 	PWMD23H	@	0x1C;
volatile  unsigned char 	PWM4TL	@	0x1D;
volatile  unsigned char 	ADRESH	@	0x1E;
volatile  unsigned char 	ADCON0	@	0x1F;
volatile  unsigned char 	OPTION_REG	@	0x81;
volatile  unsigned char 	TRISA	@	0x85;
volatile  unsigned char 	TRISB	@	0x86;
volatile  unsigned char 	WPDB	@	0x87;
volatile  unsigned char 	WDTCON	@	0x88;
volatile  unsigned char 	PIE1	@	0x8C;
volatile  unsigned char 	PIE2	@	0x8D;
volatile  unsigned char 	PWMCON1	@	0x8E;
volatile  unsigned char 	OSCCON	@	0x8F;
volatile  unsigned char 	LVDCON	@	0x91;
volatile  unsigned char 	PR2	@	0x92;
volatile  unsigned char 	ANSEL	@	0x93;
volatile  unsigned char 	ANSELH	@	0x94;
volatile  unsigned char 	WPUB	@	0x95;
volatile  unsigned char 	IOCB	@	0x96;
volatile  unsigned char 	TABLE_SPH	@	0x97;
volatile  unsigned char 	TABLE_SPL	@	0x98;
volatile  unsigned char 	TABLE_DATAH	@	0x99;
volatile  unsigned char 	ADRESL	@	0x9E;
volatile  unsigned char 	ADCON1	@	0x9F;


/* Definitions for STATUS  register */
volatile 	 bit 	 RP0	 @ ((unsigned)&STATUS*8)+5;
volatile 	 bit 	 TO	 @ ((unsigned)&STATUS*8)+4;
volatile 	 bit 	 PD	 @ ((unsigned)&STATUS*8)+3;
volatile 	 bit 	 Z	 @ ((unsigned)&STATUS*8)+2;
volatile 	 bit 	 DC	 @ ((unsigned)&STATUS*8)+1;
volatile 	 bit 	 C	 @ ((unsigned)&STATUS*8)+0;

/* Definitions for PORTA  register */
volatile 	 bit 	 RA6	 @ ((unsigned)&PORTA*8)+6;
volatile 	 bit 	 RA5	 @ ((unsigned)&PORTA*8)+5;
volatile 	 bit 	 RA4	 @ ((unsigned)&PORTA*8)+4;
volatile 	 bit 	 RA3	 @ ((unsigned)&PORTA*8)+3;
volatile 	 bit 	 RA2	 @ ((unsigned)&PORTA*8)+2;
volatile 	 bit 	 RA1	 @ ((unsigned)&PORTA*8)+1;
volatile 	 bit 	 RA0	 @ ((unsigned)&PORTA*8)+0;

/* Definitions for PORTB  register */
volatile 	 bit 	 RB6	 @ ((unsigned)&PORTB*8)+6;
volatile 	 bit 	 RB5	 @ ((unsigned)&PORTB*8)+5;
volatile 	 bit 	 RB4	 @ ((unsigned)&PORTB*8)+4;
volatile 	 bit 	 RB3	 @ ((unsigned)&PORTB*8)+3;
volatile 	 bit 	 RB2	 @ ((unsigned)&PORTB*8)+2;
volatile 	 bit 	 RB1	 @ ((unsigned)&PORTB*8)+1;
volatile 	 bit 	 RB0	 @ ((unsigned)&PORTB*8)+0;

/* Definitions for WPUA  register */
volatile 	 bit 	 WPUA6	 @ ((unsigned)&WPUA*8)+6;
volatile 	 bit 	 WPUA5	 @ ((unsigned)&WPUA*8)+5;
volatile 	 bit 	 WPUA4	 @ ((unsigned)&WPUA*8)+4;
volatile 	 bit 	 WPUA3	 @ ((unsigned)&WPUA*8)+3;
volatile 	 bit 	 WPUA2	 @ ((unsigned)&WPUA*8)+2;
volatile 	 bit 	 WPUA1	 @ ((unsigned)&WPUA*8)+1;
volatile 	 bit 	 WPUA0	 @ ((unsigned)&WPUA*8)+0;

/* Definitions for WPDA  register */
volatile 	 bit 	 WPDA6	 @ ((unsigned)&WPDA*8)+6;
volatile 	 bit 	 WPDA5	 @ ((unsigned)&WPDA*8)+5;
volatile 	 bit 	 WPDA4	 @ ((unsigned)&WPDA*8)+4;
volatile 	 bit 	 WPDA3	 @ ((unsigned)&WPDA*8)+3;
volatile 	 bit 	 WPDA2	 @ ((unsigned)&WPDA*8)+2;
volatile 	 bit 	 WPDA1	 @ ((unsigned)&WPDA*8)+1;
volatile 	 bit 	 WPDA0	 @ ((unsigned)&WPDA*8)+0;

/* Definitions for IOCA  register */
volatile 	 bit 	 IOCA6	 @ ((unsigned)&IOCA*8)+6;
volatile 	 bit 	 IOCA5	 @ ((unsigned)&IOCA*8)+5;
volatile 	 bit 	 IOCA4	 @ ((unsigned)&IOCA*8)+4;
volatile 	 bit 	 IOCA3	 @ ((unsigned)&IOCA*8)+3;
volatile 	 bit 	 IOCA2	 @ ((unsigned)&IOCA*8)+2;
volatile 	 bit 	 IOCA1	 @ ((unsigned)&IOCA*8)+1;
volatile 	 bit 	 IOCA0	 @ ((unsigned)&IOCA*8)+0;

/* Definitions for INTCON  register */
volatile 	 bit 	 GIE	 @ ((unsigned)&INTCON*8)+7;
volatile 	 bit 	 PEIE	 @ ((unsigned)&INTCON*8)+6;
volatile 	 bit 	 T0IE	 @ ((unsigned)&INTCON*8)+5;
volatile 	 bit 	 INTE	 @ ((unsigned)&INTCON*8)+4;
volatile 	 bit 	 RBIE	 @ ((unsigned)&INTCON*8)+3;
volatile 	 bit 	 T0IF	 @ ((unsigned)&INTCON*8)+2;
volatile 	 bit 	 INTF	 @ ((unsigned)&INTCON*8)+1;
volatile 	 bit 	 RBIF	 @ ((unsigned)&INTCON*8)+0;

/* Definitions for PIR1  register */
volatile 	 bit 	 RAIF	 @ ((unsigned)&PIR1*8)+3;
volatile 	 bit 	 PWMIF	 @ ((unsigned)&PIR1*8)+2;
volatile 	 bit 	 TMR2IF	 @ ((unsigned)&PIR1*8)+1;
volatile 	 bit 	 ADIF	 @ ((unsigned)&PIR1*8)+0;

/* Definitions for PIR2  register */
volatile 	 bit 	 LVDIF	 @ ((unsigned)&PIR2*8)+0;

/* Definitions for T2CON  register */
volatile 	 bit 	 TOUTPS3	 @ ((unsigned)&T2CON*8)+6;
volatile 	 bit 	 TOUTPS2	 @ ((unsigned)&T2CON*8)+5;
volatile 	 bit 	 TOUTPS1	 @ ((unsigned)&T2CON*8)+4;
volatile 	 bit 	 TOUTPS0	 @ ((unsigned)&T2CON*8)+3;
volatile 	 bit 	 TMR2ON	 @ ((unsigned)&T2CON*8)+2;
volatile 	 bit 	 T2CKPS1	 @ ((unsigned)&T2CON*8)+1;
volatile 	 bit 	 T2CKPS0	 @ ((unsigned)&T2CON*8)+0;

/* Definitions for LCDCON0  register */
volatile 	 bit 	 COM6EN	 @ ((unsigned)&LCDCON0*8)+6;
volatile 	 bit 	 COM5EN	 @ ((unsigned)&LCDCON0*8)+5;
volatile 	 bit 	 COM4EN	 @ ((unsigned)&LCDCON0*8)+4;
volatile 	 bit 	 COM3EN	 @ ((unsigned)&LCDCON0*8)+3;
volatile 	 bit 	 COM2EN	 @ ((unsigned)&LCDCON0*8)+2;
volatile 	 bit 	 COM1EN	 @ ((unsigned)&LCDCON0*8)+1;
volatile 	 bit 	 COM0EN	 @ ((unsigned)&LCDCON0*8)+0;

/* Definitions for LCDCON1  register */
volatile 	 bit 	 COM14EN	 @ ((unsigned)&LCDCON1*8)+6;
volatile 	 bit 	 COM13EN	 @ ((unsigned)&LCDCON1*8)+5;
volatile 	 bit 	 COM12EN	 @ ((unsigned)&LCDCON1*8)+4;
volatile 	 bit 	 COM11EN	 @ ((unsigned)&LCDCON1*8)+3;
volatile 	 bit 	 COM9EN	 @ ((unsigned)&LCDCON1*8)+1;
volatile 	 bit 	 COM8EN	 @ ((unsigned)&LCDCON1*8)+0;

/* Definitions for LCDCON  register */
volatile 	 bit 	 LCDEN	 @ ((unsigned)&LCDCON*8)+7;
volatile 	 bit 	 LCD_ISLE1	 @ ((unsigned)&LCDCON*8)+1;
volatile 	 bit 	 LCD_ISLE0	 @ ((unsigned)&LCDCON*8)+0;

/* Definitions for PWMD01H  register */
volatile 	 bit 	 PWMD19	 @ ((unsigned)&PWMD01H*8)+3;
volatile 	 bit 	 PWMD18	 @ ((unsigned)&PWMD01H*8)+2;
volatile 	 bit 	 PWMD09	 @ ((unsigned)&PWMD01H*8)+1;
volatile 	 bit 	 PWMD08	 @ ((unsigned)&PWMD01H*8)+0;

/* Definitions for PWMCON  register */
volatile 	 bit 	 CLKDIV2	 @ ((unsigned)&PWMCON*8)+7;
volatile 	 bit 	 CLKDIV1	 @ ((unsigned)&PWMCON*8)+6;
volatile 	 bit 	 CLKDIV0	 @ ((unsigned)&PWMCON*8)+5;
volatile 	 bit 	 PWM1DIR	 @ ((unsigned)&PWMCON*8)+3;
volatile 	 bit 	 PWM0DIR	 @ ((unsigned)&PWMCON*8)+2;
volatile 	 bit 	 PWM1EN	 @ ((unsigned)&PWMCON*8)+1;
volatile 	 bit 	 PWM0EN	 @ ((unsigned)&PWMCON*8)+0;

/* Definitions for PWMD23H  register */
volatile 	 bit 	 PWMD39	 @ ((unsigned)&PWMD23H*8)+3;
volatile 	 bit 	 PWMD38	 @ ((unsigned)&PWMD23H*8)+2;
volatile 	 bit 	 PWMD29	 @ ((unsigned)&PWMD23H*8)+1;
volatile 	 bit 	 PWMD28	 @ ((unsigned)&PWMD23H*8)+0;

/* Definitions for ADCON0  register */
volatile 	 bit 	 ADCS1	 @ ((unsigned)&ADCON0*8)+7;
volatile 	 bit 	 ADCS0	 @ ((unsigned)&ADCON0*8)+6;
volatile 	 bit 	 CHS3	 @ ((unsigned)&ADCON0*8)+5;
volatile 	 bit 	 CHS2	 @ ((unsigned)&ADCON0*8)+4;
volatile 	 bit 	 CHS1	 @ ((unsigned)&ADCON0*8)+3;
volatile 	 bit 	 CHS0	 @ ((unsigned)&ADCON0*8)+2;
volatile 	 bit 	 GODONE	 @ ((unsigned)&ADCON0*8)+1;
volatile 	 bit 	 ADON	 @ ((unsigned)&ADCON0*8)+0;

/* Definitions for OPTION_REG  register */
volatile 	 bit 	 INTEDG	 @ ((unsigned)&OPTION_REG*8)+6;
volatile 	 bit 	 T0CS	 @ ((unsigned)&OPTION_REG*8)+5;
volatile 	 bit 	 T0SE	 @ ((unsigned)&OPTION_REG*8)+4;
volatile 	 bit 	 PSA	 @ ((unsigned)&OPTION_REG*8)+3;
volatile 	 bit 	 PS2	 @ ((unsigned)&OPTION_REG*8)+2;
volatile 	 bit 	 PS1	 @ ((unsigned)&OPTION_REG*8)+1;
volatile 	 bit 	 PS0	 @ ((unsigned)&OPTION_REG*8)+0;

/* Definitions for TRISA  register */
volatile 	 bit 	 TRISA6	 @ ((unsigned)&TRISA*8)+6;
volatile 	 bit 	 TRISA5	 @ ((unsigned)&TRISA*8)+5;
volatile 	 bit 	 TRISA4	 @ ((unsigned)&TRISA*8)+4;
volatile 	 bit 	 TRISA3	 @ ((unsigned)&TRISA*8)+3;
volatile 	 bit 	 TRISA2	 @ ((unsigned)&TRISA*8)+2;
volatile 	 bit 	 TRISA1	 @ ((unsigned)&TRISA*8)+1;
volatile 	 bit 	 TRISA0	 @ ((unsigned)&TRISA*8)+0;

/* Definitions for TRISB  register */
volatile 	 bit 	 TRISB6	 @ ((unsigned)&TRISB*8)+6;
volatile 	 bit 	 TRISB5	 @ ((unsigned)&TRISB*8)+5;
volatile 	 bit 	 TRISB4	 @ ((unsigned)&TRISB*8)+4;
volatile 	 bit 	 TRISB3	 @ ((unsigned)&TRISB*8)+3;
volatile 	 bit 	 TRISB2	 @ ((unsigned)&TRISB*8)+2;
volatile 	 bit 	 TRISB1	 @ ((unsigned)&TRISB*8)+1;
volatile 	 bit 	 TRISB0	 @ ((unsigned)&TRISB*8)+0;

/* Definitions for WPDB  register */
volatile 	 bit 	 WPDB6	 @ ((unsigned)&WPDB*8)+6;
volatile 	 bit 	 WPDB5	 @ ((unsigned)&WPDB*8)+5;
volatile 	 bit 	 WPDB4	 @ ((unsigned)&WPDB*8)+4;
volatile 	 bit 	 WPDB3	 @ ((unsigned)&WPDB*8)+3;
volatile 	 bit 	 WPDB1	 @ ((unsigned)&WPDB*8)+1;
volatile 	 bit 	 WPDB0	 @ ((unsigned)&WPDB*8)+0;

/* Definitions for WDTCON  register */
volatile 	 bit 	 SWDTEN	 @ ((unsigned)&WDTCON*8)+0;

/* Definitions for PIE1  register */
volatile 	 bit 	 RAIE	 @ ((unsigned)&PIE1*8)+3;
volatile 	 bit 	 PWMIE	 @ ((unsigned)&PIE1*8)+2;
volatile 	 bit 	 TMR2IE	 @ ((unsigned)&PIE1*8)+1;
volatile 	 bit 	 ADIE	 @ ((unsigned)&PIE1*8)+0;

/* Definitions for PIE2  register */
volatile 	 bit 	 LVDIE	 @ ((unsigned)&PIE2*8)+0;

/* Definitions for PWMCON1  register */
volatile 	 bit 	 PMW4DIR	 @ ((unsigned)&PWMCON1*8)+5;
volatile 	 bit 	 PWM3DIR	 @ ((unsigned)&PWMCON1*8)+4;
volatile 	 bit 	 PWM2DIR	 @ ((unsigned)&PWMCON1*8)+3;
volatile 	 bit 	 PWM4EN	 @ ((unsigned)&PWMCON1*8)+2;
volatile 	 bit 	 PWM3EN	 @ ((unsigned)&PWMCON1*8)+1;
volatile 	 bit 	 PWM2EN	 @ ((unsigned)&PWMCON1*8)+0;

/* Definitions for OSCCON  register */
volatile 	 bit 	 IRCF2	 @ ((unsigned)&OSCCON*8)+6;
volatile 	 bit 	 IRCF1	 @ ((unsigned)&OSCCON*8)+5;
volatile 	 bit 	 IRCF0	 @ ((unsigned)&OSCCON*8)+4;

/* Definitions for LVDCON  register */
volatile 	 bit 	 LVD_RES	 @ ((unsigned)&LVDCON*8)+7;
volatile 	 bit 	 LVD_SEL2	 @ ((unsigned)&LVDCON*8)+3;
volatile 	 bit 	 LVD_SEL1	 @ ((unsigned)&LVDCON*8)+2;
volatile 	 bit 	 LVD_SEL0	 @ ((unsigned)&LVDCON*8)+1;
volatile 	 bit 	 LVDEN	 @ ((unsigned)&LVDCON*8)+0;

/* Definitions for ANSEL  register */
volatile 	 bit 	 ANS6	 @ ((unsigned)&ANSEL*8)+6;
volatile 	 bit 	 ANS5	 @ ((unsigned)&ANSEL*8)+5;
volatile 	 bit 	 ANS4	 @ ((unsigned)&ANSEL*8)+4;
volatile 	 bit 	 ANS3	 @ ((unsigned)&ANSEL*8)+3;
volatile 	 bit 	 ANS2	 @ ((unsigned)&ANSEL*8)+2;
volatile 	 bit 	 ANS1	 @ ((unsigned)&ANSEL*8)+1;
volatile 	 bit 	 ANS0	 @ ((unsigned)&ANSEL*8)+0;

/* Definitions for ANSELH  register */
volatile 	 bit 	 ANS14	 @ ((unsigned)&ANSELH*8)+6;
volatile 	 bit 	 ANS13	 @ ((unsigned)&ANSELH*8)+5;
volatile 	 bit 	 ANS12	 @ ((unsigned)&ANSELH*8)+4;
volatile 	 bit 	 ANS11	 @ ((unsigned)&ANSELH*8)+3;
volatile 	 bit 	 ANS9	 @ ((unsigned)&ANSELH*8)+1;
volatile 	 bit 	 ANS8	 @ ((unsigned)&ANSELH*8)+0;

/* Definitions for WPUB  register */
volatile 	 bit 	 WPUB6	 @ ((unsigned)&WPUB*8)+6;
volatile 	 bit 	 WPUB5	 @ ((unsigned)&WPUB*8)+5;
volatile 	 bit 	 WPUB4	 @ ((unsigned)&WPUB*8)+4;
volatile 	 bit 	 WPUB3	 @ ((unsigned)&WPUB*8)+3;
volatile 	 bit 	 WPUB2	 @ ((unsigned)&WPUB*8)+2;
volatile 	 bit 	 WPUB1	 @ ((unsigned)&WPUB*8)+1;
volatile 	 bit 	 WPUB0	 @ ((unsigned)&WPUB*8)+0;

/* Definitions for IOCB  register */
volatile 	 bit 	 IOCB6	 @ ((unsigned)&IOCB*8)+6;
volatile 	 bit 	 IOCB5	 @ ((unsigned)&IOCB*8)+5;
volatile 	 bit 	 IOCB4	 @ ((unsigned)&IOCB*8)+4;
volatile 	 bit 	 IOCB3	 @ ((unsigned)&IOCB*8)+3;
volatile 	 bit 	 IOCB2	 @ ((unsigned)&IOCB*8)+2;
volatile 	 bit 	 IOCB1	 @ ((unsigned)&IOCB*8)+1;
volatile 	 bit 	 IOCB0	 @ ((unsigned)&IOCB*8)+0;

/* Definitions for ADCON1  register */
volatile 	 bit 	 ADFM	 @ ((unsigned)&ADCON1*8)+7;
volatile 	 bit 	 TADSEL	 @ ((unsigned)&ADCON1*8)+3;
volatile 	 bit 	 LDOEN	 @ ((unsigned)&ADCON1*8)+2;
volatile 	 bit 	 LDOSEL	 @ ((unsigned)&ADCON1*8)+0;

#endif
