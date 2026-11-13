
#ifndef personagem_h
#define personagem_h

typedef struct Personagem {
    char nome[50];
    int vida;
    int vida_max;
    int vivo;
    int iniciativa;
    char jogavel;
    int numero_baralho;
} Personagem;

//funções
Personagem criar_personagem(const char* nome, int vida, int iniciativa, int jogavel, int vida_max, int numero_baralho);
void tomar_dano(Personagem* personagem, int dano, int vivo);
void curar(Personagem* personagem, int cura, int vivo, int vida_max);

#endif