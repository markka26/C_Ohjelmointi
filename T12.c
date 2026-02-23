#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_words(char *string, const char *detect);

int main(void) {
    char text[80];
    char find[20];
    int count = 0;

    printf("Enter a word: "); //"stop" lopettaa ohjelman
    fgets(find, sizeof(find), stdin);
    find[strcspn(find, "\n")] = '\0';

    while (strcmp(find, "stop") != 0) {
        printf("Enter string: ");
        fgets(text, sizeof(text), stdin);
        text[strcspn(text, "\n")] = '\0';

        count = count_words(text, find);
        printf("Word %s is found %d times\n", find, count);

        printf("Enter word: ");
        fgets(find, sizeof(find), stdin);
        find[strcspn(find, "\n")] = '\0';
    }
    return 0;
}

int count_words(char *string, const char *detect) {
    int count = 0;
    const char *ptr = string;

    while (strstr(ptr, detect) != NULL) {
        ptr = strstr(ptr, detect);
        count++;
        ptr += strlen(detect);
    }
    return count;
}