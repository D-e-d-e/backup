.globl _start
.data
    array: .word  1,2,3,4,5,6,7,8,9,10
    size:  .word  10
    
.text
_start:
    # chiama sumarray
    la   a0, array
    la   a1, size
    lw   a1, 0(a1)
    jal  ra, sumarray
    
    #exit
    li   a7, 10
    ecall

#****************************************************
# completare la funzione sumarray nel campo di sotto

sumarray:
	#NOTA: il caso base è una funzione foglia: non mi serve creare un record di attivazione
	bnez a1, sumarray_rec
	li a0, 0 		#return 0
	ret
sumarray_rec:
	addi sp, sp, -8
	sw ra, 0(sp)
	sw s1, 4(sp)
	

	lw s1,0(a0)
	addi a0, a0, 4
	addi a1, a1, -1
	jal ra, sumarray
	add a0, s1, a0
	
	lw ra, 0(sp)
	lw s1, 4(sp)
	addi sp, sp, 8
	ret
	