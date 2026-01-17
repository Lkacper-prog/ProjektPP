#include <stdio.h>
#include <stdlib.h>
#include "dino.h"
#include "file_manager.h"
#include "utils.h"

int main(int argc, char *argv[]) {
    Node *glowa = NULL;
    int opcja = -1;
    while (opcja != 10) {
        wyswietl_menu();
        opcja = pobieranie_opcji_menu();
        switch (opcja) {
            case 0:
                wczytaj_liste_plik(&glowa);
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
                zapisz_liste(glowa);
                break;
            case 9:
                zwolnij_liste(&glowa);
                break;
                case 10:
                opcja = 10;
                break;
        }
    }
    free(glowa);
    return 0;
}
