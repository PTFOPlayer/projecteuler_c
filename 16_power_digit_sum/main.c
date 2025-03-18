#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    // aprox 330 numbers
    const int32_t arr_size = 350;
    char arr[arr_size];
    memset(arr, 0, arr_size);

    arr[0] = 1;
    for (int32_t i = 0; i < 1000; i++) {
        for (int32_t j = arr_size - 2; j >= 0; j--) {
            arr[j] *= 2;
            arr[j + 1] += arr[j] / 10;
            arr[j] %= 10;
        }
    }

    uint64_t sum = 0;
    for (size_t i = 0; i < arr_size; i++) {
        printf("%d", arr[i]);
        sum += arr[i];
    }
    printf("\n\n%d", sum);

    return 0;
}
