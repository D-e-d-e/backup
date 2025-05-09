#prelevare i bit 2 e 3 da x5 e salvarli nei bit 6 e 7 di x6

.globl _start

.text

_start:

    #<assembler code here>
    li x5, 0x00000000
    li x6, 0xFFFFFFFF
    
    li x7, 0x0003F000
    and x8, x5, x7
    slli x7,x7,15
    xori x7, x7, -1 # inverte i bit
    and x6,x6,x7
    


exit:
    addi x17, x0, 10  # call number 10 = exit
    ecall