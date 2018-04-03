#include <stdio.h>
#include <sys/time.h>
#include <iostream>
#include <cstring>
#include "osm.h"

#define MICRO_TO_NANO 1000
#define SEC_TO_NANO 1000000000
#define DEFAULT_ITER 1000

#define NUM_OF_ITER 1000000

#define LOOP_FAC 3 // loop unwinding factor


int osm_init()
{
    return 0;
}

int osm_finalizer()
{
    return 0;
}


void set_iterations(unsigned int &iterations)
{
    if (iterations == 0)
    {
        iterations = DEFAULT_ITER;
    }
}

double osm_operation_time(unsigned int iterations)
{
    set_iterations(iterations);

    struct timeval start, end;
    int curr = iterations;

    gettimeofday(&start, NULL);
    for (; curr > 0; curr -= LOOP_FAC)
    {
        unsigned int x1 = 1 + 2;
        unsigned int x2 = 1 + 2;
        unsigned int x3 = 1 + 2;
    }
    gettimeofday(&end, NULL);

    return double((end.tv_sec - start.tv_sec) * SEC_TO_NANO +
            (end.tv_usec - start.tv_usec) * MICRO_TO_NANO) / (iterations / LOOP_FAC);
}

void empty()
{
}

double osm_function_time(unsigned int iterations)
{
    set_iterations(iterations);

    struct timeval start, end;
    int curr = iterations;

    gettimeofday(&start, NULL);
    for (; curr > 0; curr -= LOOP_FAC)
    {
        empty();
        empty();
        empty();
    }
    gettimeofday(&end, NULL);

    return double((end.tv_sec - start.tv_sec) * SEC_TO_NANO +
            (end.tv_usec - start.tv_usec) * MICRO_TO_NANO) / (iterations / LOOP_FAC);
}

double osm_syscall_time(unsigned int iterations)
{
    set_iterations(iterations);

    struct timeval start, end;
    int curr = iterations;

    gettimeofday(&start, NULL);
    for (; curr > 0; curr -= LOOP_FAC)
    {
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
    }
    gettimeofday(&end, NULL);
    return double((end.tv_sec - start.tv_sec) * SEC_TO_NANO +
            (end.tv_usec - start.tv_usec) * MICRO_TO_NANO) / (iterations / LOOP_FAC);
}

int main(int argc, char *argv[])
{
    printf("osm_operation_time: %f\n" , osm_operation_time(NUM_OF_ITER));
    printf("osm_function_time: %f\n", osm_function_time(NUM_OF_ITER));
    printf("osm_syscall_time: %f\n", osm_syscall_time(NUM_OF_ITER));
}