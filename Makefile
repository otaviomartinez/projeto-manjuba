jogo.exe: build/personagem.o build/turno.o build/main.o build/carta.o build/batalha.o
	gcc -Wall  build/personagem.o build/turno.o build/main.o build/carta.o build/batalha.o -o jogo.exe

build/personagem.o: src/personagem.c src/personagem.h
	gcc -Wall -c src/personagem.c -o build/personagem.o

build/turno.o: src/turno.c src/turno.h src/personagem.h		
	gcc -Wall -c src/turno.c -o build/turno.o

build/carta.o: src/carta.c src/carta.h
	gcc -Wall -c src/carta.c -o build/carta.o

build/batalha.o: src/batalha.c src/batalha.h src/personagem.h src/turno.h
	gcc -Wall -c src/batalha.c -o build/batalha.o

build/main.o: src/main.c src/personagem.h src/turno.h src/carta.h
	gcc -Wall -c src/main.c -o build/main.o

test_batalha.exe: tests/test_batalha.c build/batalha.o build/personagem.o build/turno.o
	gcc -Wall tests/test_batalha.c build/batalha.o build/personagem.o build/turno.o -o test_batalha.exe