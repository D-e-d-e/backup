.globl _start
.data
    str1: .string  "first."
    str2: .string  "second."
.text
_start:
    # call strcmp
    la   a0, str1
    la   a1, str2
    jal  ra, strcmp

    #exit
    li   a7, 10
    ecall
    
strcmp:	
	li t0, 0
for:
	lbu a2, 0(a0)
	lbu a3, 0(a1)
	bne a2, a3, ne
	beqz a2, endfor
	addi a0, a0, 1
	addi a1, a1, 1
	j for
ne:
	li t0, 1
endfor:
	mv a0, t0
	ret