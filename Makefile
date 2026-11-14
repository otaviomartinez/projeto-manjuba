jogo.exe: personagem.o turno.o main.o carta.o batalha.o
	gcc -Wall  personagem.o turno.o main.o carta.o batalha.o -o jogo.exe

personagem.o: personagem.c personagem.h
	gcc -Wall -c personagem.c

turno.o: turno.c turno.h personagem.h		
	gcc -Wall -c turno.c

carta.o: src/carta.c src/carta.h
	gcc -Wall -c src/carta.c

batalha.o: batalha.c batalha.h personagem.h turno.h
	gcc -Wall -c batalha.c

main.o: src/main.c personagem.h turno.h src/carta.h
	gcc -Wall -c src/main.c 

test_batalha.exe: tests/test_batalha.c batalha.o personagem.o turno.o
	gcc -Wall tests/test_batalha.c batalha.o personagem.o turno.o -o test_batalha.exe