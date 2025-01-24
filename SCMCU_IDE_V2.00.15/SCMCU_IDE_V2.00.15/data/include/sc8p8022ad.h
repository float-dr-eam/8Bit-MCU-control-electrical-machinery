#ifndef __SC8P8022AD_H
#define __SC8P8022AD_H


volatile 	unsigned char 	INDF		@	0x00;
volatile 	unsigned char 	OPTION_REG	@	0x01;
volatile 	unsigned char 	PCL			@	0x02;
volatile 	unsigned char 	STATUS		@	0x03;
volatile 	unsigned char 	FSR			@	0x04;
volatile 	unsigned char 	TRISB		@	0x05;
volatile 	unsigned char 	PORTB		@	0x06;
volatile 	unsigned char 	WPDB		@	0x07;
volatile 	unsigned char 	WPUB		@	0x08;
volatile 	unsigned char 	IOCB		@	0x09;
volatile 	unsigned char 	PCLATH		@	0x0A;
volatile 	unsigned char 	INTCON		@	0x0B;
volatile 	unsigned char 	PIR1		@	0x0D;
volatile 	unsigned char 	PIE1		@	0x0E;
volatile 	unsigned char 	CMPCON0		@	0x0F;
volatile 	unsigned char 	CMPCON1		@	0x10;
volatile 	unsigned char 	PR2			@	0x11;
volatile 	unsigned char 	TMR2		@	0x12;
volatile 	unsigned char 	T2CON		@	0x13;
volatile 	unsigned char 	OSCCON		@	0x14;
volatile 	unsigned char 	PWMCON0		@	0x15;
volatile 	unsigned char 	PWMCON1		@	0x16;
volatile 	unsigned char 	PWMTL		@	0x17;
volatile 	unsigned char 	PWMTH		@	0x18;
volatile 	unsigned char 	PWMD0L		@	0x19;
volatile 	unsigned char 	PWMD1L		@	0x1A;
volatile 	unsigned char 	PWMD4L		@	0x1B;
volatile 	unsigned char 	PWMT4L		@	0x1C;
volatile 	unsigned char 	PWMCON2		@	0x1D;
volatile 	unsigned char 	PWMD01H		@	0x1E;
volatile 	unsigned char 	PWM01DT		@	0x1F;
volatile 	unsigned char 	TMR0		@	0x81;
volatile 	unsigned char 	PWMD2L		@	0x9B;
volatile 	unsigned char 	PWMD3L		@	0x9C;
volatile 	unsigned char 	PWM23DT		@	0x9D;
volatile 	unsigned char 	PWMD23H		@	0x9E;
volatile 	unsigned char 	PIR2		@	0x10F;
volatile 	unsigned char 	PIE2		@	0x110;
volatile 	unsigned char 	KEYCON0		@	0x111;
volatile 	unsigned char 	KEYCON1		@	0x112;
volatile 	unsigned char 	KEYCON2		@	0x113;
volatile 	unsigned char 	KEYDATAL	@	0x116;
volatile 	unsigned char 	KEYDATAH	@	0x117;
/* Definitions for OPTION_REG  register */
volatile 	 bit 	 INTEDG	 @ ((unsigned)&OPTION_REG*8)+6;
volatile 	 bit 	 T0CS	 @ ((unsigned)&OPTION_REG*8)+5;
volatile 	 bit 	 T0SE	 @ ((unsigned)&OPTION_REG*8)+4;
volatile 	 bit 	 PSA	 @ ((unsigned)&OPTION_REG*8)+3;
volatile 	 bit 	 PS2	 @ ((unsigned)&OPTION_REG*8)+2;
volatile 	 bit 	 PS1	 @ ((unsigned)&OPTION_REG*8)+1;
volatile 	 bit 	 PS0	 @ ((unsigned)&OPTION_REG*8)+0;

/* Definitions for STATUS  register */
volatile 	 bit 	 IRP	 @ ((unsigned)&STATUS*8)+7;
volatile 	 bit 	 RP1	 @ ((unsigned)&STATUS*8)+6;
volatile 	 bit 	 RP0	 @ ((unsigned)&STATUS*8)+5;
volatile 	 bit 	 TO	 @ ((unsigned)&STATUS*8)+4;
volatile 	 bit 	 PD	 @ ((unsigned)&STATUS*8)+3;
volatile 	 bit 	 Z	 @ ((unsigned)&STATUS*8)+2;
volatile 	 bit 	 DC	 @ ((unsigned)&STATUS*8)+1;
volatile 	 bit 	 C	 @ ((unsigned)&STATUS*8)+0;

/* Definitions for TRISB  register */
volatile 	 bit 	 TRISB6	 @ ((unsigned)&TRISB*8)+6;
volatile 	 bit 	 TRISB4	 @ ((unsigned)&TRISB*8)+4;
volatile 	 bit 	 TRISB3	 @ ((unsigned)&TRISB*8)+3;
volatile 	 bit 	 TRISB2	 @ ((unsigned)&TRISB*8)+2;
volatile 	 bit 	 TRISB1	 @ ((unsigned)&TRISB*8)+1;
volatile 	 bit 	 TRISB0	 @ ((unsigned)&TRISB*8)+0;

/* Definitions for PORTB  register */
volatile 	 bit 	 RB6	 @ ((unsigned)&PORTB*8)+6;
volatile 	 bit 	 RB4	 @ ((unsigned)&PORTB*8)+4;
volatile 	 bit 	 RB3	 @ ((unsigned)&PORTB*8)+3;
volatile 	 bit 	 RB2	 @ ((unsigned)&PORTB*8)+2;
volatile 	 bit 	 RB1	 @ ((unsigned)&PORTB*8)+1;
volatile 	 bit 	 RB0	 @ ((unsigned)&PORTB*8)+0;

/* Definitions for WPDB  register */
volatile 	 bit 	 WPDB6	 @ ((unsigned)&WPDB*8)+6;
volatile 	 bit 	 WPDB4	 @ ((unsigned)&WPDB*8)+4;
volatile 	 bit 	 WPDB2	 @ ((unsigned)&WPDB*8)+2;
volatile 	 bit 	 WPDB1	 @ ((unsigned)&WPDB*8)+1;
volatile 	 bit 	 WPDB0	 @ ((unsigned)&WPDB*8)+0;

/* Definitions for WPUB  register */
volatile 	 bit 	 WPUB6	 @ ((unsigned)&WPUB*8)+6;
volatile 	 bit 	 WPUB4	 @ ((unsigned)&WPUB*8)+4;
volatile 	 bit 	 WPUB3	 @ ((unsigned)&WPUB*8)+3;
volatile 	 bit 	 WPUB2	 @ ((unsigned)&WPUB*8)+2;
volatile 	 bit 	 WPUB1	 @ ((unsigned)&WPUB*8)+1;
volatile 	 bit 	 WPUB0	 @ ((unsigned)&WPUB*8)+0;

/* Definitions for IOCB  register */
volatile 	 bit 	 IOCB6	 @ ((unsigned)&IOCB*8)+6;
volatile 	 bit 	 IOCB4	 @ ((unsigned)&IOCB*8)+4;
volatile 	 bit 	 IOCB3	 @ ((unsigned)&IOCB*8)+3;
volatile 	 bit 	 IOCB2	 @ ((unsigned)&IOCB*8)+2;
volatile 	 bit 	 IOCB1	 @ ((unsigned)&IOCB*8)+1;
volatile 	 bit 	 IOCB0	 @ ((unsigned)&IOCB*8)+0;

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
volatile 	 bit 	 CMPIF	 @ ((unsigned)&PIR1*8)+5;
volatile 	 bit 	 PWMIF	 @ ((unsigned)&PIR1*8)+4;
volatile 	 bit 	 TMR2IF	 @ ((unsigned)&PIR1*8)+1;

/* Definitions for PIE1  register */
volatile 	 bit 	 CMPIE	 @ ((unsigned)&PIE1*8)+5;
volatile 	 bit 	 PWMIE	 @ ((unsigned)&PIE1*8)+4;
volatile 	 bit 	 TMR2IE	 @ ((unsigned)&PIE1*8)+1;

/* Definitions for CMPCON0  register */
volatile 	 bit 	 CMPEN	 @ ((unsigned)&CMPCON0*8)+7;
volatile 	 bit 	 CMPPS	 @ ((unsigned)&CMPCON0*8)+6;
volatile 	 bit 	 CMPNS2	 @ ((unsigned)&CMPCON0*8)+5;
volatile 	 bit 	 CMPNS1	 @ ((unsigned)&CMPCON0*8)+4;
volatile 	 bit 	 CMPNS0	 @ ((unsigned)&CMPCON0*8)+3;
volatile 	 bit 	 CMPNV	 @ ((unsigned)&CMPCON0*8)+2;
volatile 	 bit 	 CMPOUT	 @ ((unsigned)&CMPCON0*8)+1;
volatile 	 bit 	 CMPOEN	 @ ((unsigned)&CMPCON0*8)+0;

/* Definitions for CMPCON1  register */
volatile 	 bit 	 CMPIM	 @ ((unsigned)&CMPCON1*8)+7;
volatile 	 bit 	 AN_EN	 @ ((unsigned)&CMPCON1*8)+6;
volatile 	 bit 	 RBIAS_H	 @ ((unsigned)&CMPCON1*8)+5;
volatile 	 bit 	 RBIAS_L	 @ ((unsigned)&CMPCON1*8)+4;
volatile 	 bit 	 LVDS3	 @ ((unsigned)&CMPCON1*8)+3;
volatile 	 bit 	 LVDS2	 @ ((unsigned)&CMPCON1*8)+2;
volatile 	 bit 	 LVDS1	 @ ((unsigned)&CMPCON1*8)+1;
volatile 	 bit 	 LVDS0	 @ ((unsigned)&CMPCON1*8)+0;

/* Definitions for T2CON  register */
volatile 	 bit 	 TOUTPS3	 @ ((unsigned)&T2CON*8)+6;
volatile 	 bit 	 TOUTPS2	 @ ((unsigned)&T2CON*8)+5;
volatile 	 bit 	 TOUTPS1	 @ ((unsigned)&T2CON*8)+4;
volatile 	 bit 	 TOUTPS0	 @ ((unsigned)&T2CON*8)+3;
volatile 	 bit 	 TMR2ON	 @ ((unsigned)&T2CON*8)+2;
volatile 	 bit 	 T2CKPS1	 @ ((unsigned)&T2CON*8)+1;
volatile 	 bit 	 T2CKPS0	 @ ((unsigned)&T2CON*8)+0;

/* Definitions for OSCCON  register */
volatile 	 bit 	 IRCF2	 @ ((unsigned)&OSCCON*8)+6;
volatile 	 bit 	 IRCF1	 @ ((unsigned)&OSCCON*8)+5;
volatile 	 bit 	 IRCF0	 @ ((unsigned)&OSCCON*8)+4;
volatile 	 bit 	 SWDTEN	 @ ((unsigned)&OSCCON*8)+1;

/* Definitions for PWMCON0  register */
volatile 	 bit 	 CLKDIV2	 @ ((unsigned)&PWMCON0*8)+7;
volatile 	 bit 	 CLKDIV1	 @ ((unsigned)&PWMCON0*8)+6;
volatile 	 bit 	 CLKDIV0	 @ ((unsigned)&PWMCON0*8)+5;
volatile 	 bit 	 PWM4EN	 @ ((unsigned)&PWMCON0*8)+4;
volatile 	 bit 	 PWM3EN	 @ ((unsigned)&PWMCON0*8)+3;
volatile 	 bit 	 PWM2EN	 @ ((unsigned)&PWMCON0*8)+2;
volatile 	 bit 	 PWM1EN	 @ ((unsigned)&PWMCON0*8)+1;
volatile 	 bit 	 PWM0EN	 @ ((unsigned)&PWMCON0*8)+0;

/* Definitions for PWMCON1  register */
volatile 	 bit 	 PWM2DTEN	 @ ((unsigned)&PWMCON1*8)+5;
volatile 	 bit 	 PWM0DTEN	 @ ((unsigned)&PWMCON1*8)+4;
volatile 	 bit 	 DT_DIV1	 @ ((unsigned)&PWMCON1*8)+1;
volatile 	 bit 	 DT_DIV0	 @ ((unsigned)&PWMCON1*8)+0;

/* Definitions for PWMTH  register */
volatile 	 bit 	 PWM4D9	 @ ((unsigned)&PWMTH*8)+5;
volatile 	 bit 	 PWM4D8	 @ ((unsigned)&PWMTH*8)+4;
volatile 	 bit 	 PWM4T9	 @ ((unsigned)&PWMTH*8)+3;
volatile 	 bit 	 PWM4T8	 @ ((unsigned)&PWMTH*8)+2;
volatile 	 bit 	 PWMT9	 @ ((unsigned)&PWMTH*8)+1;
volatile 	 bit 	 PWMT8	 @ ((unsigned)&PWMTH*8)+0;

/* Definitions for PWMCON2  register */
volatile 	 bit 	 PWM4DIR	 @ ((unsigned)&PWMCON2*8)+4;
volatile 	 bit 	 PWM3DIR	 @ ((unsigned)&PWMCON2*8)+3;
volatile 	 bit 	 PWM2DIR	 @ ((unsigned)&PWMCON2*8)+2;
volatile 	 bit 	 PWM1DIR	 @ ((unsigned)&PWMCON2*8)+1;
volatile 	 bit 	 PWM0DIR	 @ ((unsigned)&PWMCON2*8)+0;

/* Definitions for PWMD01H  register */
volatile 	 bit 	 PWMD19	 @ ((unsigned)&PWMD01H*8)+5;
volatile 	 bit 	 PWMD18	 @ ((unsigned)&PWMD01H*8)+4;
volatile 	 bit 	 PWMD09	 @ ((unsigned)&PWMD01H*8)+1;
volatile 	 bit 	 PWMD08	 @ ((unsigned)&PWMD01H*8)+0;

/* Definitions for PWM01DT  register */
volatile 	 bit 	 PWM01DT5	 @ ((unsigned)&PWM01DT*8)+5;
volatile 	 bit 	 PWM01DT4	 @ ((unsigned)&PWM01DT*8)+4;
volatile 	 bit 	 PWM01DT3	 @ ((unsigned)&PWM01DT*8)+3;
volatile 	 bit 	 PWM01DT2	 @ ((unsigned)&PWM01DT*8)+2;
volatile 	 bit 	 PWM01DT1	 @ ((unsigned)&PWM01DT*8)+1;
volatile 	 bit 	 PWM01DT0	 @ ((unsigned)&PWM01DT*8)+0;

/* Definitions for PWMD23H  register */
volatile 	 bit 	 PWMD39	 @ ((unsigned)&PWMD23H*8)+5;
volatile 	 bit 	 PWMD38	 @ ((unsigned)&PWMD23H*8)+4;
volatile 	 bit 	 PWMD29	 @ ((unsigned)&PWMD23H*8)+1;
volatile 	 bit 	 PWMD28	 @ ((unsigned)&PWMD23H*8)+0;

/* Definitions for PIR2  register */
volatile 	 bit 	 TKIF	 @ ((unsigned)&PIR2*8)+6;

/* Definitions for PIE2  register */
volatile 	 bit 	 TKIE	 @ ((unsigned)&PIE2*8)+6;

/* Definitions for KEYCON0  register */
volatile 	 bit 	 KDONE	 @ ((unsigned)&KEYCON0*8)+7;
volatile 	 bit 	 KTOUT	 @ ((unsigned)&KEYCON0*8)+2;
volatile 	 bit 	 KCAP	 @ ((unsigned)&KEYCON0*8)+1;
volatile 	 bit 	 KEN	 @ ((unsigned)&KEYCON0*8)+0;

/* Definitions for KEYCON1  register */
volatile 	 bit 	 KVREF1	 @ ((unsigned)&KEYCON1*8)+7;
volatile 	 bit 	 KVREF0	 @ ((unsigned)&KEYCON1*8)+6;
volatile 	 bit 	 KCLK1	 @ ((unsigned)&KEYCON1*8)+5;
volatile 	 bit 	 KCLK0	 @ ((unsigned)&KEYCON1*8)+4;
volatile 	 bit 	 KCHS3	 @ ((unsigned)&KEYCON1*8)+3;
volatile 	 bit 	 KCHS2	 @ ((unsigned)&KEYCON1*8)+2;
volatile 	 bit 	 KCHS1	 @ ((unsigned)&KEYCON1*8)+1;
volatile 	 bit 	 KCHS0	 @ ((unsigned)&KEYCON1*8)+0;

/* Definitions for KEYCON2  register */
volatile 	 bit 	 CAP_LVBO2	 @ ((unsigned)&KEYCON2*8)+7;
volatile 	 bit 	 CAP_LVBO1	 @ ((unsigned)&KEYCON2*8)+6;
volatile 	 bit 	 CAP_LVBO0	 @ ((unsigned)&KEYCON2*8)+5;
volatile 	 bit 	 TP_EN	 @ ((unsigned)&KEYCON2*8)+4;
volatile 	 bit 	 TKLDOEN	 @ ((unsigned)&KEYCON2*8)+3;
volatile 	 bit 	 TKEN	 @ ((unsigned)&KEYCON2*8)+0;

#endif
