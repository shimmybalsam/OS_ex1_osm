#include "osm.h"
#include <iostream>
#include <sys/time.h>
#include <cmath>

#define DEFAULT_ITERS 1000
#define NUM_OF_REPEATS 10
#define SEC_TO_MICRO 1000000
#define MICRO_TO_NANO 1000

using namespace std;

/* Initialization function that the user must call
 * before running any other library function.
 * The function may, for example, allocate memory or
 * create/open files.
 * Pay attention: this function may be empty for some desings. It's fine.
 * Returns 0 uppon success and -1 on failure
 */
int osm_init(){
    return 0;
}


/* finalizer function that the user must call
 * after running any other library function.
 * The function may, for example, free memory or
 * close/delete files.
 * Returns 0 uppon success and -1 on failure
 */
int osm_finalizer(){
    return 0;
}

/*
 * helper funcion, checks and reassigns num of iterations in case not positive
 * or if smaller that loop unrolling factor of 10.
 */
unsigned int iter_correct(unsigned int iterations){
    if (iterations <= 0)
    {
        iterations = DEFAULT_ITERS;
    }
    if (iterations <NUM_OF_REPEATS)
    {
        iterations = NUM_OF_REPEATS;

    }
    return iterations;
}

/* Time measurement function for a simple arithmetic operation.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_operation_time(unsigned int iterations){

    timeval tv;
    if (gettimeofday(&tv, nullptr)==-1)
    {
        return -1;
    }
    double t1 = tv.tv_sec*SEC_TO_MICRO + tv.tv_usec;
    iterations = iter_correct(iterations);
    int temp_iter = iterations/NUM_OF_REPEATS;
    int a1=0, a2=0, a3=0, a4=0, a5=0, a6=0, a7=0, a8=0, a9=0, a10=0;
    for (int i = 0; i<temp_iter; ++i)
    {
        a1+=2;
        a2+=2;
        a3+=2;
        a4+=2;
        a5+=2;
        a6+=2;
        a7+=2;
        a8+=2;
        a9+=2;
        a10+=2;
    }
    if (gettimeofday(&tv, nullptr)==-1)
    {
        return -1;
    }
    double t2 = tv.tv_sec*SEC_TO_MICRO + tv.tv_usec;
    double nano = (t2-t1)*MICRO_TO_NANO/(double)iterations;
    return nano;
}

void emptyfunc(){} // to be used in next func's call


/* Time measurement function for an empty function call.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_function_time(unsigned int iterations){
    iterations = iter_correct(iterations);
    timeval tv;
    if (gettimeofday(&tv, nullptr)==-1)
    {
        return -1;
    }    double t1 = tv.tv_sec*SEC_TO_MICRO + tv.tv_usec;
    int temp_iter = iterations/NUM_OF_REPEATS;
    for (int i = 0; i<temp_iter; ++i)
    {
        emptyfunc();
        emptyfunc();
        emptyfunc();
        emptyfunc();
        emptyfunc();
        emptyfunc();
        emptyfunc();
        emptyfunc();
        emptyfunc();
        emptyfunc();
    }
    if (gettimeofday(&tv, nullptr)==-1)
    {
        return -1;
    }
    double t2 = tv.tv_sec*SEC_TO_MICRO + tv.tv_usec;
    double nano = (t2-t1)*MICRO_TO_NANO/(double)iterations;
    return nano;
}

/* Time measurement function for an empty trap into the operating system.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_syscall_time(unsigned int iterations){
    iterations = iter_correct(iterations);
    timeval tv;
    if (gettimeofday(&tv, nullptr)==-1)
    {
        return -1;
    }    double t1 = tv.tv_sec*SEC_TO_MICRO + tv.tv_usec;
    int temp_iter = iterations/NUM_OF_REPEATS;
    for (int i = 0; i<temp_iter; ++i)
    {
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
    }
    if (gettimeofday(&tv, nullptr)==-1)
    {
        return -1;
    }
    double t2 = tv.tv_sec*SEC_TO_MICRO + tv.tv_usec;
    double nano = (t2-t1)*MICRO_TO_NANO/(double)iterations;
    return nano;
}

