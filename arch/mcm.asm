.globl _start
.data
    num1: .word 5
    num2: .word 6
.text
_start:
    # call mcm
    la    a0, num1
    la    a1, num2
    lw    a0, 0(a0)
    lw    a1, 0(a1)     
    jal   ra, mcm

    #exit
    li    a7, 10
    ecall

#****************************************************
# completare la funzione mcm nel campo di sotto
mcm:
	mul a2, a0, a1 #(a*b)
	addi sp, sp, -8 #decremento lo stackpointer per far salvarmi ra
	sw ra, 0(sp) #salvo ra
	sw a2, 4(sp)
	call mcd #chiamo la funzione
	mv t2, a0 #salvo il return della funzione
	lw ra, 0(sp) #ripristino ra
	lw a2, 4(sp)
	addi sp, sp, 8 #ripristino dimensione dello stack
	div a0, a2, t2 #mcm(a,b) = (a*b) / mcd(a.b)
	ret
	
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