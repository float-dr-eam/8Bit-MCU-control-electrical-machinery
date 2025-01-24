#ifndef _HTC_H_
#warning Header file SC8F8122.h included directly. Use #include <cms.h> instead.
#endif

#ifndef __SC8F8122_H
#define __SC8F8122_H


volatile unsigned char      INDF         @   0x0000;
volatile unsigned char      TMR0         @   0x0001;
volatile unsigned char      PCL      @   0x0002;
volatile unsigned char      STATUS       @   0x0003;
volatile unsigned char      FSR      @   0x0004;
volatile unsigned char      OPTION_REG       @   0x0005;
volatile unsigned char      PORTB        @   0x0006;
volatile unsigned char      TRISB        @   0x0007;
volatile unsigned char      WPUB         @   0x0008;
volatile unsigned char      IOCB         @   0x0009;
volatile unsigned char      PCLATH       @   0x000A;
volatile unsigned char      INTCON       @   0x000B;
volatile unsigned char      KEYCON0      @   0x000C;
volatile unsigned char      KEYCON1      @   0x000D;
volatile unsigned char      KEYDATAL         @   0x000E;
volatile unsigned char      KEYDATAH         @   0x000F;
volatile unsigned char      TMR2         @   0x0010;
volatile unsigned char      T2CON        @   0x0011;
volatile unsigned char      PR2      @   0x0012;
volatile unsigned char      CCPR1L       @   0x0013;
volatile unsigned char      CCPCON       @   0x0014;
volatile unsigned char      CCPR2L       @   0x0015;
volatile unsigned char      KEYCON2      @   0x0016;
volatile unsigned char      OSCCON       @   0x0017;
volatile unsigned char      WPDB         @   0x0018;
volatile unsigned char      ANSEL        @   0x0019;
volatile unsigned char      TABLE_SPL        @   0x001A;
volatile unsigned char      TABLE_SPH        @   0x001B;
volatile unsigned char      TABLE_DATAH      @   0x001C;
volatile unsigned char      PIR1         @   0x001D;
volatile unsigned char      PIE1         @   0x001E;
        
        
        
        
/* Definitions for STATUS register */       
volatile       bit      RP0    @ ((unsigned)&STATUS*8)+5;
volatile       bit      TO     @ ((unsigned)&STATUS*8)+4;
volatile       bit      PD     @ ((unsigned)&STATUS*8)+3;
volatile       bit      Z      @ ((unsigned)&STATUS*8)+2;
volatile       bit      DC     @ ((unsigned)&STATUS*8)+1;
volatile       bit      C      @ ((unsigned)&STATUS*8)+0;
        
        
/* Definitions for OPTION_REG register */       
volatile       bit      T0CS       @ ((unsigned)&OPTION_REG*8)+5;
volatile       bit      T0SE       @ ((unsigned)&OPTION_REG*8)+4;
volatile       bit      PSA    @ ((unsigned)&OPTION_REG*8)+3;
volatile       bit      PS2    @ ((unsigned)&OPTION_REG*8)+2;
volatile       bit      PS1    @ ((unsigned)&OPTION_REG*8)+1;
volatile       bit      PS0    @ ((unsigned)&OPTION_REG*8)+0;
        
        
/* Definitions for PORTB register */        
volatile       bit      RB5    @ ((unsigned)&PORTB*8)+5;
volatile       bit      RB4    @ ((unsigned)&PORTB*8)+4;
volatile       bit      RB3    @ ((unsigned)&PORTB*8)+3;
volatile       bit      RB2    @ ((unsigned)&PORTB*8)+2;
volatile       bit      RB1    @ ((unsigned)&PORTB*8)+1;
volatile       bit      RB0    @ ((unsigned)&PORTB*8)+0;
        
        
/* Definitions for TRISB register */        
volatile       bit      TRISB5     @ ((unsigned)&TRISB*8)+5;
volatile       bit      TRISB4     @ ((unsigned)&TRISB*8)+4;
volatile       bit      TRISB3     @ ((unsigned)&TRISB*8)+3;
volatile       bit      TRISB2     @ ((unsigned)&TRISB*8)+2;
volatile       bit      TRISB1     @ ((unsigned)&TRISB*8)+1;
volatile       bit      TRISB0     @ ((unsigned)&TRISB*8)+0;
        
        
/* Definitions for WPUB register */     
volatile       bit      WPUB5      @ ((unsigned)&WPUB*8)+5;
volatile       bit      WPUB4      @ ((unsigned)&WPUB*8)+4;
volatile       bit      WPUB3      @ ((unsigned)&WPUB*8)+3;
volatile       bit      WPUB2      @ ((unsigned)&WPUB*8)+2;
volatile       bit      WPUB1      @ ((unsigned)&WPUB*8)+1;
volatile       bit      WPUB0      @ ((unsigned)&WPUB*8)+0;
        
        
/* Definitions for IOCB register */     
volatile       bit      IOCB5      @ ((unsigned)&IOCB*8)+5;
volatile       bit      IOCB4      @ ((unsigned)&IOCB*8)+4;
volatile       bit      IOCB3      @ ((unsigned)&IOCB*8)+3;
volatile       bit      IOCB2      @ ((unsigned)&IOCB*8)+2;
volatile       bit      IOCB1      @ ((unsigned)&IOCB*8)+1;
volatile       bit      IOCB0      @ ((unsigned)&IOCB*8)+0;
        
        
/* Definitions for INTCON register */       
volatile       bit      GIE    @ ((unsigned)&INTCON*8)+7;
volatile       bit      PEIE       @ ((unsigned)&INTCON*8)+6;
volatile       bit      T0IE       @ ((unsigned)&INTCON*8)+5;
volatile       bit      TMR2IE     @ ((unsigned)&INTCON*8)+4;
volatile       bit      RBIE       @ ((unsigned)&INTCON*8)+3;
volatile       bit      T0IF       @ ((unsigned)&INTCON*8)+2;
volatile       bit      TMR2IF     @ ((unsigned)&INTCON*8)+1;
volatile       bit      RBIF       @ ((unsigned)&INTCON*8)+0;
        
        
/* Definitions for KEYCON0 register */      
volatile       bit      KDONE      @ ((unsigned)&KEYCON0*8)+7;
volatile       bit      CAPK2      @ ((unsigned)&KEYCON0*8)+5;
volatile       bit      CAPK1      @ ((unsigned)&KEYCON0*8)+4;
volatile       bit      CAPK0      @ ((unsigned)&KEYCON0*8)+3;
volatile       bit      KTOUT      @ ((unsigned)&KEYCON0*8)+2;
volatile       bit      KCAP       @ ((unsigned)&KEYCON0*8)+1;
volatile       bit      KEN    @ ((unsigned)&KEYCON0*8)+0;
        
        
/* Definitions for KEYCON1 register */      
volatile       bit      KVREF1     @ ((unsigned)&KEYCON1*8)+7;
volatile       bit      KVREF0     @ ((unsigned)&KEYCON1*8)+6;
volatile       bit      KCLK1      @ ((unsigned)&KEYCON1*8)+5;
volatile       bit      KCLK0      @ ((unsigned)&KEYCON1*8)+4;
volatile       bit      KCHS3      @ ((unsigned)&KEYCON1*8)+3;
volatile       bit      KCHS2      @ ((unsigned)&KEYCON1*8)+2;
volatile       bit      KCHS1      @ ((unsigned)&KEYCON1*8)+1;
volatile       bit      KCHS0      @ ((unsigned)&KEYCON1*8)+0;
        
        
/* Definitions for T2CON register */        
volatile       bit      TOUTPS3    @ ((unsigned)&T2CON*8)+6;
volatile       bit      TOUTPS2    @ ((unsigned)&T2CON*8)+5;
volatile       bit      TOUTPS1    @ ((unsigned)&T2CON*8)+4;
volatile       bit      TOUTPS0    @ ((unsigned)&T2CON*8)+3;
volatile       bit      TMR2ON     @ ((unsigned)&T2CON*8)+2;
volatile       bit      T2CKPS1    @ ((unsigned)&T2CON*8)+1;
volatile       bit      T2CKPS0    @ ((unsigned)&T2CON*8)+0;
        
        
/* Definitions for CCPCON register */       
volatile       bit      PWM2EN     @ ((unsigned)&CCPCON*8)+6;
volatile       bit      PWM2B1     @ ((unsigned)&CCPCON*8)+5;
volatile       bit      PWM2B0     @ ((unsigned)&CCPCON*8)+4;
volatile       bit      PWM1EN     @ ((unsigned)&CCPCON*8)+2;
volatile       bit      PWM1B1     @ ((unsigned)&CCPCON*8)+1;
volatile       bit      PWM1B0     @ ((unsigned)&CCPCON*8)+0;
        
        
/* Definitions for KEYCON2 register */      
volatile       bit      CAP_LVBO2      @ ((unsigned)&KEYCON2*8)+7;
volatile       bit      CAP_LVBO1      @ ((unsigned)&KEYCON2*8)+6;
volatile       bit      CAP_LVBO0      @ ((unsigned)&KEYCON2*8)+5;
volatile       bit      TKEN       @ ((unsigned)&KEYCON2*8)+0;
        
        
/* Definitions for OSCCON register */       
volatile       bit      IRCF2      @ ((unsigned)&OSCCON*8)+6;
volatile       bit      IRCF1      @ ((unsigned)&OSCCON*8)+5;
volatile       bit      IRCF0      @ ((unsigned)&OSCCON*8)+4;
        
        
/* Definitions for WPDB register */     
volatile       bit      WPDB5      @ ((unsigned)&WPDB*8)+5;
volatile       bit      WPDB4      @ ((unsigned)&WPDB*8)+4;
volatile       bit      WPDB3      @ ((unsigned)&WPDB*8)+3;
volatile       bit      WPDB2      @ ((unsigned)&WPDB*8)+2;
volatile       bit      WPDB1      @ ((unsigned)&WPDB*8)+1;
volatile       bit      WPDB0      @ ((unsigned)&WPDB*8)+0;
        
        
/* Definitions for ANSEL register */        
volatile       bit      ANS5       @ ((unsigned)&ANSEL*8)+5;
volatile       bit      ANS4       @ ((unsigned)&ANSEL*8)+4;
volatile       bit      ANS3       @ ((unsigned)&ANSEL*8)+3;
volatile       bit      ANS2       @ ((unsigned)&ANSEL*8)+2;
volatile       bit      ANS1       @ ((unsigned)&ANSEL*8)+1;
volatile       bit      ANS0       @ ((unsigned)&ANSEL*8)+0;
        
        
/* Definitions for PIR1 register */     
volatile       bit      TKIF       @ ((unsigned)&PIR1*8)+0;
        
        
/* Definitions for PIE1 register */     
volatile       bit      TKIE       @ ((unsigned)&PIE1*8)+0;

#endif