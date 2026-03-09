#include <stdio.h>
#include <ctype.h>

const int  MAX_LINES = 100;
const int MAX_LEN = 80;

FILE *open_file(const char *filename, const char *mode);
int read_line(FILE *file, char lines[][MAX_LEN]);
void uppercase(char lines[][MAX_LEN], int count);
void write_lines(const char *filename, char lines[][MAX_LEN], int count);

int main(void) {
    char filename[100];
    char lines[MAX_LINES][MAX_LEN];
    FILE *file;
    int line_count;

    printf("Enter filename: ");
    scanf("%99s", filename);

    file = open_file(filename, "r");
    if (file == NULL) {
        return 1;
    }

    line_count = read_line(file, lines);
    fclose(file);

    uppercase(lines, line_count);
    file = open_file(filename, "w");
    if (file == NULL) {
        return 1;
    }

    write_lines(filename, lines, line_count);
    fclose(file);
    return 0;
}

FILE *open_file(const char *filename, const char *mode) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", filename);
    }
    return file;
}

//rivit listaan
int read_line(FILE *file, char lines[][MAX_LEN]) {
    int count = 0;

    while (count < MAX_LINES &&
           fgets(lines[count], MAX_LEN, file) != NULL) {
        count++;
           }
    return count;
}

void uppercase(char lines[][MAX_LEN], int count) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; lines[i][j] != '\0'; j++) {
            lines[i][j] = toupper((unsigned char)lines[i][j]);
        }
    }
}

void write_lines(const char *filename, char lines[][MAX_LEN], int count) {
    FILE *file = fopen(filename, "w");
    for (int i = 0; i < count; i++) {
        fputs(lines[i], file);
    }
    fclose(file);
}