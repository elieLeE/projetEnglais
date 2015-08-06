#include "fichier.h"

void ouvertureFichiers(FILE *tab[]){
    int i = 0;
    char *name = (char *)calloc(11, sizeof(char));
    
    //fichiers de vocabulaire
    for(i=0; i<NBRE_FICHIERS; i++){
	sprintf(name, "../voc/voc%d", i);
	ouvertureFichier(&tab[i], name);
    }

    /*for(i=0; i<NBRE_FICHIERS; i++){
	sprintf(name, "../verbesIrr/verbesIrr%d", i);
	//printf("name : %s\n", name);
	ouvertureFichier(tab[1][i], name);
    }*/
}

void ouvertureFichier(FILE** f, char *name){
    *f = fopen(name, "r+");
    if(f == NULL){
	printf("impossible de lire le fichier %s\n", name); //mettre dans stderr ??
	exit(0);
    }
}

void lectureFichiersVO(FILE *tabFichiers[], struct L_coupleVoc *tabHach){
    int i = 0;
    for(i=0; i<NBRE_FICHIERS; i++){
	lectureFichierVO(tabFichiers[i]);
    }
}

void lectureFichierVO(FILE *f){
    char *motFr = (char *)calloc(20, sizeof(char));
    char *motEn = (char *)calloc(20, sizeof(char));

    while(fscanf(f, "%s %s", motFr, motEn) == 2){
	printf("motFr : %s, motEn : %s\n", motFr, motEn);
    }
}

void fermetureFichiers(FILE* tab[]){
    int i = 0;
    for(i=0; i<NBRE_FICHIERS; i++){
	free(tab[i]);
    }
}

void fermetureFichiersVI(FILE tab[NBRE_FICHIERS]){

}
