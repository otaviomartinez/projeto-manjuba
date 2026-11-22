#include <stdio.h>
#include <stdlib.h>
#include "baralho.h"

Baralho *criarBaralho() {
    Baralho *b = malloc(sizeof(Baralho));
    if (b == NULL) return NULL;
    b->inicio = 0;
    b->fim = 0;
    b->qtd = 0;
    return b;
}

void liberarBaralho(Baralho *b) {
    free(b);
}

int baralhoVazio(Baralho *b) {
    return b->qtd == 0;
}

int baralhoCheio(Baralho *b) {
    return b->qtd == MAX_CARTAS;
}

int inserirCarta(Baralho *b, int carta) {
    if (baralhoCheio(b)) return 0;
    b->cartas[b->fim] = carta;
    b->fim = (b->fim + 1) % MAX_CARTAS;
    b->qtd++;
    return 1;
}

int obterProximaCarta(Baralho *b) {
    if (baralhoVazio(b)) return -1;
    return b->cartas[b->inicio];
}

void mostrarCartasDisponiveis(Baralho *b) {
    int n = b->qtd < CARTAS_MAO ? b->qtd : CARTAS_MAO;
    for (int i = 0; i < n; i++) {
        int idx = (b->inicio + i) % MAX_CARTAS;
        printf("[%d] carta %d\n", i + 1, b->cartas[idx]);
    }
}

void rotacionarCarta(Baralho *b) {
    if (baralhoVazio(b)) return;
    int carta = b->cartas[b->inicio];
    b->inicio = (b->inicio + 1) % MAX_CARTAS;
    b->qtd--;
    inserirCarta(b, carta);
}

int usarCarta(Baralho *b, int pos) {
    int n = b->qtd < CARTAS_MAO ? b->qtd : CARTAS_MAO;
    if (pos < 1 || pos > n) return -1;

    int idx = (b->inicio + pos - 1) % MAX_CARTAS;
    int carta = b->cartas[idx];

    for (int i = pos - 1; i > 0; i--) {
        int atual = (b->inicio + i) % MAX_CARTAS;
        int anterior = (b->inicio + i - 1) % MAX_CARTAS;
        b->cartas[atual] = b->cartas[anterior];
    }

    b->inicio = (b->inicio + 1) % MAX_CARTAS;
    b->qtd--;

    inserirCarta(b, carta);
    return carta;
}
