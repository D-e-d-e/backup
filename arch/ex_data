globl _start
.data
	v1: .word 8
	v2: .word 9
	v3: .word 0
.text
_start:
	la t0, v1
	lw t1, 0(t0)
	lw t2, 4(t0)
	add t3, t1, t2
	sw t3, 8(t0)
	
exit:
	add x17,x0,10
	ecall