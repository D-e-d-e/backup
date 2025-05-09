#include <stdio.h>
#include <string.h>
#define NMAX 50

/*Estendi l'esercizio precedente per memorizzare i dati di 5 persone in un array di struct.
 Chiedi all'utente di inserire i dati per ciascuna persona e poi stampali tutti.*/

typedef struct {
    char nome[NMAX];    
    int età;
    float altezza;
}persona;
int main(){
    persona persone [5];
    
    for(int i = 0; i < 5; i++){//inserimento dati delle persone nell' array
        printf("Inserire i dati della persona: \n");
        printf("Nome: \n");
        scanf("%s", persone[i].nome);
        printf("Eta': \n");
        scanf("%d",&persone[i].età);
        printf("Altezza: \n");
        scanf("%f", &persone[i].altezza);
    }

    for(int i = 0; i < 5; i++){//stampa dati delle persone
        printf("Persona %d: \n", i+1);
        printf("Nome: %s\n", persone[i].nome);
        printf("Eta': %d\n", persone[i].età);
        printf("Altezza: %.2f\n", persone[i].altezza);
    }
}

    
