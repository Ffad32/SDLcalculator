#define  SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>

#include "funkce/funkce.h"

int main() {

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 576, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    const Uint8* state = SDL_GetKeyboardState(NULL);

    // buttons
    SDL_Rect button[10] = {
        (SDL_Rect){50, 350, 60, 40},
        (SDL_Rect){50, 300, 60, 40},
        (SDL_Rect){120, 300, 60, 40},
        (SDL_Rect){190, 300, 60, 40},
        (SDL_Rect){50, 250, 60, 40},
        (SDL_Rect){120, 250, 60, 40},
        (SDL_Rect){190, 250, 60, 40},
        (SDL_Rect){50, 200, 60, 40},
        (SDL_Rect){120, 200, 60, 40},
        (SDL_Rect){190, 200, 60, 40},
    };  

    SDL_Event event;
    bool quit = false;
    while (!quit){
        while (SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                quit = true;
            }
        }

        Uint32 state_m = SDL_GetMouseState(NULL, NULL);
        // Set render color to blue
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        // Clear the window with the render color
        SDL_RenderClear(renderer);

        // checks if the mouse is over the button
        for (int i = 0; i < 10; i++) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            if (x >= button[i].x && y >= button[i].y && x <= (button[i].x + button[i].w) && y <= (button[i].y + button[i].h)) {
                SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
                SDL_RenderFillRect(renderer, &button[i]);

        // checks if the button is clicked
                    static bool isFKeyPressed = false;
                    if(state_m & SDL_BUTTON(SDL_BUTTON_LEFT) && !isFKeyPressed){
                        isFKeyPressed = true;
                        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                        SDL_RenderFillRect(renderer, &button[i]);
                        printf("Button %d clicked\n", i);   
                        }

                        if(!state_m & SDL_BUTTON(SDL_BUTTON_LEFT)){

                        isFKeyPressed = false;
                        }

            } else {
                SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
                SDL_RenderFillRect(renderer, &button[i]);
            }

        }

        // Update the screen
        SDL_RenderPresent(renderer);

    }

    // Clean up resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
