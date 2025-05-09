.globl _start

.data
	size: 5
	array: .word 4, 2, 10, 45, 1

.text

_start:
    	la t0, size
    	lw t0, 0(t0) #size
    	addi t0, t0, -1 #size -1
    	
    	li t2, 1 #change = 1
    	
loop1:
 	la t1, array #indirizzo array[0]
    	beqz t2, end1
    	add t2, zero, zero #change = 0
    	li t3, 0 #i=0
loop2:
   	bge t3, t0, end2
    	lw t4,0(t1) #array[i]
    	lw t5, 4(t1) #array[i+1]
if:
    	ble t4, t5, endif
    	sw t5, 0(t1) #array[i] = array[i+1]
    	sw t4, 4(t1) #array[i+1] = array[i]
    	li t2, 1 #change=1
endif:
   	addi t3, t3, 1 #i++
    	addi t1, t1, 4
    	j loop2
end2:
	j loop1
end1:
exit:
    addi x17, x0, 10  # call number 10 = exit
    ecall
