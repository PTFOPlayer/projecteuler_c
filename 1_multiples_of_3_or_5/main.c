#include <stdint.h>
#include <stdio.h>
int main(int argc, char const *argv[]) {
    // sum of multiples of 3 or 5 up to 1000
    uint64_t sum = 0;
    
    for (size_t i = 0; i < 1000; i++) sum += i * ((i % 5 == 0) || (i % 3 == 0));

    printf("%ld", sum);
    return 0;
}
