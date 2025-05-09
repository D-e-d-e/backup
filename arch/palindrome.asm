.globl _start
.data
        array: .word 1,2,3,4,5,4,3,2,1
        size:  .word 9
        
.text
_start:
        # chiama palindrome
        la   a0, array
        la   a1, size
        lw   a1, 0(a1)
        jal  ra, palindrome
        
        #exit
        li   a7, 10
        ecall
    
#*********************************************************
# completare la funzione palindrome nel campo di sotto

palindrome:
	li t0, 0 #i
	addi t1, a1, -1 #j = size-1
	li t2, 1 #result = 1
	addi sp, sp, -24
	sw ra, 0(sp)
	sw a0, 4(sp)
	sw a1, 8(sp)
	sw t2, 20(sp)
	while:
		bge t0, t1, endloop
		sw t0, 12(sp)
		sw t1, 16(sp)
		mv a1, t0
		mv a2, t1
		call equal
		mv t3, a0
		lw t2, 20(sp)
		and t2, t2, t3
		lw a0, 4(sp)
		lw t1, 16(sp)
		lw t0, 12(sp)
		addi t0, t0, 1
		addi t1, t1, -1
		beqz t2, endloop
		j while
	endloop:
		mv a0, t2
		lw ra, 0(sp)
		addi sp, sp, 24
		ret
		

equal: 
	slli a1, a1, 2 #x*4
	slli a2, a2, 2 #y*4
	
	add t0, a0, a1 #indirizzo array[x]
	add t1, a0, a2 #indirizzp array[y]
	
	lw t0, 0(t0)
	lw t1, 0(t1)
	bne t0, t1, ne
	li a0, 1
	j end
	ne:
	li a0, 0
	end:
	ret
