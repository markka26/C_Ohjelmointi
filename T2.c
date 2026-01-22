#include <stdio.h>
const int KUUKAUDET = 12;

float veroprosentti();
float tuloraja();
float veroprosentti_korkea();

int main(void) {
    float tulot[KUUKAUDET];
    float vero[KUUKAUDET];

    float normaali = veroprosentti();
    float raja = tuloraja();
    float yli_rajan = veroprosentti_korkea();

    float koko_tulot = 0;

    for (int i = 0; i < KUUKAUDET; i++) {
        printf("Anna kuukauden %d tulot: ", i + 1);
        scanf("%f", &tulot[i]);
    }

    for (int i = 0; i < KUUKAUDET; i++) {
        float kk_tulot = tulot[i];
        float kk_vero = 0;

        if (koko_tulot >= raja) {
            kk_vero = kk_tulot * (yli_rajan / 100.0f);
        }
        else if (koko_tulot + kk_tulot <= raja) {
            kk_vero = kk_tulot * (normaali / 100.0f);
        }
        else {
            float matala = raja - koko_tulot;
            float korkea = kk_tulot - matala;

            kk_vero =
                matala * (normaali / 100.0f) +
                korkea * (yli_rajan / 100.0f);
        }

        vero[i] = kk_vero;
        koko_tulot += kk_tulot;
    }

    printf("\nkk      tulot       vero\n");

    for (int i = 0; i < KUUKAUDET; i++) {
        printf("%-6d %8.2f %8.2f\n", i + 1, tulot[i], vero[i]);
    }

    return 0;
}

float veroprosentti() {
    float x = 0;
    printf("Anna veroprosentti: ");
    scanf("%f", &x);
    return x;
}

float tuloraja() {
    float x = 0;
    printf("Anna tuloraja: ");
    scanf("%f", &x);
    return x;
}

float veroprosentti_korkea() {
    float x = 0;
    printf("Anna korkea veroprosentti tulorajan ylittaville tuloille: ");
    scanf("%f", &x);
    return x;
}
