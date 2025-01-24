#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const uint8_t GRID_SIZE = 20;

uint64_t traverse(uint8_t col, uint8_t row);

int main(int argc, char const *argv[]) {
    uint64_t paths = traverse(0, 0);
    printf("%ld", paths);
    return 0;
}

uint64_t traverse(uint8_t col, uint8_t row) {
    if (col == GRID_SIZE && row == GRID_SIZE) return 1;

    uint64_t paths = 0;
    if (col < GRID_SIZE) {
        paths += traverse(col + 1, row);
    }

    if (row < GRID_SIZE) {
        paths += traverse(col, row + 1);
    }

    return paths;
}
