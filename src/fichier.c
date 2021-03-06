#include "fichier.h"

void ouvertureFichiers(FILE *tab[], char* mode){
    int i = 0;
    //char *name = (char *)calloc(11, sizeof(char));
    char name[20];
    
    //fichiers de vocabulaire
    for(i=0; i<nbreListe; i++){
	//sprintf(name, "../voc/voc%d", i);
	sprintf(name, "%s%d", SUFFIXE_VOC, i);
	ouvertureFichier(&tab[i], name, mode);
    }
    
    /*for(i=0; i<NBRE_FICHIERS; i++){
	sprintf(name, "../verbesIrr/verbesIrr%d", i);
	//printf("name : %s\n", name);
	ouvertureFichier(tab[1][i], name);
    }*/
}

void ouvertureFichier(FILE** f, char *name, char* mode){
    *f = fopen(name, mode);
    if(f == NULL){
	printf("impossible de lire le fichier %s\n", name); //mettre dans stderr ??
	exit(0);
    }
}

void lectureFichierConfig(){
    FILE* f = NULL;
    ouvertureFichier(&f, FICHIER_CONFIG, "r+");
    if(fscanf(f, "%d", &nbreMots)!=1){
	fprintf(stderr, "erreur lecture fichier config\n");
    }
    int n = nbreMots/120;
    if(n>5){
	nbreListe = 128;
    }
    else{
	nbreListe = pow(2, 2+n);
    }
    if(nbreListe > 128){
	fprintf(stderr, "nbreListe > 128, %s, %d\n", __FILE__, __LINE__);
	exit(0);
    }
    fclose(f);
}

void lectureFichiersVO(struct L_coupleVoc *tabHach){
    int i = 0;
    FILE *tabF[TAILLE_HACHTAB];
    ouvertureFichiers(tabF, "r");
    for(i=0; i<nbreListe; i++){
	lectureFichierVO(tabF[i], &tabHach[i]);
    }
    fermetureFichiers(tabF);
}

void lectureFichierVO(FILE *f, struct L_coupleVoc *l){
    char motFr[20];
    char motEn[20];

    while(fscanf(f, "%s %s", motFr, motEn) == 2){
	addFirstVO(l, motFr, motEn);
    }
}

void ecritureFichiers(struct L_coupleVoc l[]){
    int i = 0, compteur = 0;
    FILE *tabF[TAILLE_HACHTAB], *fConfig = NULL;
    ouvertureFichiers(tabF, "w+");
    for(i=0; i<nbreListe; i++){
	compteur += ecritureFichier(tabF[i], l[i]);
    }
    ouvertureFichier(&fConfig, FICHIER_CONFIG, "w+");
    fprintf(fConfig, "%d", compteur);
    fclose(fConfig);
    fermetureFichiers(tabF);
}

int ecritureFichier(FILE* f, struct L_coupleVoc l){
    int compteur = 0;
    struct E_coupleVoc *p = l.first;
    while(p!=NULL){
	fprintf(f, "%s %s\n", p->motFr, p->motEn);
	p = p->suiv;
	compteur++;
    }
    return compteur;
}

void fermetureFichiers(FILE* tab[]){
    int i = 0;
    for(i=0; i<nbreListe; i++){
	fclose(tab[i]);
    }
}

void lectureStats(int *nbreQ, int *nbreRight){
    FILE* fichStats = NULL;
    ouvertureFichier(&fichStats, FICHIER_STATS, "r+");
    if(fscanf(fichStats, "%d %d", nbreQ, nbreRight) != 2){
	fprintf(stderr, "lecture fichier stats incorrecte, fichier : %s, ligne : %d\n", __FILE__, __LINE__);
    }
    fclose(fichStats);
}

void ecritureStats(int nbreQ, int nbreRight){
    FILE* fichStats = NULL;
    ouvertureFichier(&fichStats, FICHIER_STATS, "w+");
    fprintf(fichStats, "%d %d", nbreQ, nbreRight);
    fclose(fichStats);
}

void modifStats(int nbreQ, int nbreRight){
    int nbreQTot = 0, nbreRightTot = 0;
    lectureStats(&nbreQTot, &nbreRightTot);
    nbreQTot += nbreQ;
    nbreRightTot += nbreRight;
    ecritureStats(nbreQTot, nbreRightTot);
}
