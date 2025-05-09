.globl _start

.text
_start:
	# calculate the average of the two even numbers in x5 and x6
	# Put result in x7


    addi x17,x0,5#si puo scrivere anche li a7, 5
    ecall#eseguo la prima lettura da tastiera
    add x5,x0,x10#salvo il risultato della lettura in x5 | si puo scrivere anche mv x5,a0
    ecall
    add x6,x0,x10
    
    add x7,x5,x6#metto la somma dei due numeri in x7
    srli x7,x7,1#divido per due facendo uno shift a destra di 1(2^1)
    

exit:
    addi x17, x0, 10  # call number 10 = exit
    ecall
