.globl _start

.text

_start:
	
    #<assembler code here>
    li t0, 8
    li t1, 1#R
    li t2, 0#A
    li t3, 1#B
    
    LOOP:
    	ble t0, zero END
    	
    	add t1, t2, t3
    	add t2, t3, zero
    	add t3, t1, zero
    	addi t0, t0, -1
    	
    	j LOOP
    END:
    	

exit:
    addi x17, x0, 10  # call number 10 = exit
    ecall
