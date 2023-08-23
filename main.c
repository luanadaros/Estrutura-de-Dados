
#include <stdio.h>

#include <stdio.h>
#include <string.h>

#include "vector.h"

int main()
{
    int i, m, n, o, val;

    Vector *v;

    v = vector_construct();

    scanf("%d %d %d", &m, &n, &o);

    for (i = 0; i < m; i++)
    {
        scanf("%d", &val);
        vector_push_back(v, val);
    }

    for (i = 0; i < n; i++)
        printf("%d\n", vector_pop_front(v));

    for (i = 0; i < o; i++)
        printf("%d\n", vector_pop_back(v));

    vector_destroy(v);

    return 0;
}