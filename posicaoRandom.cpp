#include "posicaoRandom.h"
#include <time.h>
#include <cstdlib>
#include <iostream>

void posicaoRandom (int matriz[4][4], int vezesRandon){

    int linha,coluna,porcetagem;

    srand(time(NULL));

    for (int i=0; i<vezesRandon;i++) {
        do {
            linha = rand() % 4;
            coluna = rand() % 4;
        } while (matriz[linha][coluna] != 0);

        if (vezesRandon == 2){
            matriz[linha][coluna] = 2;
        } else {
            porcetagem = rand() % 100;

            if (porcetagem <= 70){
                matriz[linha][coluna] = 2;
            }else{
                matriz[linha][coluna] = 4;
            }
        }
    }
}
