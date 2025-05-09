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
    (*ssptr)->size = 0;
    *ssptr = NULL;
    return 1;
}

_Bool sset_add(IntSortedSetADT ss, const int elem) {
    if(ss == NULL) return 0;   

    ListNodePtr current = ss->first;
    ListNodePtr prev = NULL;

    while(current && current->elem < elem) {
        prev = current;
        current = current->next;
    }

    if(current && current->elem == elem) return 0;

    ListNodePtr new = malloc(sizeof(ListNode));
    new->elem = elem;
    new->next = current;

    if(!prev) ss->first = new;              //se prev è null ho lista vuota
    if(new->next == NULL) ss->last = new;   //aggiorno se è ultimo elem

    if(prev) prev->next = new;
    
    ss->size++;

    return 1;
}

_Bool sset_remove(const IntSortedSetADT ss, const int elem) {
    if (ss == NULL || ss->size == 0) return 0;

    ListNodePtr current = ss->first;
    ListNo
dePtr prev = NULL;

    while(current && current->elem<elem){
        prev = current;
        current = current->next;
    }
    if(!current || current->elem > elem) return 0;

    if(prev) prev->next = current->next;
    else ss->first = current->next;
    if(!current->next) ss->last = prev;

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
    if (!s1 || !s2 || s1->size != s2->size) return false;
    
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
    if(s1 == NULL || s2 == NULL) return NULL;

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
    if (s1 == NULL || s2 == NULL) return NULL;
    if (s2->size > s1->size) return NULL;

    ListNodePtr a = s1->first;
    ListNodePtr b = s2->first;    

    IntSortedSetADT ret = mkSSet();
    if(!ret) return NULL;

    while(a && b){
        if(a->elem < b->elem) sset_add(ret, a->elem);
        else b = b->next;

        a = a->next;
    }

    while(a){
        sset_add(ret, a->elem);
        a = a->next;
    }

    return ret;
}


_Bool sset_min(const IntSortedSetADT ss, int *ptr) {
    if(ss == NULL || ss->size == 0) return 0;

    if(ptr) *ptr = ss->first->elem;
    else return 0;
    return 1;
}


_Bool sset_max(const IntSortedSetADT ss, int *ptr) {
    if(ss == NULL || ss->size == 0 || ptr == NULL) return 0;

    *ptr = ss->last->elem;
    return 1;
}

_Bool sset_extractMin(IntSortedSetADT ss, int *ptr) {
    if(ss == NULL || ss->size == 0 || ptr == NULL) return 0;

    *ptr = ss->first->elem;
    return (sset_remove(ss, *ptr));
}

_Bool sset_extractMax(IntSortedSetADT ss, int *ptr) {
    if(ss == NULL || ss->size == 0 || ptr == NULL) return 0;

    *ptr = ss->last->elem;
    return (sset_remove(ss, *ptr));
}
