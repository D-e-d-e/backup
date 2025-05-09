.globl _start

.data
	str: .string "forza Roma sempre daje"
	n: .word 4
.text

_start:
	#convenzioni di chiamata: in a0 l'indirizzo della stringa, in a1 l'indice del carattere da stampare
	la a0, str #str[0]
	la a1, n
	lw a1, 0(a1) #n
	
	mv s1, a0 #MI SALVO IL CONTENUTO DI a0 E a1 IN UN REGISTRO DI APPOGGIO
	mv s2, a1
	
	call charAt #chiamo la funzione
	
	mv a0, s1 #RIPRISTINO IL VALORE DEI REGISTRI, IN QUESTO MODO POSSO RIUTILIZZARLI
	mv a1, s2
	#ora posso per esempio richiamare la funzione con un valore n diverso
	
	#a questo punto in a0 mi aspetto di trovare il carattere str[n]
	
print:
	addi a7, a7, 11 #print char
	ecall
exit:
	addi x17, x0, 10  # call number 10 = exit
	ecall

charAt:
	add a0, a0, a1
	lbu a0, 0(a0)
	ret
