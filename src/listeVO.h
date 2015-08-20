#ifndef _LISTEVO_H_
#define _LISTEVO_H_

#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"
#include <string.h>
#include "gestionStdin.h"

void initStructsVO(struct L_coupleVoc *l);
void addFirstVO(struct L_coupleVoc *l, char* motFr, char* motEn);
void moveElemVO(struct L_coupleVoc *l1, struct L_coupleVoc *l2);
void visuHachTab(struct L_coupleVoc l[]);
void visuListeVO(struct E_coupleVoc *e);
void freeStructures(struct L_coupleVoc *l);
void freeStruct(E_coupleVoc *l);
struct E_coupleVoc* searchElem (struct L_coupleVoc *l, const char*);
void melange();

#endif
