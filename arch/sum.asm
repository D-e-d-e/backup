#Scrivere un programma per caricare le costanti 41, 43, 47 nei registri t1, t2 e t3 e calcolare la loro
#somma. Il risultato va scritto nel registro t4.
#Eseguire il programma nel simulatore RARS. Eseguire un'istruzione alla volta e verificare i valori
#dei registri.

addi t1, zero, 41
addi t2, zero, 43
addi t3, zero, 47

add t4, t1, t2
add t4, t4, t3
