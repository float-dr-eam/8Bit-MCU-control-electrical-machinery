#include "pic18.inc"
;include "itoption.inc"

GLOBAL  __IT_INT_MASK
GLOBAL  __IT_SAVE_BSR
GLOBAL  __IT_SAVE_WREG
GLOBAL  __IT_SAVE_STATUS

;Global functions
GLOBAL	__IT_SAVE_ASM_INTPRI
GLOBAL	__IT_RESTORE_ASM_INTPRI


psect text,class=CODE,reloc=2
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; 
; Use this function to disable interrupts and save context in an 
; assembly application that may have priority interrupts enabled.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

__IT_SAVE_ASM_INTPRI:
	btfsc   INTCON,7
	bra     __it_1x

	btfsc   INTCON,6
	bra     __it_01

; 00
	movff   WREG,__IT_SAVE_WREG
	movlw   0                     ; clrf affects status
	bra     __it_save_regs

__it_1x:
	bcf     INTCON,7,c
	btfsc   INTCON,6,c
	bra     __it_11

; 10
	movff   WREG,__IT_SAVE_WREG
	movlw   2
	bra     __it_save_regs

__it_01:
	bcf     INTCON,6,c
	movff   WREG,__IT_SAVE_WREG
	movlw   1
	bra     __it_save_regs

__it_11:
	bcf     INTCON,6,c
	movff   WREG,__IT_SAVE_WREG
	movlw   3

__it_save_regs:
	movff   BSR,__IT_SAVE_BSR
	movff   STATUS,__IT_SAVE_STATUS

	movlb	__IT_INT_MASK>>8
	movwf   __IT_INT_MASK,b
	return


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

__IT_RESTORE_ASM_INTPRI:
	movff   __IT_SAVE_WREG,WREG
	movff   __IT_SAVE_STATUS,STATUS

	btfsc   __IT_INT_MASK,1,b
	bra     __it_set_1x

	btfsc   __IT_INT_MASK,0,b
	bra     __it_set_01

; set 00
	movff   __IT_SAVE_BSR,BSR
	return

__it_set_1x:
	btfsc   __IT_INT_MASK,0,b
	bra     __it_set_11

; set 10
	movff   __IT_SAVE_BSR,BSR
	bsf     INTCON,7,c
	return

__it_set_01:
	movff   __IT_SAVE_BSR,BSR
	bsf     INTCON,6,c
	return

__it_set_11:
	movff   __IT_SAVE_BSR,BSR
	bsf     INTCON,7,c
	bsf     INTCON,6,c
	return


    END
