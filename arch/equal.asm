.globl _start
.data        
array: .word 1,1,2,2,3,4,4,1
x:     .word 0
y:     .word 1
        
.text
start:
	# chiama equal
	la   a0, array
	la   a1, x
	lw   a1, 0(a1)
	la   a2, y
	lw   a2, 0(a2)
	jal  ra, equal
	
	#exit
	li   a7, 10
	ecall
    
#***************************************************
#completare la funzione equal nel campo di sotto

equal: 
	slli a1, a1, 2 #x*4
	slli a2, a2, 2 #y*4
	
	add t0, a0, a1 #indirizzo array[x]
	add t1, a0, a2 #indirizzp array[y]
	
	lw t0, 0(t0)
	lw t1, 0(t1)
	bne t0, t1, ne
	li a0, 1
	j end
	ne:
	li a0, 0
	end:
	ret