#include "charArrayQueue.h"
#include "charQueueADT.h"
#include <stdlib.h>

/* @brief Restituisce una coda vuota, se non trova memoria restituisce NULL */
CharQueueADT mkQueue(){
    CharQueueADT q1 = malloc(sizeof(struct charQueue));
    if(q1 == NULL){
        return NULL;
    }
    q1->capacity = INITIAL_CAPACITY;
    q1->size = 0;
    q1->front = 0;
    q1->rear = 0;
    q1->a = malloc(INITIAL_CAPACITY*sizeof(char));
    if(q1->a == NULL){
        free (q1);
        return NULL;
    }
    

    return q1;
}

/* @brief Distrugge la coda, recuperando la memoria */
void dsQueue(CharQueueADT *pq){
    if((*pq) != NULL){
        free((*pq)->a);
        free((*pq));
        *pq=NULL;
    }
}

/* @brief Aggiunge un elemento in fondo alla coda, restituisce esito 0/1 */
_Bool enqueue(CharQueueADT q, const char e){
    if (q == NULL || q->size == q->capacity) {
        return 0; 
    }else{
        q->a[q->rear] = e;
        q->rear = (q->rear + 1) % (q->capacity);
        (q->size) ++;
        if(q->size == (q->capacity)){
            int new_capacity = (q->capacity)*2;
            char* new_array = malloc(sizeof(char) * new_capacity);
            for(int i = 0; i < q->size; i++){
                new_array[i] = q->a[(q->front + i) % q->capacity];
            }
            free(q->a);
            q->a = new_array;
            q->capacity = new_capacity;
            q->front = 0;
            q->rear = q->size;
        }
        return 1;
    }

}

/* @brief Toglie e restituisce l'elemento in testa alla coda, restituisce esito 0/1 */
_Bool dequeue(CharQueueADT q, char*res){
    if (q == NULL || q->size == 0) {
        return 0; 
    }else{
        *res = (q->a[q->front]);
        (q->front) = (q->front + 1) % (q->capacity);
        (q->size)--;
        if(q->size < (q->capacity)/4 && q->capacity>INITIAL_CAPACITY){
            int new_capacity = q->capacity / 2;
            char* new_array = malloc(sizeof(char) * new_capacity);            
            for(int i = 0; i < q->size; i++){
                new_array[i] = q->a[(q->front + i) % q->capacity];
            }
            free(q->a);
            q->a = new_array;
            q->capacity = new_capacity;
            q->front = 0;
            q->rear = q->size;
        }
        return 1;
    }
}

/* @brief Controlla se la coda è vuota */
_Bool isEmpty(CharQueueADT q){
    if(q->size == 0){
        return 1;
    }else{
        return 0;
    }
}

/* @brief Restituisce il numero degli elementi presenti nella coda */
int size(CharQueueADT q){
    if(q!=NULL){
        return (q->size);
    }else{
        return -1;
    }
}

/* @brief Restituisce l'elemento nella posizione data (a partire dalla testa con indice zero) (senza toglierlo), restituisce esito 0/1 */
_Bool peek(CharQueueADT q, int position, char* res){
    if(q==NULL||position<0||position>=q->size){
        return 0;
    }else{
        int i = (q->front + position) % q->capacity;
        *res = (q->a[i]);
        return 1;
    }
}