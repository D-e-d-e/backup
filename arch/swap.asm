.globl _start
.data
    size:  .word 8
    array: .word 1,5,3,7,2,6,4,8
    x:     .word 0
    y:     .word 1
    
.text
_start:
    # chiama swap
    la   a0, array
    la   a1, x
    lw   a1, 0(a1)
    la   a2, y
    lw   a2, 0(a2)
    jal  ra, swap
    
    #exit
    li   a7, 10
    ecall

#***************************************************
# completare la funzione swap nel campo di sotto

swap:
	slli t1, a1, 2
	slli t2, a2, 2
	
	add t3, a0, t1#indirizzo array[x]
	add t4, a0, t2#indirizzo array[y]
	lw a2, 0(t3) #swap
	lw a3, 0(t4)
	sw a2, 0(t4)
	sw a3, 0(t3)
	ret
	