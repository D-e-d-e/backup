.globl _start
.data
    num: .word 5
.text
_start:
    # call fib
    la    a0, num
    lw    a0, 0(a0)
    jal   ra, fib

    #exit
    li    a7, 10
    ecall

#****************************************************
# completare la funzione fib nel campo di sotto

fib:
	bnez a0, else_if 		#if n == 0
	li a0, 0
	ret
else_if:
	li s1, 1
	bne a0, s1, fib_rec		#if n == 1
	li a0, 1
	ret
fib_rec:					#else recursion
	addi sp, sp, -12
	sw ra, 0(sp)
	sw a0, 4(sp)
	addi a0, a0, -1
	
	call fib
	
	mv t1, a0
	sw t1, 8(sp)
	lw a0, 4(sp)
	addi a0, a0, -1
	
	call fib
	
	
	
	
	