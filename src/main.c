#define  SDL_MAIN_HANDLED

#include <stdio.h>
#include <stdbool.h>
#include "funkce/windowgen.h"
#include "funkce/funkce.h"
#include "funkce/buttons.h"
int finalsorage = 0;
int main() {
    int storage[50]= {0,0,0,0,0,0,0,0,0,0,0,0};
    int storagenum = 0;
    int key[50];
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
                        storage[storagenum] = buttons(i, storage[storagenum],&storagenum, &key[storagenum]);
                        printf("storage: %d\n", storage[storagenum]);
                        }

                        if(!state_m & SDL_BUTTON(SDL_BUTTON_LEFT)){

                        isFKeyPressed = false;
                        }

            } else {
                SDL_SetRenderDrawColor(pack.renderer, 100, 100, 100, 255);
                SDL_RenderFillRect(pack.renderer, &button[i]);
            }
            if (i == 17) {
                // evaluation 
                for(int i= 0; i < 50; i++){
                    if(i == 15 || i == 16 ){
                        if(storage[i] == 15){
                            finalsorage = storage[i-1] * storage[i];
                            printf("finalsorage: %d\n", finalsorage);
                        }
                        if(storage[i] == 16){
                            finalsorage = storage[i-1] / storage[i];
                            printf("finalsorage: %d\n", finalsorage);
                        }
                    }
                    }
                

            }

        }

        // Update the screen
        SDL_RenderPresent(pack.renderer);

    }
    end(&pack);
    printf("storage: %d\n", storage[storagenum]);
    return 0;
}
