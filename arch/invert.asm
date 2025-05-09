.globl _start
.data
    size:   .word  8                 # size of the array        
    array:  .word 1,2,3,4,5,6,7,8    # array of integers

.text
_start:
    # completare con il codice assembly RISC-V nel campo sottostante
    la t0, size
    lw t0,0(t0)
    
    la t1, array
    srai t2, t0, 1 #size/2
    
    li s0, 0#i
loop:
	bge s0, t2, endloop
	sub s1, t0, s0
	addi s1,s1,-1 #size-i-1
	lw t3, 0(t1)#array[i]
	slli s1,s1,2
	add s2, t1, s1
	lw t4, 0(s2)
	sw t3,0(s2)
	sw t4,0(t1)
	addi t1,t1,4
	addi s0,s0,1
	j loop
	
endloop:
    
exit:
    addi x17, x0, 10  # call number 10 = exit
    ecall
