jogo.exe: personagem.o turno.o main.o carta.o batalha.o
	gcc -Wall  personagem.o turno.o main.o carta.o batalha.o -o jogo.exe

personagem.o: src/personagem.c src/personagem.h
	gcc -Wall -c personagem.c

turno.o: src/turno.c src/turno.h src/personagem.h		
	gcc -Wall -c src/turno.c

carta.o: src/carta.c src/carta.h
	gcc -Wall -c src/carta.c

batalha.o: src/batalha.c src/batalha.h src/personagem.h src/turno.h
	gcc -Wall -c src/batalha.c

main.o: src/main.c src/personagem.h src/turno.h src/carta.h
	gcc -Wall -c src/main.c 

test_batalha.exe: tests/test_batalha.c batalha.o personagem.o turno.o
	gcc -Wall tests/test_batalha.c batalha.o personagem.o turno.o -o test_batalha.exe
