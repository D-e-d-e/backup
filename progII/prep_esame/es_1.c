#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Dato un array di caratteri ac, con n elementi, restituisce un nuovo
array (di lunghezza n) ottenuto da ac eliminando tutte le occorrenze
delle cifre ('0'...'9'), trasformando tutte le occorrenze delle lettere
minuscole 'k' e 'h' nelle corrispondenti lettere maiuscole, e riempiendo
le eventuali posizioni rimaste libere alla fine del nuovo array con delle 
occorrenze del carattere '#'.


'56akhra45' diventa 'aKHra####'

*/

char* change(char* ac, int n){
    char* newac = (char*)malloc((n+1) * sizeof(char));
    size_t j = 0;

    for(size_t i = 0; i < n; i++){
        if(ac[i] <= '0' || ac[i] >= '9'){ //se il carattere non è tra 0 e 9 (valore ASCII) lo salvo nel nuovo array
            if(ac[i] == 'k') newac[j] = 'K';
            else if(ac[i] == 'h') newac[j] = 'H';
            else newac[j] = ac[i];
            j ++;
        }
    }
    
    for(; j < n; j++){
        newac[j] = '#';
    }
    newac [n] = '\0';
    return newac;
}


#define N 12

int main(){

	char ac[N] = {'a','1','b','2','c','3','d','4','k','5','h','\0'};
	
	char* newAc = change(ac, N);

    for(int i = 0; i < N; i++){
        printf("%c ", newAc[i]);
    }
	

}