#include "fichier.h"
#include "listeVO.h"
#include "jeu.h"
#include <time.h>

int main(){
    struct L_coupleVoc l[127];
    nbreListe = 4;
    srand(time(NULL));

    initStructsVO(l);
    lectureFichiersVO(l);

    /*printf("visu : \n");
    visuListeVO(l[0].first);*/

    char* motEn = "five";
    char* motFr = "cinq";
    printf("motFr : %s, motEn : %s\n", motFr, motEn);

    int s = 0, d = 1;

    addFirstVO(&l[s], motEn, motFr);
    /*printf("visu l[%d] : \n", s);
    visuListeVO(l[s].first);*/

    /*moveElemVO(&l[s], &l[d]);
    moveElemVO(&l[s], &l[d]);
    moveElemVO(&l[s], &l[d]);
    moveElemVO(&l[s], &l[d]);
    moveElemVO(&l[s], &l[d]);
    printf("visu l[%d] : \n", s);
    visuListeVO(l[s].first);
    printf("visu l[%d] : \n", d);
    visuListeVO(l[d].first);*/
    
    game(l);
    freeStructures(l);
    /*if(compareChaines("hello", "hello")){
	printf("les chaines sont identiques\n");
    }
    else{
	printf("les chaines ne sont pas identiques\n");
    }

    ecritureFichiers(l);
    lectureFichiersVO(l);
    lectureFichiersVO(l);
    visuHachTab(l);

    printf("main fini\n");*/
    return 0;
}
