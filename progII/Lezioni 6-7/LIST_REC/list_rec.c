#include "list_rec.h"


// Ritorna una lista contenente tutti i numeri interi compresi tra @m ed @n, estremi inclusi. 
ListNodePtr fromTo_rec(int m, int n){
    if(m > n) return NULL;
    
    ListNodePtr newNode = malloc(sizeof(newNode));
    newNode->data = m;
    newNode->next = fromTo_rec(m + 1, n);
    return newNode;
}

// Ritorna true se tutti gli elementi nella lista @ls1 compaiono nello stesso ordine anche nella lista @ls2.
_Bool included_rec(ListNodePtr ls1, ListNodePtr ls2){
    if(ls1 == NULL) return 1;
    if(ls2 == NULL) return 0;

    if(ls1->data == ls2->data){
        return included_rec(ls1->next, ls2->next);
    }else{
        return included_rec(ls1, ls2->next);
    }
    
}

// Ritorna una nuova lista con gli elementi di @ls in ordine inverso (non modifica la lista @ls).
ListNodePtr reverse_rec(ListNodePtr ls){
    /*
    [1] [2] [3] [4]

    [4] [3] [2] [1]*/

    ListNodePtr prev = NULL;
    if()
}

// Ritorna la lista i cui elementi sono le somme a coppie degli elementi corrispondenti di due liste @ls1 e @ls2 di uguale lunghezza (non modifica la liste @ls1 e @ls2).
ListNodePtr zipSum_rec(ListNodePtr ls1, ListNodePtr ls2){
    if(ls1 == NULL) return NULL;

    ListNodePtr newNode = malloc(sizeof(ListNode));
    newNode->data = (ls1->data) + (ls2->data);
    newNode->next = zipSum_rec(ls1->next, ls2->next);
    return newNode;
}

// Conta il numero di occorrenze di @x nella lista @ls.
int occurrences_rec(ListNodePtr ls, int x){
    if(ls == NULL) return NULL;

    if(ls->data == x){
        return 1 + occurrences_rec(ls->next, x);
    }else{
        return occurrences_rec(ls->next, x);
    }
}

// Toglie tutte le occorrenze di @x dalla lista *@p_ls (modifica *@p_ls).
void remove_all_rec(ListNodePtr *p_ls, int x){
    if((*p_ls) == NULL) return;

    ListNodePtr current = (*p_ls);
    ListNodePtr prev = current;
    if((*p_ls)->data == x){
        current = current->next;
        prev->next = current;
        return remove_all_rec(())
    }
}

// Duplica tutti i nodi della lista @ls che contengono un numero pari (modifica @ls).
void duplicate_even_rec(ListNodePtr ls);
