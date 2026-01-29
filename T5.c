#include <stdio.h>

int read_range(int low, int high);

int main(void) {
    int choice = 0;
    for (int i = 0; i < 3; i++) {
        choice = read_range(1, 6);
        if (choice > 0) {
            if (choice == 6) {
                printf("I got 6. It is a tie!\n");
            } else {
                printf("I got %d. I win!\n", choice + 1);
            }
        }
    }
    printf("Better luck next time!");
    return 0;
}

int read_range(int low, int high) {
    int number;
    printf("Pick a number between %d and %d: ", low, high);
    if (scanf("%d", &number) != 1) {
        while (getchar() != '\n');
        printf("invalid input\n");
        return 0;
    }
    if (number >= low && number <= high) {
        return number;
    } else {
        printf("Number not in the range\n");
        return 0;
    }
}
