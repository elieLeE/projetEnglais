#ifndef _DONNEES_H_
#define _DONNEES_H_

typedef struct L_coupleVoc *L_coupleVoc;
typedef struct L_coupleVerbesIrr *L_coupleVI;
typedef struct E_coupleVoc *E_coupleVoc;
typedef struct E_coupleVerbesIrr *E_coupleVI;

struct E_coupleVoc{
    char *motFr, *motEn;
    struct E_coupleVoc *suiv;
};

struct E_coupleVI{
    char *motFr, *motEn, *preterit, *participeP;    //liste de mot => parfois plusieurs sens...
    struct E_coupleVI *suiv;
};

struct L_coupleVoc{
    int nbreElem;
    struct E_coupleVov *first, *last;
};

struct L_coupleVI{
    int nbreElem;
    struct E_coupleVI *first, *last;
};

#endif
