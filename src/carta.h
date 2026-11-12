#include <stdio.h>
#include <stdlib.h>

#ifndef CARTA
#define CARTA

typedef struct{
    char nome[15];
    char descricao[200];
    char tipo; // A = Ataque, C = cura
    int efeito;
    int namao;
} Carta;

Carta criar(char nome[15], char descricao[200], char tipo, int efeito);
void usar(); //Função que usa a carta, depende da implementação do baralho e personagens

#endif