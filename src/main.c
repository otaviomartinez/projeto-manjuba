#include <stdlib.h>
#include <stdio.h>
#include "carta.h"

int main(){
    // Exemplo de criação de carta
    Carta soco = criar_carta("Soco", "Uma pancada no primeiro inimigo na frente, ataque simples.", 'A', 0, 5);
    print_carta(soco);
    

    return 0;
}