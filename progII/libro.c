#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXA 100
#define MAXT 200
#define MAXL 1000000
/*
*codice del 17/03/2025 lezione 06
*/

typedef struct libro {
    char autore[MAXA];
    char titolo[MAXT];
    int pagine;
    double prezzo;
    struct libro* next;

} Libro, *Libroptr;

Libroptr crealibro(char* a, char*t, int p, double pr){
    Libroptr ret = (Libroptr)malloc(sizeof(Libro));
    if(ret != NULL){
        if(a) strcpy(ret->autore, a);
        if(t) strcpy(ret->titolo, t);
        ret->pagine = p;
        ret->prezzo = pr;
        ret->next = NULL;
    }
    return ret;
}


void stampalibro(Libroptr l){
    if(l->autore) printf("Autore: %s\n",l->autore);
    if(l->titolo) printf("Titolo: %s\n", l->titolo);
    printf("Pagine: %d\n",l->pagine);
    printf("Prezzo: %.2f\n", l->prezzo);
}

void stampabiblioteca(Libroptr bib){
    printf("Biblioteca: \n\n");
    while(bib->next != NULL){
        stampalibro(bib);
        printf("\n");
        bib = bib->next;
    }
}

void addtesta(Libroptr l, Libroptr* bibp){
    l->next = *bibp;
    *bibp = l;
}

void rimuovicoda(Libroptr* bibp){
    Libroptr cur = *bibp;
    Libroptr prev = NULL;

    if(cur == NULL) return;//caso di biblioteca vuota

    while(cur->next != NULL){
        prev = cur;
        cur = cur->next;
    }

    free(cur);
    if(prev){
        prev->next = NULL;
    }else{
        *bibp = NULL;
    }
}

void insord(Libroptr* bibp, Libroptr l){

    //if(cur == NULL) //lista vuota

    while(cur && cur->prezzo <= l->prezzo){
        prev = cur;
        cur = cur->next;
    }

    if(prev==NULL){//inserimento in testa
        (*bibp) = l;
    }else{//altrimenti
        prev->next = l;
        cur= cur->next;
    }
    
}

Libro Biblioteca[MAXL];
Libroptr bib, l;

int main() {
    bib = NULL;
    l = crealibro("Dennis","Daje",124,16.5);
    addtesta(l, &bib);

    l = crealibro("Marian","Titolo",88,6.8);
    addtesta(l, &bib);

    stampabiblioteca(bib);

    rimuovicoda(&bib);//trovare l'ultimo elemento e distruggerlo liberando la memoria
    rimuovicoda(&bib);
    stampabiblioteca(bib);

    return 0;
}