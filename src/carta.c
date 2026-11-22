#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Carta criar_carta(char nome[], char descricao[], char tipo, int area, int efeito){
    Carta carta_nova;
    strcpy(carta_nova.nome, nome);
    strcpy(carta_nova.descricao, descricao);
    carta_nova.tipo = tipo;
    carta_nova.area = area;
    carta_nova.efeito = efeito;
    return carta_nova;
}


void print_carta(Carta carta){
    printf(" -- Carta -- \n");

    printf("Nome: ");
    for(int i = 0; i < strlen(carta.nome); i++){
        printf("%c", carta.nome[i]);
    }
    printf("\n");

    printf("Descricao: ");  
    for(int i = 0; i < strlen(carta.descricao); i++){
        printf("%c", carta.descricao[i]);
    }
    printf("\n");
    
    printf("Tipo de ataque: ");
    if(carta.area == 1){ 
        printf("Em area"); 
    }
    else{ 
        printf("Individual"); 
    }

    printf("\n");

    printf("Tipo: ");
    if (carta.tipo == 'A'){
        printf("Ataque");
    } else {
        printf("Cura");
    }
    printf("\n");

    printf("Efeito: %d\n\n", carta.efeito);
    printf("\n\n");
    return;
}

