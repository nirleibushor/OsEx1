#include <stdio.h>
#include <sys/time.h>
#include "osm.h"

#define MICRO_TO_NANO 1000
#define SEC_TO_NANO 1000000000
#define DEFAULT_ITER 1000

#define NUM_OF_ITER 1000000


int osm_init()
{
    return 0;
}

int osm_finalizer()
{
    return 0;
}

double osm_operation_time(unsigned int iterations)
{
    if (iterations == 0)
    {
        iterations = DEFAULT_ITER;
    }
    struct timeval start, end;
    int x = 1;
    int curr = iterations;

    gettimeofday(&start, NULL);
    for (; curr > 0; curr--)
    {
        x = x + 1;
    }
    gettimeofday(&end, NULL);
    return ((end.tv_sec - start.tv_sec) * SEC_TO_NANO +
            (end.tv_usec - start.tv_usec) * MICRO_TO_NANO) / iterations;
}

void empty()
{
}

double osm_function_time(unsigned int iterations)
{
    if (iterations == 0)
    {
        iterations = DEFAULT_ITER;
    }
    struct timeval start, end;
    int curr = iterations;

    gettimeofday(&start, NULL);
    for (; curr > 0; curr--)
    {
        empty();
    }
    gettimeofday(&end, NULL);
    return ((end.tv_sec - start.tv_sec) * SEC_TO_NANO +
            (end.tv_usec - start.tv_usec) * MICRO_TO_NANO) / iterations;
}

double osm_syscall_time(unsigned int iterations)
{
    if (iterations == 0)
    {
        iterations = DEFAULT_ITER;
    }
    struct timeval start, end;
    int curr = iterations;

    gettimeofday(&start, NULL);
    for (; curr > 0; curr--)
    {
        OSM_NULLSYSCALL;
    }
    gettimeofday(&end, NULL);
    return ((end.tv_sec - start.tv_sec) * SEC_TO_NANO +
            (end.tv_usec - start.tv_usec) * MICRO_TO_NANO) / iterations;
}

int main()
{
    printf("osm_operation_time: %f\n", osm_operation_time(NUM_OF_ITER));

    printf("osm_function_time: %f\n", osm_function_time(NUM_OF_ITER));

    printf("osm_syscall_time: %f\n", osm_syscall_time(NUM_OF_ITER));
}