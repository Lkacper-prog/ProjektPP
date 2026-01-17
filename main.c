#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dino.h"
#include "file_manager.h"
#include "utils.h"

int main(void) {
    Node **glowa = NULL;
    int opcja = -1;
    while (opcja != 9) {
        wyswietl_menu();
        opcja = pobieranie_opcji_menu();
        switch (opcja) {
            case 0:
                wczytaj_liste_plik(glowa);
                break;
            case 1:
                Dino dino = pobierz_dane_dinozaur();
                dodaj_dinozaura(glowa, dino);
                break;
            case 2:
                usun_dinozaura(glowa);
                break;
            case 3:
                usun_dinozaury(glowa);
                break;
            case 4:
                wyszukaj_dinozaury(*glowa);
                break;
            case 5:
                wyswietl_liste(*glowa);
                break;
            case 6:
                edytuj_dinozaura(glowa);
                break;
            case 7:
                sortuj_dinozaury(glowa);
                break;
            case 8:
                zapisz_liste(*glowa);
                break;
            case 9:
                opcja = 9;
                break;
        }
    }
    return 0;
}
