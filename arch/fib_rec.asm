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
	bnez a0, else
	li a0, 0
	ret
else:
	li t0, 1
	bne a0, t0, fib_rec
	li a0, 1
	ret
fib_rec:
	addi sp, sp, -8
	sw ra, 0(sp)
	sw a0, 4(sp)
	
	addi a0, a0, -1		#n-1
	lw a0, 4(sp)
	call fib
	mv t1, a0
	addi a0, a0, -1		#n-2
	call fib
	add a0, a0, t1
	
	lw ra, 0(sp)
	
	addi sp, sp, 8
	ret