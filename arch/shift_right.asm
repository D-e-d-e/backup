.globl _start
.data
	var1: .word 0x12345678 # Word value to process
	byte4: .byte 0 # Most significant byte (will be 0x12)
	byte3: .byte 0 # Third byte (will be 0x34)
	byte2: .byte 0 # Second byte (will be 0x56)
	byte1: .byte 0 # Least significant byte (will be 0x78)
.text
_start:
	la t0, var1
	lw t1, 0(t0)
	
	andi t2,t1,0xFF
	
	srli t1,t1,8
	andi t3,t1,0xFF
	
	srli t1,t1,8
	andi t4,t1,0xFF
	
	srli t1,t1,8
	andi t5,t1,0xFF
	
	la t0, byte1
	sb t2, 0(t0)
	
	la t0, byte2
	sb t3, 0(t0)
	
	la t0, byte3
	sb t4, 0(t0)
	
	la t0, byte4
	sb t5, 0(t0)
	
	
	
	
	  
	
# Exit program
	li a7, 10 # System call for exit
	ecall
