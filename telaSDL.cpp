#include "telaSDL.h"
#include "iostream"
#include <SDL2/SDL.h>

SDL_Texture* CarregarImg(const char *arquivo, SDL_Renderer* render){
    SDL_Surface* img = SDL_LoadBMP(arquivo);
    if (img == NULL){
        std::cout<<SDL_GetError()<<std::endl;
    }
    SDL_Texture* textura = SDL_CreateTextureFromSurface(render,img);
    if (textura == NULL){
        std::cout<<SDL_GetError();
    }
    SDL_FreeSurface(img);

    return textura;
}

void tela(SDL_Renderer * render, SDL_Texture* Map, SDL_Texture* SpriteSheet, int matriz[4][4]){

   // SDL_RenderClear(render);
    SDL_RenderCopy(render, Map, NULL, NULL);

    SDL_Rect origem;
    origem.x = 0;
    origem.w = 64;
    origem.h = 64;

    SDL_Rect destino;
    destino.w = 64;
    destino.h = 64;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if(matriz[i][j] == 2){
                origem.y =0;
                destino.x = 10 + (j * 64);
                destino.y = 10 + (i * 64);
                SDL_RenderCopy(render, SpriteSheet, &origem, &destino);
            } else if(matriz[i][j] == 4){
                origem.y = 64;
                destino.x = 10 + (j * 64);
                destino.y = 10 + (i * 64);
                SDL_RenderCopy(render, SpriteSheet, &origem, &destino);
            } else if(matriz[i][j] == 8){
                origem.y = 128;
                destino.x = 10 + (j * 64);
                destino.y = 10 + (i * 64);
                SDL_RenderCopy(render, SpriteSheet, &origem, &destino);
            } else if(matriz[i][j] == 16){
                origem.y = 192;
                destino.x = 10 + (j * 64);
                destino.y = 10 + (i * 64);
                SDL_RenderCopy(render, SpriteSheet, &origem, &destino);
            } else if(matriz[i][j] == 32){
                origem.y = 256;
                destino.x = 10 + (j * 64);
                destino.y = 10 + (i * 64);
                SDL_RenderCopy(render, SpriteSheet, &origem, &destino);
            } else if(matriz[i][j] == 64){
                origem.y = 320;
                destino.x = 10 + (j * 64);
                destino.y = 10 + (i * 64);
                SDL_RenderCopy(render, SpriteSheet, &origem, &destino);
            } else if(matriz[i][j] == 128){
                origem.y = 384;
                destino.x = 10 + (j * 64);
                destino.y = 10 + (i * 64);
                SDL_RenderCopy(render, SpriteSheet, &origem, &destino);
            } else if(matriz[i][j] == 256){
                origem.y = 448;
                destino.x = 10 + (j * 64);
                destino.y = 10 + (i * 64);
                SDL_RenderCopy(render, SpriteSheet, &origem, &destino);
            } else if(matriz[i][j] == 512){
                origem.y = 512;
                destino.x = 10 + (j * 64);
                destino.y = 10 + (i * 64);
                SDL_RenderCopy(render, SpriteSheet, &origem, &destino);
            } else if(matriz[i][j] == 1024){
                origem.y = 576;
                destino.x = 10 + (j * 64);
                destino.y = 10 + (i * 64);
                SDL_RenderCopy(render, SpriteSheet, &origem, &destino);
            } else if(matriz[i][j] == 2048){
                origem.y = 640;
                destino.x = 10 + (j * 64);
                destino.y = 10 + (i * 64);
                SDL_RenderCopy(render, SpriteSheet, &origem, &destino);
            } else if(matriz[i][j] == 3){
            origem.y = 704;
            destino.x = 10 + (j * 64);
            destino.y = 10 + (i * 64);
            SDL_RenderCopy(render, SpriteSheet, &origem, &destino);
        }else if(matriz[i][j] == 5){
                origem.y = 768;
                destino.x = 10 + (j * 64);
                destino.y = 10 + (i * 64);
                SDL_RenderCopy(render, SpriteSheet, &origem, &destino);
            }
        }
    }
    SDL_RenderPresent(render);
}
