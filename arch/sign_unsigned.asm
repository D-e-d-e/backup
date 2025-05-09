..globl _start
.data
	array: .byte 130, 150, 200 # Array with 3 bytes
	result1: .word 0 # result signed
	result2: .word 0 # result unsigned
.text
_start:
	la t0, array
	lb t1, 0(t0)#load primo byte signed
	lb t2, 1(t0)
	lb t3, 2(t0)#load ultimo byte signed
	lbu t6, 0(t0)#load primo byte unsigned
	lbu s0, 1(t0)
	lbu s1, 2(t0)#load ultimo byte unsigned
	
	add t4,t1,t2
	add t4,t4,t3#somma dei valori signed
	
	add t6,t6,s1
	add t6,t6,s0#omma dei valori unsigned

	la t0, result1#carico in t0 l'indirizzo dell'etichetta result1
	sw t4, 0(t0)#carico il risultato signed nell'indirizzo in t0
	sw t6, 4(t0)#carico nell'indirizzo di t0 con offset 4(ovvero l'indirizzo di result2) il risultato unsigned
	
	
# Exit program
	li a7, 10 # System call for exit
	ecall