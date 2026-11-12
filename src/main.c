#include <stdlib.h>
#include <stdio.h>
#include "carta.h"

int main(){
    // Exemplo de criação de carta
    Carta ataque1 = criar_carta("Soco", "Uma pancada no primeiro inimigo na frente, ataque simples.", 'A', 5);
    print_carta(ataque1);
    

    return 0;
}