#ifndef WINDOWGEN_H
#define WINDOWGEN_H
#include <SDL.h>
#include <stdio.h>

typedef struct Pack{
 SDL_Window* window;
 SDL_Renderer* renderer;
} Pack;

int window(Pack *pack){
        // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create a window
    pack->window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 576, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    // Create a renderer
    pack->renderer = SDL_CreateRenderer(pack->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (pack->renderer == NULL) {
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(pack->window);
        SDL_Quit();
        return 1;
    }
    //SDL_RenderSetLogicalSize(pack->renderer, 1024, 576);

}
void end(Pack *pack){
    SDL_DestroyRenderer(pack->renderer);
    SDL_DestroyWindow(pack->window);
    SDL_Quit();
    printf("End\n");
}
#endif