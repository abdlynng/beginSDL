#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

void pause();

int main(){

    SDL_Surface *ecran = NULL;

    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(815,500,32,SDL_HWSURFACE);
    SDL_WM_SetCaption("les evenements",NULL);

    pause();

    SDL_Quit();
    return EXIT_SUCCESS;
}

void pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym){
                    case SDLK_ESCAPE:
                        continuer = 0;
                        break;
                }
                break;
        }
    }
}
