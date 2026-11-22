#include <stdio.h>
#include <string.h>
#include "batalha.h"
#include "baralho.h"
#include "carta.h"
#define NUM_CARTAS 5
#define ROTACIONAR 4
#define NUM_COMBATES 3

/* Leva 1, leva 2 e chefe. */
static const int inimigos_por_combate[NUM_COMBATES] = {3, 2, 1};
static const int vida_por_combate[NUM_COMBATES] = {30, 45, 90};
static Carta cartas[NUM_CARTAS];

static void mostrar_estado(const Batalha* b) {
    for (int equipe = 0; equipe < 2; equipe++) {
        const Personagem* p = equipe ? b->inimigos : b->jogadores;
        int n = equipe ? b->quantidade_inimigos : b->quantidade_jogadores;
        printf("\n%s\n", equipe ? "INIMIGOS" : "ALIADOS");
        for (int i = 0; i < n; i++)
            printf("%s: %d/%d %s\n", p[i].nome, p[i].vida, p[i].vida_max,
                   p[i].vivo ? "" : "[derrotado]");
    }
}

static int escolher(Baralho* b, int automatico) {
    char linha[80];
    for (;;) {
        for (int i = 0; i < CARTAS_MAO && i < b->qtd; i++) {
            int id = b->cartas[(b->inicio + i) % MAX_CARTAS];
            if (automatico && cartas[id].tipo == 'A') return i + 1;
            if (!automatico) printf("%d - %s (%d)\n", i+1, cartas[id].nome, cartas[id].efeito);
        }
        if (automatico) return ROTACIONAR;
        printf("Carta (1..%d; r para rotacionar; 0 para sair): ", CARTAS_MAO);
        fflush(stdout);
        if (!fgets(linha, sizeof linha, stdin)) return 0;
        if (linha[0] == 'r' || linha[0] == 'R') return ROTACIONAR;
        int opcao;
        char extra;
        if (sscanf(linha, "%d %c", &opcao, &extra) == 1 && opcao >= 0 &&
            opcao <= CARTAS_MAO && opcao <= b->qtd) return opcao;
        printf("Opcao invalida.\n");
    }
}

static void aplicar(Batalha* b, Personagem* ator, Carta c) {
    printf("%s usa %s.\n", ator->nome, c.nome);
    if (c.tipo == 'C') {
        curar(ator, c.efeito, ator->vivo, ator->vida_max);
        printf("%s: %d de vida\n", ator->nome, ator->vida);
    } else if (c.area) {
        Personagem* alvos = ator->jogavel ? b->inimigos : b->jogadores;
        int n = ator->jogavel ? b->quantidade_inimigos : b->quantidade_jogadores;
        for (int i = 0; i < n; i++) {
            if (!alvos[i].vivo) continue;
            tomar_dano(&alvos[i], c.efeito, alvos[i].vivo);
            printf("%s recebe %d de dano: vida %d\n", alvos[i].nome, c.efeito, alvos[i].vida);
        }
    } else {
        Personagem* alvo = encontrar_alvo(b, ator->jogavel);
        if (alvo) {
            tomar_dano(alvo, c.efeito, alvo->vivo);
            printf("%s recebe %d de dano: vida %d\n", alvo->nome, c.efeito, alvo->vida);
        }
    }
}

int main(int argc, char** argv) {
    int automatico = argc > 1 && strcmp(argv[1], "--auto") == 0;
    Batalha b = {0};
    Baralho* baralhos[3] = {0};
    cartas[0] = criar_carta("Espadada", "Ataque no primeiro inimigo vivo", 'A', 0, 12);
    cartas[1] = criar_carta("Curativo", "Cura o proprio personagem", 'C', 0, 10);
    cartas[2] = criar_carta("Terremoto", "Dano em todos os inimigos vivos", 'A', 1, 7);
    cartas[3] = criar_carta("Investida", "Ataque forte no primeiro inimigo", 'A', 0, 15);
    cartas[4] = criar_carta("Bandagem", "Cura leve no proprio personagem", 'C', 0, 6);
    Carta soco = criar_carta("Soco", "Ataque inimigo", 'A', 0, 6);
    b.quantidade_jogadores = 3;
    b.jogadores[0] = criar_personagem("Ana", 60, 60, 12, 1, 0);
    b.jogadores[1] = criar_personagem("Bruno", 60, 60, 10, 1, 1);
    b.jogadores[2] = criar_personagem("Carla", 60, 60, 8, 1, 2);
    for (int i = 0; i < 3; i++) {
        baralhos[i] = criarBaralho();
        if (!baralhos[i]) {
            for (int j = 0; j < i; j++) liberarBaralho(baralhos[j]);
            fprintf(stderr, "Falha ao criar baralho.\n");
            return 1;
        }
        for (int id = 0; id < NUM_CARTAS; id++) inserirCarta(baralhos[i], id);
    }
    int sair = 0;
    for (int combate = 1; combate <= NUM_COMBATES && !sair; combate++) {
        int chefe = combate == NUM_COMBATES;
        b.quantidade_inimigos = inimigos_por_combate[combate - 1];
        for (int i = 0; i < b.quantidade_inimigos; i++) {
            char nome[30];
            snprintf(nome, sizeof nome, "Inimigo %d", i+1);
            int vida = vida_por_combate[combate - 1];
            b.inimigos[i] = criar_personagem(chefe ? "Chefe" : nome, vida, vida, 9, 0, 0);
        }
        /* Referencias para os personagens dentro de b, que permanece no mesmo lugar. */
        Personagem* participantes[6];
        int n = 0;
        for (int i = 0; i < b.quantidade_jogadores; i++) participantes[n++] = &b.jogadores[i];
        for (int i = 0; i < b.quantidade_inimigos; i++) participantes[n++] = &b.inimigos[i];
        b.turno = criar_turno(participantes, n);
        printf("\n=== COMBATE %d: %d participantes ===\n", combate, n);
        printf("Ordem: ");
        for (int i = 0; i < n; i++) printf("%s%s", i ? " -> " : "", b.turno.personagem[i]->nome);
        printf("\n");
        while (verificar_fim_batalha(&b) == EM_ANDAMENTO) {
            Personagem* ator = personagem_atual(&b.turno);
            if (!ator->vivo) { avancar_turno(&b.turno); continue; }
            mostrar_estado(&b);
            printf("\nVez de %s\n", ator->nome);
            if (ator->jogavel) {
                Baralho* deck = baralhos[ator->numero_baralho];
                int opcao = escolher(deck, automatico);
                if (!opcao) { sair = 1; break; }
                if (opcao == ROTACIONAR) {
                    rotacionarCarta(deck);
                    printf("%s rotaciona o baralho.\n", ator->nome);
                } else {
                    int id = usarCarta(deck, opcao);
                    aplicar(&b, ator, cartas[id]);
                }
            } else aplicar(&b, ator, soco);
            avancar_turno(&b.turno);
        }
        if (sair) break;
        mostrar_estado(&b);
        if (b.estado == DERROTA) { printf("\nDERROTA!\n"); break; }
        printf("\nVITORIA NO COMBATE %d!\n", combate);
        /* Vida e baralhos dos aliados persistem entre os combates. */
    }
    for (int i = 0; i < 3; i++) liberarBaralho(baralhos[i]);
    return 0;
}