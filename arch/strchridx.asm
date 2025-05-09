.globl _start
.data
    str:  .string "my long string"
    c:    .byte 'g'
.text
_start:
    # call strchridx
    la   a0, str
    la   a1, c
    lbu  a1, 0(a1)
    jal  ra, strchridx

    #exit
    li   a7, 10
    ecall

#****************************************************
# completare la funzione strchr nel campo di sotto
strchridx:
	li t0, 0 #i
	lbu t2, 0(a1)
for:
	lbu t1, 0(a0)
	beq t1, t2, eq
	addi a0, a0, 1
	addi t0, t0, 1
eq:
	mv a0, t0
endfor:
	beqz t1, np
	j end
np: 
	li a0, -1
end:	
	ret