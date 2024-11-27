#include <math.h>
#include <memory.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    uint64_t max = 10000;
    uint64_t *primes = (uint64_t *)malloc(max * sizeof(uint64_t));

    primes[0] = 2;
    uint64_t current_primes = 1;

    for (uint64_t i = 3; i < 2000000; i += 2) {
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

        if (current_primes == max - 1) {
            uint64_t *t_primes =
                realloc(primes, (max + 100) * sizeof(uint64_t));
            if (t_primes == NULL)
                return -1;
            else
                primes = t_primes;
            max += 100;
        }
    }

    printf("%ld, %ld\n", current_primes, max);

    uint64_t sum = 0;
    for (uint64_t i = 0; i < current_primes; i++) sum += primes[i];
    printf("sum: %ld", sum);
    return 0;
}