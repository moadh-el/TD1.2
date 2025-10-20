#include "fonctions.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>

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

    bool *sieve = malloc(n * sizeof(bool));
    if (!sieve)
        return 0;

    memset(sieve, true, n * sizeof(bool));
    sieve[0] = sieve[1] = false;

    int count = 0;
    for (int i = 2; i < n; i++) {
        if (sieve[i]) {
            count++;
            for (int j = i * i; j < n; j += i)
                sieve[j] = false;
        }
    }

    free(sieve);
    return count;
}
