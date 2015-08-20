#include "listeVO.h"

void initStructsVO(struct L_coupleVoc l[]){
    int i = 0;
    for(i=0; i<nbreListe; i++){
	l[i].nbreElem = 0;
	l[i].first = NULL;
	l[i].last = NULL;
    }
}

void addFirstVO(struct L_coupleVoc *l, char* motFr, char* motEn){
    E_coupleVoc new = (E_coupleVoc)calloc(1, sizeof(struct E_coupleVoc));
    memcpy(new->motFr, motFr, strlen(motFr)+1);
    memcpy(new->motEn, motEn, strlen(motEn)+1);
    new->suiv = NULL;
    l->nbreElem++;

    if(l->first == NULL){
	l->first = new;
    }
    else{
	l->last->suiv = new;
    }
    l->last = new;
}

void visuHachTab(struct L_coupleVoc l[]){
    int i = 0;
    printf("%d mots divisés dans %d listes\n", nbreMots, nbreListe);
    for(i=0; i<nbreListe; i++){
	printf("liste %d => ", i);
	visuListeVO(l[i].first);
    }
}

void visuListeVO(struct E_coupleVoc *e){
    struct E_coupleVoc *p = e;
    if(p == NULL){
	printf("VIDE");
    }
    else{
	printf("%s, %s\n", p->motFr, p->motEn);
	p = p->suiv;
	while(p != NULL){
	    printf("\t   %s, %s\n", p->motFr, p->motEn);
	    p = p->suiv;
	}
    }
    printf("\n");
}

void moveElemVO(struct L_coupleVoc *l1, struct L_coupleVoc *l2){
    if(l1->first == NULL){
	fprintf(stderr, "move d'un element inexistant fichier %s, ligne %d\n", __FILE__, __LINE__);
	exit(0);
    }
    l1->nbreElem--;
    l2->nbreElem++;

    struct E_coupleVoc *e = l1->first;
    if(l1->first == l1->last){
	l1->last = NULL;
    }
    l1->first = l1->first->suiv;
    e->suiv = NULL;
    if(l2->first == NULL){
	l2->first = e;
    }
    else{
        l2->last->suiv = e;
    }
    l2->last = e;
}

void freeStructures(struct L_coupleVoc *l){
    int i = 0;
    for(i=0; i<nbreListe; i++){
	freeStruct(&(l[i].first));
    }
}

void freeStruct(struct E_coupleVoc **l){
    struct E_coupleVoc *p = *l;
    while(*l != NULL){
	p = *l;
	*l = (*l)->suiv;
	free(p);
    }
}

struct E_coupleVoc* searchElem (struct L_coupleVoc *l, const char *s){
    char motFr[20], motEn[20];
    printf("Veuillez entrer les mots Francais et anglais associés au couple à %s.\n", s);
    printf("Il n est pas nécessaire d'entrer les deux mais au moins l'un des deux devra l'etre\n");
    printf("entrez le mot francais associé au couple à %s => ", s);
    scanf("%s", motFr);
    viderBuffeur();
    printf("entrez le mot anglais associé au couple à %s => ", s);
    scanf("%s", motEn);
    viderBuffeur();

    printf("%s\n", l->first->motFr);

    return NULL;

}

void melange(){

}
