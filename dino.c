#include "dino.h"

#include <stdlib.h>



void dodaj_dinozaura(Node** head,Dino dane) {

}



void wyswietl_liste(Node* head) {

}



void usun_dinozaura(Node** glowa, int indeks_lub_kryterium) {

}




void zwolnij_liste(Node** glowa) {
    Node* obecny = *glowa;
    Node* nastepny_node;

    while (obecny != NULL) {
        nastepny_node = obecny->nastepny;

        free(obecny);

        obecny = nastepny_node;
    }

    *glowa = NULL;
}