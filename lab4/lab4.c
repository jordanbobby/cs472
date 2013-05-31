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

long double avg(long double data[], int n)
{
    long int i = 0;
    long double mean = 0.0;
    for (i = 0; i < n; ++i){
        mean += data[i];
    }
    mean = mean/n;
    return mean;
}
long double standard_deviation(long double data[], int n)
{
    long double  mean=0.0, sum_deviation=0.0;
    int i;
    for(i=0; i<n;++i){
        mean+=data[i];
    }
    mean=mean/n;
    for(i=0; i<n;++i){
        sum_deviation+=(data[i]-mean)*(data[i]-mean);
    }
    return sqrtl(sum_deviation/n);
}
int main(int argc, char **args){

    clock_t begin, inner_total;
    long double n_avg, n_access;
    char *array;
    long int n; // number of elements in array
    long int i; // array iterator
    int k = 0;
    char dummy;
    double cache_size;
    long double access_times[200];
    long double std = 0.0;
    long double prev_avg, cur_avg, prev_std, cur_std;
    int accept = 5;
    char input[1];


    for(n = KB; n < ARRAY_SIZE; n *= 2){
        //create array of size n
        array = (char *) malloc(sizeof(char) * n);

        //perform MAX_COUNT trials

        begin = clock();

        //access every element in the array sequentially
        for(i = 0; i < n; i++){

            dummy = array[i];
        }

        //calculate access time
        inner_total = clock() - begin;
        printf("inner_total = %ld\n", inner_total);
        n_access = inner_total * 1.0  / n;

        //get current access time avg and standard deviation
        access_times[k] = n_access;
        cur_avg = avg(access_times, k);
        cur_std = standard_deviation(access_times, k);

        printf("n = %ld, access time total = %ld, access time = %.32Lf\n", n, inner_total, n_access);
        if (n_access > accept * (cur_avg + cur_std))
        {
            printf("cached increase detected!\n");
            printf("Cache is %d KB\n", n/ KB);
            break;
        }
        else{
            k++;
        }
        free(array);
    }
    exit(0);
}

