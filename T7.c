#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool read_positive(int *value);

int main(void) {
    int value = 0;
    if (read_positive(&value)) {
        printf("You entered: %d\n", value);
        printf("You didnt get it right, I have %d euros\n", (value * 2) + 20);
        return 0;
    }
}

bool read_positive(int *value) {
    int number = 0;
    printf("Guess how much money I have\n");
    printf("Enter a positive number: ");
    if (scanf("%d", &number) != 1) {
        while (getchar() != '\n');
        printf("Thats not a number\n");
        return false;
    }
    if (number > -1) {
        *value = number;
        return true;
    }
    else {
        printf("Number is not positive\n");
        return false;
    }
}
