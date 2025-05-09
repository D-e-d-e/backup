.globl _start

.data
	array: .word 5,8,6,1 # -> 1,5,6,8
	size: .word 4
	
.text
_start:
	la t0, size
	lw t0, 0(t0) #t0 <- size
	addi t0, t0, -1 #se no se i = 3, array[i+1] = 4 fuori dall'array 
	li t2, 1 #t2 <- change = 1
WHILE:
	la t1, array
	beqz t2, ENDWHILE
	li t2, 0 #chsnge = 0
	li t3, 0 # t3 <- i = 0
FOR:
	bge t3, t0, ENDFOR
	
	lw t4, 0(t1) #t4 <- array[i]
	lw t5, 4(t1) #t5 <- array[i+1] 
	ble t4, t5, ENDIF
	
	add t6, zero, t4 #t6 <- temp = array[i]
	add t4, t5, zero #array[i] = array[i+1]
	add t5, zero, t6 #array[i+1] = temp
	li t2, 1
	sw t4, 0(t1)
	sw t5, 4(t1)
	
ENDIF:	
	addi t1, t1, 4
	addi t3, t3, 1
	j FOR
ENDFOR:
	j WHILE
ENDWHILE:

	li a7, 10
	ecall 