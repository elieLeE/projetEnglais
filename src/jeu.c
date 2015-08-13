#include "jeu.h"

void game(struct L_coupleVoc l[]){
    E_coupleVoc word = choixMot(l);
    char answer[20]; 
    int i = 0, nbreQuestion = 40;
    for(i=0; i<4; i++){
	word = choixMot(l);
	printf("mot choisi : %s\n", word->motFr);
	scanf("%s", answer);
	if(compareChaines(word->motEn, answer)){
	    printf("bonne reponse\n");
	}
	else{
	    printf("mauvaise reponse\n");
	}
    }
    printf("sorti de game\n");
}

int transfoNbre(int n){
    int t = n/4;
    printf("n : %d, t : %d\n", n, t);
    return t;
}

E_coupleVoc choixMot(struct L_coupleVoc l[]){
    int i =0, lim = 1000;
    int max = nbreListe;
    int tab[5] = {0};
    int nbreHas = 0;
    //for(i=0; i<lim; i++){
    do{
	nbreHas = rand()%max;
    }while(l[nbreHas].first == NULL);
	//tab[transfoNbre(nbreHas)]++;
    /*for(i=0; i<6; i++){
	printf("%d => theorie : %lf, trouvee : %lf\n", i, (i+1)*1.0/max, tab[i]*1.0/lim);
    }*/
    return l[nbreHas].first;
}

bool compareChaines(char c1[], char c2[]){
    unsigned int taille = 0, i;
    if((taille = strlen(c1)) != strlen(c2)){
	return false;
    }
    for(i=0; i<taille; i++){
	if(c1[i] != c2[i]){
	    return false;
	}
    }
    return true;
}

