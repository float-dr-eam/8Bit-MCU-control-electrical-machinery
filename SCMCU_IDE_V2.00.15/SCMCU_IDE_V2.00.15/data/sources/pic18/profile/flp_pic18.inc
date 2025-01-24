#include <xc.inc>

; defined in flp_pic18_data.c
; located in banked memory
GLOBAL ___DCByte
; defined by the compiler's code-generator in common memory.
GLOBAL ___DCDelay
; defined by the compiler's code-generator in common memory.
GLOBAL ___flp_WREG_temp

;
; Delay by at least ___DCDelay cycles
;
dcdelay MACRO 
	LOCAL dcdelay_start
		movf ___DCDelay,c,w
	dcdelay_start:
		decfsz WREG,f,c
		goto dcdelay_start
ENDM
