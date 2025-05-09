.globl _start
.data
	numbers: .word 12, 16, 20, 24 # Four sample integers
	result: .word 0 # Space for result
.text
_start:
	la t0, numbers # Load address of first number
	# complete the code
	
	#carico i numeri in 4 registri dalla memoria
	lw t1,0(t0)
	lw t2,4(t0)
	lw t3,8(t0)
	lw t4,12(t0)
	
	#eseguo la media(faccio la somma e divido per 4 facendo shift aritmetico di 2)
	add t5,t1,t2
	add t5,t5,t3
	add t5,t5,t4
	srai t5,t5,2
	
	sw t5, 16(t0)
	  
	
# Exit program
exit:
	li a7, 10 # System call for exit
	ecall