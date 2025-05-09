/*Scrivi un programma che dichiari una struct per rappresentare una persona con i seguenti campi:

Nome (stringa)
Età (intero)
Altezza in cm (float)
Chiedi all'utente di inserire i dati di una persona, salva questi dati in una variabile di tipo struct 
e stampali.

*/


#include <stdio.h>
#include <string.h>
#define MAXN 50

int main(){
    struct persona{
        char nome[MAXN];
        int età;
        float altezza;
    };
    struct persona test;
    char n[MAXN];
    int e;
    float h;
    printf("Inserire i dati della persona: \n");
    printf("Nome: \n");
    scanf("%49s", n);
    printf("Eta': \n");
    scanf("%d", &e);
    printf("Altezza: \n");
    scanf("%f", &h);
    strcpy(test.nome, n);
    test.altezza = h;
    test.età = e;
    printf("Nome: %s\n", test.nome);
    printf("Eta': %d\n", test.età);
    printf("Altezza: %.2f", test.altezza);
}