#include <stdio.h>

int main(){
    char op;
    double n1, n2, res;
    printf("Insert operation(+,-,*,/): ");
    scanf("%c\n",&op);
    printf("insert 2 numbers: ");
    scanf("%lf %lf",&n1, &n2);
    switch(op){
        case '+':
            res = n1 + n2;
            printf("%lf",res);
            break;
        case '-':
            res = n1 - n2;
            printf("lf", res);
            break;
        case '*':
            res = n1 * n2;
            printf("%lf",res);
            break; 
        case '/':
            res = n1 / n2;
            printf("%lf",res);
            break;
        default:
            printf("non-valid operation!\n");
            break;
    }
}