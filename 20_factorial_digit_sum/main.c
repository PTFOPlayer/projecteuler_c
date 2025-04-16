#include <stdio.h>
#include <stdint.h>


const uint64_t max_per_cell = 1000000000000;
#define arr_size 16

int main(int argc, char const *argv[])
{
    uint64_t big_int[arr_size] = {0};
    big_int[0] = 1;
    

    for (size_t i = 1; i <= 100; i++)
    {
        for (int j = 0; j < arr_size; j++)  // Multiply all cells
        {
            big_int[j] *= i;
        }

        for (int j = 0; j < arr_size-1; j++)
        {
            big_int[j+1] += big_int[j] / max_per_cell;
            big_int[j] %= max_per_cell;
        }
    }

    uint64_t sum = 0;
    for (size_t i = 0; i < arr_size; i++)
    {
        while (big_int[i] != 0)
        {
            sum += big_int[i] % 10;
            big_int[i] /= 10;
        }
        
    }

    printf("%lld", sum);
        
    
    
    return 0;
}
