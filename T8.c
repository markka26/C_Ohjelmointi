#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int COUNT = 15;
const int SIZE = 15;

void print_numbers(const int *array, int count);

int main(void) {
    int numbers[SIZE];
    srand(time(NULL));
    for (int i = 0; i < COUNT; i++) {
        numbers[i] = rand() % 100;
    }
    print_numbers(numbers, COUNT);
    return 0;
}

void print_numbers(const int *array, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d\n", array[i]);
    }
}
