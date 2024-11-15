#include <math.h>
#include <memory.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    // 10001st prime number

    uint64_t *primes = (uint64_t *)malloc(10001 * sizeof(uint64_t));
    memset(primes, 0, 10001 * sizeof(uint64_t));

    primes[0] = 2;
    uint64_t current_primes = 1;

    for (uint64_t i = 3; current_primes < 10001; i += 2) {
        bool is_prime = 1;
        for (uint64_t j = 0; j < current_primes; j++) {
            uint64_t p = primes[j];
            if ((i % p) == 0) {
                is_prime = 0;
                break;
            }

            if (p * p > i) {
                break;
            }
        }

        if (is_prime) {
            primes[current_primes] = i;
            current_primes++;
        }
    }

    printf("%ld", primes[current_primes - 1]);
    return 0;
}