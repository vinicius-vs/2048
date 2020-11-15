#include <SDL2/SDL.h>

#ifndef UNTITLED2_TELASDL_H
#define UNTITLED2_TELASDL_H
void tela(SDL_Renderer * render, SDL_Texture* Map, SDL_Texture* SpriteSheet, int matriz[4][4]);
SDL_Texture* CarregarImg(const char *arquivo, SDL_Renderer* render);
#endif //UNTITLED2_TELASDL_H
