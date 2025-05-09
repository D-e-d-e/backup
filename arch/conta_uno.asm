.globl _start

.text

_start:

    #<assembler code here>
    li t0, 37 #N
    #37 = 0000 0000 0000 0000 0000 0000 0010 0101
    li t1, 0x00000001#maschera per verificare se il bit meno significativo è a 1
    li t2, 0#registro che conterrà il risultato
    li t3, 32 #i da decrementare (corrisponde al numero di bit)
    LOOP:
    	ble t3, zero, ENDLOOP
    	and t4, t0, t1#confronto il bit meno significativo
    	add t2, t2, t4#aggiungo il risultato del confronto
    	srli t0, t0, 1#sposto a destra di 1 bit per prepararmi al prossimo bit da confrontare
    	addi  t3, t3, -1#decremento i
    	j LOOP
    ENDLOOP:
	
exit:
    addi x17, x0, 10  # call number 10 = exit
    ecall
