#include <stdio.h>
#include <OmatFunktiot.h>

int main(void) {
    int kuppi = 7;
    int *robbie = &kuppi;
    int **daniel = &robbie;

    printf("Arvo kupissa: %d\n", kuppi);
    printf("Kupin osoite: %d\n", &kuppi);

    printf("Robbien arvo: %d\n", robbie);
    printf("Robbien osoite: %d\n", &robbie);
    printf("Arvo kupissa: %d\n", *robbie);

    printf("Danielin arvo: %d\n", daniel);
    printf("Danielin osoite: %d\n", &daniel);
    printf("Kupin osoite: %d\n", *daniel);
    printf("Arvo kupissa: %d\n", **daniel);

    //Input validation funktio
    if (scanf("%d", &selection) != 1) {
        while(getchar() != '\n');
        printf("invalid input\n");
    }

    return 0;
}