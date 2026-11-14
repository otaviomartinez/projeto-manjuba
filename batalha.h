#ifndef batalha_h
#define batalha_h
#define MAX_JOGADORES 3
#define MAX_INIMIGOS 3
#include "personagem.h"
#include "turno.h"

typedef enum EstadoBatalha { EM_ANDAMENTO, VITORIA, DERROTA } EstadoBatalha ;

typedef struct Batalha {
    Personagem jogadores[MAX_JOGADORES];
    int quantidade_jogadores;
    Personagem inimigos[MAX_INIMIGOS];
    int quantidade_inimigos;
    Turno turno;
    EstadoBatalha estado;   
} Batalha;

Personagem* encontrar_alvo(Batalha* b, int atacante_jogavel);

#endif