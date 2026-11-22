Jogo de RPG de turno com cartas rotativas, desenvolvido em C para a disciplina de Estruturas de Dados (UFSCar 2026/2).

Autores:
- Gabriel Cotrim Lemos
- Rhédy Marques
- Otávio Martinez
- Felipe Pezzato

# Implementação atual

O projeto possui os TADs e módulos principais do jogo:

- `Personagem`: controla nome, vida, iniciativa, estado vivo/derrotado e vínculo com um baralho.
- `Carta`: representa cartas de ataque e cura, com efeito individual ou em área.
- `Baralho`: implementa uma fila circular de cartas, armazenadas como IDs inteiros, com suporte para rotação e uso das cartas disponíveis.
- `Turno`: organiza os personagens por iniciativa e controla o avanço dos turnos.
- `Batalha`: controla jogadores, inimigos, estado da batalha e seleção de alvos.
- `main.c`: integra os módulos, executa os combates e controla a interface textual do jogo.

# Fluxo do jogo

Ao iniciar, o programa cria as cartas, os personagens dos jogadores e um baralho para cada personagem jogável.

Em seguida, são executados até dois combates:

1. Os participantes do combate são criados.
2. A ordem dos personagens é definida pela iniciativa.
3. O programa verifica se a batalha terminou.
4. O personagem atual realiza sua ação.
5. Jogadores escolhem uma carta do próprio baralho.
6. Inimigos utilizam a carta “Soco”.
7. O efeito da ação é aplicado.
8. O turno avança para o próximo personagem.
9. O ciclo continua até ocorrer vitória, derrota ou saída do jogador.

A vida dos aliados e os seus baralhos permanecem entre os combates.

# Cartas implementadas

Atualmente existem as seguintes cartas:

- `Espadada`: ataque individual no primeiro inimigo vivo.
- `Curativo`: recupera vida do próprio personagem.
- `Terremoto`: causa dano em área nos inimigos vivos.
- `Soco`: ataque individual utilizado pelos inimigos.

No modo automático, o programa escolhe a primeira carta de ataque disponível no baralho do jogador.

# Interface

A interface atual é textual e utiliza:

- `printf` para mostrar o estado da batalha, a ordem dos turnos e os efeitos das ações;
- `fgets` e `sscanf` para ler a escolha da carta do jogador;
- o argumento `--auto` para executar as escolhas dos jogadores automaticamente.

Ainda não existe uma camada de interface separada. A interação está concentrada no arquivo `main.c`.

# Compilação e execução

Para compilar o jogo:

```bash
make
```

Para executar normalmente:

```bash
./jogo.exe
```

Para executar no modo automático:

```bash
./jogo.exe --auto
```

Também é possível compilar o teste da lógica de batalha:

```bash
make test_batalha.exe
```

E executá-lo com:

```bash
./test_batalha.exe
```

# Testes

O arquivo `tests/test_batalha.c` testa:

- a busca pelo primeiro alvo vivo;
- a troca de alvo quando um inimigo é derrotado;
- a ausência de alvo quando todos os inimigos estão mortos;
- o estado de vitória;
- o estado de derrota.

# Observações

O baralho atualmente armazena inteiros que funcionam como IDs das cartas. As cartas correspondentes ficam armazenadas no vetor global utilizado pelo `main.c`.

O efeito das cartas já está integrado ao fluxo da batalha, incluindo ataques individuais, ataques em área e cura.

O `Makefile` compila cada módulo separadamente e depois realiza a ligação dos arquivos objeto para gerar o executável do jogo.
