#Supponiamo che i registri x5 e x6 contengano i numeri 0x80000000 e 0xD0000000.
#Usare il simulatore RARS per rispondere alle domande.
#Quale sar� il contenuto di x30 dopo l�esecuzione di questa istruzione
#add x30, x5, x6
#Il contenuto di x30 � corretto, o si � verificato un overflow?
#Quale sar� il contenuto di x30 dopo l�esecuzione di questa istruzione:
#sub x30, x5, x6
#Il contenuto di x30 � corretto o si � verificato un overflow?
#Quale sar� il contenuto di x30 dopo l�esecuzione di queste due istruzioni:
#add x30, x5, x6
#add x30, x30, x5
#Il contenuto di x30 � corretto o si � verificato un overflow?

lui x5, 0x80000
lui x6, 0xD0000

#add x30,x5,x6
#il contenuto di x30 � scorretto: si � verificato overflow
#sub x30,x5,x6
#il contenuto � corretto: non si � verificato overflow
#add x30,x5,x6
#add x30,x30,x5
#non � corretto: si � verificato overflow