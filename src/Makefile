#Makefile
#cible: dependances
#	commandes
#$@ : cible
#$< : nom de la premiere dependance
#$^ : liste des dependances
#$? : liste des dependances plus recentes que la cible
#$* : nom du fichier sans le suffixe

EXE: prog

all: clean prog

prog: main.o fichier.o listeVO.o jeu.o menu.o gestionStdin.o
	gcc -std=c99 -Wall -Wextra -o $@ $^ -lm

%.o: %.c
	gcc -std=c99 -Wall -Wextra -o $@ -c $< -lm

clean:
	rm -f *.o prog
