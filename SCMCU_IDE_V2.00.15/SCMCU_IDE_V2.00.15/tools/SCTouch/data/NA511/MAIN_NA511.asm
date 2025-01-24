;注意事项：
;1、SC8P8022 的 PIN2 是由 RE0、RB7 合封在一起，在触摸方案应用过程中 TRISB,7 必须设置为1，即RB7为输入状态。
;2、SC8P8022 的 PIN7 是由 RA1、RA2、RC2 合封在一起，应用过程中将未使用的2个管脚固定设置为输入状态。
;**********************************************
;**********************************************

GPR0		EQU 		?	       
GPR1		EQU 		?        
TCOUNT		EQU 		?	
TEMP        EQU         ?
TEMPL		EQU			?
COUNT       EQU         ?

KEYF_OLD	EQU			?
;--------------------------------------------
;工作RAM
;**************************************
;*********************************************************
		ORG 		00H
   		JP  		START
		ORG 		04H
;***************************************************

        LD  		GPR0,A			;中断现场保9护
		SWAPR		GPR0
		SWAPA		STATUS
		LD  		GPR1,A
INT_TMR2:
		CLR 		PIR1			;清中断响应标志位
		INCR		TCOUNT
;*****************************************
INT_EXIT:
		SWAPA		GPR1
		LD  		STATUS,A
		SWAPA		GPR0
		RETI
;********************************************

;********************************************
;********************************************
		
;********************************************
START:
		NOP
		CLRWDT
		NOP
		NOP
		NOP
;-----------初始化I/O------------------------
		LDIA		071H
		LD			OSCCON,A
		LDIA		000H
		LD  		PORTA,A	    ;上电关闭继电器 PA.6 PA.7			
		LDIA		B'00000000'
		LD  		TRISA,A
	    LDIA		080H
		LD  		PORTA,A	
		
		LDIA		B'11111111'			
		LD  		PORTB,A
		LDIA		B'11111111'	
		LD  		TRISB,A
		LDIA		B'11111111'			
		LD  		PORTB,A	
		LDIA		B'11111111'
		LD  		PORTC,A
		LDIA		B'01000000'		
		LD  		TRISC,A			
	    LDIA		B'11111111'
		LD  		PORTC,A
		
;		LDIA		00H
;		LD  		PORTE,A
;		LDIA		B'00001111'		
;		LD  		TRISE,A
;		LDIA		0H
;		LD  		PORTE,A

		CLR			INTCON
;-----------清寄存器10~7FH--------------------------
		CLRB		STATUS,IRP
CLR_RAM：
		LDIA		1FH					;从20H开始
		LD  		FSR,A
CLR_RAM_LOOP:
		INCR		FSR
		CLR 		INDF
		LDIA		07FH
		ANDA		FSR
		SUBIA		07FH				;20-7F,A0-FF,120-17F,1A0-1FF
		SNZB 		STATUS,Z
		JP  		CLR_RAM_LOOP
		SZB 		FSR,7
		JP  		CLR_RAM_H
		LDIA		20H					;当前是7FH，增加20H，开始清A0-FF
		ADDR		FSR
		JP  		CLR_RAM_LOOP
CLR_RAM_H:						
		SZB 		STATUS,IRP			;判断是否已经是第3-4BANK
		JP  		CLR_RAM_BACK		;已经是第3-4BANK,清RAM结束
		SETB		STATUS,IRP			;不是3-4BANK,设置BANK标志位，开始清3-4BANK的RAM
		JP  		CLR_RAM
CLR_RAM_BACK:
		CLRB		STATUS,IRP
;----------------------------------------------
INIT_LOOP:						;上电延时3*256*256/2=100MS
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		SZDECR		COUNT
		JP  		INIT_LOOP
		CLRWDT
	
		SZDECR		TEMP
		JP  		INIT_LOOP
;************************************************
;-----------------------------------------------
INIT_RAM:
		LDIA		.250			;8M下125US
		LD  		PR2,A			;TMR2设置成250US
		LDIA		B'00000100'
		LD  		T2CON,A
		LDIA		02H
		LD			PIE1,A
		LDIA		0C0H
		LD  		INTCON,A		;定时2中断使能

;********************************************
;********************************************
;********************************************
MAIN:
        CALL        SYS_SET_1
		LDIA		.32					;125us*32=4ms一个主循环
		SUBA		TCOUNT
		SNZB		STATUS,C
		JP  		MAIN
;********************************************
		CLR 		TCOUNT
		CLRWDT
;********************************************
;********************************************
MAIN_SUB:
		CALL		SET_SYS		
		CALL  		KSCAN           ;触摸扫描程序	
		CALL        MAINK	
		JP  		MAIN
;********************************************
;********************************************
SET_SYS:		
 	    LDIA		B'00000000'
		LD  		TRISA,A
		LDIA		B'00000000'	
		CLRA
		LD  		TRISB,A
		LDIA		B'00000000'		
		LD  		TRISC,A			
;		LDIA		B'00001000'		
;		LD  		TRISE,A
;		CLRB		PORTE,0
		LDIA		B'00000000'
		LD			ADRESL,A
		
        CLR         T1CON
        CLR         CCP1CON
        CLR         CCP2CON
        CLR         WPUB
;        CLR         IOCB
;        CLR         VRCON                      
SYS_SET_1:		
		LDIA		.250
		LD  		PR2,A
		LDIA		02H
		LD			PIE1,A
		LDIA		0C0H
		LD  		INTCON,A		;定时2中断使能
		LDIA		04H
		SUBA		T2CON			;T2CON为04时不写
		SZB 		STATUS,Z
		JP  		SYS_BACK
		LDIA		00H				;写操作会影响计时，在T2CON没有乱的时候不写
		LD  		T2CON,A
		SETB		T2CON,2	
SYS_BACK:
		RET
;*****************************************

;*****************************************

;*****************************************
MAINK:
		LD			A,KEYF
		SZB			STATUS,Z
		JP			MAINK_NO			;没有按键
		XORA		KEYF_OLD
		SZB			STATUS,Z
		JP			MAINK_BACK			;相同按键不在处理
		
		LD			A,KEYF
		LD			KEYF_OLD,A
		
		SZB			KEYF,0
		JP			MAINK_KEY1
		SZB			KEYF,1
		JP			MAINK_KEY2
		SZB			KEYF,2
		JP			MAINK_KEY3
		JP			MAINK_BACK
MAINK_KEY1:
		;这儿加入按键1的处理程序
		JP			MAINK_BACK
MAINK_KEY2:
		;这儿加入按键2的处理程序
		JP			MAINK_BACK
MAINK_KEY3:
		;这儿加入按键3的处理程序
		JP			MAINK_BACK
MAINK_NO:
		CLR			KEYF_OLD
MAINK_BACK:
        RET
;********************************************
KSCAN：
        #INCLUDE	"Touch_Kscan_Library.lib"
;********************************************
		END

