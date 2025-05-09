#include "list_iter.h"
#include <stdio.h>

int main(){
    ListNodePtr l = fromTo_iter(1,2);
    //printList(l);

    ListNodePtr p = fromTo_iter(1,2);
    //printList(p);

    _Bool lp = included_iter(l, p);
//    printf("Expected 1 || got %d\n", lp);

    ListNodePtr revl = reverse_iter(l);
//    printList(revl);

    ListNodePtr sumlp = zipSum_iter(l,p);
    printList(sumlp);



    return 0;
}