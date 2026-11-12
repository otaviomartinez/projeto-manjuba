#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[15];
    char descricao[200];
    char tipo; // A = Ataque, C = cura
    int efeito; // quantidade de cura ou de dano
    int namao; // 0 = não ta na mao, 1 = ta na mão
} Carta;

Carta criar_carta(char nome[], char descricao[], char tipo, int efeito){
    Carta carta_nova;
    strcpy(carta_nova.nome, nome);
    strcpy(carta_nova.descricao, descricao);
    carta_nova.tipo = tipo;
    carta_nova.efeito = efeito;
    carta_nova.namao = 0;
    return carta_nova;
}

void usar_carta(Carta carta); 
//Função que usa a carta, depende da implementação do baralho e personagens

void print_carta(Carta carta){
    printf(" -- Carta -- \n\n");

    printf("Nome: ");
    for(int i = 0; i < strlen(carta.nome); i++){
        printf("%c", carta.nome[i]);
    }
    printf("\n\n");

    printf("Descricao: ");
    for(int i = 0; i < strlen(carta.descricao); i++){
        printf("%c", carta.descricao[i]);
    }
    printf("\n\n");

    printf("Tipo: ");
    if (carta.tipo == 'A'){
        printf("Ataque");
    } else {
        printf("Cura");
    }
    printf("\n\n");

    printf("Efeito: %d\n\n", carta.efeito);
    return;
}

