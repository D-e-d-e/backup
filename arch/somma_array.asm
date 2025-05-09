.globl _start

.data
	len:5
	array: .word 2, 3, 5, 7, 10
	result: .word
	
.text

_start:

    #<assembler code here>
    la t0, len
    lw t0, 0(t0) #lunghezza array
    la t1, array 
    
    li t2, 0 #somma
    li t3, 0 #indice
    
    loop:
    	bge t3, t0, end #loop per controllare tutto l'array
    	lw t4, 0(t1) #carico dalla memoria il valore dell'array
    	addi t1, t1, 4 #aggiorno l'indirizzo dell'elemento successivo(4 perchè ho un array di word)
    	add t2, t2, t4 #somma
    	addi t3, t3, 1 #aggiorno indice
    	j loop #salto sopra
    end:
    	la, t0, result #carico indirizzo del risultato
    	sw t2, 0(t0) #salvo il risultato in memoria
exit:
    addi x17, x0, 10  # call number 10 = exit
    ecall
