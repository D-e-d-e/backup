#include "contact.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    Contact c1,c2;
    ContactPtr c3 = malloc(sizeof(Contact));
    ContactPtr c4 = malloc(sizeof(Contact));
    char name1[10] = "Paolo";
    char surname1[10] = "Rossi";
    char name2[10] = "Luca";
    char surname2[10] = "Bianco";
    char name3[10] = "paolo";
    char surname3[10] = "rossi";

    c1.name = name1;
    c2.name = name1;
    c1.surname = surname1;
    c2.surname = surname1;

    int test1 = contactEq(c1, c2);//nome e cognome uguali 
    printf("(ContactEq): Expected 1 | got: %d\n", test1);

    c1.name = name1;
    c2.name = name2;
    c1.surname = surname1;
    c2.surname = surname2;
    int test2 = contactEq(c1,c2);//nome e cognome diversi
    printf("(ContactEq):Expected 0 | got %d\n", test2);

    c1.name = name1;
    c2.name = name3;
    c1.surname = surname1;
    c2.surname = surname3;
    int test3 = contactEq(c1,c2);//nome e cognome uguali ma case sensitive
    printf("(ContactEq):Expected 1 | got %d\n", test3);

    c3->name = name1;
    c4->name = name1;
    c3->surname = surname1;
    c4->surname = surname1;
    int test1Eff = contactEqEff(c3, c4);
    printf("(ContactEqEff):Expected 1 | got %d\n", test1Eff);

    c1.name = name1;
    c2.name = name2;
    c1.surname = surname1;
    c2.surname = surname2;

    int test1Cmp = contactCmp(c1,c2);//secondo minore del primo
    printf("(contactCmp):Expected 1 | got %d\n", test1Cmp);

    c3->name = name1;
    c4->name = name2;
    c3->surname = surname1;
    c4->surname = surname2;
    int test1CmpEff = contactCmpEff(c3,c4);
    printf("(contactCmpEff):Expected 1 | got %d\n", test1CmpEff);



    free(c3);
    free(c4);
    c3 = NULL;c4=NULL;
    return 0;

}