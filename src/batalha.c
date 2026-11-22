#include "batalha.h"
#include <stdio.h>  

Personagem* encontrar_alvo(Batalha* b, int atacante_jogavel){
    if (atacante_jogavel) {
        for (int i = 0; i < b->quantidade_inimigos; i++) {
            if (b->inimigos[i].vivo) {  // verifica se o inimigo está vivo  
                return &b->inimigos[i]; // retorna o ponteiro para o inimigo vivo encontrado
            }
        }
    } else {
        for (int i = 0; i < b->quantidade_jogadores; i++) {
            if (b->jogadores[i].vivo) { // verifica se o jogador está vivo
                return &b->jogadores[i]; // retorna o ponteiro para o jogador vivo encontrado
            }
        }
         
    }
    return NULL; // nenhum jogador vivo encontrado  
}


EstadoBatalha verificar_fim_batalha(Batalha* b){
    int jogadores_vivos = 0;
    int inimigos_vivos = 0; 

    for (int i = 0; i < b->quantidade_jogadores; i++) {
        if (b->jogadores[i].vivo) {
            jogadores_vivos++;
        }
    }

    for (int i = 0; i < b->quantidade_inimigos; i++) {
        if (b->inimigos[i].vivo) {
            inimigos_vivos++;
        }
    }

    if (jogadores_vivos == 0) {
        b->estado =  DERROTA; // Todos os jogadores estão mortos
    }   
    else if (inimigos_vivos == 0) {
        b->estado = VITORIA; // Todos os inimigos estão mortos
    } else {
        b->estado = EM_ANDAMENTO; // A batalha ainda está em andamento
    }  
    return b->estado;   

}