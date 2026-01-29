#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int menu();
int dice_roller(int selection);

int main(void) {
    int selection = 0;
    selection = menu();
    dice_roller(selection);
}

int menu() {
    int number = 0;
    printf("1) Roll D6\n");
    printf("2) Roll D10\n");
    printf("3) Quit\n");
    printf("Select an option: ");
    if (scanf("%d", &number) != 1) {
        while (getchar() != '\n');
        printf("invalid input\n");
    }
    if (number >= 1 && number <= 3) {
        return number;
    }
    else {
        printf("Number not in the range\n");
        return 0;
    }
    return number;
}

int dice_roller(int selection) {

    if (selection == 1) {
        srand(time(NULL)); // use current time as seed for random generator
        int random_variable = rand();
        printf("Random value on [0,%d]: %d\n", RAND_MAX, random_variable);

        int num = 1 + rand() / ((RAND_MAX + 1u) / 6);
        printf("number is %d\n", num);
    }
    if (selection == 2) {
        srand(time(NULL)); // use current time as seed for random generator
        int random_variable = rand();
        printf("Random value on [0,%d]: %d\n", RAND_MAX, random_variable);

        int num = 1 + rand() / ((RAND_MAX + 1u) / 10);
        printf("number is %d\n", num);
    }
    if (selection == 3) {
        printf("Bye.");
        return 0;
    }
}
