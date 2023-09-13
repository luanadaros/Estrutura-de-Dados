#include <stdlib.h>
#include <stdio.h>
#include "flist.h"

int main (){
    Flist *flist = flist_construct();

    for(int i = 10; i >= 1; i--){
        flist_push_front(flist, i);
    }

    Node * node_it = flist->head;

    while(node_it != NULL){
        printf("%d\n", node_it->value);
        node_it = node_it->next;
    }

    flist_destroy(flist);

    return 0;
}