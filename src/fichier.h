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

void ouvertureFichiers(FILE *tab[], char* mode);
void ouvertureFichier(FILE** f, char *name, char *mode);
//void lectureFichiersVO(FILE *tabFichiers[], struct L_coupleVoc *tabHach);
void lectureFichiersVO(struct L_coupleVoc *tabHach);
void lectureFichierVO(FILE *tabFichiers, struct L_coupleVoc* l);
void lectureFichierConfig();
void ecritureFichiers(struct L_coupleVoc l[]);
void ecritureFichier(FILE* f, struct L_coupleVoc l);
void fermetureFichiers(FILE* tab[]);

#endif
