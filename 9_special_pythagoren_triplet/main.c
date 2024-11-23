#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a,b,c;
    for (size_t i = 0; i < 500; i++)
    for (size_t j = 0; j < i; j++)
    for (size_t k = 0; k < j; k++)
        if (((j*j)+(k*k) == i*i) && (i+j+k == 1000))
        {
            c = i;
            b = j;
            a = k;
        }

    printf("%d, %d, %d, prod: %d", a, b, c, a*b*c);
        
    
    
    
    return 0;
}
