.globl _start
.data
    size:  .word 8
    array: .word 1,5,3,7,2,6,4,8
.text
_start:
    # chiama invert
    la   a0, array
    la   a1, size
    lw   a1, 0(a1)        
    jal  ra, invert
    
    #exit
    li   a7, 10
    ecall

#***************************************************
# completare la funzione invert nel campo di sotto

invert:
	li t0, 0#i
	addi t1, a1, -1 #size - 1
	srai t2, a1, 1 #size/2
	addi sp, sp, -20
for:
	bge t0, t2, endfor
	mv a1, t0 #secondo parametro
	sub t3, t1, t0 #size-1-i
	mv a2, t3 #terzo parametro
	
	sw ra, 0(sp)
	sw t0, 4(sp)
	sw t1, 8(sp)
	sw t2, 12(sp)
	sw t3, 16(sp)
	
	call swap
	
	lw ra, 0(sp)
	lw t0, 4(sp)
	lw t1, 8(sp)
	lw t2, 12(sp)
	lw t3, 16(sp)
	
	addi t0, t0, 1 #i++
	j for
endfor:	
	ret
	
swap:
	slli t1, a1, 2
	slli t2, a2, 2
	
	add t3, a0, t1#indirizzo array[x]
	add t4, a0, t2#indirizzo array[y]
	lw a2, 0(t3)
	lw a3, 0(t4)
	sw a2, 0(t4)
	sw a3, 0(t3)
	ret