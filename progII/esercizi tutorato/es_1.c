/*Esercizio: Operazioni su Array di Numeri
Sviluppa un programma C modulare che permetta di eseguire diverse operazioni su array di numeri interi.
Funzionalità richieste:

- Stampa dell'array
- Calcolo della somma degli elementi
- Calcolo della media
- Trovare il valore massimo e minimo*/

#include <stdio.h>
#include <limits.h>

void printArray(int a[],size_t aLen){
    for(int i = 0; i < aLen; i++){
        printf("%d ",a[i]);
    }
    puts("");
}

int sumArray(int a[], size_t aLen){
    int sum = 0;
    for(int i = 0; i < aLen; i++){
        sum += a[i];
    }
    return sum;
}

float averageArray(int a[], size_t aLen){
    int sum = sumArray(a, aLen);
    
    return (float)sum / aLen;
}

int MaxArray(int a[], size_t aLen){
    int max = 0;
    for(int i = 0; i < aLen; i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    return max;
}

int MinArray(int a[], size_t aLen){
    size_t min = INT_MAX;
    for(int i = 0; i < aLen; i++){
        if(a[i] < min){
            min = a[i];
        }
    }
    return min;
}


int main(void){
    int a[5] = {1,2,100,30,44};
    int s = sumArray(a, 5);
    int average = averageArray(a, 5);
    int max = MaxArray(a, 5);
    int min = MinArray(a, 5);

    printArray(a, 5);
    printf("La somma degli elementi e': %d\n", s);
    printf("La media degli elementi e': %.3f\n", average);
    printf("L'elemento minimo e': %d\n", min);
    printf("L'elemento massimo e': %d\n", max);

}