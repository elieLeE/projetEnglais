#include "menu.h"

void affMenu(){
    printf("\n");
    printf("que souhaitez-vous faire ?\n");
    printf("\tentrez %d pour jouer\n", JEU);
    printf("\tentrez %d pour ajouter des couples de mots\n", ADD_WORDS);
    printf("\tentrez %d pour modifier des couples de mots\n", MODIFY_WORDS);
    printf("\tentrez %d pour supprimer des couples de mots\n", SUPR_WORDS);
    printf("\tentrez %d pour tout visualiser\n", VISU);
    printf("\tentrez %d pour visualiser vos statistiques\n", VISU_STATS);
    printf("\tentrez %d pour cleaner vos statistiques\n", STATS_0);
    printf("\tentrez %d pour mélanger\n", MELANGER);
    printf("\tentrez %d pour quitter\n", QUIT);
}

void menu(struct L_coupleVoc *l){
    int c_tmp;
    Choice c;

    do{
	affMenu();
	scanf("%d", &c_tmp);
	viderBuffeur();
	c = (Choice)c_tmp;
	printf("\n");
	switch(c){
	    case JEU:
		printf("\n");
		game(l);
		break;

	    case ADD_WORDS :
		printf("add words\n");
		addCouples(&l[nbreListe-1]);
		break;

	    case SUPR_WORDS :
		printf("supe words\n");
		supprimerCouples(l);
		break;

	    case MODIFY_WORDS :
		printf("modifier words\n");
		modifierCouples(l);
		break;

	    case QUIT :
		break;

	    case VISU :
		visuHachTab(l);
		break;

	    case VISU_STATS:
		visuStats();	
		break;

	    case STATS_0:
		cleanStats();
		break;

	    case MELANGER:
		printf("NOT YET IMPLEMENTED\n");
		break;

	    default:
		printf("choix non reconnu. Veuillez recommencez\n");
		break;
	}
    }while(c != QUIT);
}

void cleanStats(){
    ecritureStats(0, 0);
}

void visuStats(){
    int nbreQ = 0, nbreR = 0;
    lectureStats(&nbreQ, &nbreR);
    printf("nbre de mots : %d\nnbre de questions : %d\nnbre de bonne réponse : %d => %.1lf \n", nbreMots, nbreQ, nbreR, ((1.0*nbreR)/nbreQ)*100);
}

void addCouples(struct L_coupleVoc *l){
    char motFr[20], motEn[20];
    int choix = 0, has = 0;
    do{
	viderBuffeur();
	printf("entrez le mot francais => ");
	scanf("%s", motFr);
	viderBuffeur();

	printf("entrez le mot anglais => ");
	scanf("%s", motEn);
	viderBuffeur();

	has = rand()%nbreListe;
	assert((has >=0) && (has<nbreListe));
	addFirstVO(&l[has], motFr, motEn);

	printf("\nsouhaitez-vous ajouter un autre couple ?\n");
	printf("entrez 1 pour oui et 0 pour non\n");
	scanf("%d", &choix);
    }while(choix != 0);
    viderBuffeur();
}

void supprimerCouples(struct L_coupleVoc *l){
    printf("NOT YET IMPELMENTED : %s\n", l->first->motFr);

    //struct E_coupleVoc* e = searchElem(l, "supprimer");
}

void modifierCouples(struct L_coupleVoc *l){
    printf("NOT YET IMPELMENTED\n");
}
