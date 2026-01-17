#include "file_manager.h"
#include <stdio.h>
#include <string.h>
#include "dino.h"


void wczytaj_liste_plik(Node **glowa, char plik[100]) {
    FILE *otwarty_plik = fopen(plik, "r");
    if (otwarty_plik == NULL) {
        printf("Plik się nie otworzył lub nie istnieje\n");
        return;
    }
    zwolnij_liste(glowa);
    char gatunek[101];
    int dieta_int;
    double masa;
    char zagroda[41];
    int temperament_int;
    int status_bezpieczenstwa_int;
    while (fscanf(otwarty_plik, " %100[^,],%d,%lf,%40[^,],%d,%d", gatunek, &dieta_int, &masa, zagroda, &temperament_int,
                  &status_bezpieczenstwa_int) == 6) {
        Dino dino;
        strcpy(dino.gatunek, gatunek);
        strcpy(dino.zagroda, zagroda);
        dino.dieta = dieta_int;
        dino.masa = masa;
        dino.temperament = temperament_int;
        dino.status_bezpieczenstwa = status_bezpieczenstwa_int;
        dodaj_dinozaura(glowa, dino);
    }
    printf("wczytano dane z pliku\n");
    fclose(otwarty_plik);
}


void zapisz_liste(Node *glowa, char plik[100]) {
    FILE *otwarty_plik = fopen(plik, "w");
    if (otwarty_plik == NULL) {
        printf("pliku nie można otworzzyć");
        return;
    }
    Node *obecny = glowa;
    while (obecny != NULL) {
        fprintf(otwarty_plik, "%s,%d,%.2lf,%s,%d,%d\n", obecny->dane.gatunek, obecny->dane.dieta, obecny->dane.masa,
                obecny->dane.zagroda, obecny->dane.temperament, obecny->dane.status_bezpieczenstwa);
        obecny = obecny->nastepny;
    }
    printf("zapisano dane do pliku \n");
    fclose(otwarty_plik);
}
