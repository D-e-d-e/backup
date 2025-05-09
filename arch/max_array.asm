.globl _start

.data
	size: 5
	array: .word 9, 6, 7, 8, 1
	result: .word 0

.text

_start:
	la t0, size
    	lw t0, 0(t0) #lunghezza array
    	la t1, array 
    
    	li t2, 0x80000000 #minimo valore rappresentabile -->MAX
    	li t3, 0 #indice
	
loop:
	bge t3, t0, end
	lw t4, 0(t1)
	addi t1, t1, 4
	
	bge t2, t4, next
		
	mv t2, t4
		
next:
	addi t3, t3, 1
			
	j loop  
end:
	la t0, result
	sw t2, 0(t0)
    

exit:
    addi x17, x0, 10  # call number 10 = exit
    ecall
