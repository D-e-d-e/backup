.globl _start
.data
    numstr: .string  "123"
.text
_start:
    # chiama strlen per ottenere la lunghezza della stringa
    la   a0, numstr
    jal  ra, strlen
    
    # chiama atoi
    mv   a1, a0
    la   a0, numstr
    jal  ra, atoi

    #exit
    li   a7, 10
    ecall

#*******************************************************************************
# strlen
# a0 - str
#*******************************************************************************
# usare la funzione strlen sviluppata in precedenza 

#****************************************************
# completare la funzione atoi nel campo di sotto

strlen:
   	mv t0, a0
	li a0, 0 #i
for:
	lbu t1, 0(t0)
	beqz t1, endfor
	addi a0, a0, 1
	addi t0, t0, 1
	j for
endfor:
	ret



atoi:
	
		
			
				
					
	
			
