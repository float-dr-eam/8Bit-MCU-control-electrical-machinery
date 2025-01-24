        
INDF        EQU      H'0000'
TMR0        EQU      H'0001'
PCL         EQU      H'0002'
STATUS      EQU      H'0003'
FSR         EQU      H'0004'
PORTA       EQU      H'0005'
PORTB       EQU      H'0006'
WPDA        EQU      H'0007'
WPDB        EQU      H'0008'
PCLATH      EQU      H'000A'
INTCON      EQU      H'000B'
PIR1        EQU      H'000C'
PIR2        EQU      H'000D'
TMR1L       EQU      H'000E'
TMR1H       EQU      H'000F'
T1CON       EQU      H'0010'
TMR2        EQU      H'0011'
T2CON       EQU      H'0012'
ADRESH      EQU      H'001E'
ADCON0      EQU      H'001F'
OPTION_REG  EQU      H'0081'
TRISA       EQU      H'0085'
TRISB       EQU      H'0086'
IOCA        EQU      H'0087'
PIE1        EQU      H'008C'
PIE2        EQU      H'008D'
OSCCON      EQU      H'008F'
OSCTUNE     EQU      H'0090'
PR2         EQU      H'0092'
PWM01DT     EQU      H'0093'
PWM23DT     EQU      H'0094'
WPUB        EQU      H'0095'
IOCB        EQU      H'0096'
LVDCON      EQU      H'0097'
OPA0CON     EQU      H'009A'
OPA0ADJ     EQU      H'009B'
OPA1CON     EQU      H'009C'
OPA1ADJ     EQU      H'009D'
ADRESL      EQU      H'009E'
ADCON1      EQU      H'009F'
WDTCON      EQU      H'0105'
PWMCON0     EQU      H'0107'
PWMCON1     EQU      H'0108'
PWMCON2     EQU      H'0109'
EEDAT       EQU      H'010C'
EEADR       EQU      H'010D'
EEDATH      EQU      H'010E'
EEADRH      EQU      H'010F'
TABLE_SPH   EQU      H'0110'
TABLE_SPL   EQU      H'0111'
TABLE_DATAH EQU      H'0112'
PWMD01H     EQU      H'011C'
PWMD23H     EQU      H'011D'
ANSEL       EQU      H'0188'
ANSELH      EQU      H'0189'
EECON1      EQU      H'018C'
EECON2      EQU      H'018D'
WPUA        EQU      H'018E'
PWMTL       EQU      H'018F'
PWMTH       EQU      H'0190'
PWMT4L      EQU      H'0191'
PWMD0L      EQU      H'0193'
PWMD1L      EQU      H'0194'
PWMD2L      EQU      H'0195'
PWMD3L      EQU      H'0196'
PWMD4L      EQU      H'0197'
        
        
        
        
;------------------------STATUS  Bits-------------------------------        
IRP    EQU      H'0007'
RP1    EQU      H'0006'
RP0    EQU      H'0005'
TO     EQU      H'0004'
PD     EQU      H'0003'
Z      EQU      H'0002'
DC     EQU      H'0001'
C      EQU      H'0000'
        
        
;------------------------PORTA  Bits-------------------------------     
RA7    EQU      H'0007'
RA6    EQU      H'0006'
RA5    EQU      H'0005'
RA4    EQU      H'0004'
RA3    EQU      H'0003'
RA2    EQU      H'0002'
RA1    EQU      H'0001'
RA0    EQU      H'0000'
        
        
;------------------------PORTB  Bits-------------------------------     
RB5    EQU      H'0005'
RB4    EQU      H'0004'
RB3    EQU      H'0003'
RB2    EQU      H'0002'
RB1    EQU      H'0001'
RB0    EQU      H'0000'
        
        
;------------------------WPDA  Bits-------------------------------      
WPDA7      EQU      H'0007'
WPDA6      EQU      H'0006'
WPDA5      EQU      H'0005'
WPDA4      EQU      H'0004'
WPDA3      EQU      H'0003'
WPDA2      EQU      H'0002'
WPDA1      EQU      H'0001'
WPDA0      EQU      H'0000'
        
        
;------------------------WPDB  Bits-------------------------------      
WPDB5      EQU      H'0005'
WPDB4      EQU      H'0004'
WPDB3      EQU      H'0003'
WPDB2      EQU      H'0002'
WPDB1      EQU      H'0001'
WPDB0      EQU      H'0000'
        
        
;------------------------INTCON  Bits-------------------------------        
GIE        EQU      H'0007'
PEIE       EQU      H'0006'
T0IE       EQU      H'0005'
INTE       EQU      H'0004'
RBIE       EQU      H'0003'
T0IF       EQU      H'0002'
INTF       EQU      H'0001'
RBIF       EQU      H'0000'
        
        
;------------------------PIR1  Bits-------------------------------      
RAIF       EQU      H'0007'
ADIF       EQU      H'0006'
EEIF       EQU      H'0003'
PWMIF      EQU      H'0002'
TMR2IF     EQU      H'0001'
TMR1IF     EQU      H'0000'
        
        
;------------------------PIR2  Bits-------------------------------      
LVDIF      EQU      H'0000'
        
        
;------------------------T1CON  Bits-------------------------------     
T1GINV     EQU      H'0007'
TMR1GE     EQU      H'0006'
T1CKPS1    EQU      H'0005'
T1CKPS0    EQU      H'0004'
T1SYNC     EQU      H'0002'
TMR1CS     EQU      H'0001'
TMR1ON     EQU      H'0000'
        
        
;------------------------T2CON  Bits-------------------------------     
TOUTPS3    EQU      H'0006'
TOUTPS2    EQU      H'0005'
TOUTPS1    EQU      H'0004'
TOUTPS0    EQU      H'0003'
TMR2ON     EQU      H'0002'
T2CKPS1    EQU      H'0001'
T2CKPS0    EQU      H'0000'
        
        
;------------------------ADCON0  Bits-------------------------------        
ADCS1      EQU      H'0007'
ADCS0      EQU      H'0006'
CHS3       EQU      H'0005'
CHS2       EQU      H'0004'
CHS1       EQU      H'0003'
CHS0       EQU      H'0002'
GODONE     EQU      H'0001'
ADON       EQU      H'0000'
        
        
;------------------------OPTION_REG  Bits-------------------------------        
INTEDG     EQU      H'0006'
T0CS       EQU      H'0005'
T0SE       EQU      H'0004'
PSA        EQU      H'0003'
PS2        EQU      H'0002'
PS1        EQU      H'0001'
PS0        EQU      H'0000'
        
        
;------------------------TRISA  Bits-------------------------------     
TRISA7     EQU      H'0007'
TRISA6     EQU      H'0006'
TRISA5     EQU      H'0005'
TRISA4     EQU      H'0004'
TRISA3     EQU      H'0003'
TRISA2     EQU      H'0002'
TRISA1     EQU      H'0001'
TRISA0     EQU      H'0000'
        
        
;------------------------TRISB  Bits-------------------------------     
TRISB5     EQU      H'0005'
TRISB4     EQU      H'0004'
TRISB3     EQU      H'0003'
TRISB2     EQU      H'0002'
TRISB1     EQU      H'0001'
TRISB0     EQU      H'0000'
        
        
;------------------------IOCA  Bits-------------------------------      
IOCA7      EQU      H'0007'
IOCA6      EQU      H'0006'
IOCA5      EQU      H'0005'
IOCA4      EQU      H'0004'
IOCA3      EQU      H'0003'
IOCA2      EQU      H'0002'
IOCA1      EQU      H'0001'
IOCA0      EQU      H'0000'
        
        
;------------------------PIE1  Bits-------------------------------      
RAIE       EQU      H'0007'
ADIE       EQU      H'0006'
EEIE       EQU      H'0003'
PWMIE      EQU      H'0002'
TMR2IE     EQU      H'0001'
TMR1IE     EQU      H'0000'
        
        
;------------------------PIE2  Bits-------------------------------      
LVDIE      EQU      H'0000'
        
        
;------------------------OSCCON  Bits-------------------------------        
IRCF2      EQU      H'0006'
IRCF1      EQU      H'0005'
IRCF0      EQU      H'0004'
SCS        EQU      H'0000'
        
        
;------------------------OSCTUNE  Bits-------------------------------       
TUN4       EQU      H'0004'
TUN3       EQU      H'0003'
TUN2       EQU      H'0002'
TUN1       EQU      H'0001'
TUN0       EQU      H'0000'
        
        
;------------------------WPUB  Bits-------------------------------      
WPUB5      EQU      H'0005'
WPUB4      EQU      H'0004'
WPUB3      EQU      H'0003'
WPUB2      EQU      H'0002'
WPUB1      EQU      H'0001'
WPUB0      EQU      H'0000'
        
        
;------------------------IOCB  Bits-------------------------------      
IOCB5      EQU      H'0005'
IOCB4      EQU      H'0004'
IOCB3      EQU      H'0003'
IOCB2      EQU      H'0002'
IOCB1      EQU      H'0001'
IOCB0      EQU      H'0000'
        
        
;------------------------LVDCON  Bits-------------------------------        
LVD_RES    EQU      H'0007'
LVD_SEL2   EQU      H'0003'
LVD_SEL1   EQU      H'0002'
LVD_SEL0   EQU      H'0001'
LVDEN      EQU      H'0000'
        
        
;------------------------OPA0CON  Bits-------------------------------       
OPA0EN     EQU      H'0007'
OPA0O      EQU      H'0006'
OPA0_CMP   EQU      H'0005'
OPA0_ADC   EQU      H'0004'
OPA0_FW    EQU      H'0003'
OPA0_BG    EQU      H'0002'
        
        
;------------------------OPA0ADJ  Bits-------------------------------       
OPA0OUT        EQU      H'0007'
OPA0COFM       EQU      H'0006'
OPA0CRS        EQU      H'0005'
OPA0ADJ4       EQU      H'0004'
OPA0ADJ3       EQU      H'0003'
OPA0ADJ2       EQU      H'0002'
OPA0ADJ1       EQU      H'0001'
OPA0ADJ0       EQU      H'0000'
        
        
;------------------------OPA1CON  Bits-------------------------------       
OPA1EN     EQU      H'0007'
OPA1O      EQU      H'0006'
OPA1_CMP   EQU      H'0005'
OPA1_ADC   EQU      H'0004'
OPA1_FW    EQU      H'0003'
OPA1_BG    EQU      H'0002'
        
        
;------------------------OPA1ADJ  Bits-------------------------------       
OPA1OUT        EQU      H'0007'
OPA1COFM       EQU      H'0006'
OPA1CRS        EQU      H'0005'
OPA1ADJ4       EQU      H'0004'
OPA1ADJ3       EQU      H'0003'
OPA1ADJ2       EQU      H'0002'
OPA1ADJ1       EQU      H'0001'
OPA1ADJ0       EQU      H'0000'
        
        
;------------------------ADCON1  Bits-------------------------------        
ADFM       EQU      H'0007'
LDO_EN     EQU      H'0002'
LDO_SEL    EQU      H'0000'
        
        
;------------------------WDTCON  Bits-------------------------------        
SWDTEN     EQU      H'0000'
        
        
;------------------------PWMCON0  Bits-------------------------------       
CLKDIV2    EQU      H'0007'
CLKDIV1    EQU      H'0006'
CLKDIV0    EQU      H'0005'
PWM4EN     EQU      H'0004'
PWM3EN     EQU      H'0003'
PWM2EN     EQU      H'0002'
PWM1EN     EQU      H'0001'
PWM0EN     EQU      H'0000'
        
        
;------------------------PWMCON1  Bits-------------------------------       
PWM2DTEN   EQU      H'0005'
PWM0DTEN   EQU      H'0004'
DT_DIV1    EQU      H'0001'
DT_DIV0    EQU      H'0000'
        
        
;------------------------PWMCON2  Bits-------------------------------       
PWM4DIR    EQU      H'0004'
PWM3DIR    EQU      H'0003'
PWM2DIR    EQU      H'0002'
PWM1DIR    EQU      H'0001'
PWM0DIR    EQU      H'0000'
        
        
;------------------------EEDAT  Bits-------------------------------     
EEDAT7     EQU      H'0007'
EEDAT6     EQU      H'0006'
EEDAT5     EQU      H'0005'
EEDAT4     EQU      H'0004'
EEDAT3     EQU      H'0003'
EEDAT2     EQU      H'0002'
EEDAT1     EQU      H'0001'
EEDAT0     EQU      H'0000'
        
        
;------------------------EEADR  Bits-------------------------------     
EEADR7     EQU      H'0007'
EEADR6     EQU      H'0006'
EEADR5     EQU      H'0005'
EEADR4     EQU      H'0004'
EEADR3     EQU      H'0003'
EEADR2     EQU      H'0002'
EEADR1     EQU      H'0001'
EEADR0     EQU      H'0000'
        
        
;------------------------EEDATH  Bits-------------------------------        
EEDATH7    EQU      H'0007'
EEDATH6    EQU      H'0006'
EEDATH5    EQU      H'0005'
EEDATH4    EQU      H'0004'
EEDATH3    EQU      H'0003'
EEDATH2    EQU      H'0002'
EEDATH1    EQU      H'0001'
EEDATH0    EQU      H'0000'
        
        
;------------------------EEADRH  Bits-------------------------------        
EEADRH3    EQU      H'0003'
EEADRH2    EQU      H'0002'
EEADRH1    EQU      H'0001'
EEADRH0    EQU      H'0000'
        
        
;------------------------PWMD01H  Bits-------------------------------       
PWMD19     EQU      H'0005'
PWMD18     EQU      H'0004'
PWMD09     EQU      H'0001'
PWMD08     EQU      H'0000'
        
        
;------------------------PWMD23H  Bits-------------------------------       
PWMD39     EQU      H'0005'
PWMD38     EQU      H'0004'
PWMD29     EQU      H'0001'
PWMD28     EQU      H'0000'
        
        
;------------------------ANSEL  Bits-------------------------------     
ANS7       EQU      H'0007'
ANS6       EQU      H'0006'
ANS5       EQU      H'0005'
ANS4       EQU      H'0004'
ANS3       EQU      H'0003'
ANS2       EQU      H'0002'
ANS1       EQU      H'0001'
        
        
;------------------------ANSELH  Bits-------------------------------        
ANS13      EQU      H'0005'
ANS12      EQU      H'0004'
ANS11      EQU      H'0003'
ANS10      EQU      H'0002'
ANS9       EQU      H'0001'
ANS8       EQU      H'0000'
        
        
;------------------------EECON1  Bits-------------------------------        
EEPGD      EQU      H'0007'
WRERR      EQU      H'0003'
WREN       EQU      H'0002'
WR         EQU      H'0001'
RD         EQU      H'0000'
        
        
;------------------------WPUA  Bits-------------------------------      
WPUA7      EQU      H'0007'
WPUA6      EQU      H'0006'
WPUA5      EQU      H'0005'
WPUA4      EQU      H'0004'
WPUA3      EQU      H'0003'
WPUA2      EQU      H'0002'
WPUA1      EQU      H'0001'
WPUA0      EQU      H'0000'
