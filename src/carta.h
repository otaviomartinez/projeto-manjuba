#ifndef CARTA
#define CARTA

typedef struct{
    char nome[15];
    char descricao[200];
    char tipo; // A = Ataque, C = cura
    int area;
    int efeito;
} Carta;

Carta criar_carta(char nome[15], char descricao[200], char tipo, int area, int efeito);

void print_carta(Carta carta);

#endif