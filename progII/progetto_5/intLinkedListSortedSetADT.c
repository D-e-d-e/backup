#include <stdlib.h>
#include <stdbool.h>

#include "intSortedSetADT.h"
#include "intLinkedListSortedSetADT.h"

IntSortedSetADT mkSSet() {
    IntSortedSetADT newset = malloc(sizeof(struct intSortedSet));
    newset->first = NULL;
    newset->last = NULL;
    newset->size = 0;
    return newset;
}

_Bool dsSSet(IntSortedSetADT *ssptr) {
    if(ssptr==NULL || *ssptr == NULL ) return 0;
    ListNodePtr node = (*ssptr)->first; 
    while(node!=NULL){
        ListNodePtr temp = node;
        node = node->next;
        free(temp);
    }
    (*ssptr)->size == 0;
    *ssptr = NULL;
    return 1;
}

_Bool sset_add(IntSortedSetADT ss, const int elem) {
    if(ss == NULL) return 0;
    ListNodePtr node = ss->first;
    ListNodePtr newNode = malloc(sizeof(ListNode));
    if(newNode == NULL) return 0; //malloc fallita
    newNode->elem = elem;

    if(node == NULL){ //ho 0 elementi
        newNode->next = NULL;
        node = newNode;
        ss->first = newNode;
        ss->last = newNode;
        ss->size++;
        return 1;
    }

    if(node == ss->last){ //ho 1 elemento
        if(elem > node->elem){ //devo aggiungerlo come ultimo
            newNode->next = NULL;
            node->next = newNode;
            ss->last = newNode;
        }else if(elem < node->elem){ //devo aggiungerlo come primo
            node->next = NULL;
            newNode->next = node;
            ss->first = newNode;
            node->next = NULL;
            ss->last = node;
        }else{ //vuol dire che l'elemento è già presente
            return 0;
        }
        ss->size++;
        return 1;
    }

    ListNodePtr prev = NULL;

    while(node != NULL && node->elem <= elem){ //ho più di un elemento nel set
        if(node->elem == elem) return 0; //elemento già presente
        prev = node; //tengo un puntatore al nodo precedente, servirà dopo per aggiornare i ->next
        node = node->next;
    }
    /*esco dal ciclo quando node->elem diventa maggiore --> node punterà al nodo con l'elemento maggiore
    mentre prev punterà all'elemento con il nodo ancora minore, devo aggiungere il nuovo nodo tra
    questi due*/
    prev->next = newNode; //inserisco il nodo dopo prev
    newNode->next = node; //inserisco il nodo tra prev e node

    if(node == NULL) ss->last = newNode;
    if(prev == NULL) ss->first = newNode;
    
    (ss->size)++; //aggiorno size

    return 1;
}

_Bool sset_remove(const IntSortedSetADT ss, const int elem) {
    if(ss == NULL || ss->size == 0) return 0;
    ListNodePtr current = ss->first;
    ListNodePtr prev = NULL;

    if(current->elem == elem){ //devo rimuovere il primo elemento
        ss->first = current->next; //nuova testa
        if(ss->first == NULL){ //avevo 1 solo elemento nella lista
            ss->last = NULL;
        }
        free(current);
        ss->size--;
        return 1;
    }

    while(current->elem < elem && current != NULL){ //scorro la lista finchè trovo elem o finisco
        prev = current;
        current = current->next;
    }

    if(current == NULL || current->elem > elem) return 0; // ho scorso tutta la lista: elemento non presente

    prev->next = current->next; // rimuovo l'elemento
    if(current->next == NULL){//ultimo elemento
        ss->last = prev;
    }
    free(current);
    ss->size--;
    return 1;
}

_Bool sset_member(const IntSortedSetADT ss, const int elem) {
    if (ss == NULL) return 0; 

    ListNodePtr current = ss->first;

    while (current != NULL){
        if(current->elem == elem) return 1; //elemento presente

        current = current->next;
    }
    return 0;
}

_Bool isEmptySSet(const IntSortedSetADT ss) {
    if(ss == NULL) return 0; //puntatore non valido

    if(ss->size == 0) return 1;

    return 0;
}

int sset_size(const IntSortedSetADT ss) {
    if(ss == NULL) return -1;

    return (ss->size);
}

_Bool sset_extract(IntSortedSetADT ss, int *ptr) {
    if (ss == NULL || ss->size == 0) return 0;
    
    int randomIndex = rand() % (ss->size);
    int i = 0;
    ListNodePtr current = ss->first;
    ListNodePtr prev = NULL;

    while(i < randomIndex){
        prev = current;
        current = current->next;
        i++;
    }

    if(ptr != NULL) *ptr = current->elem;

    if(prev == NULL){
        ss->first = current->next;
    }else{
        prev->next = current->next;
    }
    free(current);
    ss->size--;
    return 1;
}

_Bool sset_equals(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if((s1 == NULL || s1->first))
    
        

    ListNodePtr list1 = s1->first;
    ListNodePtr list2 = s2->first;

    while(list1 != NULL && list2 != NULL){
        if(list1->elem != list2->elem) return 0;

        list1 = list1->next;
        list2 = list2->next;
    }

    return (list1 == NULL && list2 == NULL);



}

_Bool sset_subseteq(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if(s1 == NULL || s2 == NULL) return 0;

    if(s1->size > s2->size) return 0; //il primo insieme deve essere incluso nel secondo

    ListNodePtr s1current = s1->first;
    ListNodePtr s2current = s2->first;

    while(s1current != NULL){
        while(s2current != NULL && s2current->elem < s1current->elem){
            s2current = s2current->next;
        }
        if(s2current == NULL || s2current->elem != s1current->elem) return 0;

        s1current = s1current->next;
        s2current = s2current->next;
    }
    return 1;
    
}

_Bool sset_subset(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if(s1 == NULL || s2 == NULL) return 0;

    if(s1->size >= s2->size) return 0; //il primo insieme deve essere inculo nel secondo

    ListNodePtr s1current = s1->first;
    ListNodePtr s2current = s2->first;

    while(s1current != NULL){
        while(s2current != NULL && s2current->elem < s1current->elem){
            s2current = s2current->next;
        }
        if(s2current == NULL || s2current->elem != s1current->elem) return 0;

        s1current = s1current->next;
        s2current = s2current->next;
    }
    return 1;
}

IntSortedSetADT sset_union(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if(s1 == NULL || s2 == NULL || s1->size == 0 && s2->size == 0) return NULL;

    IntSortedSetADT newset = mkSSet();
    ListNodePtr newtail = NULL;
    ListNodePtr s1current = s1->first;
    ListNodePtr s2current = s2->first;
    
    while(s1current != NULL || s2current != NULL){
        ListNodePtr newnode = malloc(sizeof(ListNode));
        if(s1current != NULL && (s2current == NULL || s1current->elem < s2current->elem)){
            newnode->elem = s1current->elem;
            s1current = s1current->next;
        }else if(s2current != NULL &&(s1current == NULL || s1current->elem > s2current->elem)){
            newnode->elem = s2current->elem;
            s2current = s2current->next;
        }else{ //elemento uguale lo aggiungo solo una volta e incremento entrambi
            newnode->elem = s1current->elem;
            s1current = s1current->next;
            s2current = s2current->next;
        }

        newnode->next = NULL;

        if(newset->first == NULL){ //sto aggiungendo il primo elemento
            newset->first = newnode;
        }else{
            newtail->next = newnode;
        }
        newtail = newnode;

        newset->size++;
    }    
    newset->last = newtail;
    return newset;
}

IntSortedSetADT sset_intersection(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if(s1 == NULL || s2 == NULL) return 0;

    IntSortedSetADT newset = mkSSet();
    ListNodePtr s1current = s1->first;
    ListNodePtr s2current = s2->first;
    ListNodePtr newtail = NULL;

    while(s1current != NULL && s2current != NULL){
        if(s1current->elem < s2current->elem){
            s1current = s1current->next;
        }else if(s2current->elem < s1current->elem){
            s2current = s2current->next;
        }else{
        ListNodePtr newnode = malloc(sizeof(ListNode));
        if(newnode == NULL) return NULL;
        
        newnode->elem = s1current->elem;
        newnode->next = NULL;
        if(newset->first == NULL){
            newset->first = newnode;
        }else{
            newtail->next = newnode;
        }
        newtail = newnode;
        newset->size++;

        s1current = s1current->next;
        s2current = s2current->next;
        }
    }
    newset->last = newtail;

    return newset;
}

IntSortedSetADT sset_subtraction(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if (s1 == NULL && s2 == NULL) return NULL;

    ListNodePtr s1current = s1->first;
    ListNodePtr s2current = s2->first;
    IntSortedSetADT newset = mkSSet();
    ListNodePtr newtail = NULL;

    while(s1current != NULL || s2current != NULL){
        if(s1current->elem != s2current->elem){
            ListNodePtr newnode = malloc(sizeof(ListNode));
            
            if(s1current != NULL && (s2current == NULL || s1current->elem < s2current->elem)){
                newnode->elem = s1current->elem;
                s1current = s1current->next;
            }else{
                newnode->elem = s2current->elem;
                s2current = s2current->next;
            }
            if(newset->first == NULL){
                newset->first = newnode;
            }else{
                newtail->next = newnode;
            }
            newtail = newnode;
            newset->size++;
        }else if(s1current->elem == s2current->elem){
            s1current = s1current->next;
            s2current = s2current->next;
        }        
    }
    newset->last = newtail;

    return newset;
}

_Bool sset_min(const IntSortedSetADT ss, int *ptr) {
    if(ss == NULL) return 0;

    if(ptr != NULL){
        *ptr = ss->first->elem;
        return 1;
    }else {
        return 0;
    }
}

_Bool sset_max(const IntSortedSetADT ss, int *ptr) {
    if(ss == NULL) return 0;

    if(ptr != NULL){
        *ptr = ss->last->elem;
        return 1;
    }else{
        return 0;
    }
}

_Bool sset_extractMin(IntSortedSetADT ss, int *ptr) {
    if(ss == NULL) return 0;

    if(ptr != NULL){
        *ptr = ss->first->elem;
        ss->first = ss->first->next;
        free(ss->first);
        ss->size--;
        return 1;
    }else{
        return 0;
    }
}

_Bool sset_extractMax(IntSortedSetADT ss, int *ptr) {
    if(ss == NULL) return 0;

    ListNodePtr newlast = ss->first;

    for (int i = 0; i < ss->size-1; i++){
        newlast = newlast->next;
    }

    if(ptr != NULL){
        *ptr = ss->last->elem;
        ss->last = newlast;
        free(ss->last);
        ss->size--;
        return 1;
    }else{
        return 0;
    }
}