#include "listeVO.h"

void initStructsVO(struct L_coupleVoc *l){
    int i = 0;
    for(i=0; i<nbreListe; i++){
	l[i].nbreElem = 0;
	l[i].first = NULL;
	l[i].last = NULL;
    }
}

void addFirstVO(struct L_coupleVoc *l, char* motFr, char* motEn){
    printf("debut addFirstVO\n");
    E_coupleVoc new = (E_coupleVoc)calloc(1, sizeof(struct E_coupleVoc));
    memcpy(new->motFr, motFr, strlen(motFr)+1);
    memcpy(new->motEn, motEn, strlen(motEn)+1);
    new->suiv = NULL;
    l->nbreElem++;

    printf("apres allocation\n");
    if(l->last == NULL){
	printf("l->last NULL\n");
    }
    else{
	printf("l->last non NULL\n");
    }
    if(l->first == NULL){
	printf("l->first NULL\n");
    }
    else{
	printf("l->first non NULL\n");
    }
    if(l->first == NULL){
	printf("if\n");
	l->first = new;
	printf("sorti if\n");
    }
    else{
	printf("else\n");
	if(l->last == NULL){
	    fprintf(stderr, "l->last NULL, fichier %s, ligne %d\n", __FILE__, __LINE__);
	    free(new);
	}
	else{
	    l->last->suiv = new;
	}
	printf("sorti else\n");
    }
    l->last = new;
    printf("fin addFirstVO\n");
}

void visuHachTab(struct L_coupleVoc l[]){
    int i = 0;
    printf("%d mots divisés dans %d listes\n", nbreMots, nbreListe);
    for(i=0; i<nbreListe; i++){
	printf("liste %d => %d elements\n", i, l[i].nbreElem);
	visuListeVO(l[i].first);
    }
}

void visuListeVO(struct E_coupleVoc *e){
    struct E_coupleVoc *p = e;
    if(p == NULL){
	printf("VIDE");
    }
    else{
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

/*struct E_coupleVoc* removeElemListe(struct L_coupleVoc *l, int n){
    printf("dans removeElemListe\n");
    struct E_coupleVoc *p = NULL, *p2;
    int compt = 1;
    //visuListeVO(l->first);
    if(l->nbreElem < n){
	fprintf(stderr, "l'element %d n'existe pas, fichier %s, ligne %d\n", n, __FILE__, __LINE__);
	return NULL;
    }
    else{
	printf("ici1, n : %d\n", n);
	if(n == 0){
	    if(l->first->suiv != NULL){
		p = l->first;
		l->first->suiv = l->first->suiv->suiv;
		l->nbreElem--;
		return p;
	    }
	    else{
		fprintf(stderr, "l'element %d n'existe pas, fichier %s, ligne %d\n", n, __FILE__, __LINE__);
		fprintf(stderr, "le nombre d'element indiqué dans la structure L_coupleVoc est incorrecte, fichier %s, ligne %d\n", __FILE__, __LINE__);
		return NULL;
	    }
	}
	else{
	    printf("ici2, n : %d\n", n);
	    p = l->first;
	    while(p->suiv != NULL && compt < n-1){
		//printf("compt : %d, p : (%s, %s)\n", compt, p->motFr, p->motEn);
		compt++;
		p = p->suiv;
	    }
	    //printf("compt : %d, p : (%s, %s)\n", compt, p->motFr, p->motEn);
	    printf("ici3, n : %d\n", n);
	    if(p->suiv == NULL){
		fprintf(stderr, "l'element %d n'existe pas, fichier %s, ligne %d\n", n, __FILE__, __LINE__);
		fprintf(stderr, "le nombre d'element indiqué dans la structure L_coupleVoc est incorrecte, fichier %s, ligne %d\n", __FILE__, __LINE__);
		return NULL;
	    }
	    else{
		printf("ici4, n : %d\n", n);
		p2 = p->suiv;
		printf("ici5, n : %d\n", n);
		p->suiv = p->suiv->suiv;
		printf("ici6, n : %d\n", n);
		l->nbreElem--;
		printf("ici7, n : %d\n", n);
		return p2;
	    }
	}
    }
}*/


/*void melangeTabH(struct L_coupleVoc l[]){
    printf("dans melangeTabH\n");
    int i = 0;
    melangeListe(&l[nbreListe-1]);
    printf("fin melangeTabH\n");
}*/

/*void melangeListe(struct L_coupleVoc *l){
    printf("dans melangeListe\n");
    int i = 0, max = l->nbreElem, has;
    struct L_coupleVoc new;
    initStructsVO(&new);
    struct E_coupleVoc *p;
    char *mFr = NULL, *mEn = NULL;

    has = rand()%max;
    p = removeElemListe(l, has);
    if(p == NULL){
	fprintf(stderr, "melange impossible, fichier %s, ligne %d\n", __FILE__, __LINE__);
	return;
    }
    new.first = p;
    new.last = p;
    new.nbreElem++;
    mFr = p->motFr;
    mEn = p->motEn;

    printf("avant le for\n");
    for(i=1; i<max; i++){
	printf("mFr : %s, mEn : %s\n", mFr, mEn);
	visuListeVO(new.first);
	has = rand()%max;
	p = removeElemListe(l, has);
	if(p == NULL){
	    fprintf(stderr, "melange impossible, fichier %s, ligne %d\n", __FILE__, __LINE__);
	    return;
	}
	new.first = p;
	new.last = p;
	new.nbreElem++;
	p->suiv = new.first;
	new.first = p;
	mFr = p->motFr;
	mEn = p->motEn;
    }
    *l = new;
    printf("fin melangeListe\n");
}*/
