#ifndef BARALHO_H
#define BARALHO_H

#define MAX_CARTAS 10
#define CARTAS_MAO 3

typedef struct {
    int cartas[MAX_CARTAS];
    int inicio;
   int fim;
    int qtd;
} Baralho;

Baralho *criarBaralho();
void liberarBaralho(Baralho *b);

int baralhoVazio(Baralho *b);
int baralhoCheio(Baralho *b);

int inserirCarta(Baralho *b, int carta);
int obterProximaCarta(Baralho *b);
void mostrarCartasDisponiveis(Baralho *b);
void rotacionarCarta(Baralho *b);
int usarCarta(Baralho *b, int pos);

#endif
