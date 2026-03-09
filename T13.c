#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void minmax(FILE *file, int *count, int *min, int *max);
FILE *open_file(const char *fname);

int main(void) {
    char fname[100];
    FILE *file;
    int count;
    int min;
    int max;

    printf("Enter filename: ");
    scanf("%99s", fname);

    file = open_file(fname);
    if (file == NULL) {
        return 1;
    }

    minmax(file, &count, &min, &max);

    if (count > 0) {
        printf("Count: %d\n", count);
        printf("Min: %d\n", min);
        printf("Max: %d\n", max);
    } else {
        printf("No numbers found.\n");
    }

    fclose(file);
    return 0;
}

// tiedoston avaus
FILE *open_file(const char *fname) {
    FILE *file = fopen(fname, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", fname);
    }
    return file;
}

//min max laskenta
void minmax(FILE *file, int *count, int *min, int *max) {
    int number;
    *count = 0;

    while (fscanf(file, "%d", &number) == 1) {
        if (*count == 0) {
            *min = number;
            *max = number;
        } else {
            if (number < *min) {
                *min = number;
            }
            if (number > *max) {
                *max = number;
            }
        }
        (*count)++;
    }
}