#include "charArrayQueue.h"
#include <stdio.h>

int main (){

    CharQueueADT q1 = mkQueue();

    printf("size: %d||expected: 0\n", q1->size);

    _Bool t1 = enqueue(q1, 5);
    printf("size: %d||expected: 1\n", q1->size);
    printf("elemento inserito: %d||expected: 5\n", (q1->a[q1->rear - 1]));

    char res;
    _Bool t2 = dequeue(q1, &res);
    printf("dequeue: %d||expected:1\nres: %d||expected: 5\n", t2, res);

    _Bool t3 = isEmpty(q1);
    printf("isEmpty: %d||expected: 1\n", t3);

    char res2;
    enqueue(q1, 3);
    enqueue(q1, 4);
    peek(q1, 1, &res2);
    printf("peek: %d||expected: 4\n", res2);
    enqueue(q1,130);
    enqueue(q1,14);
    enqueue(q1,12);
    enqueue(q1,11);
    enqueue(q1,2);
    enqueue(q1,0);
    enqueue(q1,3);

    printf("capacity: %d||expected: 16\n", q1->capacity);
    dequeue(q1, &res);
    dequeue(q1, &res);
    dequeue(q1, &res);
    dequeue(q1, &res);
    dequeue(q1, &res);
    dequeue(q1, &res);
    printf("capacity after dequeue: %d||expected: 8\n", q1->capacity);


    return 0;
}