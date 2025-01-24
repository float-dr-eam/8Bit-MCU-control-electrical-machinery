;**********************************************
;触摸库程序使用范例,此程序仅供参考
;**********************************************

;工作RAM
GPR0		EQU 		?
GPR1		EQU 		?        
TCOUNT		EQU 		？	
TEMP        EQU         ?
TEMPL		EQU			?
COUNT       EQU         ?

KEYF_OLD	EQU			?

TIME		EQU			?

WORK		EQU			?
F_ONOFF		EQU			WORK,0

;**********************************************
;**********************************************
		ORG 		00H
   		JP  		START
		ORG 		04H
;**********************************************
        LD  		GPR0,A			;中断现场保护
		SWAPR		GPR0
		SWAPA		STATUS
		LD  		GPR1,A
INT_TMR2:
		CLR 		PIR1			;清中断响应标志位
		INCR		TCOUNT
;**********************************************
INT_EXIT:
		SWAPA		GPR1
		LD  		STATUS,A
		SWAPA		GPR0
		RETI
;**********************************************
;**********************************************

;**********************************************
;**********************************************
START:
		NOP
		CLRWDT
		
		LDIA		071H
		LD			OSCCON,A		;8MHz
		CLR			INTCON
		
;-----------初始化I/O------------------------
		LDIA		00H
		LD  		PORTA,A
		LD  		TRISA,A
		LD  		PORTA,A	
				
		LD  		PORTB,A
		LD  		TRISB,A			
		LD  		PORTB,A	
		
		LD  		PORTC,A		
		LD  		TRISC,A
		LD  		PORTC,A
		
;-----------清寄存器10~7FH-------------------
		CLRB		STATUS,IRP
CLR_RAM：
		LDIA		1FH					;从20H开始
		LD  		FSR,A
CLR_RAM_LOOP
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
INIT_LOOP:							;上电延时3*256*256/2=100MS
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
;**********************************************
;**********************************************
MAIN:
        CALL        SET_SYS
		LDIA		.32				;125us*32=4ms一个主循环
		SUBA		TCOUNT
		SNZB		STATUS,C
		JP  		MAIN
;**********************************************
		CLR 		TCOUNT
		CLRWDT
		
		CALL		SET_SYS		
		CALL  		KSCAN           ;触摸扫描程序
		CALL        MAINK
		CALL		SET_WORK
		CALL		WORK_SLEPP
		JP  		MAIN


;**********************************************
;**********************************************
SET_SYS:
		LDIA		.250
		LD  		PR2,A
		LDIA		02H
		LD			PIE1,A
		LDIA		0C0H
		LD  		INTCON,A		;定时2中断使能
		LDIA		04H
		SUBA		T2CON			;T2CON为04时不写
		LDIA		04H	
		SNZB 		STATUS,Z	
		LD  		T2CON,A			;写操作会影响计时，在T2CON没有乱的时候不写	
		RET


;**********************************************
;按键处理程序
;每次检测到按键翻转IO口输出电平
;**********************************************
MAINK:
		LD			A,KEYF
		SZB			STATUS,Z
		JP			MAINK_NO
		
		LD			A,KEYF
		XORA		KEYF_OLD		;相同
		SZB			STATUS,Z
		JP			MAINK_BACK
		
		LD			KEYF_OLD,A
		
		LDIA		10H
		SNZB		KEYF_OLD,0
		JP			$+3
		SZB			KEYF,0
		XORR		PORTA
		
		LDIA		20H
		SNZB		KEYF_OLD,1
		JP			$+3
		SZB			KEYF,1
		XORR		PORTA
		
		LD			A,KEYF
		LD			KEYF_OLD,A

		JP			MAINK_BACK
MAINK_NO:
		CLR			KEYF_OLD
MAINK_BACK:
		RET

;**********************************************
;**********************************************
SET_WORK:
		LD			A,KEYF
		SZB			STATUS,Z
		JP			SET_WORK_BACK
		
		SNZB		KEYF,0
		JP			SET_WORK_ON
		
		CLRB		F_ONOFF
		SZB			PORTA,4
SET_WORK_ON:
		SETB		F_ONOFF
		
		SNZB		F_ONOFF
		CLRB		PORTA,4
		SZB			F_ONOFF
		SETB		PORTA,4
SET_WORK_BACK:
		RET

;**********************************************
;进入休眠
;**********************************************
WORK_SLEPP:
#if 	C_KEY_WAKEUP != 0
		SZB			F_ONOFF
		CLR			TIME

		;关机500MS系统进入休眠
		INCR		TIME
		LDIA		125					;4MS*125=500MS
		SUBA		TIME
		SNZB		STATUS,C
		RET
		CLR			TIME

		;进入休眠前关掉所有功能模块,以降低休眠电流
		CLR			ADCON0
		CLR			KEYCON0
		CLR			CCP1CON
		CLR			CCP2CON
		
		
		;进入休眠前,必须固定口线电平,这儿全部输出低电平,并关闭所有上拉电阻
		CLR			TRISA
		CLR			PORTA
		CLR			TRISB
		CLR			PORTB
		CLR			TRISC
		CLR			PORTC
		
		CLR			WPUA
		CLR			WPUB
		CLR			WPUC
		
		CALL		_KSCAN_ENTER_SLEEP	;进入休眠模式
		
		;休眠被唤醒,重新配置中断等SFR,使系统进入正常工作
;		CALL		SET_SYS
#endif		
		RET

;**********************************************
;调用按键库文件
;**********************************************
KSCAN:
        #INCLUDE	"Touch_Kscan_Library.lib"
;**********************************************
		END

