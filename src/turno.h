#ifndef turno_h
#define turno_h

#include "personagem.h"

typedef struct Turno {
    Personagem* personagem[6];
    int proximo;
    int quantidade_personagens;
} Turno;

void ordenar_por_iniciativa(Turno* turno);
Turno criar_turno(Personagem* personagens[], int quantidade_personagens);
Personagem* personagem_atual(const Turno* turno);
void avancar_turno(Turno* turno);

#endif