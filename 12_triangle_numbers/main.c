#include <math.h>
#include <stdint.h>
#include <stdio.h>
int main(int argc, char const *argv[]) {
    // find first triangle number with over 500 divisors
    uint64_t triangle_number = 0;

    uint64_t n = 1;
    uint64_t divisors = 2;
    for (;divisors <= 500; n++) {
        triangle_number = n * (n + 1) / 2;
        divisors = 2;  // one and self is guaranteed
        for (size_t j = 2; j < sqrt(triangle_number); j++)
            if (triangle_number % j == 0) {
                divisors += 1;
                if (triangle_number / j != j) {
                    divisors += 1;
                }
            }
    }
    printf("%lld \t %lld\n", triangle_number, n);

    return 0;
}
