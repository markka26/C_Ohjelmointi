#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    char name[32];
    while (strcmp(name, "stop") != 0) {
        printf("Enter a string: ");
        fgets(name, 32, stdin);

        if (name[strlen(name) - 1] == '\n') {
            name[strlen(name) - 1] = '\0';
        }

        printf("length: %lu\n", strlen(name));
    }
    return 0;
}
