#include <math.h>
#include <memory.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void fill_up_sieve(bool *sieve, size_t limit);

int main(int argc, char const *argv[]) {
    // largest prime factor of 600851475143
    uint64_t number = 600851475143;

    bool *sieve = (bool *)malloc(sqrt(number));
    memset(sieve, true, sqrt(number));
    sieve[0] = false;
    fill_up_sieve(sieve, sqrt(number));

    uint64_t max = 0;
    for (size_t i = 0; i < sqrt(number) && number > 0; i++) {
        if (sieve[i]) {
            if (number % i == 0) {
                number = number / i;
                if (i > max) max = i;
            }
        }
    }

    printf("%ld", max);
    return 0;
}

void fill_up_sieve(bool *sieve, size_t limit) {
    for (size_t i = 1; i < sqrt(limit); i++)
        if (sieve[i])
            for (size_t j = i * i; j < limit; j += i) sieve[i] = false;
}
