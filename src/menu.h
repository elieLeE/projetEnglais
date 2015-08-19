#ifndef _MEHU_H_
#define _MENU_H_

#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"
#include "jeu.h"
#include "listeVO.h"
#include "gestionStdin.h"

typedef enum Choice Choice;
enum Choice{
    JEU, ADD_WORDS, SUPR_WORDS, MODIFY_WORDS, QUIT, VISU
};

void affMenu();
void menu(struct L_coupleVoc *l);
void addCouples(struct L_coupleVoc *l);
void supprimerCouples(struct L_coupleVoc *l);
void modifierCouples(struct L_coupleVoc *l);

#endif


