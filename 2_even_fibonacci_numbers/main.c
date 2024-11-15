#include <stdint.h>
#include <stdio.h>
int main(int argc, char const *argv[]) {
    // sum of even elements of fibonaci sequence up to 4000000
    uint64_t sum = 2;
    uint64_t f1 = 1;
    uint64_t f2 = 2;
    while (f1 + f2 < 4000000) {
        uint64_t temp = f1 + f2;
        if (temp % 2 == 0) {
            sum += temp;
        }
        f1 = f2;
        f2 = temp;
    }

    printf("%ld", sum);

    return 0;
}
