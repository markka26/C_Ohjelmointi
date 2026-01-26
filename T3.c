#include <stdio.h>

int opiskelijoiden_maara();
void alusta_arvosanat(int arvosanat[], int maara);
int syota_arvosanat(int arvosanat[], int maara);
void tulosta_taulukko(int arvosanat[], int maara);

int main(void) {
    int maara = opiskelijoiden_maara();
    int arvosanat[maara];

    alusta_arvosanat(arvosanat, maara);
    int lopeta = syota_arvosanat(arvosanat, maara);
    if (lopeta == 1) {
        tulosta_taulukko(arvosanat, maara);
    }

    return 0;
}

int opiskelijoiden_maara() {
    int x = 0;
    printf("Kuinka monta opiskelijaa: ");
    scanf("%d", &x);
    return x;
}

void alusta_arvosanat(int arvosanat[], int maara) {
    for (int i = 0; i < maara; i++) {
        arvosanat[i] = -1;
    }
}

int syota_arvosanat(int arvosanat[], int maara) {
    int opiskelija = -1;

    do {
        printf("Anna opiskelijan numero (1 - %d) tai 0 lopettaaksesi: ", maara);
        scanf("%d", &opiskelija);

        if (opiskelija == 0) {
            return 1;
        }

        if (opiskelija < 1 || opiskelija > maara) {
            printf("Virheellinen opiskelijan numero!\n");
        } else {
            int arvosana = -2;

            do {
                printf("Anna arvosana (0 - 5) opiskelijalle %d tai -1 peruuttaaksesi: ", opiskelija);
                scanf("%d", &arvosana);

                if (arvosana >= 0 && arvosana <= 5) {
                    arvosanat[opiskelija - 1] = arvosana;
                } else {
                    printf("Virheellinen arvosana!\n");
                }
            } while (arvosana < -1 || arvosana > 5);
        }
    } while (opiskelija != 0);

    return 1;
}

void tulosta_taulukko(int arvosanat[], int maara) {
    printf("\nOpiskelija   Arvosana\n");

    for (int i = 0; i < maara; i++) {
        printf("%-11d ", i + 1);
        if (arvosanat[i] == -1) {
            printf("N/A\n");
        } else {
            printf("%d\n", arvosanat[i]);
        }
    }
}
