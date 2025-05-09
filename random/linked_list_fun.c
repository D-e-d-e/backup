#include <stdlib.h>
#include <stdio.h>


typedef struct listNode ListNode, *ListNodePtr;

struct listNode {
    int data;
    ListNodePtr next;
};

ListNodePtr create_list(){
    ListNodePtr newList = malloc(sizeof(ListNode));
    newList->next = NULL;
    return newList;
}

/*Creazione di una lista collegata
Scrivi un programma che consenta di creare una lista collegata aggiungendo nodi in coda.
Ogni nodo deve contenere un numero intero.*/
void add_node(ListNodePtr head, int x){
    if (head == NULL) return;

    ListNodePtr current = head;
    while(head->next != NULL){
        current = current->next;
    }
    ListNodePtr newNode = malloc(sizeof(ListNode));
    newNode->data = x;
    newNode->next = NULL;
    current->next = newNode;
}

/*Stampa di una lista collegata
Implementa una funzione che stampi gli elementi di una lista collegata.*/
void print_list(ListNodePtr ls){
    if(ls==NULL) return;

    while (ls != NULL){
        printf("[%d] ", ls->data);
        ls = ls->next;
    }
    puts("");
}

/*Ricerca in una lista collegata
Scrivi una funzione che prenda come input un numero intero e verifichi
se è presente nella lista collegata.*/
bool is_in(ListNodePtr ls, int x){
    if(ls == NULL) return false;

    while(ls != NULL){
        if(ls->data == x) return true;

        ls = ls->next;
    }
    return false;
}

/*Inserimento di un nodo in testa
Implementa una funzione per inserire un nodo all’inizio della lista collegata.*/
void insert_node(ListNodePtr ls, int x){
    if(ls == NULL) return;

    ListNodePtr newNode = malloc(sizeof(ListNode));

    newNode->data = x;
    newNode->next = ls;
}

/*Inserimento ordinato
Scrivi una funzione per inserire un elemento in una lista collegata mantenendo
l’ordine crescente dei numeri.*/
void insert_ordered(ListNodePtr ls, int x){
    if(ls == NULL) return;

    ListNodePtr current = ls;
    ListNodePtr prev = NULL;
    while(current != NULL){
        if(current->data < x){
            current = current->next;
            prev = current;
        }else{
            return;
        }
    }
}

/*Cancellazione di un nodo
Implementa una funzione per rimuovere un nodo specifico (dato il valore) dalla lista collegata.*/
void del_node(ListNodePtr ls, int x){
    if (ls == NULL) return;

    ListNodePtr current = ls;
    ListNodePtr prev = NULL;

    while(ls != NULL){
        if(ls->data == x){
            if(prev == NULL){
                current->next = NULL;
                free(current);
            }else{
                prev->next = current->next;
                free(current);
            }
        }
        prev = current;
        current = current->next;
    }
}

/*Invertire una lista collegata
Scrivi una funzione per invertire l’ordine dei nodi in una lista collegata.*/
ListNodePtr invert_list(ListNodePtr ls){
    if(ls == NULL) return NULL;

    if(ls->next == NULL) return ls;

    ListNodePtr current = ls;
    ListNodePtr prev = NULL;
    ListNodePtr next;
    
    while(current != NULL){
       next = current->next;
       current->next = prev;
       prev = current;
       current = next;
    }
    return prev;
}




int main(){

    return 0;
}

