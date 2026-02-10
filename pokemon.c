#include <stdio.h>

#define NAME_MAX_LEN 32
#define TYPE_MAX_LEN 20
#define MAX_POKEMON 100

typedef struct poke_struct {
    int id;
    char name[NAME_MAX_LEN];
    char type[TYPE_MAX_LEN];
} pokemon;

void print_all(pokemon *pokelist);

int main(void) {
    pokemon poke_list[MAX_POKEMON];
    // Tapa 1
    struct poke_struct caterpie = {10, "Caterpie", "Bug"};

    // Tapa 2
    pokemon pikachu = {25, "Pikachu", "Electric"};

    // Tapa 3
    pokemon ekans = {.id = 23, .name = "Ekans", .type = "Poison"};

    // Lopetus  (Huom nimi ja tyyppi tyhjiä)
    pokemon none = {0, "", ""};

    poke_list[0] = caterpie;
    poke_list[1] = pikachu;
    poke_list[2] = ekans;
    poke_list[3] = none;

    print_all(poke_list);
    return 0;
}

void print_all(pokemon *poke_list) {
    for (int i = 0; poke_list[i].id != 0; i++) {
        if (poke_list[i].id != 0) {
            printf("ID: %d, name: %s, type: %s\n", poke_list[i].id, poke_list[i].name, poke_list[i].type);
        }
    }
}
