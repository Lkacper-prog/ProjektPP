#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dino.h"

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

int pobieranie_opcji_menu() {
    // w trakcie
    int opcja;
    int petla = 1;
    while (petla != 0) {
        if (scanf("%d", &opcja) == 1) {
            if (opcja >= 0 && opcja <= 9) {
                return opcja;
            } else {
                printf("Błąd: Wybierz liczbę od 0 do 9!\n");
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

int pobieranie_enuma_status_bezpieczenstwa() {
    int opcja;
    int petla = 1;
    while (petla != 0) {
        printf("Wybierz temperament:\n"
            " 0: bezpieczny\n"
            " 1: pod_obserwacja\n"
            " 2: awaryjny_kwarantanna\n"
            " 3: zagrozenie\n"
            " 4: ucieczka\n"
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

char *pobieranie_stringa_gatunek() {
    char *napis = malloc(101 * sizeof(char));
    if (napis == NULL) {
        printf("BŁĄD: Nie udało się przydzielić pamięci.\n");
        return NULL;
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
    char *napis = malloc(41 * sizeof(char));
    if (napis == NULL) {
        printf("BŁĄD: Nie udało się przydzielić pamięci\n");
        return NULL;
    }
    printf("Podaj nazwę: ");
    scanf("%40s", napis);

    return napis;
}

void wyswietl_menu() {
    printf("----------------\n");
    printf(" System Zarządzania Parkiem Dinozaurów\n");
    printf("----------------\n");
    printf("opcje:\n"
        "0: Wczytaj Dinozaury z pliku\n"
        "1: Dodaj Dinozaura \n"
        "2: usuń dinozaura\n"
        "3: usuń dinozaury\n"
        "4: wyszukaj dinozaury\n"
        "5: wyswietl liste\n"
        "6: edytuj dinozaura\n"
        "7: posortuj dinozaury\n"
        "8: zapisz dinozaury do pliku\n"
        "9: zakończ działanie programu\n");
}

Dino pobierz_dane_dinozaur() {
    Dino dino;
    char *gatunek = NULL;
    char *zagroda= NULL;
    printf("podaj gatunek dinozaura:\n");
    while (gatunek == NULL) {
        gatunek = pobieranie_stringa_gatunek();
    }
    strcpy(dino.gatunek, gatunek);
    free(gatunek);
    dino.dieta = pobieranie_enuma_dieta();
    dino.masa = pobieranie_masy();
    while (zagroda == NULL) {
        zagroda = pobieranie_stringa_zagroda();
    }
    strcpy(dino.zagroda, zagroda);
    free(zagroda);
    dino.temperament = pobieranie_enuma_temperament();
    dino.status_bezpieczenstwa = pobieranie_enuma_status_bezpieczenstwa();
    return dino;
}

