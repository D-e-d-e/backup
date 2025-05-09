.globl _start
.data
    str: .string "Hello World!"

.text
_start:
    # call hash
    la  a0, str
    jal ra, hash

    #exit
    li   a7, 10
    ecall

#******************************************
# completare la funzione nel campo di sotto
hash:
	li t0, 0 #i
	li t1, 5381 #hash
while:
	lbu t2, 0(a0)
	beqz t2, endloop
	slli t3, t1, 5 #hash<<5
	add t1, t1, t3 #hash = (hash<<5)+hash
	add t1, t1, t2
	addi t0, t0, 1
	addi a0, a0, 1
	j while
endloop:
	mv a0, t1
	ret
