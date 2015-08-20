#ifndef _FICHIER_H_
#define _FICHIER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "donnees.h"
#include "listeVO.h"
#include "math.h"

extern int nbreMots;
extern int nbreListe;
//#define NBRE_FICHIERS 128
#define SUFFIXE_VOC (char *)"../voc/voc"
#define FICHIER_CONFIG (char*)"../config"
#define FICHIER_STATS (char *)"../stats"

void ouvertureFichiers(FILE *tab[], char* mode);
void ouvertureFichier(FILE** f, char *name, char *mode);
//void lectureFichiersVO(FILE *tabFichiers[], struct L_coupleVoc *tabHach);
void lectureFichiersVO(struct L_coupleVoc *tabHach);
void lectureFichierVO(FILE *tabFichiers, struct L_coupleVoc* l);
void lectureFichierConfig();
void lectureStats(int *nbreQ, int *nbreRight);
void ecritureFichiers(struct L_coupleVoc l[]);
int ecritureFichier(FILE* f, struct L_coupleVoc l);
void ecritureStats(int nbreQ, int nbreRight);
void fermetureFichiers(FILE* tab[]);
void modifStats(int nbreQ, int nbreRight);

#endif
