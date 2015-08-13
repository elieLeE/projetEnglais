#ifndef _LISTEVO_H_
#define _LISTEVO_H_

#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"
#include <string.h>

void initStructsVO(struct L_coupleVoc *l);
void addFirstVO(struct L_coupleVoc *l, char* motFr, char* motEn);
void moveElemVO(struct L_coupleVoc *l1, struct L_coupleVoc *l2);
void visuHachTab(struct L_coupleVoc l[]);
void visuListeVO(struct E_coupleVoc *e);
void freeStructures(struct L_coupleVoc *l);
void freeStruct(E_coupleVoc *l);

#endif
