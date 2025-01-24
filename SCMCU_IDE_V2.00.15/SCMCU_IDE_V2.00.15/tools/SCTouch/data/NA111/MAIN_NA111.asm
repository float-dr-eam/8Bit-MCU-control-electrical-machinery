
;注意事项
;寄存器：KEYF、KEYF1、
;标志位：B_KEY_EN、B_KEY_LONG、B_KEY_UP、B_KEY_SLP、B_KEY_WAKE	
;为BANK0的空间，使用时需要注意页的切换

;**********************************************
;**********************************************

GPR0		EQU 		0EH	        ;中断现场保护寄存器必须用BANK1,BANK0公用寄存器
GPR1		EQU 		0FH         ;中断现场保护寄存器必须用BANK1,BANK0公用寄存器
TCOUNT		EQU 		？	;系统计时，125US加1
;--------------------------------------------
;工作RAM
;**************************************

;;********************************************************
;*********************************************************
		ORG 		00H
   		JP  		START
		ORG 		01H
;--------------------------------------------
INT_IN:
		LD  		GPR0,A			;中断现场保护
		SWAPR		GPR0
		SWAPA		FLAGS
		LD  		GPR1,A
;--------------------------------------------
INT_TMR1:							;只用到1个中断，TMR1中断每125US进一次
        BANKSEL_BANK0
		INCR		TCOUNT
		CLR 		INT_FLAG
;--------------------------------------------							
INT_BACK:
		SWAPA		GPR1
		LD  		FLAGS,A
		SWAPA		GPR0			;中断返回
		RETI
;********************************************

;********************************************
;********************************************
		
;********************************************
START:
		NOP
		CLRWDT								;上电清WDT（必要）
;-----------初始化I/O------------------------;设置IO口的初始状态
		CLR 		P0
		SET			P1
		LDIA		03H
		LD			P2,A
		
		LDIA		B'11111111'
		LD  		P0CH,A			
		LDIA		B'11111111'		;P0,0-P0,7为触摸按键检测口
		LD  		P0CL,A	

		LDIA		B'01110010'		;P1,6 检测AD（灵敏度调节）
		LD  		P1CH,A			;P1.5 灵敏度电容，先输出低放电
		LDIA  		B'10101010'		;P1,0 BCD码高位，其它口未用
		LD  		P1CL,A

		LDIA		B'00010010'		;P2.0编码输出
		LD  		P2C,A			;P2.2 为防水/抗干扰选择
		
;-----------清寄存器 BANK0--------------------------
CLR_RAM:								;间接寻址清掉所有RAM
		BANKSEL_BANK0
		LDIA		0FH
		LD  		MP,A
CLR_LOOP:
		INCR		MP
		CLR 		IAR
		LDIA		07FH
		SUBA		MP
		SNZB		FLAGS,C
		JP  		CLR_LOOP
;***************清寄存器 BANK1************************
CLR_RAM_1:
        BANKSEL_BANK1
		LDIA		02FH
		LD  		MP,A
CLR_LOOP_1:
		INCR		MP
		CLR 		IAR
		LDIA		07FH
		SUBA		MP
		SNZB		FLAGS,C
		JP  		CLR_LOOP_1
		
;-------------上电延时-----------------------
INIT_DELAY:
        BANKSEL_BANK0
		LDIA		.0
		LD  		TCOUNT,A
INIT_LOOP:								;上电延时3*256*256*5/2=500MS
		CLRWDT
		SZDECR	    TCOUNT
		JP  		INIT_LOOP
;---------------------------------------------
;-----------初始化RAM-------------------------
INIT_RAM:
        BANKSEL_BANK0
        CLR         TCOUNT
 		CLR			PWM8DATA
		CLR			PWM10DATA
		CLR			TABLE_SPL	;
		CLR			BUZCON
		CLR			INT_EXT		;
		CLR			TABLE_SPH	;
		CLR         08H
		CLR         0EH
		CLR         0FH
		CLR         25H
		CLR         26H
		CLR         27H
		CLR         2AH
		CLR         2BH

		LDIA		.6
		LD  		TMR1,A				; TMR1初值设定
		LDIA		80H					; TMR1设定为定时器，分频比1：1
		LD  		TMR1C,A
		SETB		TMR1C,4				; TMR1开启
		
		LDIA		03H
		LD  		SYS_GEN,A			;中断使能，AD禁止
		LDIA		08H					;TMR1中断使能，其它中断关闭
		LD  		INT_EN,A

;********************************************
;********************************************
;********************************************
MAIN:
        CALL        SET_SYS_1
        BANKSEL_BANK0
		LDIA		.20					;125us*10=1.25ms一个主循环
		SUBA		TCOUNT
		SNZB		FLAGS,C
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
        BANKSEL_BANK0
		LDIA		B'11111111'
		LD  		P0CH,A			
		LDIA		B'11111111'		;P0,0-P0,7为触摸按键检测口
		LD  		P0CL,A	
		LDIA		B'10010001'		;P1,6 检测AD（灵敏度调节）
		LD  		P1CH,A			;P1.5 灵敏度电容，先输出低放电
		CLR			28H
		CLR			29H
SET_SYS_1:		
		LDIA		03H
		LD  		SYS_GEN,A		;中断使能，AD禁止
		LDIA		08H					; TMR1中断使能，其它中断关闭
		LD  		INT_EN,A
		LDIA		.6
		LD  		TMR1,A				; TMR1初值设定
		LDIA		90H
		SUBA		TMR1C				;TMR1在没有乱的情况下不进行写操作，以免影响定时
		SZB 		FLAGS,Z
		JP  		SET_SYS_BACK
		LDIA		80H					; TMR1设定为定时器，分频比1：1
		LD  		TMR1C,A
		SETB		TMR1C,4				; TMR1开启
SET_SYS_BACK:
		RET
;*****************************************
		;ORG			0100H
;*****************************************
;*****************************************

;*****************************************
MAINK:
		SNZB		 B_KEY_EN			;有按键进入处理
		JP			 MAINK_BACK
		CLRB		 B_KEY_EN
		
		SZB			 B_KEY_LONG			;长按键
		JP			 MAINK_LONG
		
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
MAINK_LONG:
MAINK_BACK:
        RET
;********************************************
		;ORG			0500H
KSCAN：
        #INCLUDE	"Touch_Kscan_Library.lib"
;********************************************
		END
