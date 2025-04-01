#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

uint32_t month_len[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

uint32_t is_leap_year(uint32_t year) {
    if ((year % 4 == 0) && (year % 400 != 0)) {
        return 1;
    }
    return 0;
}

uint32_t get_month_len(uint32_t month, uint32_t year) {
    month -= 1;
    if (month == 1) return month_len[month] + is_leap_year(year);

    return month_len[month];
}

void gen_next(uint32_t *year, uint32_t *month_day, uint32_t *month, uint32_t add) {
    *month_day += add;

    if (*month_day <= get_month_len(*month, *year)) return;

    *month_day = *month_day - get_month_len(*month, *year);

    *month += 1;
    if (*month > 12) {
        *month = 1;
        *year += 1;
    }
}

int main(int argc, char const *argv[]) {
    uint32_t year = 1900;
    uint32_t month_day = 1;  // monday
    uint32_t month = 1;

    uint32_t num_sundays = 0;
    gen_next(&year, &month_day, &month, 6);
    while (1) {
        gen_next(&year, &month_day, &month, 7);
        if (year == 2001) break;
        if (month_day == 1) num_sundays++;
    }

    printf("%d\n", num_sundays - 1);
    return 0;
}