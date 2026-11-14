#include <stdio.h>
#include "../batalha.h"

/* Imprime o nome do alvo, ou avisa se nao ha nenhum. */
void mostrar_alvo(Personagem* alvo) {
    if (alvo == NULL) {
        printf("Alvo: nenhum (NULL)\n");
    } else {
        printf("Alvo: %s\n", alvo->nome);
    }
}

int main() {
    Batalha b;

    /* Ordem dos parametros do personagem.c:
       nome, vida, vida_max, iniciativa, jogavel, numero_baralho */
    b.jogadores[0] = criar_personagem("Felipe", 30, 30, 5, 1, 0);
    b.jogadores[1] = criar_personagem("Rhedy",  30, 30, 4, 1, 1);
    b.quantidade_jogadores = 2;

    b.inimigos[0] = criar_personagem("Culpa",   20, 20, 3, 0, 0);
    b.inimigos[1] = criar_personagem("Mentira", 20, 20, 2, 0, 0);
    b.quantidade_inimigos = 2;

    printf("--- Teste 1: todos vivos ---\n");
    mostrar_alvo(encontrar_alvo(&b, 1));   /* esperado: Culpa */
    mostrar_alvo(encontrar_alvo(&b, 0));   /* esperado: Felipe */
    printf("Estado: %d (esperado 0 = EM_ANDAMENTO)\n", verificar_fim_batalha(&b));

    printf("\n--- Teste 2: Culpa morreu ---\n");
    b.inimigos[0].vivo = 0;
    mostrar_alvo(encontrar_alvo(&b, 1));   /* esperado: Mentira */
    printf("Estado: %d (esperado 0 = EM_ANDAMENTO)\n", verificar_fim_batalha(&b));

    printf("\n--- Teste 3: os dois inimigos morreram ---\n");
    b.inimigos[1].vivo = 0;
    mostrar_alvo(encontrar_alvo(&b, 1));   /* esperado: nenhum */
    printf("Estado: %d (esperado 1 = VITORIA)\n", verificar_fim_batalha(&b));

    printf("\n--- Teste 4: inimigos vivos, jogadores mortos ---\n");
    b.inimigos[0].vivo = 1;
    b.jogadores[0].vivo = 0;
    b.jogadores[1].vivo = 0;
    mostrar_alvo(encontrar_alvo(&b, 0));   /* esperado: nenhum */
    printf("Estado: %d (esperado 2 = DERROTA)\n", verificar_fim_batalha(&b));

    return 0;
}