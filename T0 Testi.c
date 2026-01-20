#include <stdio.h>
void print_hello();
int read_number();

int main(void) {
    int number = 0;
    number = read_number();
    printf("Numero on:%d\n", number);
    return 0;
}


int read_number() {
    int number = 0;
    printf("Enter a number: ");
    scanf("%d", &number);
    return number;
}