#include "contact.h"
#include <string.h>
#include <ctype.h>

void convertToLower(char *str){
    int i = 0;
    while (str[i] != '\0'){
        str[i] = tolower(str[i]);
        i++;
    }
}
int max(int a, int b){
    if(a>=b){
        return a;
    }else{
        return b;
    }
}

_Bool contactEq(Contact c1, Contact c2){
    
    convertToLower(c1.name);
    convertToLower(c2.name);
    convertToLower(c1.surname);
    convertToLower(c2.surname);
    if (strcmp(c1.name, c2.name) == 0 && strcmp(c1.surname, c2.surname) == 0){
        return 1;
    }else{
        return 0;
    }
}

_Bool contactEqEff(const Contact const *pc1, const Contact const *pc2){
    char name1[50], name2[50], surname1[50], surname2[50];
    strcpy(name1, pc1->name);
    strcpy(name2, pc2->name);
    strcpy(surname1, pc1->surname);
    strcpy(surname2, pc2->surname);

    convertToLower(name1);
    convertToLower(name2);
    convertToLower(surname1);
    convertToLower(surname2);

    if(strcmp(name1, name2) == 0 && strcmp(surname1, surname2) == 0){
        return 1;
    }else{
        return 0;
    }
}

int contactCmp(Contact c1, Contact c2){
    char name1[50], name2[50], surname1[50], surname2[50];

    convertToLower (c1.name);
    convertToLower (c2.name);
    convertToLower (c1.surname);
    convertToLower (c2.surname);

    strcpy(name1, c1.name);
    strcpy(name2, c2.name);
    strcpy(surname1, c1.surname);
    strcpy(surname2, c2.surname);

    
    if(strcmp(surname1, surname2) == 0){
        return strcmp(name1,name2);
    }else{
        return strcmp(surname1,surname2);
    }
    
    
}

int contactCmpEff(const Contact const *pc1, const Contact const *pc2){
    char name1[50], name2[50], surname1[50], surname2[50];

    convertToLower (pc1->name);
    convertToLower (pc2->name);
    convertToLower (pc1->surname);
    convertToLower (pc2->surname);

    strcpy(name1, pc1->name);
    strcpy(name2, pc2->name);
    strcpy(surname1, pc1->surname);
    strcpy(surname2, pc2->surname);

    if(strcmp(surname1, surname2) == 0){
        return strcmp(name1,name2);
    }else{
        return strcmp(surname1,surname2);
    }
}
