.globl_start

.text
#Si supponga che i registri seguenti contengano i valori:
#x5 = 0xAAAAAAAA, x6 = 0x12345678
#Determinare il contenuto di x7 dopo l’esecuzione delle seguenti istruzioni:
#slli x7, x5, 4
#or x7, x7, x6
#Supponendo che i registri x5 e x6 contengano i valori riportati sopra, determinare
#il contenuto di x28 dopo l’esecuzione di:
#slli x28, x6, 4
#Supponendo che i registri x5 e x6 contengano i valori riportati sopra, determinare
#il contenuto di x29 dopo l’esecuzione di:
#srli x29, x5, 3
#andi x29, x29, 0xFF

.start:
	li x5, 0xAAAAAAAA#carico i valori nei registri
	li x6, 0x12345678
	
	slli x7,x5,4#si sposta verso sinistra e i 4 bit meno significativi saranno 4 zero e sto moltiplicando per 2^4
	or x7,x7,x6#fare l'or bit a bit tr x7 e la maschera x6, significa porre a 1 i bit che sono a 1 nella maschera, gli altri resteranno 0
	#il valore contenuto da x7 è: 0xbabefef8 (3133079288)
	
	slli x28,x6,4
	
	srli x29,x5,3#shift logico, quindi vengono aggiunti 0 nei bit piu significativi
	andi x29,x29,0xFF

exit:
	addi x17,x0,10 #call number 10 = exit
	ecall