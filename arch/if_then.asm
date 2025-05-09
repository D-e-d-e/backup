.globl _start

.text

_start:

    #<assembler code here>
    li t0, 7
    li t1, 5
    
    sub t0, t0, t1
    bge t0, zero, JUMP
    
    add t0, zero, zero
    
    JUMP:
    	addi t1, t1, -1 

exit:
    addi x17, x0, 10  # call number 10 = exit
    ecall
