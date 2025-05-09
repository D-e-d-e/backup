.globl _start
.data
    size:   .word  8                 # size of the array        
    array:  .word 1,2,3,4,5,6,7,8    # array of integers

.text
_start:
	#for (int i = 0; i < size/2; i++)  {
    	#int temp = array[i];
    	#array[i] = array[size-i-1];
    	#array[size-i-1] = temp;
	#}     
    # completare con il codice assembly RISC-V nel campo sottostante
    	la t0, size
    	lw t0, 0(t0)
    	srai t3, t0, 1 #size/2
    	addi t5, t0, -1 #size - 1
    	slli t5, t5, 2 #moltiplico per 4
    	    	
    	la t1, array
    	
    	add t6, t1, t5 #array[size - 1]
    	
    	li t2, 0 #indice
FOR:
	bge t2, t3, ENDFOR
	lw t4, 0(t1) #array[i]
	slli s0, t2, 2 #indice per word
	sub s1, t6, s0 #indirizzo di array[size - 1 - i]
	lw s2, 0(s1)
	
	sw s2, 0(t1)
	sw t4, 0(s1)
	
	addi t2, t2, 1
	addi t1, t1, 4  
	j FOR
ENDFOR: