#ifndef _HTC_H_
#warning Header file sc8f6890.h included directly. Use #include <sc.h> instead.
#endif

/* header file for the cms microcontroller. Base On Datasheet V1.0
    SC8F6890
*/


#ifndef __SC8F6890_H
#define __SC8F6890_H


volatile 	unsigned char 	INDF	@	0x00;
volatile 	unsigned char 	TMR0	@	0x01;
volatile 	unsigned char 	PCL	@	0x02;
volatile 	unsigned char 	STATUS	@	0x03;
volatile 	unsigned char 	FSR	@	0x04;
volatile 	unsigned char 	PORTA	@	0x05;
volatile 	unsigned char 	PORTB	@	0x06;
volatile 	unsigned char 	PORTC	@	0x07;
volatile 	unsigned char 	PCLATH	@	0x0A;
volatile 	unsigned char 	INTCON	@	0x0B;
volatile 	unsigned char 	PIR1	@	0x0C;
volatile 	unsigned char 	PIR2	@	0x0D;
volatile 	unsigned char 	TMR1L	@	0x0E;
volatile 	unsigned char 	TMR1H	@	0x0F;
volatile 	unsigned char 	T1CON	@	0x10;
volatile 	unsigned char 	TMR2	@	0x11;
volatile 	unsigned char 	T2CON	@	0x12;
volatile 	unsigned char 	T2CON2	@	0x13;
volatile 	unsigned char 	BAUDCTL1	@	0x15;
volatile 	unsigned char 	RCREG1	@	0x16;
volatile 	unsigned char 	RCSTA1	@	0x17;
volatile 	unsigned char 	RCSTA0	@	0x18;
volatile 	unsigned char 	TXREG0	@	0x19;
volatile 	unsigned char 	RCREG0	@	0x1A;
volatile 	unsigned char 	ADRESH	@	0x1E;
volatile 	unsigned char 	ADCON0	@	0x1F;
volatile 	unsigned char 	OPTION_REG	@	0x81;
volatile 	unsigned char 	TRISA	@	0x85;
volatile 	unsigned char 	TRISB	@	0x86;
volatile 	unsigned char 	TRISC	@	0x87;
volatile 	unsigned char 	WPDA	@	0x89;
volatile 	unsigned char 	PIE1	@	0x8C;
volatile 	unsigned char 	PIE2	@	0x8D;
volatile 	unsigned char 	OSCCON	@	0x8F;
volatile 	unsigned char 	OSCTUNE	@	0x90;
volatile 	unsigned char 	PR2	@	0x92;
volatile 	unsigned char 	WPUB	@	0x95;
volatile 	unsigned char 	IOCB	@	0x96;
volatile 	unsigned char 	TXSTA1	@	0x97;
volatile 	unsigned char 	TXSTA0	@	0x98;
volatile 	unsigned char 	SPBRG0	@	0x99;
volatile 	unsigned char 	SPBRGH0	@	0x9A;
volatile 	unsigned char 	SPBRG1	@	0x9B;
volatile 	unsigned char 	SPBRGH1	@	0x9C;
volatile 	unsigned char 	TXREG1	@	0x9D;
volatile 	unsigned char 	ADRESL	@	0x9E;
volatile 	unsigned char 	ADCON1	@	0x9F;
volatile 	unsigned char 	WDTCON	@	0x105;
volatile 	unsigned char 	WPDB	@	0x107;
volatile 	unsigned char 	WPDC	@	0x108;
volatile 	unsigned char 	EEDAT	@	0x10C;
volatile 	unsigned char 	EEADR	@	0x10D;
volatile 	unsigned char 	EEDATH	@	0x10E;
volatile 	unsigned char 	EEADRH	@	0x10F;
volatile 	unsigned char 	TABLE_SPH	@	0x110;
volatile 	unsigned char 	TABLE_SPL	@	0x111;
volatile 	unsigned char 	TABLE_DATAH	@	0x112;
volatile 	unsigned char 	LCDCON	@	0x114;
volatile 	unsigned char 	LVDCON	@	0x115;
volatile 	unsigned char 	PWMTL	@	0x116;
volatile 	unsigned char 	PWMTH	@	0x117;
volatile 	unsigned char 	PWMT4L	@	0x118;
volatile 	unsigned char 	PWMD0L	@	0x119;
volatile 	unsigned char 	PWMD1L	@	0x11A;
volatile 	unsigned char 	PWMD2L	@	0x11B;
volatile 	unsigned char 	PWMD3L	@	0x11C;
volatile 	unsigned char 	PWMD4L	@	0x11D;
volatile 	unsigned char 	PWMD01H	@	0x11E;
volatile 	unsigned char 	PWMD23H	@	0x11F;
volatile 	unsigned char 	BAUDCTL0	@	0x187;
volatile 	unsigned char 	EECON1	@	0x18C;
volatile 	unsigned char 	EECON2	@	0x18D;
volatile 	unsigned char 	WPUA	@	0x18E;
volatile 	unsigned char 	WPUC	@	0x18F;
volatile 	unsigned char 	LCDCON0	@	0x190;
volatile 	unsigned char 	LCDCON1	@	0x191;
volatile 	unsigned char 	PWMCON0	@	0x192;
volatile 	unsigned char 	PWMCON1	@	0x193;
volatile 	unsigned char 	PWMCON2	@	0x194;
volatile 	unsigned char 	PWM01DT	@	0x195;
volatile 	unsigned char 	PWM23DT	@	0x196;
volatile 	unsigned char 	LCDCON2	@	0x197;
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
volatile 	 bit 	 RB7	 @ ((unsigned)&PORTB*8)+7;
volatile 	 bit 	 RB6	 @ ((unsigned)&PORTB*8)+6;
volatile 	 bit 	 RB5	 @ ((unsigned)&PORTB*8)+5;
volatile 	 bit 	 RB4	 @ ((unsigned)&PORTB*8)+4;
volatile 	 bit 	 RB3	 @ ((unsigned)&PORTB*8)+3;
volatile 	 bit 	 RB2	 @ ((unsigned)&PORTB*8)+2;
volatile 	 bit 	 RB1	 @ ((unsigned)&PORTB*8)+1;
volatile 	 bit 	 RB0	 @ ((unsigned)&PORTB*8)+0;

/* Definitions for PORTC  register */
volatile 	 bit 	 RC1	 @ ((unsigned)&PORTC*8)+1;
volatile 	 bit 	 RC0	 @ ((unsigned)&PORTC*8)+0;

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
volatile 	 bit 	 RC1IF	 @ ((unsigned)&PIR1*8)+7;
volatile 	 bit 	 TX1IF	 @ ((unsigned)&PIR1*8)+6;
volatile 	 bit 	 RC0IF	 @ ((unsigned)&PIR1*8)+5;
volatile 	 bit 	 TX0IF	 @ ((unsigned)&PIR1*8)+4;
volatile 	 bit 	 EEIF	 @ ((unsigned)&PIR1*8)+3;
volatile 	 bit 	 ADIF	 @ ((unsigned)&PIR1*8)+2;
volatile 	 bit 	 TMR2IF	 @ ((unsigned)&PIR1*8)+1;
volatile 	 bit 	 TMR1IF	 @ ((unsigned)&PIR1*8)+0;

/* Definitions for PIR2  register */
volatile 	 bit 	 PWMIF	 @ ((unsigned)&PIR2*8)+1;
volatile 	 bit 	 LVDIF	 @ ((unsigned)&PIR2*8)+0;

/* Definitions for T1CON  register */
volatile 	 bit 	 T1GINV	 @ ((unsigned)&T1CON*8)+7;
volatile 	 bit 	 TMR1GE	 @ ((unsigned)&T1CON*8)+6;
volatile 	 bit 	 T1CKPS1	 @ ((unsigned)&T1CON*8)+5;
volatile 	 bit 	 T1CKPS0	 @ ((unsigned)&T1CON*8)+4;
volatile 	 bit 	 T0OSCEN	 @ ((unsigned)&T1CON*8)+3;
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

/* Definitions for T2CON2  register */
volatile 	 bit 	 T2CLK	 @ ((unsigned)&T2CON2*8)+0;

/* Definitions for BAUDCTL1  register */
volatile 	 bit 	 RCIDL1	 @ ((unsigned)&BAUDCTL1*8)+6;
volatile 	 bit 	 SCKP1	 @ ((unsigned)&BAUDCTL1*8)+4;
volatile 	 bit 	 BRG16EN1	 @ ((unsigned)&BAUDCTL1*8)+3;

/* Definitions for RCSTA1  register */
volatile 	 bit 	 SPEN1	 @ ((unsigned)&RCSTA1*8)+7;
volatile 	 bit 	 RX9EN1	 @ ((unsigned)&RCSTA1*8)+6;
volatile 	 bit 	 SREN1	 @ ((unsigned)&RCSTA1*8)+5;
volatile 	 bit 	 CREN1	 @ ((unsigned)&RCSTA1*8)+4;
volatile 	 bit 	 FERR1	 @ ((unsigned)&RCSTA1*8)+2;
volatile 	 bit 	 OERR1	 @ ((unsigned)&RCSTA1*8)+1;
volatile 	 bit 	 RX9D1	 @ ((unsigned)&RCSTA1*8)+0;

/* Definitions for RCSTA0  register */
volatile 	 bit 	 SPEN0	 @ ((unsigned)&RCSTA0*8)+7;
volatile 	 bit 	 RX9EN0	 @ ((unsigned)&RCSTA0*8)+6;
volatile 	 bit 	 SREN0	 @ ((unsigned)&RCSTA0*8)+5;
volatile 	 bit 	 CREN0	 @ ((unsigned)&RCSTA0*8)+4;
volatile 	 bit 	 FERR0	 @ ((unsigned)&RCSTA0*8)+2;
volatile 	 bit 	 OERR0	 @ ((unsigned)&RCSTA0*8)+1;
volatile 	 bit 	 RX9D0	 @ ((unsigned)&RCSTA0*8)+0;

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
volatile 	 bit 	 TRISA7	 @ ((unsigned)&TRISA*8)+7;
volatile 	 bit 	 TRISA6	 @ ((unsigned)&TRISA*8)+6;
volatile 	 bit 	 TRISA5	 @ ((unsigned)&TRISA*8)+5;
volatile 	 bit 	 TRISA4	 @ ((unsigned)&TRISA*8)+4;
volatile 	 bit 	 TRISA3	 @ ((unsigned)&TRISA*8)+3;
volatile 	 bit 	 TRISA2	 @ ((unsigned)&TRISA*8)+2;
volatile 	 bit 	 TRISA1	 @ ((unsigned)&TRISA*8)+1;
volatile 	 bit 	 TRISA0	 @ ((unsigned)&TRISA*8)+0;

/* Definitions for TRISB  register */
volatile 	 bit 	 TRISB7	 @ ((unsigned)&TRISB*8)+7;
volatile 	 bit 	 TRISB6	 @ ((unsigned)&TRISB*8)+6;
volatile 	 bit 	 TRISB5	 @ ((unsigned)&TRISB*8)+5;
volatile 	 bit 	 TRISB4	 @ ((unsigned)&TRISB*8)+4;
volatile 	 bit 	 TRISB3	 @ ((unsigned)&TRISB*8)+3;
volatile 	 bit 	 TRISB2	 @ ((unsigned)&TRISB*8)+2;
volatile 	 bit 	 TRISB1	 @ ((unsigned)&TRISB*8)+1;
volatile 	 bit 	 TRISB0	 @ ((unsigned)&TRISB*8)+0;

/* Definitions for TRISC  register */
volatile 	 bit 	 TRISC1	 @ ((unsigned)&TRISC*8)+1;
volatile 	 bit 	 TRISC0	 @ ((unsigned)&TRISC*8)+0;

/* Definitions for WPDA  register */
volatile 	 bit 	 WPDA7	 @ ((unsigned)&WPDA*8)+7;
volatile 	 bit 	 WPDA6	 @ ((unsigned)&WPDA*8)+6;
volatile 	 bit 	 WPDA5	 @ ((unsigned)&WPDA*8)+5;
volatile 	 bit 	 WPDA4	 @ ((unsigned)&WPDA*8)+4;
volatile 	 bit 	 WPDA3	 @ ((unsigned)&WPDA*8)+3;
volatile 	 bit 	 WPDA2	 @ ((unsigned)&WPDA*8)+2;
volatile 	 bit 	 WPDA1	 @ ((unsigned)&WPDA*8)+1;
volatile 	 bit 	 WPDA0	 @ ((unsigned)&WPDA*8)+0;

/* Definitions for PIE1  register */
volatile 	 bit 	 RC1IE	 @ ((unsigned)&PIE1*8)+7;
volatile 	 bit 	 TX1IE	 @ ((unsigned)&PIE1*8)+6;
volatile 	 bit 	 RC0IE	 @ ((unsigned)&PIE1*8)+5;
volatile 	 bit 	 TX0IE	 @ ((unsigned)&PIE1*8)+4;
volatile 	 bit 	 EEIE	 @ ((unsigned)&PIE1*8)+3;
volatile 	 bit 	 ADIE	 @ ((unsigned)&PIE1*8)+2;
volatile 	 bit 	 TMR2IE	 @ ((unsigned)&PIE1*8)+1;
volatile 	 bit 	 TMR1IE	 @ ((unsigned)&PIE1*8)+0;

/* Definitions for PIE2  register */
volatile 	 bit 	 PWMIE	 @ ((unsigned)&PIE2*8)+1;
volatile 	 bit 	 LVDIE	 @ ((unsigned)&PIE2*8)+0;

/* Definitions for OSCCON  register */
volatile 	 bit 	 IRCF2	 @ ((unsigned)&OSCCON*8)+6;
volatile 	 bit 	 IRCF1	 @ ((unsigned)&OSCCON*8)+5;
volatile 	 bit 	 IRCF0	 @ ((unsigned)&OSCCON*8)+4;
volatile 	 bit 	 SCS	 @ ((unsigned)&OSCCON*8)+0;

/* Definitions for OSCTUNE  register */
volatile 	 bit 	 TUN6	 @ ((unsigned)&OSCTUNE*8)+6;
volatile 	 bit 	 TUN5	 @ ((unsigned)&OSCTUNE*8)+5;
volatile 	 bit 	 TUN4	 @ ((unsigned)&OSCTUNE*8)+4;
volatile 	 bit 	 TUN3	 @ ((unsigned)&OSCTUNE*8)+3;
volatile 	 bit 	 TUN2	 @ ((unsigned)&OSCTUNE*8)+2;
volatile 	 bit 	 TUN1	 @ ((unsigned)&OSCTUNE*8)+1;
volatile 	 bit 	 TUN0	 @ ((unsigned)&OSCTUNE*8)+0;

/* Definitions for WPUB  register */
volatile 	 bit 	 WPUB7	 @ ((unsigned)&WPUB*8)+7;
volatile 	 bit 	 WPUB6	 @ ((unsigned)&WPUB*8)+6;
volatile 	 bit 	 WPUB5	 @ ((unsigned)&WPUB*8)+5;
volatile 	 bit 	 WPUB4	 @ ((unsigned)&WPUB*8)+4;
volatile 	 bit 	 WPUB3	 @ ((unsigned)&WPUB*8)+3;
volatile 	 bit 	 WPUB2	 @ ((unsigned)&WPUB*8)+2;
volatile 	 bit 	 WPUB1	 @ ((unsigned)&WPUB*8)+1;
volatile 	 bit 	 WPUB0	 @ ((unsigned)&WPUB*8)+0;

/* Definitions for IOCB  register */
volatile 	 bit 	 IOCB7	 @ ((unsigned)&IOCB*8)+7;
volatile 	 bit 	 IOCB6	 @ ((unsigned)&IOCB*8)+6;
volatile 	 bit 	 IOCB5	 @ ((unsigned)&IOCB*8)+5;
volatile 	 bit 	 IOCB4	 @ ((unsigned)&IOCB*8)+4;
volatile 	 bit 	 IOCB3	 @ ((unsigned)&IOCB*8)+3;
volatile 	 bit 	 IOCB2	 @ ((unsigned)&IOCB*8)+2;
volatile 	 bit 	 IOCB1	 @ ((unsigned)&IOCB*8)+1;
volatile 	 bit 	 IOCB0	 @ ((unsigned)&IOCB*8)+0;

/* Definitions for TXSTA1  register */
volatile 	 bit 	 CSRC1	 @ ((unsigned)&TXSTA1*8)+7;
volatile 	 bit 	 TX9EN1	 @ ((unsigned)&TXSTA1*8)+6;
volatile 	 bit 	 TXEN1	 @ ((unsigned)&TXSTA1*8)+5;
volatile 	 bit 	 SYNC1	 @ ((unsigned)&TXSTA1*8)+4;
volatile 	 bit 	 BRGHEN1	 @ ((unsigned)&TXSTA1*8)+2;
volatile 	 bit 	 TRMT1	 @ ((unsigned)&TXSTA1*8)+1;
volatile 	 bit 	 TX9D1	 @ ((unsigned)&TXSTA1*8)+0;

/* Definitions for TXSTA0  register */
volatile 	 bit 	 CSRC0	 @ ((unsigned)&TXSTA0*8)+7;
volatile 	 bit 	 TX9EN0	 @ ((unsigned)&TXSTA0*8)+6;
volatile 	 bit 	 TXEN0	 @ ((unsigned)&TXSTA0*8)+5;
volatile 	 bit 	 SYNC0	 @ ((unsigned)&TXSTA0*8)+4;
volatile 	 bit 	 BRGHEN0	 @ ((unsigned)&TXSTA0*8)+2;
volatile 	 bit 	 TRMT0	 @ ((unsigned)&TXSTA0*8)+1;
volatile 	 bit 	 TX9D0	 @ ((unsigned)&TXSTA0*8)+0;

/* Definitions for ADCON1  register */
volatile 	 bit 	 ADFM	 @ ((unsigned)&ADCON1*8)+7;
volatile 	 bit 	 CHS4	 @ ((unsigned)&ADCON1*8)+6;
volatile 	 bit 	 LDOEN	 @ ((unsigned)&ADCON1*8)+2;
volatile 	 bit 	 LDOSEL	 @ ((unsigned)&ADCON1*8)+0;

/* Definitions for WDTCON  register */
volatile 	 bit 	 SWDTEN	 @ ((unsigned)&WDTCON*8)+0;

/* Definitions for WPDB  register */
volatile 	 bit 	 WPDB7	 @ ((unsigned)&WPDB*8)+7;
volatile 	 bit 	 WPDB6	 @ ((unsigned)&WPDB*8)+6;
volatile 	 bit 	 WPDB5	 @ ((unsigned)&WPDB*8)+5;
volatile 	 bit 	 WPDB4	 @ ((unsigned)&WPDB*8)+4;
volatile 	 bit 	 WPDB3	 @ ((unsigned)&WPDB*8)+3;
volatile 	 bit 	 WPDB2	 @ ((unsigned)&WPDB*8)+2;
volatile 	 bit 	 WPDB1	 @ ((unsigned)&WPDB*8)+1;
volatile 	 bit 	 WPDB0	 @ ((unsigned)&WPDB*8)+0;

/* Definitions for WPDC  register */
volatile 	 bit 	 WPDC1	 @ ((unsigned)&WPDC*8)+1;
volatile 	 bit 	 WPDC0	 @ ((unsigned)&WPDC*8)+0;

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

/* Definitions for LCDCON  register */
volatile 	 bit 	 LCDEN	 @ ((unsigned)&LCDCON*8)+7;

/* Definitions for LVDCON  register */
volatile 	 bit 	 LVD_RES	 @ ((unsigned)&LVDCON*8)+7;
volatile 	 bit 	 LVD_SEL2	 @ ((unsigned)&LVDCON*8)+3;
volatile 	 bit 	 LVD_SEL1	 @ ((unsigned)&LVDCON*8)+2;
volatile 	 bit 	 LVD_SEL0	 @ ((unsigned)&LVDCON*8)+1;
volatile 	 bit 	 LVDEN	 @ ((unsigned)&LVDCON*8)+0;

/* Definitions for PWMTL  register */
volatile 	 bit 	 PWMT7	 @ ((unsigned)&PWMTL*8)+7;
volatile 	 bit 	 PWMT6	 @ ((unsigned)&PWMTL*8)+6;
volatile 	 bit 	 PWMT5	 @ ((unsigned)&PWMTL*8)+5;
volatile 	 bit 	 PWMT4	 @ ((unsigned)&PWMTL*8)+4;
volatile 	 bit 	 PWMT3	 @ ((unsigned)&PWMTL*8)+3;
volatile 	 bit 	 PWMT2	 @ ((unsigned)&PWMTL*8)+2;
volatile 	 bit 	 PWMT1	 @ ((unsigned)&PWMTL*8)+1;
volatile 	 bit 	 PWMT0	 @ ((unsigned)&PWMTL*8)+0;

/* Definitions for PWMTH  register */
volatile 	 bit 	 PWM4D9	 @ ((unsigned)&PWMTH*8)+5;
volatile 	 bit 	 PWM4D8	 @ ((unsigned)&PWMTH*8)+4;
volatile 	 bit 	 PWM4T9	 @ ((unsigned)&PWMTH*8)+3;
volatile 	 bit 	 PWM4T8	 @ ((unsigned)&PWMTH*8)+2;
volatile 	 bit 	 PWMT9	 @ ((unsigned)&PWMTH*8)+1;
volatile 	 bit 	 PWMT8	 @ ((unsigned)&PWMTH*8)+0;

/* Definitions for PWMT4L  register */
volatile 	 bit 	 PWMT4L7	 @ ((unsigned)&PWMT4L*8)+7;
volatile 	 bit 	 PWMT4L6	 @ ((unsigned)&PWMT4L*8)+6;
volatile 	 bit 	 PWMT4L5	 @ ((unsigned)&PWMT4L*8)+5;
volatile 	 bit 	 PWMT4L4	 @ ((unsigned)&PWMT4L*8)+4;
volatile 	 bit 	 PWMT4L3	 @ ((unsigned)&PWMT4L*8)+3;
volatile 	 bit 	 PWMT4L2	 @ ((unsigned)&PWMT4L*8)+2;
volatile 	 bit 	 PWMT4L1	 @ ((unsigned)&PWMT4L*8)+1;
volatile 	 bit 	 PWMT4L0	 @ ((unsigned)&PWMT4L*8)+0;

/* Definitions for PWMD0L  register */
volatile 	 bit 	 PWMD07	 @ ((unsigned)&PWMD0L*8)+7;
volatile 	 bit 	 PWMD06	 @ ((unsigned)&PWMD0L*8)+6;
volatile 	 bit 	 PWMD05	 @ ((unsigned)&PWMD0L*8)+5;
volatile 	 bit 	 PWMD04	 @ ((unsigned)&PWMD0L*8)+4;
volatile 	 bit 	 PWMD03	 @ ((unsigned)&PWMD0L*8)+3;
volatile 	 bit 	 PWMD02	 @ ((unsigned)&PWMD0L*8)+2;
volatile 	 bit 	 PWMD01	 @ ((unsigned)&PWMD0L*8)+1;
volatile 	 bit 	 PWMD00	 @ ((unsigned)&PWMD0L*8)+0;

/* Definitions for PWMD1L  register */
volatile 	 bit 	 PWMD17	 @ ((unsigned)&PWMD1L*8)+7;
volatile 	 bit 	 PWMD16	 @ ((unsigned)&PWMD1L*8)+6;
volatile 	 bit 	 PWMD15	 @ ((unsigned)&PWMD1L*8)+5;
volatile 	 bit 	 PWMD14	 @ ((unsigned)&PWMD1L*8)+4;
volatile 	 bit 	 PWMD13	 @ ((unsigned)&PWMD1L*8)+3;
volatile 	 bit 	 PWMD12	 @ ((unsigned)&PWMD1L*8)+2;
volatile 	 bit 	 PWMD11	 @ ((unsigned)&PWMD1L*8)+1;
volatile 	 bit 	 PWMD10	 @ ((unsigned)&PWMD1L*8)+0;

/* Definitions for PWMD2L  register */
volatile 	 bit 	 PWMD27	 @ ((unsigned)&PWMD2L*8)+7;
volatile 	 bit 	 PWMD26	 @ ((unsigned)&PWMD2L*8)+6;
volatile 	 bit 	 PWMD25	 @ ((unsigned)&PWMD2L*8)+5;
volatile 	 bit 	 PWMD24	 @ ((unsigned)&PWMD2L*8)+4;
volatile 	 bit 	 PWMD23	 @ ((unsigned)&PWMD2L*8)+3;
volatile 	 bit 	 PWMD22	 @ ((unsigned)&PWMD2L*8)+2;
volatile 	 bit 	 PWMD21	 @ ((unsigned)&PWMD2L*8)+1;
volatile 	 bit 	 PWMD20	 @ ((unsigned)&PWMD2L*8)+0;

/* Definitions for PWMD3L  register */
volatile 	 bit 	 PWMD37	 @ ((unsigned)&PWMD3L*8)+7;
volatile 	 bit 	 PWMD36	 @ ((unsigned)&PWMD3L*8)+6;
volatile 	 bit 	 PWMD35	 @ ((unsigned)&PWMD3L*8)+5;
volatile 	 bit 	 PWMD34	 @ ((unsigned)&PWMD3L*8)+4;
volatile 	 bit 	 PWMD33	 @ ((unsigned)&PWMD3L*8)+3;
volatile 	 bit 	 PWMD32	 @ ((unsigned)&PWMD3L*8)+2;
volatile 	 bit 	 PWMD31	 @ ((unsigned)&PWMD3L*8)+1;
volatile 	 bit 	 PWMD30	 @ ((unsigned)&PWMD3L*8)+0;

/* Definitions for PWMD4L  register */
volatile 	 bit 	 PWMD47	 @ ((unsigned)&PWMD4L*8)+7;
volatile 	 bit 	 PWMD46	 @ ((unsigned)&PWMD4L*8)+6;
volatile 	 bit 	 PWMD45	 @ ((unsigned)&PWMD4L*8)+5;
volatile 	 bit 	 PWMD44	 @ ((unsigned)&PWMD4L*8)+4;
volatile 	 bit 	 PWMD43	 @ ((unsigned)&PWMD4L*8)+3;
volatile 	 bit 	 PWMD42	 @ ((unsigned)&PWMD4L*8)+2;
volatile 	 bit 	 PWMD41	 @ ((unsigned)&PWMD4L*8)+1;
volatile 	 bit 	 PWMD40	 @ ((unsigned)&PWMD4L*8)+0;

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

/* Definitions for BAUDCTL0  register */
volatile 	 bit 	 RCIDL0	 @ ((unsigned)&BAUDCTL0*8)+6;
volatile 	 bit 	 SCKP0	 @ ((unsigned)&BAUDCTL0*8)+4;
volatile 	 bit 	 BRG16EN0	 @ ((unsigned)&BAUDCTL0*8)+3;

/* Definitions for EECON1  register */
volatile 	 bit 	 EEPGD	 @ ((unsigned)&EECON1*8)+7;
volatile 	 bit 	 EETIME1	 @ ((unsigned)&EECON1*8)+5;
volatile 	 bit 	 EETIME0	 @ ((unsigned)&EECON1*8)+4;
volatile 	 bit 	 WRERR	 @ ((unsigned)&EECON1*8)+3;
volatile 	 bit 	 WREN	 @ ((unsigned)&EECON1*8)+2;
volatile 	 bit 	 WR	 @ ((unsigned)&EECON1*8)+1;
volatile 	 bit 	 RD	 @ ((unsigned)&EECON1*8)+0;

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
volatile 	 bit 	 WPUC1	 @ ((unsigned)&WPUC*8)+1;
volatile 	 bit 	 WPUC0	 @ ((unsigned)&WPUC*8)+0;

/* Definitions for LCDCON0  register */
volatile 	 bit 	 COM7EN	 @ ((unsigned)&LCDCON0*8)+7;
volatile 	 bit 	 COM6EN	 @ ((unsigned)&LCDCON0*8)+6;
volatile 	 bit 	 COM5EN	 @ ((unsigned)&LCDCON0*8)+5;
volatile 	 bit 	 COM4EN	 @ ((unsigned)&LCDCON0*8)+4;
volatile 	 bit 	 COM3EN	 @ ((unsigned)&LCDCON0*8)+3;
volatile 	 bit 	 COM2EN	 @ ((unsigned)&LCDCON0*8)+2;
volatile 	 bit 	 COM1EN	 @ ((unsigned)&LCDCON0*8)+1;
volatile 	 bit 	 COM0EN	 @ ((unsigned)&LCDCON0*8)+0;

/* Definitions for LCDCON1  register */
volatile 	 bit 	 COM15EN	 @ ((unsigned)&LCDCON1*8)+7;
volatile 	 bit 	 COM14EN	 @ ((unsigned)&LCDCON1*8)+6;
volatile 	 bit 	 COM13EN	 @ ((unsigned)&LCDCON1*8)+5;
volatile 	 bit 	 COM12EN	 @ ((unsigned)&LCDCON1*8)+4;
volatile 	 bit 	 COM11EN	 @ ((unsigned)&LCDCON1*8)+3;
volatile 	 bit 	 COM10EN	 @ ((unsigned)&LCDCON1*8)+2;
volatile 	 bit 	 COM9EN	 @ ((unsigned)&LCDCON1*8)+1;
volatile 	 bit 	 COM8EN	 @ ((unsigned)&LCDCON1*8)+0;

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
volatile 	 bit 	 PWM01_SEL	 @ ((unsigned)&PWMCON1*8)+6;
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

/* Definitions for PWM01DT  register */
volatile 	 bit 	 PWM01DT5	 @ ((unsigned)&PWM01DT*8)+5;
volatile 	 bit 	 PWM01DT4	 @ ((unsigned)&PWM01DT*8)+4;
volatile 	 bit 	 PWM01DT3	 @ ((unsigned)&PWM01DT*8)+3;
volatile 	 bit 	 PWM01DT2	 @ ((unsigned)&PWM01DT*8)+2;
volatile 	 bit 	 PWM01DT1	 @ ((unsigned)&PWM01DT*8)+1;
volatile 	 bit 	 PWM01DT0	 @ ((unsigned)&PWM01DT*8)+0;

/* Definitions for PWM23DT  register */
volatile 	 bit 	 PWM23DT5	 @ ((unsigned)&PWM23DT*8)+5;
volatile 	 bit 	 PWM23DT4	 @ ((unsigned)&PWM23DT*8)+4;
volatile 	 bit 	 PWM23DT3	 @ ((unsigned)&PWM23DT*8)+3;
volatile 	 bit 	 PWM23DT2	 @ ((unsigned)&PWM23DT*8)+2;
volatile 	 bit 	 PWM23DT1	 @ ((unsigned)&PWM23DT*8)+1;
volatile 	 bit 	 PWM23DT0	 @ ((unsigned)&PWM23DT*8)+0;

/* Definitions for LCDCON2  register */
volatile 	 bit 	 LCDISEL1	 @ ((unsigned)&LCDCON2*8)+7;
volatile 	 bit 	 LCDISEL0	 @ ((unsigned)&LCDCON2*8)+6;
volatile 	 bit 	 COM17EN	 @ ((unsigned)&LCDCON2*8)+1;
volatile 	 bit 	 COM16EN	 @ ((unsigned)&LCDCON2*8)+0;

#endif
