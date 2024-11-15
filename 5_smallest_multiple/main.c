#include <math.h>
#include <memory.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define swap(x, y)          \
    do {                    \
        typeof(x) SWAP = x; \
        x = y;              \
        y = SWAP;           \
    } while (0)

uint64_t lcm(uint64_t lhs, uint64_t rhs);
uint64_t gcd(uint64_t lhs, uint64_t rhs);

int main(int argc, char const *argv[]) {
    // smallest evenly divisable by numbers from 1 to 20
    uint64_t res = 1;
    for (size_t i = 2; i < 21; i++) {
        uint64_t temp = res;
        res = lcm(i, temp);
    }

    printf("%ld", res);
    return 0;
}

uint64_t lcm(uint64_t lhs, uint64_t rhs) { return (lhs * rhs) / gcd(lhs, rhs); }

uint64_t gcd(uint64_t lhs, uint64_t rhs) {
    // gcd using euclidean algorithm
    while (rhs != 0) {
        lhs %= rhs;
        swap(lhs, rhs);
    }
    return lhs;
}
