.globl _start

.text

_start:

    #<assembler code here>
    li t0, 6
    li t1, 8
    li t2, 10
    
    
    ble t0, t1, JUMP
    ble t0, t2, JUMP2
    mv t3, t0
    j END
    
    JUMP:
    	ble t1, t2, JUMP2
    	mv t3, t1
    	j END
    JUMP2:
    	mv t3 t2
    	
    END:
    addi x17, x0, 1
    add a0, zero, t3 #print
    ecall
    
exit:
    addi x17, x0, 10  # call number 10 = exit
    ecall
