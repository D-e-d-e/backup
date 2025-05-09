.globl _start

.data
	str: .string "0123"
.text

_start:
	la a0, str #str[0]	
    	
    	mv s1, a0 #mi salvo in un registro il valore di s0 in caso dovessi riutilizzarlo
    	
    	call strlen
    	
     	mv a0, t0
    	
    	li a7, 1 #print len
    	ecall
    	
    	mv a0, s1

exit:
	addi x17, x0, 10  # call number 10 = exit
	ecall

strlen:
   	mv t0, a0
	li a0, 0 #i
for:
	lbu t1, 0(t0)
	beqz t1, endfor
	addi a0, a0, 1
	addi t0, t0, 1
	j for
endfor:
	ret
