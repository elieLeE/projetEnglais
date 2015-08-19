#include <time.h>
#include "fichier.h"
#include "listeVO.h"
#include "jeu.h"
#include "donnees.h"
#include "menu.h"

int main(){
    srand(time(NULL));

    lectureFichierConfig();
    printf("nbreMots : %d, nbreListe : %d\n", nbreMots, nbreListe);
    struct L_coupleVoc *l = (struct L_coupleVoc*)calloc(nbreListe, sizeof(struct L_coupleVoc));
    if(l == NULL){
	fprintf(stderr, "l non allouée\n");
	exit(0);
    }

    initStructsVO(l);
    lectureFichiersVO(l);

    menu(l);

    ecritureFichiers(l);
    freeStructures(l);
    free(l);

    return 0;
}
