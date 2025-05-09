.globl _start
.data
	num1: .word 5 # First number
	num2: .word 7 # Second number
	result: .word 0 # Location for result
.text
_start:
	la t0, num1 #carico indirizzo di num1 in t0
	lw t1, 0(t0) #carico valore dell'indirizzo in t0 con offset 0 in t1
	lw t2, 4(t0)#carico in t2 il valore all'indirizzo t0 con offset 4
	
	mul t1,t1,t1 #calcolo quadrato del primo numero 
	mul t2,t2,t2 #calcolo quadrato del secondo numero
	add t1,t1,t2 #salvo nel registro t1 la somma dei due quadrati
	sw t1, 8(t0) #salvo in memoria il risultato
	
	
# Exit program
exit:
	li a7, 10 # System call for exit
	ecall
