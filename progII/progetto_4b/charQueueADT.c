#include "charQueueADT.h"
#include "linkedListQueue.h"
#include <stdlib.h>

/* Un tipo di dato astratto per le code di char */
typedef struct charQueue *CharQueueADT;

/* @brief Restituisce una coda vuota, se non trova memoria restituisce NULL */
CharQueueADT mkQueue(){
    CharQueueADT q1 = malloc(sizeof(struct charQueue));

    if(q1 == NULL) return NULL;

    q1->front = NULL;
    q1->rear = NULL;
    q1->size = 0;
    
    return q1;
}

/* @brief Distrugge la coda, recuperando la memoria */
/*void dsQueueRic(CharQueueADT *pq){
    if((*pq) == NULL || (*pq)->front == NULL){
        return;
    }
    ListNodePtr temp = (*pq)->front;
    (*pq)->front = (*pq)->front->next;
    free(temp);
    dsQueueRic(pq);

    if((*pq)->front == NULL){
        (*pq)->rear = NULL;
        (*pq)->size = 0;
        pq = NULL;
    }
}*/

void dsQueue(CharQueueADT *pq){    
    ListNodePtr temp = (*pq)->front;

    while(temp != NULL){
        ListNodePtr next = temp->next;
        free(temp);
        temp = next;
    }

    free(*pq);
    *pq = NULL;
}

/* @brief Aggiunge un elemento in fondo alla coda, restituisce esito 0/1 */
_Bool enqueue(CharQueueADT q, const char e){
    ListNodePtr newq = malloc(sizeof(struct listNode));

    if(newq == NULL) return 0;

    newq->data = e;
    newq->next = NULL;

    if(q->rear == NULL){
        q->front = newq;
        q->rear = newq;
    }else{
        q->rear->next = newq;
        q->rear = newq;
    }
    (q->size)++;

    return 1;

    
}

/* @brief Toglie e restituisce l'elemento in testa alla coda, restituisce esito 0/1 */
_Bool dequeue(CharQueueADT q, char*res){
    if(q == NULL || q->size == 0) return 0;

    ListNodePtr q1 = q->front;
    *res = q1->data;

    if(q->size == 1){
        (q->size)--;
        q->rear = NULL;
        q->front = NULL;
        free(q1);
        return 1;
    }
    q->front = q1->next;
    free(q1);
    (q->size)--;

    return 1;
}

/* @brief Controlla se la coda è vuota */
_Bool isEmpty(CharQueueADT q){
    if(q == NULL || q->size == 0) return 1;
    
    return 0;
}

/* @brief Restituisce il numero degli elementi presenti nella coda */
int size(CharQueueADT q){
    if(q == NULL) return 0;
    return q->size;
}

/* @brief Restituisce l'elemento nella posizione data (a partire dalla testa con indice zero) (senza toglierlo), restituisce esito 0/1 */
_Bool peek(CharQueueADT q, int position, char* res){
    if(position>=q->size || position < 0 || q == NULL) return 0;
    
    ListNodePtr q1 = q->front;
    for (int i = 0; i < position; i++){
        q1 = q1->next;
    }

    if(q1){
        *res = q1->data;
        return 1;
    }
    
    return 0;
}