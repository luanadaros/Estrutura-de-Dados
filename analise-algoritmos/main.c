#include <stdlib.h>
#include <time.h>

double get_timestamp()
{
    struct timespec now;
    timespec_get(&now, TIME_UTC);
    return now.tv_sec + (((double)now.tv_nsec) / 1e9);
}


int main()
{
    srand(time(NULL));
    
    int x = rand();
}
