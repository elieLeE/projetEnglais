#ifndef _JEU_H_
#define _JEU_H_

#include <stdio.h>
#include <stdlib.h>
#include "listeVO.h"
#include "donnees.h"
#include <time.h>
#include <stdbool.h>
#include "gestionStdin.h"
#include "fichier.h"

#define NBRE_QUESTION 10

extern int nbreMots;
extern int nbreListe;

int calculNewIndex(int oldIndex, bool rightAnswer);
bool affMot(struct E_coupleVoc *w, int c);
void game(struct L_coupleVoc l[]);
bool verifReponse(struct E_coupleVoc *w, char *c1, char *, bool c);
bool compareChaines(char *c1, char* c2);
E_coupleVoc choixMot(struct L_coupleVoc l[], int*, int);
void choixMode();

#endif

