
#include <stdio.h>

#include "forward-list.h"

void print_int(data_type data)
{
    int * num = data;

    printf("%d", *num);
}

int main()
{
    int n;

    ForwardList *l = forward_list_construct();

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        forward_list_push_front(l, &val);
    }

    //forward_list_sort(l);
    forward_list_print(l, print_int);
    forward_list_destroy(l);

    return 0;
}