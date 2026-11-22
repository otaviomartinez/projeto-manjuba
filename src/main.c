#include <stdlib.h>
#include <stdio.h>
#include "carta.h"

int main(){
    // Exemplo de criação de carta
    Carta soco = criar_carta("Soco", "Uma pancada no primeiro inimigo na frente, ataque simples.", 'A', 0, 5);
    Carta curativo = criar_carta("Curativo", "Aplica um curativo e cura um pouco o personagem.", 'C', 0, 5);
    Carta espadada = criar_carta("Espadada", "Aplica um corte preciso no inimigo.", 'A', 0, 10);
    Carta curar = criar_carta("Magia de cura", "Cura machucados mais graves com uma magia simples", 'C', 0, 10);
    Carta terremoto = criar_carta("Terremoto", "Da uma pancada no chao criando um terremoto que causa dano em area", 'A', 1, 5);
    Carta cura_geral = criar_carta("Cura em area", "Cura machucados mais graves de todos os aliados com uma magia", 'C', 1, 5);
    print_carta(curativo);
    print_carta(curar);
    print_carta(cura_geral);
    print_carta(soco);
    print_carta(espadada);
    print_carta(terremoto);

    return 0;
}