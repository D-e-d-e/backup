.globl _start

.data
	len: .word 5	
	array: .byte 1, 3, 5, 6, 10
	result: .word 0
.text

_start:
	la t0, len
	lw t0, 0(t0)
	
	la t1, array
	li t2, 0 #numero di dispari
	li t3, 0 #indice
	li t4, 1 #maschera per verificare se il bit meno significativo è uno(il numero è dispari)
	
	loop:
		bge t3, t0, end
		lb t5, 0(t1)
		and t6, t4, t5
		add t2, t2, t6
		addi t1, t1, 1
		addi t3, t3, 1
		j loop 	
	end:
	la t0, result
	sw t2, 0(t0)
exit:
    addi x17, x0, 10  # call number 10 = exit
    ecall
