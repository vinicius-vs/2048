#include "evento.h"
#include <SDL2/SDL.h>
#include <iostream>
#include "posicaoRandom.h"
#include "telaSDL.h"

void eventos(int matriz[4][4], bool &gameOver) {
    const int TAM = 3;
    SDL_Event event;

    while(SDL_PollEvent(&event)){

        switch (event.type) {
            case SDL_QUIT:
                gameOver = true;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {

                    case SDLK_LEFT:
                    case SDLK_a:

                        for (int a = 0; a < 3; a++) {
                            for (int i = 0; i <= TAM; i++) {
                                for (int j = 0; j < TAM; j++) {
                                    if (matriz[i][j] == 0) {
                                        matriz[i][j] = matriz[i][j + 1];
                                        matriz[i][j + 1] = 0;
                                    } else if (matriz[i][j] == matriz[i][j + 1]) {
                                        matriz[i][j] = matriz[i][j] + matriz[i][j + 1];
                                        matriz[i][j + 1] = 0;
                                    }
                                }
                            }
                        }
                        posicaoRandom(matriz);
                        break;

                    case SDLK_RIGHT:
                    case SDLK_d:
                        for (int a = 0; a < 3; a++) {
                            for (int i = 0; i <= TAM; i++) {
                                for (int j = 3; j > 0; j--) {
                                    if (matriz[i][j] == 0) {
                                        matriz[i][j] = matriz[i][j - 1];
                                        matriz[i][j - 1] = 0;
                                    } else if (matriz[i][j] == matriz[i][j - 1]) {
                                        matriz[i][j] = matriz[i][j] + matriz[i][j - 1];
                                        matriz[i][j - 1] = 0;
                                    }
                                }
                            }
                        }
                        posicaoRandom(matriz);
                        break;

                    case SDLK_DOWN:
                    case SDLK_s:
                        for (int a = 0; a < 3; a++) {
                            for (int i = 3; i > 0; i--) {
                                for (int j = 0; j <= TAM; j++) {
                                    if (matriz[i][j] == 0) {
                                        matriz[i][j] = matriz[i - 1][j];
                                        matriz[i - 1][j] = 0;
                                    } else if (matriz[i][j] == matriz[i - 1][j]) {
                                        matriz[i][j] = matriz[i][j] + matriz[i - 1][j];
                                        matriz[i - 1][j] = 0;
                                    }
                                }
                            }
                        }
                        posicaoRandom(matriz);
                        break;

                    case SDLK_UP:
                    case SDLK_w:
                        for (int a = 0; a < 3; a++) {
                            for (int i = 0; i < TAM; i++) {
                                for (int j = 0; j <= TAM; j++) {
                                    if (matriz[i][j] == 0) {
                                        matriz[i][j] = matriz[i + 1][j];
                                        matriz[i + 1][j] = 0;
                                    } else if (matriz[i][j] == matriz[i + 1][j]) {
                                        matriz[i][j] = matriz[i][j] + matriz[i + 1][j];
                                        matriz[i + 1][j] = 0;
                                    }
                                }
                            }
                        }

                        posicaoRandom(matriz);
                        break;
                }
                break;
        }
    }
}

void verificador(int matriz[4][4], bool &gameOver) {

    int cont = 0;


    //laço de vitoria
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (matriz[i][j] != 0) {
                if (matriz[i][j] == 2048) {

                    gameOver = true;
                    for (int a = 0; a < 4; a++) {
                        for (int b = 0; b < 4; b++) {
                            matriz[a][b] = 3;
                        }
                    }
                }
            }
        }
    }

    //laço de derrota
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (matriz[i][j] > 0 && matriz[i][j] != 3) {
                if (i < 3 and j < 3) {
                    if (matriz[i][j] != matriz[i + 1][j] or matriz[i][j] != matriz[i][j + 1]) {
                        cont ++;
                        std::cout<<cont<<std::endl;
                    } else{
                        cont=0;
                    }
                    } else if (j == 3 and i < 3 ) {
                        if (matriz[i][j] != matriz[i +1 ][j]) {
                            cont ++;
                            std::cout<<cont<<std::endl;
                        }
                    }else if ( i == 3 and j < 3) {
                        if (matriz[i][j] != matriz[i][j + 1]){
                            cont++;
                            std::cout<<cont<<std::endl;
                        }
                    }else{

                        cont = 0;
                        //std::cout<<cont<<std::endl;
                    }


            }
        }
    }

    if(cont>=15){
        gameOver=true;
        for(int i = 0; i < 4;i++){
            for (int j = 0; j < 4;j++){
                matriz[i][j] = 5;
            }
        }

    }
}