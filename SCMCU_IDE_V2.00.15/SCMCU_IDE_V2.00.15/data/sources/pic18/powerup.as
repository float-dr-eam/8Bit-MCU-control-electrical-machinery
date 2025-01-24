	global	powerup,start
	psect	powerup,class=CODE,delta=1,reloc=2
powerup:
	nop	; Suggested Microchip errata workaround
	goto	start
	end
