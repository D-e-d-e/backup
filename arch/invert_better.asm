.globl _start
.data
    size:  .word 8
    array: .word 1,5,3,7,2,6,4,8
.text
_start:
    # chiama invert
    la   a0, array
    la   a1, size
    lw   a1, 0(a1)        
    jal  ra, invert
    
    #exit
    li   a7, 10
    ecall

#***************************************************
# completare la funzione invert nel campo di sotto


swap:
	slli t1, a1, 2
	slli t2, a2, 2
	
	add t3, a0, t1#indirizzo array[x]
	add t4, a0, t2#indirizzo array[y]
	lw a2, 0(t3)
	lw a3, 0(t4)
	sw a2, 0(t4)
	sw a3, 0(t3)
	ret
	
invert:
	addi sp, sp, -16		
	sw ra, 0(sp)
	sw s1,4(sp)
	sw s2, 8(sp)	
	sw s3, 12(sp)	
	mv s3, a0
	li s1, 0 		#i -- USO I REGISTRI S PERCHE' COSì LI SALVO E RIPRISTINO SOLAMENTE 1 VOLTA 
	addi s2, a1, -1		#size-1
	
LOOP_invert:
	blt s2,s1,END_invert
	mv a1,s1	
	mv a2,s2
	mv a0, s3
	jal swap	
	addi  s1,s1,1
	addi s2,s2,-1
	j LOOP_invert	
END_invert:
	lw ra, 0(sp)
	lw s1, 4(sp)
	lw s2, 8(sp)
	lw s3, 12(sp)	
	addi sp, sp, 16		
	ret			