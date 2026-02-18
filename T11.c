#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int replace_char(char *str, const char *repl);

int main(void) {
    char text[80] = "I am so tired of Python. C is much better languagee";
    int count = 0;
    count = replace_char(text, "e3");

    if (count > 0) {
        printf("replaced %d characters\n", count);
        printf("new string: %s\n", text);
    }
    else {
        printf("string wasnt modified\n");
    }
}

int replace_char(char *str, const char *repl) {
    if (strlen(repl) != 2)
        return 0;
    int count = 0;
    char old = repl[0];
    char new = repl[1];

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == old) {
            str[i] = new;
            count += 1;
        }
    }

    return count;
}
