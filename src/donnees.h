#ifndef _DONNEES_H_
#define _DONNEES_H_

#define TAILLE_HACHTAB 127
#define MAX TAILLE_HACHTAB*(TAILLE_HACHTAB+1)/2

typedef struct L_coupleVoc *L_coupleVoc;
typedef struct L_coupleVerbesIrr *L_coupleVI;
typedef struct E_coupleVoc *E_coupleVoc;
typedef struct E_coupleVerbesIrr *E_coupleVI;
typedef struct statistique stats;
typedef struct config config;

/*
 * a lire dans le fichier de config => 
 * - de 120 mots => 4 liste
 * entre 120 et 240 mots => 8... jusqu'à 128;
 * */
/*#ifndef NBRE_LISTE
#define NBRE_LISTE*/
int nbreMots;
int nbreListe;
//#endif

struct statistique{
    int nbreQuestion;
    int nbreRightAnswer;
    int nbreWord;
};

struct E_coupleVoc{
    char motFr[20], motEn[20];
    struct E_coupleVoc *suiv;
};

struct E_coupleVI{
    char *motFr, *motEn, *preterit, *participeP;    //liste de mot => parfois plusieurs sens...
    struct E_coupleVI *suiv;
};

struct L_coupleVoc{
    int nbreElem;
    struct E_coupleVoc *first, *last;
};

struct L_coupleVI{
    int nbreElem;
    struct E_coupleVI *first, *last;
};

#endif
