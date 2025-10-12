#include <stdio.h>
#include <stdbool.h>
#include <math.h>



//question 1
bool is_prime_naive(int num) {
    if (num < 2)
        return false;
    int limit = (int)sqrt(num);
    for (int i = 2; i <= limit; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int count_primes_naive(int n) {
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (is_prime_naive(i))
            count++;
    }
    return count;
}

int main() {
    int n = 100;
    int count = count_primes_naive(n);
    printf("Nombre de nombres premiers inférieurs à %d : %d\n", n, count);
    return 0;
}



//QUESTION 2

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int count_primes_efficient(int n) {
    if (n <= 2) return 0;

    bool sieve[n];
    memset(sieve, true, sizeof(sieve));
    sieve[0] = false;
    sieve[1] = false;

    int count = 0;
    for (int i = 2; i < n; i++) {
        if (sieve[i]) {
            count++;
            for (int j = i * i; j < n; j += i) {
                sieve[j] = false;
            }
        }
    }
    return count;
}

int main() {
    int n = 100;
    int result = count_primes_efficient(n);
    printf("Nombre de nombres premiers inférieurs à %d (crible) : %d\n", n, result);
    return 0;
}

//QUESTION 4


#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>

bool is_prime_naive(int num) {
    if (num < 2)
        return false;
    for (int i = 2; i <= (int)sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int count_primes_naive(int n) {
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (is_prime_naive(i))
            count++;
    }
    return count;
}

int count_primes_efficient(int n) {
    if (n <= 2)
        return 0;
    bool sieve[n];
    memset(sieve, true, sizeof(sieve));
    sieve[0] = sieve[1] = false;
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (sieve[i]) {
            count++;
            for (int j = i * i; j < n; j += i)
                sieve[j] = false;
        }
    }
    return count;
}

int main() {
    int n = 100000;

    clock_t start_naive = clock();
    int naive_count = count_primes_naive(n);
    clock_t end_naive = clock();
    double naive_time = (double)(end_naive - start_naive) / CLOCKS_PER_SEC;

    clock_t start_efficient = clock();
    int efficient_count = count_primes_efficient(n);
    clock_t end_efficient = clock();
    double efficient_time = (double)(end_efficient - start_efficient) / CLOCKS_PER_SEC;

    printf("Naive: count = %d, time = %f seconds\n", naive_count, naive_time);
    printf("Efficient: count = %d, time = %f seconds\n", efficient_count, efficient_time);

    return 0;
}
