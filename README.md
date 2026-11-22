Jogo de RPG de turno com cartas rotativas, desenvolvido em C para a disciplina de Estruturas de Dados (UFSCar 2026/2):
Autores:
- Gabriel Cotrim Lemos
- Rhédy Marques
- Otávio Martinez
- Felipe Pezzato

# Implementação #1

Para a primeira parte do projeto construimos os tads de cada componente do jogo, funções para controlar o estado do jogo e a arquitetura do projeto, o que ficou pendente é a unifiação de tudo isso num jogo só, até então os baralhos se referenciam as cartas por inteiros, como indexes, que ainda não existem, futuramente isso será diferente, ao invés de ser um vetor de inteiros será um vetor de cartas. O baralho pode usar a carta, isso significa que a carta é passada para o fim do baralho, no entanto, ninguém aplica o efeito da carta até então, isso será implementando no arquivo de batalha provavelmente.

O que se pode fazer até então? 
Usar funções de criar cartas, criar personagens, criar baralhos, rotacionar o baralho, simular uma batalha mesmo sem o uso de cartas com funções de encontrar o alvo e mostrar o alvo, e algumas outras coisas.
