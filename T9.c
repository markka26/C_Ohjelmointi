#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find_first(const unsigned int *array, unsigned int what);
int search();

int main(void) {
    unsigned int numbers[20];
    srand(time(NULL));
    for (int i = 0; i < 19; i++) {
        numbers[i] = (rand() % 20) + 1;
    }
    numbers[19] = 0;

    for (int i = 0; i < 20; i++) {
        printf("%d\n", numbers[i]);
    }
    search(numbers);
}

int find_first(const unsigned int *array, unsigned int what) {
    for (int i = 0; array[i] != 0; i++) {
        if (array[i] == what) {
            return i;
        }
    }
    return -1;
}

int search(const unsigned int *array) {
    int number = 1;
    while (number != 0) {
        printf("Enter number to search, (0 to stop): ");
        if (scanf("%d", &number) != 1) {
            while (getchar() != '\n');
            printf("Thats not a number\n");
            return 0;
        }
        int index = find_first(array, number);
        if (index >= 0) {
            printf("Found it at %d\n", index);
        } else {
            printf("Not found\n");
        }
    }
}
