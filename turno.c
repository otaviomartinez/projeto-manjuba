#include "turno.h"
#include "personagem.h"
#include <stdio.h>
#include <string.h>

void ordenar_por_iniciativa(Turno* turno){
    int n = turno->quantidade_personagens;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (turno->personagem[j]->iniciativa < turno->personagem[j + 1]->iniciativa) {
                Personagem* temp = turno->personagem[j];
                turno->personagem[j] = turno->personagem[j + 1];
                turno->personagem[j + 1] = temp;
            }
        }
    }
}

Turno criar_turno(Personagem* personagens[], int quantidade_personagens){
    Turno turno = {0};
    if (quantidade_personagens < 0 || quantidade_personagens > 6) {
        return turno;
    }
    turno.quantidade_personagens = quantidade_personagens;
    turno.proximo = 0;
    for (int i = 0; i < quantidade_personagens; i++) {
        turno.personagem[i] = personagens[i];
    }
    ordenar_por_iniciativa(&turno);

    return turno;
}

Personagem* personagem_atual(const Turno* turno) {
    if (turno->quantidade_personagens > 0) {
        return turno->personagem[turno->proximo];
    }
    return NULL;
}

void avancar_turno(Turno* turno) {
    if (turno->quantidade_personagens > 0) {
        turno->proximo = (turno->proximo + 1)%turno->quantidade_personagens;
    }
}