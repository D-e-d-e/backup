/*1. Definisci una struct studente con i seguenti campi:

- nome (stringa di massimo 30 caratteri)
- cognome (stringa di massimo 30 caratteri)
- matricola (intero)


2. Implementa le seguenti funzioni:

- studente* crea_studente(char* nome, char* cognome, int matricola): Alloca dinamicamente e inizializza un nuovo studente
- void stampa_studente(studente* s): Stampa le informazioni di uno studente
- void libera_studente(studente* s): Libera la memoria allocata per uno studente


3. Nel main:

- Chiedi all'utente quanti studenti vuole inserire
- Alloca dinamicamente un array di puntatori a studente di dimensione appropriata
- Per ogni posizione dell'array, chiedi all'utente i dati dello studente e crea un nuovo studente
- Stampa l'elenco completo degli studenti
- Libera correttamente tutta la memoria allocata*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXL 30

typedef struct {
    char nome[MAXL];
    char cognome[MAXL];
    int matricola;
}studente;

/*- studente* crea_studente(char* nome, char* cognome, int matricola): 
Alloca dinamicamente e inizializza un nuovo studente*/
studente* crea_studente(char* nome, char* cognome, int matricola){
    studente* newS = malloc(sizeof(studente));
    strcpy(newS->nome, nome);
    strcpy(newS->cognome, cognome);
    newS->matricola = matricola;

    return newS;
}

/*- void stampa_studente(studente* s): Stampa le informazioni di uno studente*/
void stampa_studente(studente* s){
    if(s == NULL) return;

    printf("Stampa studente...\n");
    printf("Nome: %s\n", s->nome);
    printf("Cognome: %s\n", s->cognome);
    printf("Matricola: %d\n", s->matricola);
    puts("");
}

/*- void libera_studente(studente* s): Libera la memoria allocata per uno studente*/
void libera_studente(studente* s){
    if(s == NULL) return;

    free(s);
    s = NULL;
}

/*3. Nel main:

- Chiedi all'utente quanti studenti vuole inserire
- Alloca dinamicamente un array di puntatori a studente di dimensione appropriata
- Per ogni posizione dell'array, chiedi all'utente i dati dello studente e crea un nuovo studente
- Stampa l'elenco completo degli studenti
- Libera correttamente tutta la memoria allocata*/

int main(void){
    int n_studenti;
    studente** p_studenti;

    printf("Quanti studenti vuoi inserire? \n");
    scanf("%d", &n_studenti);
    getchar();
    if(n_studenti <= 0){
        printf("Il numero di studenti dev'essere positivo!");
        return 1;
    }

    p_studenti = (studente**)malloc(sizeof(studente*) * n_studenti);


    for(int i = 1; i <= n_studenti; i++){
        char nome[20], cognome[20];
        int matricola;
        printf("Inserire dati studente %d\n", i);
        printf("Nome: \n");
        scanf("%s", nome);
        printf("Cognome: \n");
        scanf("%s", cognome);
        printf("Matricola: \n");
        scanf("%d", &matricola);
        puts("");

        studente* new_s = crea_studente(nome, cognome, matricola);

        p_studenti[i] = new_s;
    }

    for(int i = 1; i <= n_studenti; i++){
        printf("Studente %d", i);
        stampa_studente(p_studenti[i]);
    }

    for(int i = 0; i < n_studenti; i++){
        libera_studente(p_studenti[i]);
        p_studenti[i] = NULL;
    }
    free(p_studenti);
}