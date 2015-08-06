#ifndef _FICHIER_H_
#define _FICHIER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "donnees.h"

#define NBRE_FICHIERS 128

void ouvertureFichiers(FILE *tab[]);
void ouvertureFichier(FILE** f, char *name);
void lectureFichiersVO(FILE *tabFichiers[], struct L_coupleVoc *tabHach);
void lectureFichierVO(FILE *tabFichiers);
void fermetureFichiers(FILE* tab[NBRE_FICHIERS]);

#endif
