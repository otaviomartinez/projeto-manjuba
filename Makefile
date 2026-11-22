CC = gcc
CFLAGS = -std=c11 -Wall -Wextra
OBJ = build/personagem.o build/turno.o build/main.o build/carta.o build/batalha.o build/baralho.o

jogo.exe: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

build:
	mkdir -p build

build/%.o: src/%.c $(wildcard src/*.h) | build
	$(CC) $(CFLAGS) -c $< -o $@

test_batalha.exe: tests/test_batalha.c build/batalha.o build/personagem.o build/turno.o
	$(CC) $(CFLAGS) $^ -o $@
