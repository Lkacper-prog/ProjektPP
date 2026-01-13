#ifndef DINO_H
#define DINO_H

enum dieta {
    miesozerny,
    roslinozerny,
    wszystkozerny
};

enum temperament {
    spokojny,
    reaktywny,
    agresywny,
    nieprzewidywalny
};

enum status_bezpieczenstwa {
    bezpieczny,
    pod_obserwacja,
    awaryjna_kwarantanna,
    zagrozenie,
    ucieczka
};

typedef struct Dino {
    char gatunek[101];
    enum dieta dieta;
    float masa;
    char zagroda[40];
    enum temperament temperament;
    enum status_bezpieczenstwa status_bezpieczenstwa;
} Dino;

typedef struct Node {
    Dino dane;
    struct Node *nastepny;
} Node;

void dodaj_dinozaura(Node **glowa, Dino dane);

void wyswietl_liste(Node *glowa);

void usun_dinozaura(Node **glowa);

void usun_dinozaury(Node **glowa);

void zwolnij_liste(Node **glowa);
#endif
