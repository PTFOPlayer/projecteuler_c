#include <math.h>
#include <memory.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool is_palindrome(char *string, size_t limit);

int main(int argc, char const *argv[]) {
    // largest palindrome beeing product of two 3 digit numbers
    char buffor [8] __attribute__ ((aligned (8))) = {0};
    uint32_t max = 0;
    for (size_t i = 100; i < 999; i++)
        for (size_t j = 100; j < 999; j++) {
            memset(buffor, 0, 8);
            uint32_t temp = i * j;
            snprintf(buffor, 8, "%d", temp);
            if (is_palindrome(buffor, strlen(buffor)) && temp > max) max = temp;
        }

    printf("%d", max);

    return 0;
}

bool is_palindrome(char *string, size_t limit) {
    for (size_t i = 0; i < limit / 2; i++)
        if (string[i] != string[limit - i - 1]) return false;

    return true;
}