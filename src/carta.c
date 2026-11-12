#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[15];
    char descricao[200];
    char tipo; // A = Ataque, C = cura
    int efeito; // quantidade de cura ou de dano
    int namao; // 0 = não ta na mao, 1 = ta na mão
} Carta;

Carta criar(char nome[15], char descricao[200], char tipo, int efeito){
    Carta carta_nova = {nome[15], descricao[200], tipo, efeito, 0};
    return carta_nova;
}

void usar();