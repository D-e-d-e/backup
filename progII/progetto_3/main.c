#include "contactOpq.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    char nome1[50] = "Marco";
    char cognome1[50] = "Rossi";
    char url1[50] = "https//moodle.com";
    char num1[20] = "3274477910";

    ContactPtr c1 = mkContact(nome1, cognome1, num1, url1);

    printContact(c1);

    char name2[50];
    strcpy(name2, getName(c1));

    printf("%s", name2);

    char num2[20] = "11111111";

    printf("Before:\n");
    printContact(c1);
    updateMobile(c1, num2);
    printf("After:\n");
    printContact(c1);
    


    return 0;
}