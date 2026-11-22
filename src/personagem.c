#include "personagem.h"
#include <stdio.h>
#include <string.h>

Personagem criar_personagem(const char* nome, int vida,int vida_max, int iniciativa, int jogavel, int numero_baralho) {
    Personagem personagem;
    
        strcpy(personagem.nome, nome);
        personagem.vida = vida;
        personagem.vida_max = vida_max;
        personagem.numero_baralho = numero_baralho;
        personagem.iniciativa = iniciativa;
        personagem.jogavel = jogavel;
        personagem.vivo = 1;
    
    return personagem;
}

void tomar_dano(Personagem* personagem, int dano, int vivo) {
    if (vivo) {
        personagem->vida -= dano;
        if (personagem->vida <= 0) {
            personagem->vida = 0;
            personagem->vivo = 0;
        }
    }
}

void curar(Personagem* personagem, int cura, int vivo, int vida_max) {
    if (vivo) {
        personagem->vida += cura;
        if (personagem->vida > vida_max) {
            personagem->vida = vida_max;
        }
    }
}