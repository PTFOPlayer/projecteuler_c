#include <math.h>
#include <memory.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    // (1+2..+100)^2 - (1^2+2^2+3^2...+100^2)
    uint64_t sum = 0;
    uint64_t s_sum = 0;
    for (size_t i = 0; i < 101; i++)
    {
        sum += i;
        s_sum += i*i;
    }

    printf("%ld", (sum*sum) - s_sum);
    return 0;
}
