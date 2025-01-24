#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint64_t colatz(uint64_t n);

const uint64_t MAX = 1000000;
int main(int argc, char const *argv[]) {
    int64_t *memoization = (int64_t *)malloc(sizeof(int64_t) * MAX);
    if (memoization == NULL) {
        return -1;
    }
    for (uint64_t i = 0; i < MAX; i++) memoization[i] = -1;

    int64_t max = 0;
    int64_t max_starting = 0;
    for (uint64_t i = 2; i < MAX; i++) {
        uint64_t starting = i;
        uint64_t num = colatz(i);
        int64_t count = 2;
        while (num != 1) {
            if (num < MAX && memoization[num] != -1) {
                count += memoization[num];
                break;
            }
            count += 1;
            num = colatz(num);
        }

        if (num < MAX && memoization[starting] == -1) {
            memoization[starting] = count;
        }
        if (count > max) {
            max = count;
            max_starting = starting;
        }
    }
    printf("%lld", max_starting);

    return 0;
}

uint64_t colatz(uint64_t n) {
    if (n % 2 == 0) {
        return n / 2;
    } else {
        return 3 * n + 1;
    }
}