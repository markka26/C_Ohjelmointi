#include <stdio.h>

int bussi();
int taxi();
int rahaa();
int valinta(int raha_maara, int bussin_hinta, int taxin_hinta);

int main(void) {
    int bussi_hinta = bussi();
    int taxi_hinta = taxi();
    int raha_maara = rahaa();
    raha_maara = valinta(raha_maara, bussi_hinta, taxi_hinta);
    printf("You need to walk.");
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

int valinta(int rahan_maara, int bussin_hinta, int taxin_hinta) {
    int valinta;

    while (rahan_maara >= bussin_hinta || rahan_maara >= taxin_hinta) {
        printf("Do you want to take\n");
        printf("1) bus (%d euros)\n", bussin_hinta);
        printf("2) taxi (%d euros)\n", taxin_hinta);
        scanf("%d", &valinta);

        if (valinta == 1) {
            if (rahan_maara >= bussin_hinta) {
                printf("You chose the bus\n");
                rahan_maara -= bussin_hinta;
                printf("You have %d euros left\n", rahan_maara);
            } else {
                printf("You dont have money for the bus\n");
                printf("You have %d euros left\n", rahan_maara);
            }
        }

        if (valinta == 2) {
            if (rahan_maara >= taxin_hinta) {
                printf("You chose a taxi\n");
                rahan_maara -= taxin_hinta;
                printf("You have %d euros left\n", rahan_maara);
            } else {
                printf("You dont have money for the taxi\n");
                printf("You have %d euros left\n", rahan_maara);
            }
        }
    }
    return rahan_maara;
}
