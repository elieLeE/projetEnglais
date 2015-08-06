#include "fichier.h"

int main(){
    FILE *tabFichiers[127];

    struct L_coupleVoc l;
    ouvertureFichiers(tabFichiers);

    //lectureFichierVO(tabFichiers[0]);
    lectureFichiersVO(tabFichiers, &l);

    fermetureFichiers(tabFichiers);

    return 0;
}
