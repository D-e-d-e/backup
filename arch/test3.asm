.globl _start
.data
    
.text
_start:

	addi t4, zero, 32
	loop:
		ble t4, zero, end
		
		li t1, 1#maschera
		and t3, t0, t1
		
		add t2, t2, t3
		
		srli t0, t0, 1
		
		beq t0, zero end
		
		addi t4, t4, -1
		
		j loop
	end:
		
	
	
	
	
    # termina il programma
    li a7, 10   # codice di uscita
    ecall