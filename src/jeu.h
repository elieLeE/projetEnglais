#ifndef _JEU_H_
#define _JEU_H_

#include <stdio.h>
#include <stdlib.h>
#include "listeVO.h"
#include "donnees.h"
#include <time.h>
#include <stdbool.h>

void game(struct L_coupleVoc l[]);
bool compareChaines(char c1[], char c2[]);
E_coupleVoc choixMot(struct L_coupleVoc l[]);

#endif

