#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct listNode ListNode, *ListNodePtr;

struct listNode {
   int data;
   ListNodePtr next;
};

// stampa una lista
void printList(ListNodePtr ls1){
    while (ls1 != NULL){
        printf("%d\n", ls1->data);
        ls1=ls1->next;
    }
}

// Ritorna una lista contenente tutti i numeri interi compresi tra @m ed @n, estremi inclusi. 
ListNodePtr fromTo_iter(int m, int n){
    if(m>n) return NULL;

    ListNodePtr head = NULL;
    ListNodePtr tail = NULL;

    for(int i = m; i <= n; i++){
        ListNodePtr newNode = malloc(sizeof(ListNode));
        newNode->data = i;
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        
    }
    return head;
}

// Ritorna true se tutti gli elementi nella lista @ls1 compaiono nello stesso ordine anche nella lista @ls2.
_Bool included_iter(ListNodePtr ls1, ListNodePtr ls2){
    while(ls1 != NULL && ls2 != NULL){
        if(ls1->data != ls2->data){
            return 0;
        }else{
            ls1 = ls1->next;
            ls2 = ls2->next;
        }
    }
    return 1;   
}

// Ritorna una nuova lista con gli elementi di @ls in ordine inverso (non modifica la lista @ls).
ListNodePtr reverse_iter(ListNodePtr ls){
    ListNodePtr current = ls;
    ListNodePtr prev = NULL;
    ListNodePtr nextNode;
    
    while(current!=NULL){ 
        nextNode = current->next; //puntatore al nodo successivo
        current->next = prev; //il next diventa durante la prima iterazione NULL, poi sarà l'elemento precedente
        prev = current; //prev diventa nella prima iterazione ls, poi nextNode
        current = nextNode; //prev diventa NextNode
    }
    return prev;
}

// Ritorna la lista i cui elementi sono le somme a coppie degli elementi corrispondenti di due liste @ls1 e @ls2 di uguale lunghezza (non modifica la liste @ls1 e @ls2).
ListNodePtr zipSum_iter(ListNodePtr ls1, ListNodePtr ls2){
    if(ls1==NULL||ls2==NULL) return NULL;

    ListNodePtr head = NULL;
    ListNodePtr tail = NULL;

    while(ls1 != NULL && ls2!=NULL){
        ListNodePtr newNode =(ListNodePtr)malloc(sizeof(ListNode));

        newNode->data = (ls1->data) + (ls2->data);
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;            
        }
        ls1 = ls1->next;
        ls2 = ls2->next;
    }
    return head;
}

// Conta il numero di occorrenze di @x nella lista @ls.
int occurrences_iter(ListNodePtr ls, int x){
    int count = 0;
    while (ls!=NULL){
        if(ls->data == x) count ++;
        ls = ls->next;
    }
    return count;
}
// Toglie tutte le occorrenze di @x dalla lista *@p_ls  (modifica *@p_ls).
void remove_all_iter(ListNodePtr *p_ls, int x){
    ListNodePtr prev = NULL; //tengo un puntatore al nodo precedente
    ListNodePtr current = *p_ls;

    while(current != NULL){
        if(current->data == x){
            ListNodePtr toFree = current;
            if(prev==NULL){ // caso in cui il primo nodo sia da eliminar
                *p_ls = current.next; 
            }else{ //nodo dopo il primoo
                prev->next = current->next;
            }
            current = current.next;
            free(toFree);
        }else{
            prev = current;
            current = current->next;
        }
    }
}

// Duplica tutti i nodi della lista @ls che contengono un numero pari (modifica @ls).
void duplicate_even_iter(ListNodePtr ls){
    if(ls == NULL) return;

    while(ls != NULL){
        
        if((ls->data % 2) == 0){
            ListNodePtr newNode = malloc(sizeof(ListNode));
            newNode->data = ls->data;
            newNode->next = ls->next;
            ls->next = newNode;
            ls = newNode->next;
        }else{
            ls = ls->next;
        }
    }
}
