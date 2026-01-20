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
    if (strcmp(obecny->dane.gatunek, gatunek) == 0 && (
            obecny->dane.status_bezpieczenstwa != ucieczka && obecny->dane.status_bezpieczenstwa != zagrozenie)) {
        *glowa = obecny->nastepny;
        free(obecny);
        printf("usnieto pierwszy element\n");
        return;
    }
    wczesniejszy = obecny;
    obecny = obecny->nastepny;
    while (obecny != NULL) {
        if (strcmp(obecny->dane.gatunek, gatunek) == 0) {
            if (obecny->dane.status_bezpieczenstwa == ucieczka || obecny->dane.status_bezpieczenstwa == zagrozenie) {
                wczesniejszy = obecny;
                obecny = obecny->nastepny;
                continue;
            }
            wczesniejszy->nastepny = obecny->nastepny;
            free(obecny);
            printf("usunieto element ze srodka\n");
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
    if (obecny->dane.dieta == dieta && (obecny->dane.status_bezpieczenstwa != ucieczka && obecny->dane.
                                        status_bezpieczenstwa != zagrozenie)) {
        *glowa = obecny->nastepny;
        free(obecny);
        printf("usnieto pierwszy element\n");
        return;
    }
    wczesniejszy = obecny;
    obecny = obecny->nastepny;
    while (obecny != NULL) {
        if (obecny->dane.dieta == dieta) {
            if (obecny->dane.status_bezpieczenstwa == ucieczka || obecny->dane.status_bezpieczenstwa == zagrozenie) {
                wczesniejszy = obecny;
                obecny = obecny->nastepny;
                continue;
            }
            wczesniejszy->nastepny = obecny->nastepny;
            free(obecny);
            printf("usunieto element ze srodka\n");
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
    if (obecny->dane.masa == masa && (obecny->dane.status_bezpieczenstwa != ucieczka && obecny->dane.
                                      status_bezpieczenstwa != zagrozenie)) {
        *glowa = obecny->nastepny;
        free(obecny);
        printf("usnieto pierwszy element\n");
        return;
    }
    wczesniejszy = obecny;
    obecny = obecny->nastepny;
    while (obecny != NULL) {
        if (obecny->dane.masa == masa) {
            if (obecny->dane.status_bezpieczenstwa == ucieczka || obecny->dane.status_bezpieczenstwa == zagrozenie) {
                wczesniejszy = obecny;
                obecny = obecny->nastepny;
                continue;
            }
            wczesniejszy->nastepny = obecny->nastepny;
            free(obecny);
            printf("usunieto element ze środka\n");
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
    if (strcmp(obecny->dane.zagroda, zagroda) == 0 && (
            obecny->dane.status_bezpieczenstwa != ucieczka && obecny->dane.status_bezpieczenstwa != zagrozenie)) {
        *glowa = obecny->nastepny;
        free(obecny);
        printf("usnieto pierwszy element\n");
        return;
    }
    wczesniejszy = obecny;
    obecny = obecny->nastepny;
    while (obecny != NULL) {
        if (strcmp(obecny->dane.zagroda, zagroda) == 0) {
            if (obecny->dane.status_bezpieczenstwa == ucieczka || obecny->dane.status_bezpieczenstwa == zagrozenie) {
                wczesniejszy = obecny;
                obecny = obecny->nastepny;
                continue;
            }
            wczesniejszy->nastepny = obecny->nastepny;
            free(obecny);
            printf("usunieto element ze srodka\n");
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
    if (obecny->dane.temperament == temperament && (
            obecny->dane.status_bezpieczenstwa != ucieczka && obecny->dane.status_bezpieczenstwa != zagrozenie)) {
        *glowa = obecny->nastepny;
        free(obecny);
        printf("usnieto pierwszy element\n");
        return;
    }
    wczesniejszy = obecny;
    obecny = obecny->nastepny;
    while (obecny != NULL) {
        if (obecny->dane.temperament == temperament) {
            if (obecny->dane.status_bezpieczenstwa == ucieczka || obecny->dane.status_bezpieczenstwa == zagrozenie) {
                wczesniejszy = obecny;
                obecny = obecny->nastepny;
                continue;
            }
            wczesniejszy->nastepny = obecny->nastepny;
            free(obecny);
            printf("usunieto element ze środka\n");
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
    while (*glowa != NULL && strcmp((*glowa)->dane.gatunek, gatunek) == 0 && (
               (*glowa)->dane.status_bezpieczenstwa != ucieczka && (*glowa)->dane.status_bezpieczenstwa !=
               zagrozenie)) {
        Node *do_usuniecia = *glowa;
        *glowa = (*glowa)->nastepny;
        free(do_usuniecia);
        ilosc_usunietych++;
    }
    if (*glowa == NULL) {
        printf("usunieto %d elementow\n", ilosc_usunietych);
        return;
    }
    Node *wczesniejszy = *glowa;
    Node *obecny = wczesniejszy->nastepny;

    while (obecny != NULL) {
        if (strcmp(obecny->dane.gatunek, gatunek) == 0) {
            if (obecny->dane.status_bezpieczenstwa == ucieczka || obecny->dane.status_bezpieczenstwa == zagrozenie) {
                wczesniejszy = obecny;
                obecny = obecny->nastepny;
                continue;
            }
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
    printf("usunieto %d elementow\n", ilosc_usunietych);
}

void usuwanie_dinozaurow_dieta(Node **glowa, enum dieta dieta) {
    int ilosc_usunietych = 0;
    if (*glowa == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }
    while (*glowa != NULL && (*glowa)->dane.dieta == dieta && (
               (*glowa)->dane.status_bezpieczenstwa != ucieczka && (*glowa)->dane.status_bezpieczenstwa !=
               zagrozenie)) {
        Node *do_usuniecia = *glowa;
        *glowa = (*glowa)->nastepny;
        free(do_usuniecia);
        ilosc_usunietych++;
    }
    if (*glowa == NULL) {
        printf("usunieto %d elementow\n", ilosc_usunietych);
        return;
    }
    Node *wczesniejszy = *glowa;
    Node *obecny = wczesniejszy->nastepny;

    while (obecny != NULL) {
        if (obecny->dane.dieta == dieta) {
            if (obecny->dane.status_bezpieczenstwa == ucieczka || obecny->dane.status_bezpieczenstwa == zagrozenie) {
                wczesniejszy = obecny;
                obecny = obecny->nastepny;
                continue;
            }
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
    printf("usunieto %d elementow\n", ilosc_usunietych);
}

void usuwanie_dinozaurow_masa(Node **glowa, double masa) {
    int ilosc_usunietych = 0;
    if (*glowa == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }
    while (*glowa != NULL && (*glowa)->dane.masa == masa && (
               (*glowa)->dane.status_bezpieczenstwa != ucieczka && (*glowa)->dane.status_bezpieczenstwa !=
               zagrozenie)) {
        Node *do_usuniecia = *glowa;
        *glowa = (*glowa)->nastepny;
        free(do_usuniecia);
        ilosc_usunietych++;
    }
    if (*glowa == NULL) {
        printf("usunieto %d elementow \n", ilosc_usunietych);
        return;
    }
    Node *wczesniejszy = *glowa;
    Node *obecny = wczesniejszy->nastepny;

    while (obecny != NULL) {
        if (obecny->dane.masa == masa) {
            if (obecny->dane.status_bezpieczenstwa == ucieczka || obecny->dane.status_bezpieczenstwa == zagrozenie) {
                wczesniejszy = obecny;
                obecny = obecny->nastepny;
                continue;
            }
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
    printf("usunieto %d elementow \n", ilosc_usunietych);
}

void usuwanie_dinozaurow_zagroda(Node **glowa, char zagroda[41]) {
    int ilosc_usunietych = 0;
    if (*glowa == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }
    while (*glowa != NULL && strcmp((*glowa)->dane.zagroda, zagroda) == 0 && (
               (*glowa)->dane.status_bezpieczenstwa != ucieczka && (*glowa)->dane.status_bezpieczenstwa !=
               zagrozenie)) {
        Node *do_usuniecia = *glowa;
        *glowa = (*glowa)->nastepny;
        free(do_usuniecia);
        ilosc_usunietych++;
    }
    if (*glowa == NULL) {
        printf("usunieto %d elementew\n", ilosc_usunietych);
        return;
    }
    Node *wczesniejszy = *glowa;
    Node *obecny = wczesniejszy->nastepny;

    while (obecny != NULL) {
        if (strcmp(obecny->dane.zagroda, zagroda) == 0) {
            if (obecny->dane.status_bezpieczenstwa == ucieczka || obecny->dane.status_bezpieczenstwa == zagrozenie) {
                wczesniejszy = obecny;
                obecny = obecny->nastepny;
                continue;
            }
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
    printf("usunieto %d elementew\n", ilosc_usunietych);
}

void usuwanie_dinozaurow_temperament(Node **glowa, enum temperament temperament) {
    int ilosc_usunietych = 0;
    if (*glowa == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }
    while (*glowa != NULL && (*glowa)->dane.temperament == temperament && (
               (*glowa)->dane.status_bezpieczenstwa != ucieczka && (*glowa)->dane.status_bezpieczenstwa !=
               zagrozenie)) {
        Node *do_usuniecia = *glowa;
        *glowa = (*glowa)->nastepny;
        free(do_usuniecia);
        ilosc_usunietych++;
    }
    if (*glowa == NULL) {
        printf("usunieto %d elementow\n", ilosc_usunietych);
        return;
    }
    Node *wczesniejszy = *glowa;
    Node *obecny = wczesniejszy->nastepny;

    while (obecny != NULL) {
        if (obecny->dane.temperament == temperament) {
            if (obecny->dane.status_bezpieczenstwa == ucieczka || obecny->dane.status_bezpieczenstwa == zagrozenie) {
                wczesniejszy = obecny;
                obecny = obecny->nastepny;
                continue;
            }
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
    printf("usunieto %d elementow\n", ilosc_usunietych);
}

void wyszukaj_dinozaury_masa(Node *glowa, double masa) {
    Node *obecny = glowa;
    int znaleziono = 0;

    if (obecny == NULL) {
        printf("Lista jest pusta, nie ma czego szukac.\n");
        return;
    }

    printf("--- Wyniki wyszukiwania dla masy: %.2lf ---\n", masa);

    while (obecny != NULL) {
        if (obecny->dane.masa == masa) {
            const char *dieta = dieta_na_napis(obecny->dane.dieta);
            const char *temperament = temperament_na_napis(obecny->dane.temperament);
            const char *status = status_na_napis(obecny->dane.status_bezpieczenstwa);

            printf("Gatunek: %s\n", obecny->dane.gatunek);
            printf(" Dieta: %s\n", dieta);
            printf(" Masa: %.2lf\n", obecny->dane.masa);
            printf(" Zagroda: %s\n", obecny->dane.zagroda);
            printf(" Temperament: %s\n", temperament);
            printf(" Status: %s\n", status);
            printf("------------------------\n");

            znaleziono = 1;
        }
        obecny = obecny->nastepny;
    }

    if (!znaleziono) {
        printf("Nie znaleziono zadnego dinozaura o podanej masie.\n");
    }
}

void wyszukaj_dinozaury_gatunek(Node *glowa, char gatunek[101]) {
    Node *obecny = glowa;
    int znaleziono = 0;

    if (obecny == NULL) {
        printf("Lista jest pusta, nie ma czego szukac.\n");
        return;
    }

    printf("--- Wyniki wyszukiwania dla stringa: %s ---\n", gatunek);

    while (obecny != NULL) {
        if (strstr(obecny->dane.gatunek, gatunek) != NULL) {
            const char *dieta = dieta_na_napis(obecny->dane.dieta);
            const char *temperament = temperament_na_napis(obecny->dane.temperament);
            const char *status = status_na_napis(obecny->dane.status_bezpieczenstwa);

            printf("Gatunek: %s\n", obecny->dane.gatunek);
            printf(" Dieta: %s\n", dieta);
            printf(" Masa: %.2lf\n", obecny->dane.masa);
            printf(" Zagroda: %s\n", obecny->dane.zagroda);
            printf(" Temperament: %s\n", temperament);
            printf(" Status: %s\n", status);
            printf("------------------------\n");

            znaleziono = 1;
        }
        obecny = obecny->nastepny;
    }

    if (!znaleziono) {
        printf("Nie znaleziono dinozaura pasującego do nazwy %s.\n", gatunek);
    }
}


void dodaj_dinozaura(Node **glowa, Dino dane) {
    Node *nowe_miejsce_na_dino = malloc(sizeof(Node));
    if (nowe_miejsce_na_dino == NULL) {
        printf("blad alokacji pamieci\n");
    }
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
        printf(" Masa: %.2lf\n", obecny->dane.masa);
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
            if (string == NULL) {
                printf("nie udalo sie pobrac stringa");
                break;
            }
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
            if (string == NULL) {
                printf("nie udalo sie pobrac stringa");
                break;
            }
            usuwanie_dinozaura_zagroda(glowa, string);
            free(string);
            break;
        }
        case 4: {
            enum temperament temperament = pobieranie_enuma_temperament();
            usuwanie_dinozaura_temperament(glowa, temperament);
            break;
        }
        default:
            printf("nie udalo sie wykonac");
            break;
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
            if (string == NULL) {
                printf("nie udalo sie pobrac stringa");
                break;
            }
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
            if (string == NULL) {
                printf("nie udalo sie pobrac stringa");
                break;
            }
            usuwanie_dinozaurow_zagroda(glowa, string);
            free(string);
            break;
        }
        case 4: {
            enum temperament temperament = pobieranie_enuma_temperament();
            usuwanie_dinozaurow_temperament(glowa, temperament);
            break;
        default:
            printf("nie udalo sie wykonac");
            break;
        }
    }
}


void edytuj_dinozaura(Node **glowa) {
    if (*glowa == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }
    printf("Podaj gatunek dinozaura do edycji:\n");
    char *szukany_gatunek = pobieranie_stringa_gatunek();
    if (szukany_gatunek == NULL) return;

    Node *obecny = *glowa;
    int znaleziono = 0;
    while (obecny != NULL) {
        if (strcmp(obecny->dane.gatunek, szukany_gatunek) == 0) {
            znaleziono = 1;
            printf("Edytujesz dinozaura: %s\n", obecny->dane.gatunek);
            printf("Co chcesz zmienic?\n 1. Mase\n 2. Zagrode\n 3. Temperament\n 4. Status\nWybor: ");
            int wybor = pobieranie_opcji_edycja();
            switch (wybor) {
                case 0:
                    obecny->dane.masa = pobieranie_masy();
                    break;
                case 1: {
                    char *nowa_zagroda = pobieranie_stringa_zagroda();
                        strcpy(obecny->dane.zagroda, nowa_zagroda);
                        free(nowa_zagroda);
                    break;
                }
                case 2:
                    obecny->dane.temperament = pobieranie_enuma_temperament();
                    break;
                case 3:
                    obecny->dane.status_bezpieczenstwa = pobieranie_enuma_status_bezpieczenstwa();
                    break;
                default:
                    printf("Niepoprawna opcja.\n");
            }
            printf("Dane zaktualizowane.\n");
            break;
        }
        obecny = obecny->nastepny;
    }

    if (!znaleziono) {
        printf("Nie znaleziono dinozaura o nazwie: %s\n", szukany_gatunek);
    }
    free(szukany_gatunek);
}

void sortuj_dinozaury(Node **glowa) {
    if (*glowa == NULL || (*glowa)->nastepny == NULL) {
        printf("Lista jest zbyt krotka, by ja sortowac.\n");
        return;
    }

    printf("Wybierz kryterium sortowania:\n"
           " 0: Gatunek (alfabetycznie)\n"
           " 1: Masa (rosnaco)\n"
           "Wybor: \n");
    int opcja = pobieranie_opcji_sortowania();

    int zamiana;
    Node *ptr1;
    Node *lptr = NULL;

    do {
        zamiana = 0;
        ptr1 = *glowa;

        while (ptr1->nastepny != lptr) {
            int trzeba_zamienic = 0;

            if (opcja == 0) {
                if (strcmp(ptr1->dane.gatunek, ptr1->nastepny->dane.gatunek) > 0) {
                    trzeba_zamienic = 1;
                }
            } else if (opcja == 1) {
                if (ptr1->dane.masa > ptr1->nastepny->dane.masa) {
                    trzeba_zamienic = 1;
                }
            }

            if (trzeba_zamienic) {
                Dino temp = ptr1->dane;
                ptr1->dane = ptr1->nastepny->dane;
                ptr1->nastepny->dane = temp;
                zamiana = 1;
            }
            ptr1 = ptr1->nastepny;
        }
        lptr = ptr1;
    } while (zamiana);

    printf("Lista zostala posortowana.\n");
}

void wyszukaj_dinozaury(Node *glowa) {
    printf("Po czym chcesz wyszukac dinozaura ?\n"
        "0: gatunek\n"
        "1: masa\n");
    int opcja = pobieranie_opcji_wyszukaj_dinozaura();
    switch (opcja) {
        case 1: {
            double masa = pobieranie_masy();
            wyszukaj_dinozaury_masa(glowa, masa);
            break;
        }
        case 0: {
            char *gatunek = pobieranie_stringa_gatunek();
            if (gatunek == NULL) {
                printf("nie udalo sie pobrac stringa");
                break;
            }
            wyszukaj_dinozaury_gatunek(glowa, gatunek);
            free(gatunek);
            break;
        }
        default: {
            printf("nie udalo sie wykonac");
            break;
        }
    }
}
