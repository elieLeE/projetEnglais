#include "gestionStdin.h"

void viderBuffeur(){
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}


