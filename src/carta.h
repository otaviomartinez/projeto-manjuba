#ifndef CARTA
#define CARTA

typedef struct{
    char nome[15];
    char descricao[200];
    char tipo; // A = Ataque, C = cura
    int efeito;
    int namao;
} Carta;

Carta criar_carta(char nome[15], char descricao[200], char tipo, int efeito);
void usar_carta(Carta carta); //Função que usa a carta, depende da implementação do baralho e personagens
void print_carta(Carta carta);

#endif