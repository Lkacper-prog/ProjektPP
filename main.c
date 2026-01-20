#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dino.h"
#include "file_manager.h"
#include "utils.h"

int main(int argc, char *argv[]) {
    char plik[99];
    if (argc == 1) {
        printf("Nie podano pliku, zapisywanie i odczyt od standardowego dane.csv\n");
        strcpy(plik , "dane.csv");
    }else if (argc == 2) {
        strcpy(plik,argv[1]);
    }else {
        printf(" Zła ilość argumentów wywołania funkcji,zapisywanie i odczyt od standardowego dane.csv");
        strcpy(plik,"dane.csv");
    }
    Node *glowa = NULL;
    int opcja = -1;
    while (opcja != 10) {
        wyswietl_menu();
        opcja = pobieranie_opcji_menu();
        switch (opcja) {
            case 0:
                wczytaj_liste_plik(&glowa,plik);
                break;
            case 1:
                Dino dino = pobierz_dane_dinozaur();
                dodaj_dinozaura(&glowa, dino);
                break;
            case 2:
                usun_dinozaura(&glowa);
                break;
            case 3:
                usun_dinozaury(&glowa);
                break;
            case 4:
                wyszukaj_dinozaury(glowa);
                break;
            case 5:
                wyswietl_liste(glowa);
                break;
            case 6:
                edytuj_dinozaura(&glowa);
                break;
            case 7:
                sortuj_dinozaury(&glowa);
                break;
            case 8:
                zapisz_liste(glowa,plik);
                break;
            case 9:
                zwolnij_liste(&glowa);
                break;
                case 10:
                opcja = 10;
                break;
        }
    }
    zwolnij_liste(&glowa);
    return 0;
}
