#define  SDL_MAIN_HANDLED

#include <stdio.h>
#include <stdbool.h>
#include "funkce/windowgen.h"
#include "funkce/funkce.h"
#include "funkce/buttons.h"

int main() {
    Pack pack = {NULL,NULL};
    const Uint8* state = SDL_GetKeyboardState(NULL);
    // Initialize SDL
    window(&pack);
    // buttons
    SDL_Rect button[50] = {
        (SDL_Rect){350, 450, 50, 40},
        (SDL_Rect){350, 400, 50, 40},
        (SDL_Rect){410, 400, 50, 40},
        (SDL_Rect){470, 400, 50, 40},
        (SDL_Rect){350, 350, 50, 40},
        (SDL_Rect){410, 350, 50, 40},
        (SDL_Rect){470, 350, 50, 40},
        (SDL_Rect){350, 300, 50, 40},
        (SDL_Rect){410, 300, 50, 40},
        (SDL_Rect){470, 300, 50, 40},
        (SDL_Rect){410, 450, 50, 40},
        (SDL_Rect){470, 450, 50, 40},
        (SDL_Rect){530, 300, 40, 40},
        (SDL_Rect){530, 350, 40, 40},
        (SDL_Rect){530, 400, 40, 40},
        (SDL_Rect){530, 450, 40, 40},
        (SDL_Rect){580, 300, 40, 40},
        (SDL_Rect){580, 350, 40, 40},
        (SDL_Rect){580, 400, 40, 40},
        (SDL_Rect){580, 450, 40, 40},
        (SDL_Rect){350, 260, 40, 30},
        (SDL_Rect){396, 260, 40, 30},
        (SDL_Rect){442, 260, 40, 30},
        (SDL_Rect){488, 260, 40, 30},
        (SDL_Rect){534, 260, 40, 30},
        (SDL_Rect){580, 260, 40, 30},
        (SDL_Rect){350, 220, 40, 30},
        (SDL_Rect){396, 220, 40, 30},
        (SDL_Rect){442, 220, 40, 30},
        (SDL_Rect){488, 220, 40, 30},
        (SDL_Rect){534, 220, 40, 30},
        (SDL_Rect){580, 220, 40, 30}
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
        SDL_SetRenderDrawColor(pack.renderer, 0, 0, 0, 255);
        // Clear the window with the render color
        SDL_RenderClear(pack.renderer);

        // checks if the mouse is over the button
        for (int i = 0; i < 50; i++) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            if (x >= button[i].x && y >= button[i].y && x <= (button[i].x + button[i].w) && y <= (button[i].y + button[i].h)) {
                SDL_SetRenderDrawColor(pack.renderer, 50, 50, 50, 255);
                SDL_RenderFillRect(pack.renderer, &button[i]);

        // checks if the button is clicked
                    static bool isFKeyPressed = false;
                    if(state_m & SDL_BUTTON(SDL_BUTTON_LEFT) && !isFKeyPressed){
                        isFKeyPressed = true;
                        SDL_SetRenderDrawColor(pack.renderer, 255, 0, 0, 255);
                        SDL_RenderFillRect(pack.renderer, &button[i]);
                        printf("Button %d clicked\n", i);
                        buttons(i);
                        }

                        if(!state_m & SDL_BUTTON(SDL_BUTTON_LEFT)){

                        isFKeyPressed = false;
                        }

            } else {
                SDL_SetRenderDrawColor(pack.renderer, 100, 100, 100, 255);
                SDL_RenderFillRect(pack.renderer, &button[i]);
            }

        }

        // Update the screen
        SDL_RenderPresent(pack.renderer);

    }
    end(&pack);
    return 0;
}
