.globl _start
  .data
    size:  .word  10
    array: .word  3,1,6,6,23,17,9,25,3,4
  
  .text
  _start:


      # chiama minarray
      la   a0, array
      la   a1, size
      lw   a1, 0(a1)
      jal  ra, minarray
      
      #exit


      li   a7, 10
      ecall   

#****************************************************
# completare la funzione minarray nel campo di sotto

minarray:
	li t0, 0		#min_idx
	lw t1, 0(a0)	#min_val
	li t2, 1		#i
	
while:
	bge t2, a1, endloop
	slli t3, t2, 2 	#i*4
	add t4, a0, t3	#a[i]
	lw t4, 0(t4)
	bge t4, t1, continue
	mv t0, t2
	mv t1, t4
continue:
	addi t2, t2, 1
	j while
endloop:
	mv a0, t0
	ret
	



