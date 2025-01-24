;**************************************************************************
;----- BANK0 Register ----------------------------------------------------- 
INDF        EQU      H'0000'
TMR0        EQU      H'0001'
PCL     EQU      H'0002'
STATUS      EQU      H'0003'
FSR     EQU      H'0004'
PORTA       EQU      H'0005'
PORTB       EQU      H'0006'
WPUA        EQU      H'0007'
WPDA        EQU      H'0008'
IOCA        EQU      H'0009'
PCLATH      EQU      H'000A'
INTCON      EQU      H'000B'
PIR1        EQU      H'000C'
TMR2        EQU      H'0011'
T2CON       EQU      H'0012'

PWMD0L      EQU      H'0016'
PWMD1L      EQU      H'0017'
PWMD01H     EQU      H'0018'
PWMTL       EQU      H'0019'
PWMTH       EQU      H'001A'
PWMCON      EQU      H'001B'
ADRESH      EQU      H'001E'
ADCON0      EQU      H'001F'

;----- BANK1 Register -----------------------------------------------------
OPTION_REG      EQU      H'0081'
TRISA       EQU      H'0085'
TRISB       EQU      H'0086'
WPDB        EQU      H'0087'
WDTCON      EQU      H'0088'
PIE1        EQU      H'008C'
OSCCON      EQU      H'008F'
PR2     EQU      H'0092'
ANSEL       EQU      H'0093'
ANSELH      EQU      H'0094'
WPUB        EQU      H'0095'
IOCB        EQU      H'0096'
TABLE_SPH       EQU      H'0097'
TABLE_SPL       EQU      H'0098'
TABLE_DATAH     EQU      H'0099'
KEYCON0     EQU      H'009A'
KEYCON1     EQU      H'009B'
KEYDATAL    EQU      H'009C'
KEYDATAH    EQU      H'009D'
ADRESL      EQU      H'009E'
ADCON1      EQU      H'009F'
        
        
        
        
;------------------------STATUS  Bits-------------------------------        
RP0     EQU    H'0005'
NOT_TO  EQU    H'0004'      
TO      EQU    H'0004'  
NOT_PD  EQU    H'0003'  
PD      EQU    H'0003'      
Z       EQU    H'0002'      
DC      EQU    H'0001'      
C       EQU    H'0000'      

        
;------------------------PORTA  Bits-------------------------------     
RA6   EQU    H'0006'        
RA5   EQU    H'0005'        
RA4   EQU    H'0004'        
RA3   EQU    H'0003'        
RA2   EQU    H'0002'        
RA1   EQU    H'0001'        
RA0   EQU    H'0000'        
        
        
;------------------------PORTB  Bits-------------------------------     
RB6   EQU    H'0006'        
RB5   EQU    H'0005'        
RB4   EQU    H'0004'        
RB3   EQU    H'0003'        
RB2   EQU    H'0002'        
RB1   EQU    H'0001'        
RB0   EQU    H'0000'        
        
        
;------------------------WPUA  Bits-------------------------------      
WPUA6   EQU    H'0006'      
WPUA5   EQU    H'0005'      
WPUA4   EQU    H'0004'      
WPUA3   EQU    H'0003'      
WPUA2   EQU    H'0002'      
WPUA1   EQU    H'0001'      
WPUA0   EQU    H'0000'      
        
        
;------------------------WPDA  Bits-------------------------------      
WPDA6   EQU    H'0006'      
WPDA5   EQU    H'0005'      
WPDA4   EQU    H'0004'      
WPDA3   EQU    H'0003'      
WPDA2   EQU    H'0002'      
WPDA1   EQU    H'0001'      
WPDA0   EQU    H'0000'      
        
        
;------------------------IOCA  Bits-------------------------------      
IOCA6   EQU    H'0006'      
IOCA5   EQU    H'0005'      
IOCA4   EQU    H'0004'      
IOCA3   EQU    H'0003'      
IOCA2   EQU    H'0002'      
IOCA1   EQU    H'0001'      
IOCA0   EQU    H'0000'      
        
        
;------------------------INTCON  Bits-------------------------------        
GIE   EQU    H'0007'        
PEIE   EQU    H'0006'       
T0IE   EQU    H'0005'       
INTE   EQU    H'0004'       
RBIE   EQU    H'0003'       
T0IF   EQU    H'0002'       
INTF   EQU    H'0001'       
RBIF   EQU    H'0000'       
        
        
;------------------------PIR1  Bits-------------------------------      
RAIF   EQU    H'0003'       
PWMIF   EQU    H'0002'      
TMR2IF   EQU    H'0001'     
ADIF   EQU    H'0000'       
        
        
;------------------------T2CON  Bits-------------------------------     
TOUTPS3   EQU    H'0006'        
TOUTPS2   EQU    H'0005'        
TOUTPS1   EQU    H'0004'        
TOUTPS0   EQU    H'0003'        
TMR2ON   EQU    H'0002'     
T2CKPS1   EQU    H'0001'        
T2CKPS0   EQU    H'0000'        

;------------------------PWMD01H  Bits-------------------------------       
PWMD19   EQU    H'0003'     
PWMD18   EQU    H'0002'     
PWMD09   EQU    H'0001'     
PWMD08   EQU    H'0000'     
        
        
;------------------------PWMCON  Bits-------------------------------        
CLKDIV2   EQU    H'0007'        
CLKDIV1   EQU    H'0006'        
CLKDIV0   EQU    H'0005'        
PWM1DIR   EQU    H'0003'        
PWM0DIR   EQU    H'0002'        
PWM1EN   EQU    H'0001'     
PWM0EN   EQU    H'0000'     
        
        
;------------------------ADCON0  Bits-------------------------------        
ADCS1   EQU    H'0007'      
ADCS0   EQU    H'0006'      
CHS3   EQU    H'0005'       
CHS2   EQU    H'0004'       
CHS1   EQU    H'0003'       
CHS0   EQU    H'0002'       
GODONE   EQU    H'0001'     
ADON   EQU    H'0000'       
        
        
;------------------------OPTION_REG  Bits-------------------------------        
INTEDG   EQU    H'0006'     
T0CS   EQU    H'0005'       
T0SE   EQU    H'0004'       
PSA   EQU    H'0003'        
PS2   EQU    H'0002'        
PS1   EQU    H'0001'        
PS0   EQU    H'0000'        
        
        
;------------------------TRISA  Bits-------------------------------     
TRISA6   EQU    H'0006'     
TRISA5   EQU    H'0005'     
TRISA4   EQU    H'0004'     
TRISA3   EQU    H'0003'     
TRISA2   EQU    H'0002'     
TRISA1   EQU    H'0001'     
TRISA0   EQU    H'0000'     
        
        
;------------------------TRISB  Bits-------------------------------     
TRISB6   EQU    H'0006'     
TRISB5   EQU    H'0005'     
TRISB4   EQU    H'0004'     
TRISB3   EQU    H'0003'     
TRISB2   EQU    H'0002'     
TRISB1   EQU    H'0001'     
TRISB0   EQU    H'0000'     
        
        
;------------------------WPDB  Bits-------------------------------      
WPDB6   EQU    H'0006'      
WPDB5   EQU    H'0005'      
WPDB4   EQU    H'0004'      
WPDB3   EQU    H'0003'      
WPDB1   EQU    H'0001'      
WPDB0   EQU    H'0000'      
        
        
;------------------------WDTCON  Bits-------------------------------        
SWDTEN   EQU    H'0000'     
        
        
;------------------------PIE1  Bits-------------------------------      
RAIE   EQU    H'0003'       
PWMIE   EQU    H'0002'      
TMR2IE   EQU    H'0001'     
ADIE   EQU    H'0000'       
        
        
;------------------------OSCCON  Bits-------------------------------        
IRCF2   EQU    H'0006'      
IRCF1   EQU    H'0005'      
IRCF0   EQU    H'0004'      
        
        
;------------------------ANSEL  Bits-------------------------------     
ANSEL6   EQU    H'0006'     
ANSEL5   EQU    H'0005'     
ANSEL4   EQU    H'0004'     
ANSEL3   EQU    H'0003'     
ANSEL2   EQU    H'0002'     
ANSEL1   EQU    H'0001'     
ANSEL0   EQU    H'0000'     
        
        
;------------------------ANSELH  Bits-------------------------------        
ANSEL14   EQU    H'0006'        
ANSEL13   EQU    H'0005'        
ANSEL12   EQU    H'0004'        
ANSEL11   EQU    H'0003'        
ANSEL9   EQU    H'0001'     
ANSEL8   EQU    H'0000'     
        
        
;------------------------WPUB  Bits-------------------------------      
WPUB6   EQU    H'0006'      
WPUB5   EQU    H'0005'      
WPUB4   EQU    H'0004'      
WPUB3   EQU    H'0003'      
WPUB2   EQU    H'0002'      
WPUB1   EQU    H'0001'      
WPUB0   EQU    H'0000'      
        
        
;------------------------IOCB  Bits-------------------------------      
IOCB6   EQU    H'0006'      
IOCB5   EQU    H'0005'      
IOCB4   EQU    H'0004'      
IOCB3   EQU    H'0003'      
IOCB2   EQU    H'0002'      
IOCB1   EQU    H'0001'      
IOCB0   EQU    H'0000'      

;------------------------KEYCON0  Bits-------------------------------        
KDONE   EQU    H'0007'  
CAPK2   EQU    H'0005' 
CAPK1   EQU    H'0004' 
CAPK0   EQU    H'0003' 
KTOUT   EQU    H'0002' 
KCAP    EQU    H'0001' 
KEN     EQU    H'0000' 

;------------------------KEYCON1  Bits-------------------------------        
KVREF1  EQU    H'0007'   
KVREF0  EQU    H'0006'
KCLK1   EQU    H'0005'
KCLK0   EQU    H'0004'
KCHS3   EQU    H'0003'
KCHS2   EQU    H'0002'
KCHS1   EQU    H'0001'
KCHS0   EQU    H'0000'  
        
;------------------------ADCON1  Bits-------------------------------        
ADFM   EQU    H'0007'       
