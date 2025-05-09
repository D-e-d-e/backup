.globl _start
.data
    buffer: .string  ""
    low:    .byte  'A'
    high:   .byte  'Z'

.text
_start:
    # call contains
    la   a0, buffer
    la   a1, low
    la   a2, high
    lbu  a1, 0(a1)
    lbu  a2, 0(a2)
    jal  ra, contains

    # exit
    li   a7, 10
    ecall

#******************************************
# completare la funzione nel campo di sotto

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
		
	