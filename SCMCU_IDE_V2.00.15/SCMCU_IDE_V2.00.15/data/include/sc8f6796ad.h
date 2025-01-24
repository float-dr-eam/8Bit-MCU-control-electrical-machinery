#ifndef _HTC_H_
#warning Header file sc8f6796ad.h included directly. Use #include <sc.h> instead.
#endif

/* header file for the scmcu microcontroller. Base On Datasheet V0.1
    SC8F6796AD
*/

#ifndef __SC8F6796AD_H
#define __SC8F6796AD_H


volatile 	unsigned char 	INDF		@	0x00;
volatile 	unsigned char 	TMR0		@	0x01;
volatile 	unsigned char 	PCL			@	0x02;
volatile 	unsigned char 	STATUS		@	0x03;
volatile 	unsigned char 	FSR			@	0x04;
volatile 	unsigned char 	PORTA		@	0x05;
volatile 	unsigned char 	PORTB		@	0x06;
volatile 	unsigned char 	PORTC		@	0x07;
volatile 	unsigned char 	PORTD		@	0x08;
volatile 	unsigned char 	ANSEL0		@	0x09;
volatile 	unsigned char 	PCLATH		@	0x0A;
volatile 	unsigned char 	INTCON		@	0x0B;
volatile 	unsigned char 	PIR1		@	0x0C;
volatile 	unsigned char 	PIR2		@	0x0D;
volatile 	unsigned char 	TMR1L		@	0x0E;
volatile 	unsigned char 	TMR1H		@	0x0F;
volatile 	unsigned char 	T1CON		@	0x10;
volatile 	unsigned char 	TMR2		@	0x11;
volatile 	unsigned char 	T2CON		@	0x12;
volatile 	unsigned char 	SSPBUF		@	0x13;
volatile 	unsigned char 	SSPCON		@	0x14;
volatile 	unsigned char 	CPTRL		@	0x15;
volatile 	unsigned char 	CPTRH		@	0x16;
volatile 	unsigned char 	CPTCON		@	0x17;
volatile 	unsigned char 	RCSTA0		@	0x18;
volatile 	unsigned char 	TXREG0		@	0x19;
volatile 	unsigned char 	RCREG0		@	0x1A;
volatile 	unsigned char 	TABLE_SPH	@	0x1B;
volatile 	unsigned char 	TABLE_SPL	@	0x1C;
volatile 	unsigned char 	TABLE_DATAH	@	0x1D;
volatile 	unsigned char 	TXSTA0		@	0x1E;
volatile 	unsigned char 	SPBRG0		@	0x1F;
volatile 	unsigned char 	OPTION_REG	@	0x81;
volatile 	unsigned char 	TRISA		@	0x85;
volatile 	unsigned char 	TRISB		@	0x86;
volatile 	unsigned char 	TRISC		@	0x87;
volatile 	unsigned char 	TRISD		@	0x88;
volatile 	unsigned char 	ANSEL1		@	0x89;
volatile 	unsigned char 	PIE1		@	0x8C;
volatile 	unsigned char 	PIE2		@	0x8D;
volatile 	unsigned char 	WPUD		@	0x8E;
volatile 	unsigned char 	OSCCON		@	0x8F;
volatile 	unsigned char 	WDTCON		@	0x90;
volatile 	unsigned char 	SSPCON2		@	0x91;
volatile 	unsigned char 	PR2			@	0x92;
volatile 	unsigned char 	SSPADD		@	0x93;
volatile 	unsigned char 	SSPMSK		@	0x93;
volatile 	unsigned char 	SSPSTAT		@	0x94;
volatile 	unsigned char 	WPUB		@	0x95;
volatile 	unsigned char 	IOCB		@	0x96;
volatile 	unsigned char 	WPDB		@	0x97;
volatile 	unsigned char 	WPUA		@	0x99;
volatile 	unsigned char 	WPUC		@	0x9A;
volatile 	unsigned char 	ANSEL2		@	0x9B;
volatile 	unsigned char 	ADRESL		@	0x9C;
volatile 	unsigned char 	ADRESH		@	0x9D;
volatile 	unsigned char 	ADCON0		@	0x9E;
volatile 	unsigned char 	ADCON1		@	0x9F;
volatile 	unsigned char 	RCSTA1		@	0x105;
volatile 	unsigned char 	PWMCON0		@	0x106;
volatile 	unsigned char 	PWMCON1		@	0x107;
volatile 	unsigned char 	PWMCON2		@	0x108;
volatile 	unsigned char 	PWM4TL		@	0x109;
volatile 	unsigned char 	PWMD0L		@	0x10C;
volatile 	unsigned char 	PWMD1L		@	0x10D;
volatile 	unsigned char 	PWMD2L		@	0x10E;
volatile 	unsigned char 	PWMD3L		@	0x10F;
volatile 	unsigned char 	PWMD4L		@	0x110;
volatile 	unsigned char 	PWMD01H		@	0x111;
volatile 	unsigned char 	PWMD23H		@	0x112;
volatile 	unsigned char 	LEDCON0		@	0x113;
volatile 	unsigned char 	LEDADD		@	0x115;
volatile 	unsigned char 	LEDDATA		@	0x116;
volatile 	unsigned char 	SEGEN2		@	0x117;
volatile 	unsigned char 	SEGEN1		@	0x118;
volatile 	unsigned char 	SEGEN0		@	0x119;
volatile 	unsigned char 	COMEN		@	0x11A;
volatile 	unsigned char 	PWMTL		@	0x11B;
volatile 	unsigned char 	PWMTH		@	0x11C;
volatile 	unsigned char 	LVDCON		@	0x185;
volatile 	unsigned char 	EEDAT		@	0x186;
volatile 	unsigned char 	EEADR		@	0x187;
volatile 	unsigned char 	EEDATH		@	0x188;
volatile 	unsigned char 	EEADRH		@	0x189;
volatile 	unsigned char 	EECON1		@	0x18C;
volatile 	unsigned char 	EECON2		@	0x18D;
volatile 	unsigned char 	PWM01DT		@	0x18E;
volatile 	unsigned char 	PWM23DT		@	0x18F;
/* Definitions for STATUS  register */
volatile 	 bit 	 IRP	 @ ((unsigned)&STATUS*8)+7;
volatile 	 bit 	 RP1	 @ ((unsigned)&STATUS*8)+6;
volatile 	 bit 	 RP0	 @ ((unsigned)&STATUS*8)+5;
volatile 	 bit 	 TO	 @ ((unsigned)&STATUS*8)+4;
volatile 	 bit 	 PD	 @ ((unsigned)&STATUS*8)+3;
volatile 	 bit 	 Z	 @ ((unsigned)&STATUS*8)+2;
volatile 	 bit 	 DC	 @ ((unsigned)&STATUS*8)+1;
volatile 	 bit 	 C	 @ ((unsigned)&STATUS*8)+0;

/* Definitions for PORTA  register */
volatile 	 bit 	 RA7	 @ ((unsigned)&PORTA*8)+7;
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

/* Definitions for PORTC  register */
volatile 	 bit 	 RC7	 @ ((unsigned)&PORTC*8)+7;
volatile 	 bit 	 RC6	 @ ((unsigned)&PORTC*8)+6;
volatile 	 bit 	 RC5	 @ ((unsigned)&PORTC*8)+5;
volatile 	 bit 	 RC4	 @ ((unsigned)&PORTC*8)+4;
volatile 	 bit 	 RC3	 @ ((unsigned)&PORTC*8)+3;
volatile 	 bit 	 RC2	 @ ((unsigned)&PORTC*8)+2;
volatile 	 bit 	 RC1	 @ ((unsigned)&PORTC*8)+1;
volatile 	 bit 	 RC0	 @ ((unsigned)&PORTC*8)+0;

/* Definitions for PORTD  register */
volatile 	 bit 	 RD2	 @ ((unsigned)&PORTD*8)+2;
volatile 	 bit 	 RD1	 @ ((unsigned)&PORTD*8)+1;
volatile 	 bit 	 RD0	 @ ((unsigned)&PORTD*8)+0;

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
volatile 	 bit 	 PWMIF	 @ ((unsigned)&PIR1*8)+7;
volatile 	 bit 	 ADIF	 @ ((unsigned)&PIR1*8)+6;
volatile 	 bit 	 RC0IF	 @ ((unsigned)&PIR1*8)+5;
volatile 	 bit 	 TX0IF	 @ ((unsigned)&PIR1*8)+4;
volatile 	 bit 	 SSPIF	 @ ((unsigned)&PIR1*8)+3;
volatile 	 bit 	 CPTIF	 @ ((unsigned)&PIR1*8)+2;
volatile 	 bit 	 TMR2IF	 @ ((unsigned)&PIR1*8)+1;
volatile 	 bit 	 TMR1IF	 @ ((unsigned)&PIR1*8)+0;

/* Definitions for PIR2  register */
volatile 	 bit 	 LVDIF	 @ ((unsigned)&PIR2*8)+7;
volatile 	 bit 	 EEIF	 @ ((unsigned)&PIR2*8)+4;
volatile 	 bit 	 BCLIF	 @ ((unsigned)&PIR2*8)+3;

/* Definitions for T1CON  register */
volatile 	 bit 	 T1GINV	 @ ((unsigned)&T1CON*8)+7;
volatile 	 bit 	 TMR1GE	 @ ((unsigned)&T1CON*8)+6;
volatile 	 bit 	 T1CKPS1	 @ ((unsigned)&T1CON*8)+5;
volatile 	 bit 	 T1CKPS0	 @ ((unsigned)&T1CON*8)+4;
volatile 	 bit 	 T1SYNC	 @ ((unsigned)&T1CON*8)+2;
volatile 	 bit 	 TMR1CS	 @ ((unsigned)&T1CON*8)+1;
volatile 	 bit 	 TMR1ON	 @ ((unsigned)&T1CON*8)+0;

/* Definitions for T2CON  register */
volatile 	 bit 	 TOUTPS3	 @ ((unsigned)&T2CON*8)+6;
volatile 	 bit 	 TOUTPS2	 @ ((unsigned)&T2CON*8)+5;
volatile 	 bit 	 TOUTPS1	 @ ((unsigned)&T2CON*8)+4;
volatile 	 bit 	 TOUTPS0	 @ ((unsigned)&T2CON*8)+3;
volatile 	 bit 	 TMR2ON	 @ ((unsigned)&T2CON*8)+2;
volatile 	 bit 	 T2CKPS1	 @ ((unsigned)&T2CON*8)+1;
volatile 	 bit 	 T2CKPS0	 @ ((unsigned)&T2CON*8)+0;

/* Definitions for SSPCON  register */
volatile 	 bit 	 WCOL	 @ ((unsigned)&SSPCON*8)+7;
volatile 	 bit 	 SSPOV	 @ ((unsigned)&SSPCON*8)+6;
volatile 	 bit 	 SSPEN	 @ ((unsigned)&SSPCON*8)+5;
volatile 	 bit 	 CKP	 @ ((unsigned)&SSPCON*8)+4;
volatile 	 bit 	 SSPM3	 @ ((unsigned)&SSPCON*8)+3;
volatile 	 bit 	 SSPM2	 @ ((unsigned)&SSPCON*8)+2;
volatile 	 bit 	 SSPM1	 @ ((unsigned)&SSPCON*8)+1;
volatile 	 bit 	 SSPM0	 @ ((unsigned)&SSPCON*8)+0;

/* Definitions for CPTCON  register */
volatile 	 bit 	 CPTIO_SEL1	 @ ((unsigned)&CPTCON*8)+5;
volatile 	 bit 	 CPTIO_SEL0	 @ ((unsigned)&CPTCON*8)+4;
volatile 	 bit 	 CPTM3	 @ ((unsigned)&CPTCON*8)+3;
volatile 	 bit 	 CPTM2	 @ ((unsigned)&CPTCON*8)+2;
volatile 	 bit 	 CPTM1	 @ ((unsigned)&CPTCON*8)+1;
volatile 	 bit 	 CPTM0	 @ ((unsigned)&CPTCON*8)+0;

/* Definitions for RCSTA0  register */
volatile 	 bit 	 SPEN0	 @ ((unsigned)&RCSTA0*8)+7;
volatile 	 bit 	 RX9EN0	 @ ((unsigned)&RCSTA0*8)+6;
volatile 	 bit 	 SREN0	 @ ((unsigned)&RCSTA0*8)+5;
volatile 	 bit 	 CREN0	 @ ((unsigned)&RCSTA0*8)+4;
volatile 	 bit 	 RCIDL0	 @ ((unsigned)&RCSTA0*8)+3;
volatile 	 bit 	 FERR0	 @ ((unsigned)&RCSTA0*8)+2;
volatile 	 bit 	 OERR0	 @ ((unsigned)&RCSTA0*8)+1;
volatile 	 bit 	 RX9D0	 @ ((unsigned)&RCSTA0*8)+0;

/* Definitions for TXSTA0  register */
volatile 	 bit 	 CSRC0	 @ ((unsigned)&TXSTA0*8)+7;
volatile 	 bit 	 TX9EN0	 @ ((unsigned)&TXSTA0*8)+6;
volatile 	 bit 	 TXEN0	 @ ((unsigned)&TXSTA0*8)+5;
volatile 	 bit 	 SYNC0	 @ ((unsigned)&TXSTA0*8)+4;
volatile 	 bit 	 SCKP0	 @ ((unsigned)&TXSTA0*8)+3;
volatile 	 bit 	 TRMT0	 @ ((unsigned)&TXSTA0*8)+1;
volatile 	 bit 	 TX9D0	 @ ((unsigned)&TXSTA0*8)+0;

/* Definitions for SPBRG0  register */
volatile 	 bit 	 BRG07	 @ ((unsigned)&SPBRG0*8)+7;
volatile 	 bit 	 BRG06	 @ ((unsigned)&SPBRG0*8)+6;
volatile 	 bit 	 BRG05	 @ ((unsigned)&SPBRG0*8)+5;
volatile 	 bit 	 BRG04	 @ ((unsigned)&SPBRG0*8)+4;
volatile 	 bit 	 BRG03	 @ ((unsigned)&SPBRG0*8)+3;
volatile 	 bit 	 BRG02	 @ ((unsigned)&SPBRG0*8)+2;
volatile 	 bit 	 BRG01	 @ ((unsigned)&SPBRG0*8)+1;
volatile 	 bit 	 BRG00	 @ ((unsigned)&SPBRG0*8)+0;

/* Definitions for OPTION_REG  register */
volatile 	 bit 	 RBPU	 @ ((unsigned)&OPTION_REG*8)+7;
volatile 	 bit 	 INTEDG	 @ ((unsigned)&OPTION_REG*8)+6;
volatile 	 bit 	 T0CS	 @ ((unsigned)&OPTION_REG*8)+5;
volatile 	 bit 	 T0SE	 @ ((unsigned)&OPTION_REG*8)+4;
volatile 	 bit 	 PSA	 @ ((unsigned)&OPTION_REG*8)+3;
volatile 	 bit 	 PS2	 @ ((unsigned)&OPTION_REG*8)+2;
volatile 	 bit 	 PS1	 @ ((unsigned)&OPTION_REG*8)+1;
volatile 	 bit 	 PS0	 @ ((unsigned)&OPTION_REG*8)+0;

/* Definitions for TRISA  register */
volatile 	 bit 	 TRISA7	 @ ((unsigned)&TRISA*8)+7;
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

/* Definitions for TRISC  register */
volatile 	 bit 	 TRISC7	 @ ((unsigned)&TRISC*8)+7;
volatile 	 bit 	 TRISC6	 @ ((unsigned)&TRISC*8)+6;
volatile 	 bit 	 TRISC5	 @ ((unsigned)&TRISC*8)+5;
volatile 	 bit 	 TRISC4	 @ ((unsigned)&TRISC*8)+4;
volatile 	 bit 	 TRISC3	 @ ((unsigned)&TRISC*8)+3;
volatile 	 bit 	 TRISC2	 @ ((unsigned)&TRISC*8)+2;
volatile 	 bit 	 TRISC1	 @ ((unsigned)&TRISC*8)+1;
volatile 	 bit 	 TRISC0	 @ ((unsigned)&TRISC*8)+0;

/* Definitions for TRISD  register */
volatile 	 bit 	 TRISD2	 @ ((unsigned)&TRISD*8)+2;
volatile 	 bit 	 TRISD1	 @ ((unsigned)&TRISD*8)+1;
volatile 	 bit 	 TRISD0	 @ ((unsigned)&TRISD*8)+0;

/* Definitions for PIE1  register */
volatile 	 bit 	 PWMIE	 @ ((unsigned)&PIE1*8)+7;
volatile 	 bit 	 ADIE	 @ ((unsigned)&PIE1*8)+6;
volatile 	 bit 	 RC0IE	 @ ((unsigned)&PIE1*8)+5;
volatile 	 bit 	 TX0IE	 @ ((unsigned)&PIE1*8)+4;
volatile 	 bit 	 SSPIE	 @ ((unsigned)&PIE1*8)+3;
volatile 	 bit 	 CPTIE	 @ ((unsigned)&PIE1*8)+2;
volatile 	 bit 	 TMR2IE	 @ ((unsigned)&PIE1*8)+1;
volatile 	 bit 	 TMR1IE	 @ ((unsigned)&PIE1*8)+0;

/* Definitions for PIE2  register */
volatile 	 bit 	 LVDIE	 @ ((unsigned)&PIE2*8)+7;
volatile 	 bit 	 EEIE	 @ ((unsigned)&PIE2*8)+4;
volatile 	 bit 	 BCLIE	 @ ((unsigned)&PIE2*8)+3;

/* Definitions for WPUD  register */
volatile 	 bit 	 WPUD2	 @ ((unsigned)&WPUD*8)+2;
volatile 	 bit 	 WPUD1	 @ ((unsigned)&WPUD*8)+1;
volatile 	 bit 	 WPUD0	 @ ((unsigned)&WPUD*8)+0;

/* Definitions for OSCCON  register */
volatile 	 bit 	 IRCF2	 @ ((unsigned)&OSCCON*8)+6;
volatile 	 bit 	 IRCF1	 @ ((unsigned)&OSCCON*8)+5;
volatile 	 bit 	 IRCF0	 @ ((unsigned)&OSCCON*8)+4;

/* Definitions for WDTCON  register */
volatile 	 bit 	 SWDTEN	 @ ((unsigned)&WDTCON*8)+0;

/* Definitions for SSPCON2  register */
volatile 	 bit 	 GCEN	 @ ((unsigned)&SSPCON2*8)+7;
volatile 	 bit 	 ACKSTAT	 @ ((unsigned)&SSPCON2*8)+6;
volatile 	 bit 	 ACKDT	 @ ((unsigned)&SSPCON2*8)+5;
volatile 	 bit 	 ACKEN	 @ ((unsigned)&SSPCON2*8)+4;
volatile 	 bit 	 RCEN	 @ ((unsigned)&SSPCON2*8)+3;
volatile 	 bit 	 PEN	 @ ((unsigned)&SSPCON2*8)+2;
volatile 	 bit 	 RSEN	 @ ((unsigned)&SSPCON2*8)+1;
volatile 	 bit 	 SEN	 @ ((unsigned)&SSPCON2*8)+0;

/* Definitions for SSPMSK  register */
volatile 	 bit 	 MSK7	 @ ((unsigned)&SSPMSK*8)+7;
volatile 	 bit 	 MSK6	 @ ((unsigned)&SSPMSK*8)+6;
volatile 	 bit 	 MSK5	 @ ((unsigned)&SSPMSK*8)+5;
volatile 	 bit 	 MSK4	 @ ((unsigned)&SSPMSK*8)+4;
volatile 	 bit 	 MSK3	 @ ((unsigned)&SSPMSK*8)+3;
volatile 	 bit 	 MSK2	 @ ((unsigned)&SSPMSK*8)+2;
volatile 	 bit 	 MSK1	 @ ((unsigned)&SSPMSK*8)+1;
volatile 	 bit 	 MSK0	 @ ((unsigned)&SSPMSK*8)+0;

/* Definitions for SSPSTAT  register */
volatile 	 bit 	 CKE	 @ ((unsigned)&SSPSTAT*8)+6;
volatile 	 bit 	 DA	 @ ((unsigned)&SSPSTAT*8)+5;
volatile 	 bit 	 P	 @ ((unsigned)&SSPSTAT*8)+4;
volatile 	 bit 	 S	 @ ((unsigned)&SSPSTAT*8)+3;
volatile 	 bit 	 RW	 @ ((unsigned)&SSPSTAT*8)+2;
volatile 	 bit 	 IICTOF	 @ ((unsigned)&SSPSTAT*8)+1;
volatile 	 bit 	 BF	 @ ((unsigned)&SSPSTAT*8)+0;

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

/* Definitions for WPDB  register */
volatile 	 bit 	 WPDB6	 @ ((unsigned)&WPDB*8)+6;
volatile 	 bit 	 WPDB5	 @ ((unsigned)&WPDB*8)+5;
volatile 	 bit 	 WPDB4	 @ ((unsigned)&WPDB*8)+4;
volatile 	 bit 	 WPDB3	 @ ((unsigned)&WPDB*8)+3;
volatile 	 bit 	 WPDB2	 @ ((unsigned)&WPDB*8)+2;
volatile 	 bit 	 WPDB1	 @ ((unsigned)&WPDB*8)+1;
volatile 	 bit 	 WPDB0	 @ ((unsigned)&WPDB*8)+0;

/* Definitions for WPUA  register */
volatile 	 bit 	 WPUA7	 @ ((unsigned)&WPUA*8)+7;
volatile 	 bit 	 WPUA6	 @ ((unsigned)&WPUA*8)+6;
volatile 	 bit 	 WPUA5	 @ ((unsigned)&WPUA*8)+5;
volatile 	 bit 	 WPUA4	 @ ((unsigned)&WPUA*8)+4;
volatile 	 bit 	 WPUA3	 @ ((unsigned)&WPUA*8)+3;
volatile 	 bit 	 WPUA2	 @ ((unsigned)&WPUA*8)+2;
volatile 	 bit 	 WPUA1	 @ ((unsigned)&WPUA*8)+1;
volatile 	 bit 	 WPUA0	 @ ((unsigned)&WPUA*8)+0;

/* Definitions for WPUC  register */
volatile 	 bit 	 WPUC7	 @ ((unsigned)&WPUC*8)+7;
volatile 	 bit 	 WPUC6	 @ ((unsigned)&WPUC*8)+6;
volatile 	 bit 	 WPUC5	 @ ((unsigned)&WPUC*8)+5;
volatile 	 bit 	 WPUC4	 @ ((unsigned)&WPUC*8)+4;
volatile 	 bit 	 WPUC3	 @ ((unsigned)&WPUC*8)+3;
volatile 	 bit 	 WPUC2	 @ ((unsigned)&WPUC*8)+2;
volatile 	 bit 	 WPUC1	 @ ((unsigned)&WPUC*8)+1;
volatile 	 bit 	 WPUC0	 @ ((unsigned)&WPUC*8)+0;

/* Definitions for ADCON0  register */
volatile 	 bit 	 ADCS1	 @ ((unsigned)&ADCON0*8)+7;
volatile 	 bit 	 ADCS0	 @ ((unsigned)&ADCON0*8)+6;
volatile 	 bit 	 CHS3	 @ ((unsigned)&ADCON0*8)+5;
volatile 	 bit 	 CHS2	 @ ((unsigned)&ADCON0*8)+4;
volatile 	 bit 	 CHS1	 @ ((unsigned)&ADCON0*8)+3;
volatile 	 bit 	 CHS0	 @ ((unsigned)&ADCON0*8)+2;
volatile 	 bit 	 GODONE	 @ ((unsigned)&ADCON0*8)+1;
volatile 	 bit 	 ADON	 @ ((unsigned)&ADCON0*8)+0;

/* Definitions for ADCON1  register */
volatile 	 bit 	 ADFM	 @ ((unsigned)&ADCON1*8)+7;
volatile 	 bit 	 CHS4	 @ ((unsigned)&ADCON1*8)+6;

/* Definitions for RCSTA1  register */
volatile 	 bit 	 SPEN1	 @ ((unsigned)&RCSTA1*8)+7;
volatile 	 bit 	 RX9EN1	 @ ((unsigned)&RCSTA1*8)+6;
volatile 	 bit 	 SREN1	 @ ((unsigned)&RCSTA1*8)+5;
volatile 	 bit 	 CREN1	 @ ((unsigned)&RCSTA1*8)+4;
volatile 	 bit 	 RCIDL1	 @ ((unsigned)&RCSTA1*8)+3;
volatile 	 bit 	 FERR1	 @ ((unsigned)&RCSTA1*8)+2;
volatile 	 bit 	 OERR1	 @ ((unsigned)&RCSTA1*8)+1;
volatile 	 bit 	 RX9D1	 @ ((unsigned)&RCSTA1*8)+0;

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
volatile 	 bit 	 PWMIO_SEL	 @ ((unsigned)&PWMCON1*8)+6;
volatile 	 bit 	 PWM2DTEN	 @ ((unsigned)&PWMCON1*8)+5;
volatile 	 bit 	 PWM0DTEN	 @ ((unsigned)&PWMCON1*8)+4;
volatile 	 bit 	 DT_DIV1	 @ ((unsigned)&PWMCON1*8)+1;
volatile 	 bit 	 DT_DIV0	 @ ((unsigned)&PWMCON1*8)+0;

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

/* Definitions for PWMD23H  register */
volatile 	 bit 	 PWMD39	 @ ((unsigned)&PWMD23H*8)+5;
volatile 	 bit 	 PWMD38	 @ ((unsigned)&PWMD23H*8)+4;
volatile 	 bit 	 PWMD29	 @ ((unsigned)&PWMD23H*8)+1;
volatile 	 bit 	 PWMD28	 @ ((unsigned)&PWMD23H*8)+0;

/* Definitions for LEDCON0  register */
volatile 	 bit 	 LEDEN	 @ ((unsigned)&LEDCON0*8)+6;
volatile 	 bit 	 COMSEL1	 @ ((unsigned)&LEDCON0*8)+5;
volatile 	 bit 	 COMSEL0	 @ ((unsigned)&LEDCON0*8)+4;
volatile 	 bit 	 LEDCLK3	 @ ((unsigned)&LEDCON0*8)+3;
volatile 	 bit 	 LEDCLK2	 @ ((unsigned)&LEDCON0*8)+2;
volatile 	 bit 	 LEDCLK1	 @ ((unsigned)&LEDCON0*8)+1;
volatile 	 bit 	 LEDCLK0	 @ ((unsigned)&LEDCON0*8)+0;

/* Definitions for LEDADD  register */
volatile 	 bit 	 LEDCS	 @ ((unsigned)&LEDADD*8)+7;
volatile 	 bit 	 LEDM	 @ ((unsigned)&LEDADD*8)+6;
volatile 	 bit 	 COMSEL2	 @ ((unsigned)&LEDADD*8)+5;
volatile 	 bit 	 LEDADD4	 @ ((unsigned)&LEDADD*8)+4;
volatile 	 bit 	 LEDADD3	 @ ((unsigned)&LEDADD*8)+3;
volatile 	 bit 	 LEDADD2	 @ ((unsigned)&LEDADD*8)+2;
volatile 	 bit 	 LEDADD1	 @ ((unsigned)&LEDADD*8)+1;
volatile 	 bit 	 LEDADD0	 @ ((unsigned)&LEDADD*8)+0;

/* Definitions for PWMTH  register */
volatile 	 bit 	 PWMD49	 @ ((unsigned)&PWMTH*8)+5;
volatile 	 bit 	 PWMD48	 @ ((unsigned)&PWMTH*8)+4;
volatile 	 bit 	 PWM4T9	 @ ((unsigned)&PWMTH*8)+3;
volatile 	 bit 	 PWM4T8	 @ ((unsigned)&PWMTH*8)+2;
volatile 	 bit 	 PWMT9	 @ ((unsigned)&PWMTH*8)+1;
volatile 	 bit 	 PWMT8	 @ ((unsigned)&PWMTH*8)+0;

/* Definitions for LVDCON  register */
volatile 	 bit 	 LVD_RES	 @ ((unsigned)&LVDCON*8)+7;
volatile 	 bit 	 LVD_SEL2	 @ ((unsigned)&LVDCON*8)+3;
volatile 	 bit 	 LVD_SEL1	 @ ((unsigned)&LVDCON*8)+2;
volatile 	 bit 	 LVD_SEL0	 @ ((unsigned)&LVDCON*8)+1;
volatile 	 bit 	 LVDEN	 @ ((unsigned)&LVDCON*8)+0;

/* Definitions for EEDAT  register */
volatile 	 bit 	 EEDAT7	 @ ((unsigned)&EEDAT*8)+7;
volatile 	 bit 	 EEDAT6	 @ ((unsigned)&EEDAT*8)+6;
volatile 	 bit 	 EEDAT5	 @ ((unsigned)&EEDAT*8)+5;
volatile 	 bit 	 EEDAT4	 @ ((unsigned)&EEDAT*8)+4;
volatile 	 bit 	 EEDAT3	 @ ((unsigned)&EEDAT*8)+3;
volatile 	 bit 	 EEDAT2	 @ ((unsigned)&EEDAT*8)+2;
volatile 	 bit 	 EEDAT1	 @ ((unsigned)&EEDAT*8)+1;
volatile 	 bit 	 EEDAT0	 @ ((unsigned)&EEDAT*8)+0;

/* Definitions for EEADR  register */
volatile 	 bit 	 EEADR7	 @ ((unsigned)&EEADR*8)+7;
volatile 	 bit 	 EEADR6	 @ ((unsigned)&EEADR*8)+6;
volatile 	 bit 	 EEADR5	 @ ((unsigned)&EEADR*8)+5;
volatile 	 bit 	 EEADR4	 @ ((unsigned)&EEADR*8)+4;
volatile 	 bit 	 EEADR3	 @ ((unsigned)&EEADR*8)+3;
volatile 	 bit 	 EEADR2	 @ ((unsigned)&EEADR*8)+2;
volatile 	 bit 	 EEADR1	 @ ((unsigned)&EEADR*8)+1;
volatile 	 bit 	 EEADR0	 @ ((unsigned)&EEADR*8)+0;

/* Definitions for EEDATH  register */
volatile 	 bit 	 EEDATH7	 @ ((unsigned)&EEDATH*8)+7;
volatile 	 bit 	 EEDATH6	 @ ((unsigned)&EEDATH*8)+6;
volatile 	 bit 	 EEDATH5	 @ ((unsigned)&EEDATH*8)+5;
volatile 	 bit 	 EEDATH4	 @ ((unsigned)&EEDATH*8)+4;
volatile 	 bit 	 EEDATH3	 @ ((unsigned)&EEDATH*8)+3;
volatile 	 bit 	 EEDATH2	 @ ((unsigned)&EEDATH*8)+2;
volatile 	 bit 	 EEDATH1	 @ ((unsigned)&EEDATH*8)+1;
volatile 	 bit 	 EEDATH0	 @ ((unsigned)&EEDATH*8)+0;

/* Definitions for EEADRH  register */
volatile 	 bit 	 EEADRH4	 @ ((unsigned)&EEADRH*8)+4;
volatile 	 bit 	 EEADRH3	 @ ((unsigned)&EEADRH*8)+3;
volatile 	 bit 	 EEADRH2	 @ ((unsigned)&EEADRH*8)+2;
volatile 	 bit 	 EEADRH1	 @ ((unsigned)&EEADRH*8)+1;
volatile 	 bit 	 EEADRH0	 @ ((unsigned)&EEADRH*8)+0;

/* Definitions for EECON1  register */
volatile 	 bit 	 EEPGD	 @ ((unsigned)&EECON1*8)+7;
volatile 	 bit 	 WRERR	 @ ((unsigned)&EECON1*8)+3;
volatile 	 bit 	 WREN	 @ ((unsigned)&EECON1*8)+2;
volatile 	 bit 	 WR	 @ ((unsigned)&EECON1*8)+1;
volatile 	 bit 	 RD	 @ ((unsigned)&EECON1*8)+0;

#endif
