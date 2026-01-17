#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

int pobieranie_opcji_usuwania() {
    int opcja;
    int petla = 1;
    while (petla != 0) {
        printf("Wybierz opcję usuwania:\n"
            " 0: Gatunek\n"
            " 1: Dieta\n"
            " 2: Masa\n"
            " 3: Zagroda\n"
            " 4: Temperament\n"
            "Wybor: ");

        if (scanf("%d", &opcja) == 1) {
            if (opcja >= 0 && opcja <= 4) {
                return opcja;
            } else {
                printf("Błąd: Wybierz liczbę od 0 do 4!\n");
            }
        } else {
            printf("Błąd: To nie jest liczba!\n");
            while (getchar() != '\n');
        }
        printf("\n");
    }
}

int pobieranie_enuma_dieta() {
    int opcja;
    int petla = 1;
    while (petla != 0) {
        printf("Wybierz dietę:\n"
            " 0: Mięsożerny\n"
            " 1: Roślinożerny\n"
            " 2: Wszystkożerny\n"
            "Wybor: ");

        if (scanf("%d", &opcja) == 1) {
            if (opcja >= 0 && opcja <= 2) {
                return opcja;
            } else {
                printf("Błąd: Wybierz liczbę od 0 do 2!\n");
            }
        } else {
            printf("Błąd: To nie jest liczba!\n");
            while (getchar() != '\n');
        }
        printf("\n");
    }
}

int pobieranie_enuma_temperament() {
    int opcja;
    int petla = 1;
    while (petla != 0) {
        printf("Wybierz temperament:\n"
            " 0: spokojny\n"
            " 1: reaktywny\n"
            " 2: agresywny\n"
            " 3: nieprzewidywalny\n"
            "Wybor: ");

        if (scanf("%d", &opcja) == 1) {
            if (opcja >= 0 && opcja <= 3) {
                return opcja;
            } else {
                printf("Błąd: Wybierz liczbę od 0 do 3!\n");
            }
        } else {
            printf("Błąd: To nie jest liczba!\n");
            while (getchar() != '\n');
        }
        printf("\n");
    }
}

char *pobieranie_stringa_gatunek() {
    char *napis = malloc(100 * sizeof(char));
    if (napis == NULL) {
        printf("Błąd pamięci!\n");
    }
    printf("Podaj nazwę: ");
    scanf("%100s", napis);

    return napis;
}

double pobieranie_masy() {
    double masa;
    printf("podaj masę ");
    while (scanf("%lf", &masa) != 1) {
        printf("podaj ponowonie liczbę");
        while (getchar() != '\n');
    };
    return masa;
}

char *pobieranie_stringa_zagroda() {
    char *napis = malloc(40 * sizeof(char));
    if (napis == NULL) {
        printf("Błąd pamięci!\n");
    }
    printf("Podaj nazwę: ");
    scanf("%40s", napis);

    return napis;
}
