#include <stdio.h>

int read_integer(void);

int main(void) {
    read_integer();
}

int read_integer(void) {
    int number = 0;
    int i = 0;
    float sum = 0;
    float average = 0;
    do {
        printf("Pick a positive number: ");
        if (scanf("%d", &number) != 1) {
            while (getchar() != '\n');
            printf("invalid input\n");
        }
        i++;
        if (number >= 0) {
            sum += number;
        }
    } while (number >= 0);
    printf("You picked %d numbers\n", i - 1);
    average = sum / (i - 1);
    printf("Their average was: %f\n", average);
    return 0;
}