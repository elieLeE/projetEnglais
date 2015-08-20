#include "jeu.h"

void game(struct L_coupleVoc l[]){
    struct E_coupleVoc *word = NULL;
    char answer[20], correctAnswer[20]; 
    int i = 0, index = 0, score = 0;
    bool modeBoucle, rightAnswer;
    int mode = 0, diff = 0; 
    choixMode(&mode, diff);
    if(diff == 1 && l[nbreListe-1].first == NULL){
	printf("le mode difficile n'est pas disponible => la liste l[%d] est vide ==> prendre la première liste non vide\n", nbreListe-1);
	diff = 0;
    }
    for(i=0; i<NBRE_QUESTION; i++){
	word = choixMot(l, &index, diff);
	modeBoucle = affMot(word, mode);
	scanf("%s", answer);
	rightAnswer = verifReponse(word, answer, correctAnswer, modeBoucle);
	moveElemVO(&l[index], &l[calculNewIndex(index, rightAnswer)]);
	if(rightAnswer){
	    score++;
	    printf("bonne reponse\n\n");
	}
	else{
	    printf("mauvaise reponse. La bonne réponse était : %s\n\n", correctAnswer);
	}
    }
    printf("\nvotre score : %d/%d\n", score, NBRE_QUESTION);
    modifStats(NBRE_QUESTION, score);
}

int calculNewIndex(int oldIndex, bool rightAnswer){
    int newIndex = oldIndex >> 1;

    if(!rightAnswer){
	newIndex = newIndex | ((nbreListe +1)/2);
    }
    if(newIndex > nbreListe -1){
	fprintf(stderr, "calcul du nouvel index incorrecte => %d, fichier : %s, ligne : %d\n", newIndex, __FILE__, __LINE__);
	exit(0);
    }
    return newIndex;
}

bool verifReponse(struct E_coupleVoc *w, char* answer, char* correctAnswer, bool c){
    if(c){
	strncpy(correctAnswer, w->motEn, 19);
	return compareChaines(w->motEn, answer);
    }
    else{
	strncpy(correctAnswer, w->motFr, 19);
	return compareChaines(w->motFr, answer);
    }
}

bool compareChaines(char *c1, char* c2){
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

bool affMot(struct E_coupleVoc *w, int c){
    int nbreHas = -1;
    switch(c){
	case 0:
	    printf("%s ? => ", w->motFr);
	    return true;

	case 1:
	    printf("%s ? => ", w->motEn);
	    return false;

	case 2:
	    nbreHas = rand()%2;
	    if(nbreHas){
		printf("%s ? => ", w->motFr);
		return true;
	    }
	    else{
		printf("%s ? => ", w->motEn);
		return false;
	    }

	default:
	    fprintf(stderr, "choix impossible : %d, fichier : %s, line : %d\n", c, __FILE__, __LINE__);
	    exit(0);
    }
}

void choixMode(int *mode, int *diff){
    printf("quel mode de jeu souhaitez-vous ?\n");
    printf("entrez 0 pour anglais -> francais\n");
    printf("entrez 1 pour francais -> anglais\n");
    printf("entrez 2 un mix entre les deux\n");
    scanf("%d", mode);
    while(*mode != 0 && *mode != 1 && *mode != 2){
	printf("saisie incorrecte. Recommencez\n");
        scanf("%d", mode);
	viderBuffeur();
    }

    printf("quel difficulté souhaitez-vous ?\n");
    printf("entrez 0 pour normal (les mots sont choisis aléatoirement dans toutes les listes)\n");
    printf("entrez 1 pour difficile (les mots sont choisis uniquement dans la liste de plus au niveau => les mots avec lesquelles vous avez le plus de mal\n");
    printf("avant le while\n");
    /*scanf("%d", diff);
    while(*diff != 0 && *diff != 1){ 
	printf("saisie incorrecte. Recommencez\n");
        scanf("%d", diff);
	printf("apres le scanf\n");
	viderBuffeur();
    }
    printf("avant le while\n");*/
    diff = 0; 
}

E_coupleVoc choixMot(struct L_coupleVoc l[], int *index, int diff){
    int max = nbreListe;
    int nbreHas = 0;
    if(diff == 0){
	do{
	    nbreHas = rand()%max;
	}while(l[nbreHas].first == NULL);
	*index = nbreHas;
    }
    else{
	*index = nbreListe-1;
	nbreHas = nbreListe-1;
    }
    return l[nbreHas].first;
}

int transfoNbre(int n){
    int t = n/4;
    printf("n : %d, t : %d\n", n, t);
    return t;
}
