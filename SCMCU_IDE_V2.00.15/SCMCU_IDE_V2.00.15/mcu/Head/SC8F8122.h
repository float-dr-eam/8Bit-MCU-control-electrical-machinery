        
INDF        EQU      H'0000'
TMR0        EQU      H'0001'
PCL         EQU      H'0002'
STATUS      EQU      H'0003'
FSR         EQU      H'0004'
OPTION_REG  EQU      H'0005'
PORTB       EQU      H'0006'
TRISB       EQU      H'0007'
WPUB        EQU      H'0008'
IOCB        EQU      H'0009'
PCLATH      EQU      H'000A'
INTCON      EQU      H'000B'
KEYCON0     EQU      H'000C'
KEYCON1     EQU      H'000D'
KEYDATAL    EQU      H'000E'
KEYDATAH    EQU      H'000F'
TMR2        EQU      H'0010'
T2CON       EQU      H'0011'
PR2         EQU      H'0012'
CCPR1L      EQU      H'0013'
CCPCON      EQU      H'0014'
CCPR2L      EQU      H'0015'
KEYCON2     EQU      H'0016'
OSCCON      EQU      H'0017'
WPDB        EQU      H'0018'
ANSEL       EQU      H'0019'
TABLE_SPL   EQU      H'001A'
TABLE_SPH   EQU      H'001B'
TABLE_DATAH EQU      H'001C'
PIR1        EQU      H'001D'
PIE1        EQU      H'001E'
        
        
        
        
;------------------------STATUS  Bits-------------------------------        
RP0    EQU      H'0005'
TO     EQU      H'0004'
PD     EQU      H'0003'
Z      EQU      H'0002'
DC     EQU      H'0001'
C      EQU      H'0000'
        
        
;------------------------OPTION_REG  Bits-------------------------------        
T0CS   EQU      H'0005'
T0SE   EQU      H'0004'
PSA    EQU      H'0003'
PS2    EQU      H'0002'
PS1    EQU      H'0001'
PS0    EQU      H'0000'
        
        
;------------------------PORTB  Bits-------------------------------     
RB5    EQU      H'0005'
RB4    EQU      H'0004'
RB3    EQU      H'0003'
RB2    EQU      H'0002'
RB1    EQU      H'0001'
RB0    EQU      H'0000'
        
        
;------------------------TRISB  Bits-------------------------------     
TRISB5     EQU      H'0005'
TRISB4     EQU      H'0004'
TRISB3     EQU      H'0003'
TRISB2     EQU      H'0002'
TRISB1     EQU      H'0001'
TRISB0     EQU      H'0000'
        
        
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
        
        
;------------------------INTCON  Bits-------------------------------        
GIE        EQU      H'0007'
PEIE       EQU      H'0006'
T0IE       EQU      H'0005'
TMR2IE     EQU      H'0004'
RBIE       EQU      H'0003'
T0IF       EQU      H'0002'
TMR2IF     EQU      H'0001'
RBIF       EQU      H'0000'
        
        
;------------------------KEYCON0  Bits-------------------------------       
KDONE      EQU      H'0007'
CAPK2      EQU      H'0005'
CAPK1      EQU      H'0004'
CAPK0      EQU      H'0003'
KTOUT      EQU      H'0002'
KCAP       EQU      H'0001'
KEN        EQU      H'0000'
        
        
;------------------------KEYCON1  Bits-------------------------------       
KVREF1     EQU      H'0007'
KVREF0     EQU      H'0006'
KCLK1      EQU      H'0005'
KCLK0      EQU      H'0004'
KCHS3      EQU      H'0003'
KCHS2      EQU      H'0002'
KCHS1      EQU      H'0001'
KCHS0      EQU      H'0000'
        
        
;------------------------T2CON  Bits-------------------------------     
TOUTPS3    EQU      H'0006'
TOUTPS2    EQU      H'0005'
TOUTPS1    EQU      H'0004'
TOUTPS0    EQU      H'0003'
TMR2ON     EQU      H'0002'
T2CKPS1    EQU      H'0001'
T2CKPS0    EQU      H'0000'
        
        
;------------------------CCPCON  Bits-------------------------------        
PWM2EN     EQU      H'0006'
PWM2B1     EQU      H'0005'
PWM2B0     EQU      H'0004'
PWM1EN     EQU      H'0002'
PWM1B1     EQU      H'0001'
PWM1B0     EQU      H'0000'
        
        
;------------------------KEYCON2  Bits-------------------------------       
CAP_LVBO2      EQU      H'0007'
CAP_LVBO1      EQU      H'0006'
CAP_LVBO0      EQU      H'0005'
TKEN           EQU      H'0000'
        
        
;------------------------OSCCON  Bits-------------------------------        
IRCF2      EQU      H'0006'
IRCF1      EQU      H'0005'
IRCF0      EQU      H'0004'
        
        
;------------------------WPDB  Bits-------------------------------      
WPDB5      EQU      H'0005'
WPDB4      EQU      H'0004'
WPDB3      EQU      H'0003'
WPDB2      EQU      H'0002'
WPDB1      EQU      H'0001'
WPDB0      EQU      H'0000'
        
        
;------------------------ANSEL  Bits-------------------------------     
ANS5       EQU      H'0005'
ANS4       EQU      H'0004'
ANS3       EQU      H'0003'
ANS2       EQU      H'0002'
ANS1       EQU      H'0001'
ANS0       EQU      H'0000'
        
        
;------------------------PIR1  Bits-------------------------------      
TKIF       EQU      H'0000'
        
        
;------------------------PIE1  Bits-------------------------------      
TKIE       EQU      H'0000'
