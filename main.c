#include <stdio.h>
#include <time.h>
#include "fonctions.h"

int main() {
    int n = 100000;

    clock_t start = clock();
    int naive_count = count_primes_naive(n);
    clock_t end = clock();
    double naive_time = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    int efficient_count = count_primes_efficient(n);
    end = clock();
    double efficient_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Naive: count = %d, time = %f seconds\n", naive_count, naive_time);
    printf("Efficient: count = %d, time = %f seconds\n", efficient_count, efficient_time);

    return 0;
}