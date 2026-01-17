#include "dino.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

const char *dieta_na_napis(enum dieta d) {
    if (d == miesozerny) {
        return "Miesozerny";
    } else if (d == roslinozerny) {
        return "Roslinozerny";
    } else if (d == wszystkozerny) {
        return "Wszystkozerny";
    } else {
        return "Nieznana";
    }
}

const char *temperament_na_napis(enum temperament t) {
    if (t == spokojny) {
        return "Spokojny";
    } else if (t == reaktywny) {
        return "Reaktywny";
    } else if (t == agresywny) {
        return "Agresywny";
    } else if (t == nieprzewidywalny) {
        return "Nieprzewidywalny";
    } else {
        return "Nieznany";
    }
}

const char *status_na_napis(enum status_bezpieczenstwa s) {
    if (s == bezpieczny) {
        return "Bezpieczny";
    } else if (s == pod_obserwacja) {
        return "Pod obserwacja";
    } else if (s == awaryjna_kwarantanna) {
        return "Awaryjna kwarantanna";
    } else if (s == zagrozenie) {
        return "Zagrozenie";
    } else if (s == ucieczka) {
        return "UCIECZKA!";
    } else {
        return "Nieznany";
    }
}

void usuwanie_dinozaura_gatunek(Node **glowa, char gatunek[101]) {
    if (*glowa == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }
    Node *wczesniejszy = NULL;
    Node *obecny = *glowa;
    if (strcmp(obecny->dane.gatunek, gatunek) == 0) {
        *glowa = obecny->nastepny;
        free(obecny);
        printf("usnięto pierwszy element");
        return;
    }
    wczesniejszy = obecny;
    obecny = obecny->nastepny;
    while (obecny != NULL) {
        if (strcmp(obecny->dane.gatunek, gatunek) == 0) {
            wczesniejszy->nastepny = obecny->nastepny;
            free(obecny);
            printf("usunięto element ze środka");
            break;
        }
        wczesniejszy = obecny;
        obecny = obecny->nastepny;
    }
}

void usuwanie_dinozaura_dieta(Node **glowa, enum dieta dieta) {
    if (*glowa == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }
    Node *wczesniejszy = NULL;
    Node *obecny = *glowa;
    if (obecny->dane.dieta == dieta) {
        *glowa = obecny->nastepny;
        free(obecny);
        printf("usnięto pierwszy element");
        return;
    }
    wczesniejszy = obecny;
    obecny = obecny->nastepny;
    while (obecny != NULL) {
        if (obecny->dane.dieta == dieta) {
            wczesniejszy->nastepny = obecny->nastepny;
            free(obecny);
            printf("usunięto element ze środka");
            break;
        }
        wczesniejszy = obecny;
        obecny = obecny->nastepny;
    }
}

void usuwanie_dinozaura_masa(Node **glowa, double masa) {
    if (*glowa == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }
    Node *wczesniejszy = NULL;
    Node *obecny = *glowa;
    if (obecny->dane.masa == masa) {
        *glowa = obecny->nastepny;
        free(obecny);
        printf("usnięto pierwszy element");
        return;
    }
    wczesniejszy = obecny;
    obecny = obecny->nastepny;
    while (obecny != NULL) {
        if (obecny->dane.masa == masa) {
            wczesniejszy->nastepny = obecny->nastepny;
            free(obecny);
            printf("usunięto element ze środka");
            break;
        }
        wczesniejszy = obecny;
        obecny = obecny->nastepny;
    }
}

void usuwanie_dinozaura_zagroda(Node **glowa, char zagroda[41]) {
    if (*glowa == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }
    Node *wczesniejszy = NULL;
    Node *obecny = *glowa;
    if (strcmp(obecny->dane.zagroda, zagroda) == 0) {
        *glowa = obecny->nastepny;
        free(obecny);
        printf("usnięto pierwszy element");
        return;
    }
    wczesniejszy = obecny;
    obecny = obecny->nastepny;
    while (obecny != NULL) {
        if (strcmp(obecny->dane.zagroda, zagroda) == 0) {
            wczesniejszy->nastepny = obecny->nastepny;
            free(obecny);
            printf("usunięto element ze środka");
            break;
        }
        wczesniejszy = obecny;
        obecny = obecny->nastepny;
    }
}

void usuwanie_dinozaura_temperament(Node **glowa, enum temperament temperament) {
    if (*glowa == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }
    Node *wczesniejszy = NULL;
    Node *obecny = *glowa;
    if (obecny->dane.temperament == temperament) {
        *glowa = obecny->nastepny;
        free(obecny);
        printf("usnięto pierwszy element");
        return;
    }
    wczesniejszy = obecny;
    obecny = obecny->nastepny;
    while (obecny != NULL) {
        if (obecny->dane.temperament == temperament) {
            wczesniejszy->nastepny = obecny->nastepny;
            free(obecny);
            printf("usunięto element ze środka");
            break;
        }
        wczesniejszy = obecny;
        obecny = obecny->nastepny;
    }
}

void usuwanie_dinozaurow_gatunek(Node **glowa, char gatunek[101]) {
    int ilosc_usunietych = 0;
    if (*glowa == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }
    while (*glowa != NULL && strcmp((*glowa)->dane.gatunek, gatunek) == 0) {
        Node *do_usuniecia = *glowa;
        *glowa = (*glowa)->nastepny;
        free(do_usuniecia);
        ilosc_usunietych++;
    }
    if (*glowa == NULL) {
        printf("usunięto %d elementów\n", ilosc_usunietych);
        return;
    }
    Node *wczesniejszy = *glowa;
    Node *obecny = wczesniejszy->nastepny;

    while (obecny != NULL) {
        if (strcmp(obecny->dane.gatunek, gatunek) == 0) {
            Node *do_usuniecia = obecny;
            wczesniejszy->nastepny = obecny->nastepny;
            obecny = obecny->nastepny;
            free(do_usuniecia);
            ilosc_usunietych++;
        } else {
            wczesniejszy = obecny;
            obecny = obecny->nastepny;
        }
    }
    printf("usunięto %d elementów\n", ilosc_usunietych);
}

void usuwanie_dinozaurow_dieta(Node **glowa, enum dieta dieta) {
    int ilosc_usunietych = 0;
    if (*glowa == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }
    while (*glowa != NULL && (*glowa)->dane.dieta == dieta) {
        Node *do_usuniecia = *glowa;
        *glowa = (*glowa)->nastepny;
        free(do_usuniecia);
        ilosc_usunietych++;
    }
    if (*glowa == NULL) {
        printf("usunięto %d elementów\n", ilosc_usunietych);
        return;
    }
    Node *wczesniejszy = *glowa;
    Node *obecny = wczesniejszy->nastepny;

    while (obecny != NULL) {
        if (obecny->dane.dieta == dieta) {
            Node *do_usuniecia = obecny;
            wczesniejszy->nastepny = obecny->nastepny;
            obecny = obecny->nastepny;
            free(do_usuniecia);
            ilosc_usunietych++;
        } else {
            wczesniejszy = obecny;
            obecny = obecny->nastepny;
        }
    }
    printf("usunięto %d elementów\n", ilosc_usunietych);
}

void usuwanie_dinozaurow_masa(Node **glowa, double masa) {
    int ilosc_usunietych = 0;
    if (*glowa == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }
    while (*glowa != NULL && (*glowa)->dane.masa == masa) {
        Node *do_usuniecia = *glowa;
        *glowa = (*glowa)->nastepny;
        free(do_usuniecia);
        ilosc_usunietych++;
    }
    if (*glowa == NULL) {
        printf("usunięto %d elementów \n", ilosc_usunietych);
        return;
    }
    Node *wczesniejszy = *glowa;
    Node *obecny = wczesniejszy->nastepny;

    while (obecny != NULL) {
        if (obecny->dane.masa == masa) {
            Node *do_usuniecia = obecny;
            wczesniejszy->nastepny = obecny->nastepny;
            obecny = obecny->nastepny;
            free(do_usuniecia);
            ilosc_usunietych++;
        } else {
            wczesniejszy = obecny;
            obecny = obecny->nastepny;
        }
    }
    printf("usunięto %d elementów \n", ilosc_usunietych);
}

void usuwanie_dinozaurow_zagroda(Node **glowa, char zagroda[41]) {
    int ilosc_usunietych = 0;
    if (*glowa == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }
    while (*glowa != NULL && strcmp((*glowa)->dane.zagroda, zagroda) == 0) {
        Node *do_usuniecia = *glowa;
        *glowa = (*glowa)->nastepny;
        free(do_usuniecia);
        ilosc_usunietych++;
    }
    if (*glowa == NULL) {
        printf("usunięto %d elementów\n", ilosc_usunietych);
        return;
    }
    Node *wczesniejszy = *glowa;
    Node *obecny = wczesniejszy->nastepny;

    while (obecny != NULL) {
        if (strcmp(obecny->dane.zagroda, zagroda) == 0) {
            Node *do_usuniecia = obecny;
            wczesniejszy->nastepny = obecny->nastepny;
            obecny = obecny->nastepny;
            free(do_usuniecia);
            ilosc_usunietych++;
        } else {
            wczesniejszy = obecny;
            obecny = obecny->nastepny;
        }
    }
    printf("usunięto %d elementów\n", ilosc_usunietych);
}

void usuwanie_dinozaurow_temperament(Node **glowa, enum temperament temperament) {
    int ilosc_usunietych = 0;
    if (*glowa == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }
    while (*glowa != NULL && (*glowa)->dane.temperament == temperament) {
        Node *do_usuniecia = *glowa;
        *glowa = (*glowa)->nastepny;
        free(do_usuniecia);
        ilosc_usunietych++;
    }
    if (*glowa == NULL) {
        printf("usunięto %d elementów\n", ilosc_usunietych);
        return;
    }
    Node *wczesniejszy = *glowa;
    Node *obecny = wczesniejszy->nastepny;

    while (obecny != NULL) {
        if (obecny->dane.temperament == temperament) {
            Node *do_usuniecia = obecny;
            wczesniejszy->nastepny = obecny->nastepny;
            obecny = obecny->nastepny;
            free(do_usuniecia);
            ilosc_usunietych++;
        } else {
            wczesniejszy = obecny;
            obecny = obecny->nastepny;
        }
    }
    printf("usunięto %d elementów\n", ilosc_usunietych);
}

void dodaj_dinozaura(Node **glowa, Dino dane) {
    Node *nowe_miejsce_na_dino = malloc(sizeof(Node));
    nowe_miejsce_na_dino->dane = dane;
    nowe_miejsce_na_dino->nastepny = NULL;
    if (*glowa == NULL) {
        *glowa = nowe_miejsce_na_dino;
    } else {
        Node *obecny = *glowa;
        while (obecny->nastepny != NULL) {
            obecny = obecny->nastepny;
        }
        obecny->nastepny = nowe_miejsce_na_dino;
    }
}

void wyswietl_liste(Node *glowa) {
    Node *obecny = glowa;
    if (obecny == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }

    printf("--- Lista Dinozaurow ---\n");

    while (obecny != NULL) {
        const char *dieta = dieta_na_napis(obecny->dane.dieta);
        const char *temperament = temperament_na_napis(obecny->dane.temperament);
        const char *status = status_na_napis(obecny->dane.status_bezpieczenstwa);

        printf("Gatunek: %s\n", obecny->dane.gatunek);
        printf(" Dieta: %s\n", dieta);
        printf(" Masa: %f\n", obecny->dane.masa);
        printf(" Zagroda: %s\n", obecny->dane.zagroda);
        printf(" Temperament: %s\n", temperament);
        printf(" Status: %s\n", status);
        printf("------------------------\n");

        obecny = obecny->nastepny;
    }
}

void usun_dinozaura(Node **glowa) {
    int kryterium = pobieranie_opcji_usuwania();
    switch (kryterium) {
        case 0: {
            char *string = pobieranie_stringa_gatunek();
            usuwanie_dinozaura_gatunek(glowa, string);
            free(string);
            break;
        }
        case 1: {
            enum dieta dieta = pobieranie_enuma_dieta();
            usuwanie_dinozaura_dieta(glowa, dieta);
            break;
        }
        case 2: {
            double masa = pobieranie_masy();
            usuwanie_dinozaura_masa(glowa, masa);
            break;
        }
        case 3: {
            char *string = pobieranie_stringa_zagroda();
            usuwanie_dinozaura_zagroda(glowa, string);
            free(string);
            break;
        }
        case 4: {
            enum temperament temperament = pobieranie_enuma_temperament();
            usuwanie_dinozaura_temperament(glowa, temperament);
            break;
        }
    }
}

void zwolnij_liste(Node **glowa) {
    Node *obecny = *glowa;
    Node *nastepny_node;

    while (obecny != NULL) {
        nastepny_node = obecny->nastepny;

        free(obecny);

        obecny = nastepny_node;
    }

    *glowa = NULL;
}

void usun_dinozaury(Node **glowa) {
    int kryterium = pobieranie_opcji_usuwania();
    switch (kryterium) {
        case 0: {
            char *string = pobieranie_stringa_gatunek();
            usuwanie_dinozaurow_gatunek(glowa, string);
            free(string);
            break;
        }
        case 1: {
            enum dieta dieta = pobieranie_enuma_dieta();
            usuwanie_dinozaurow_dieta(glowa, dieta);
            break;
        }
        case 2: {
            double masa = pobieranie_masy();
            usuwanie_dinozaurow_masa(glowa, masa);
            break;
        }
        case 3: {
            char *string = pobieranie_stringa_zagroda();
            usuwanie_dinozaurow_zagroda(glowa, string);
            free(string);
            break;
        }
        case 4: {
            enum temperament temperament = pobieranie_enuma_temperament();
            usuwanie_dinozaurow_temperament(glowa, temperament);
            break;
        }
    }
}
