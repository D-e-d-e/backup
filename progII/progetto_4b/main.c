#include "charQueueADT.h"
#include "linkedListQueue.h"
#include <stdio.h>

void printList(CharQueueADT q){
    ListNodePtr q1 = q->front;
    printf("size: %d\n", q->size);
    for(int i = 0; i < q->size; i++){
        printf("elemento %d: %c\n",i, q1->data);
        q1 = q1->next;
    }
}

int main(){
    CharQueueADT q1 = mkQueue();

    enqueue(q1, 'a');
    enqueue(q1, '1');

    printList(q1);



    return 0;
}