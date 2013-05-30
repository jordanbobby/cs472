#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <assert.h>
#include <sys/types.h>
#include <fcntl.h>

#define LOCAL_SIZE 100
#define KB 1024
#define MB (KB * 1024)
#define GB (MB * 1024)

#define ARRAY_SIZE (1 * GB)

int main(int argc, char **args){

    clock_t begin, inner_total;
    long double n_avg, n_access;
    char *array;
    long int n; // number of elements in array
    long int i; // array iterator
    char dummy;
    double cache_size;


    for(n = KB; n < ARRAY_SIZE; n *= 2){
        //create array of size n
        array = (char *) malloc(sizeof(char) * n);

        //perform MAX_COUNT trials

        begin = clock();

        //access every element in the array sequentially
        for(i = 0; i < n; i++){

            dummy = array[i];
        }

        inner_total = clock() - begin;
        printf("inner_total = %ld\n", inner_total);
        n_access = inner_total * 1.0  / n;
        printf("n = %ld, access time total = %ld, access time = %.32Lf\n", n, inner_total, n_access);
        free(array);
    }

    exit(0);

}

