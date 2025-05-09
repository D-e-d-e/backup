.globl _start

.text

_start:

    #<assembler code here>
    li t0, 10 #N
    li t1, 0 #S
    li t2, 0 #I
    LOOP:
    	bgt t2, t0, ENDLOOP
    	mul t3,t2,t2
    	add t1, t1, t3
    	addi t2, t2, 1
    	j LOOP
    ENDLOOP: 
    

exit:
    addi x17, x0, 10  # call number 10 = exit
    ecall

