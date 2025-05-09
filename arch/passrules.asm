.globl _start
.data
      buffer: .string  "BADPass4"
.text
_start:
    # call passrules
    la   a0, buffer
    jal  ra, passrules

    #exit
    li   a7, 10
    ecall

#****************************************************
# completare la funzione passrules nel campo di sotto

passrules:
	addi sp, sp, -12
	
	li a1, 65
	li a2, 90
	 
	sw ra, 0(sp)
	sw a0, 4(sp)
	
	call contains
	mv t0, a0
	
	lw a0, 4(sp)
	li a1, 48
	li a2, 57
	sw t0, 8(sp)
	call contains
	lw t0, 8(sp)
	
	and a0, a0, t0
	
	lw ra, 0(sp)
	
	addi sp, sp, 12
	
	ret


contains:
	li t1, 0
	while:
		lbu t0, 0(a0)
		beqz t0, endloop
		blt t0, a1, end 
		bgt t0, a2, end
		li t1, 1
		j endloop

	end: 
		addi a0, a0, 1 #guardo el. successivo
		j while
	endloop:
		mv a0, t1
		ret