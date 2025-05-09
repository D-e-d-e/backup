.globl _start
.data
    num1: .word 24
    num2: .word 30
.text
_start:
    # call mcd
    la    a0, num1
    la    a1, num2
    lw    a0, 0(a0)
    lw    a1, 0(a1)     
    jal   ra, mcd

    #exit
    li    a7, 10
    ecall

#****************************************************
# completare la funzione mcd nel campo di sotto
mcd:
while:
	beq a0, a1, endloop
	
	bgt a0, a1, if
	j else
if:
	sub a0, a0, a1
	j endif
else:
	sub a1, a1, a0
endif:
	j while
endloop:
	ret
	