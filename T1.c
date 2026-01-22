#include <stdio.h>

int bussi();
int taxi();
int rahaa();
int valinta();

int main(void) {
    int bussi_hinta = bussi();
    int taxi_hinta = taxi();
    int raha_maara = rahaa();
    valinta();
    //printf("Enter bus ticket price you have:%d\n", bussi_hinta);
    //printf("Enter taxi trip price:%d\n", taxi_hinta);
    printf("You have %d", raha_maara);
    printf(" euros left\n");
    return 0;
}

int bussi() {
    int bussi_hinta = 0;
    printf("Enter bus ticket price: ");
    scanf("%d", &bussi_hinta);
    return bussi_hinta;
}

int taxi() {
    int taxi_hinta = 0;
    printf("Enter taxi trip price: ");
    scanf("%d", &taxi_hinta);
    return taxi_hinta;
}

int rahaa() {
    int raha_maara = 0;
    printf("How much money do you have?: ");
    scanf("%d", &raha_maara);
    return raha_maara;
}

int valinta() {
    int valinta;
    int rahan_maara = rahaa();
    int bussin_hinta = bussi();
    int taxin_hinta = taxi();
    printf("testi\n");
    while (rahan_maara > bussin_hinta || rahan_maara > taxin_hinta) {
        printf("Do you want to take\n");
        printf("1) bus\n");
        printf("2) taxi\n");
        scanf("%d", &valinta);

        if (valinta == 1) {
            printf("You chose the bus\n");
            rahan_maara -= bussin_hinta;
        }
        if (valinta == 2) {
            printf("You chose a taxi\n");
            rahan_maara -= taxin_hinta;
        }
    }
}