#include <xc.inc>

; These are defined by the compiler's code-generator in common memory.
GLOBAL ___DCByte
GLOBAL ___DCDelay
GLOBAL ___flp_WREG_temp 

;
; Delay by at least ___DCDelay cycles
;
dcdelay MACRO
	LOCAL start_dcdelay
		movf ___DCDelay,w
	start_dcdelay:
		decfsz WREG,w
		goto start_dcdelay
ENDM

