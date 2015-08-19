#include "menu.h"

void affMenu(){
    printf("\n");
    printf("que souhaitez-vous faire ?\n");
    printf("\tentrez 0 pour jouer\n");
    printf("\tentrez 1 pour ajouter des couples de mots\n");
    printf("\tentrez 2 pour modifier des couples de mots\n");
    printf("\tentrez 3 pour supprimer des couples de mots\n");
    printf("\tentrez 4 pour quitter\n");

    printf("\tentrez 5 pour tout visualiser\n");
}

void menu(struct L_coupleVoc *l){
    int c_tmp;
    Choice c;

    affMenu();

    do{
	scanf("%d", &c_tmp);
	c = (Choice)c_tmp;
	printf("\n");
	switch(c){
	    case JEU:
		printf("\n");
		game(l);
		affMenu();
		break;

	    case ADD_WORDS :
		printf("add words\n");
		addCouples(&l[nbreListe-1]);
		affMenu();
		break;

	    case SUPR_WORDS :
		printf("supe words\n");
		supprimerCouples(l);
		affMenu();
		break;

	    case MODIFY_WORDS :
		printf("modifier words\n");
		modifierCouples(l);
		affMenu();
		break;

	    case QUIT :
		break;

	    case VISU :
		visuHachTab(l);
		affMenu();
		break;

	    default:
		printf("choix non reconnu. Veuillez recommencez\n");
		break;
	}
    }while(c != QUIT);
}

void addCouples(struct L_coupleVoc *l){
    char motFr[20], motEn[20];
    int choix = 0;
    do{
	printf("entrez le mot francais => ");
	scanf("%s", motFr);
	viderBuffeur();

	printf("entrez le mot anglais => ");
	scanf("%s", motEn);
	viderBuffeur();

	addFirstVO(l, motFr, motEn);

	printf("\nsouhaitez-vous ajouter un autre couple ?\n");
	printf("entrez 1 pour oui et 0 pour non\n");
	scanf("%d", &choix);
	viderBuffeur();
    }while(choix != 0);
}

void supprimerCouples(struct L_coupleVoc *l){
    printf("NOT YET IMPELMENTED\n");

    struct E_coupleVoc* e = searchElem(l, "supprimer");
}

void modifierCouples(struct L_coupleVoc *l){
    printf("NOT YET IMPELMENTED\n");
}
