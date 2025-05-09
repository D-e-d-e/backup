.globl _start
.data
    d: .byte '1'
.text
_start:
    # call digit
    la   a0, d
    lbu  a0, 0(a0)
    jal  ra, digit

    #exit
    li   a7, 10
    ecall

#****************************************************
# completare la funzione digit nel campo di sotto
digit:
	li t2, 48 #valore ascii 0
	li t3, 57 #valore ascii 9
if:
	bge a0, t2, if2
	li a0, 0
	j end2
if2:
	ble a0, t3, end1
	li a0, 0
	j end2
end1:
	li a0, 1
end2:
	ret
	