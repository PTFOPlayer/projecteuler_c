#include <stdint.h>
#include <stdio.h>
uint32_t tree[15][15] = {
    {75},
    {95, 64},
    {17, 47, 82},
    {18, 35, 87, 10},
    {20, 4, 82, 47, 65},
    {19, 1, 23, 75, 3, 34},
    {88, 2, 77, 73, 7, 63, 67},
    {99, 65, 4, 28, 6, 16, 70, 92},
    {41, 41, 26, 56, 83, 40, 80, 70, 33},
    {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
    {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
    {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
    {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
    {63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
    {4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23},
};

uint32_t check_path(uint32_t sum, uint32_t height, uint32_t width);

int main(int argc, char const *argv[]) {
    printf("%ld\n", check_path(0, 0, 0));
    return 0;
}

uint32_t check_path(uint32_t sum, uint32_t height, uint32_t width) {
    if (height == 15) return sum;
    sum += tree[height][width];
    uint32_t left_branch = check_path(sum, height + 1, width);
    uint32_t right_branch = check_path(sum, height + 1, width + 1);

    if (left_branch > right_branch) {
        printf("%ld\n", tree[height][width]);
        return left_branch;
    } else {
        printf("%ld\n", tree[height][width + 1]);
        return right_branch;
    }
};
