.globl _start

.text

_start:

    #<assembler code here>
    li t0, 10#a
    li t1, 5#b
    li t2, 0#R
    li t3, 0#i
    li t4, 0#j
    LOOP1:
    	bge t3, t0, ENDLOOP1
    LOOP2:
    	bge t2, t1, ENDLOOP2
    	add t2, t2, t2#R = 2*R
    	add t2, t2, t3#R = 2*R+i
    	add t2, t2, t4#R = 2*R+i+j
    	addi t4, t4, 1#incremento j
    	j LOOP2
    ENDLOOP2:
    	addi t3, t3, 1#incremento i
  	j LOOP1
    ENDLOOP1:

exit:
    addi x17, x0, 10  # call number 10 = exit
    ecall
