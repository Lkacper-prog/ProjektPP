#include "dino.h"

#include <stdio.h>
#include <stdlib.h>

const char* dieta_na_napis(enum dieta d) {
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

const char* temperament_na_napis(enum temperament t) {
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

const char* status_na_napis(enum status_bezpieczenstwa s) {
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


void dodaj_dinozaura(Node** glowa,Dino dane) {

}



void wyswietl_liste(Node* glowa) {
        Node* obecny = glowa;
        if (obecny == NULL) {
            printf("Lista jest pusta.\n");
            return;
        }

        printf("--- Lista Dinozaurow ---\n");

        while (obecny != NULL) {
            const char *dieta=dieta_na_napis(obecny->dane.dieta);
            const  char *temperament =temperament_na_napis(obecny->dane.temperament);
            const char *status= status_na_napis(obecny->dane.status_bezpieczenstwa);

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