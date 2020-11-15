#define SDL_MAIN_HANDLED
#include <iostream>
#include "posicaoRandom.h"
#include "evento.h"
#include "telaSDL.h"
#include <SDL2/SDL.h>
using namespace std;

int main() {

    int matriz[4][4] = {0};
    bool gameOver = false;

    posicaoRandom(matriz,2);

    if (SDL_Init(SDL_INIT_VIDEO < 0))
        cout << &SDL_GetError << endl;

    SDL_Window *janela;

    janela = SDL_CreateWindow("2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 276, 276, 0);
    if (janela == NULL){
        cout<<SDL_GetError<<endl;
    }

    SDL_Renderer* render = SDL_CreateRenderer(janela, -1,SDL_RENDERER_ACCELERATED);
    if (render == NULL){
        cout<<SDL_GetError<<endl;
    }
    SDL_SetRenderDrawColor(render,255,255,255,0);

    SDL_Texture* mapa =  CarregarImg("mapa.bmp", render);

    SDL_Texture* SpriteSheet = CarregarImg("SpriteSheet.bmp",render);

    SDL_RenderClear(render);

    tela(render, mapa,SpriteSheet,matriz);

    while (!gameOver){
             eventos(matriz, gameOver);
             verificador(matriz,gameOver);
             tela(render, mapa,SpriteSheet,matriz);
        }


    tela(render, mapa,SpriteSheet,matriz);
    SDL_Delay(2000);
    }

