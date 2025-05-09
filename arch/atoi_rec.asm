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
	bnez a1, atoi_rec
	li a0, 0		#return 0
	ret
atoi_rec:
	addi a1, a1, -1		#n-1
	addi sp, sp, -4
	sw ra, 0(sp)
	
	call atoi
	li s1, 10		#moltiplico per 10
	mul s2, a0, s1		#10*atoi(str,n-1)
	add s3, a0, a1
	lbu s4, 0(s3)
	addi s4, s4, -48
	add a0, s2, s4		
 
	
	lw ra, 0(sp)
	addi sp, sp, 4
	ret
	