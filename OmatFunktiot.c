#include <stdio.h>
#include <string.h>

int inputValidation(int selection) {
    if (scanf("%d", &selection) != 1) {
        while (getchar() != '\n');
        printf("invalid input\n");
    }
}


void remove_new_line(char name[]) {
    if (name[strlen(name) - 1] == '\n') {
        name[strlen(name) - 1] = '\0';
    }
}
