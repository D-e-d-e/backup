.globl _start
.data
    srcstr: .string  "string to be copied"
    dststr: .string  "destination string is long enough"
.text
_start:
    
    # chiama strcpy    
    la   a0, srcstr
    la   a1, dststr
    jal  ra, strcpy

    #exit
    li   a7, 10
    ecall

#*******************************************************************************
# strlen
# a0 - str
#*******************************************************************************
# usate il vostro codice fatto in precedenza per strlen

#****************************************************
# completare la funzione strcpy nel campo di sotto

strcpy:
	addi sp, sp, -16
	sw ra, 0(sp)
	sw a0, 4(sp) #source
	sw a1, 8(sp) #destination
	
	call strlen
	
	mv t0, a0 #len di src
	sw t0, 12(sp)
	
	lw a0, 8(sp)
	call strlen
	
	lw t0, 12(sp)
	mv t1, a0 #len di dst
	
	li t2, 0#i
	lw a0, 4(sp)
	lw a1, 8(sp)
	for:
		bge t2, t0, endloop
		add t3, a1, t2 #indirizzo dst[i]
		add t5, a0, t2 #indirizzo src[i]
		lbu t5, 0(t5)
		sb t5, 0(t3) #dst[i] = src[i]
		addi t2, t2, 1
		j for
	endloop:
		
	for2:
		bge t2, t1, endloop2
		sb zero, 0(t3)
		addi t2, t2, 1
		j for2
	endloop2:
		lw ra, 0(sp)
		addi sp, sp, 16
		ret
	
	


strlen:
   	mv t0, a0
	li a0, 0 #i
for3:
	lbu t1, 0(t0)
	beqz t1, endfor
	addi a0, a0, 1
	addi t0, t0, 1
	j for3
endfor:
	ret