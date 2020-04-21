#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

void pause();

int main(){

    SDL_Surface *ecran = NULL;
    SDL_Surface *zozor = NULL;
    SDL_Rect positionZozor;
    // initialisation de la postion de zozor
    positionZozor.x = 0;
    positionZozor.y = 0;


    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);
    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format, 255, 255, 255));
    SDL_WM_SetCaption("les evenements",NULL);

    zozor = SDL_LoadBMP("zozor.bmp");
    /* On centre Zozor à l'écran */
    positionZozor.x = ecran->w / 2 - zozor->w / 2;
    positionZozor.y = ecran->h / 2 - zozor->h / 2;
    SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 0, 0, 255));
    SDL_BlitSurface(zozor,NULL,ecran,&positionZozor);

    SDL_Flip(ecran);

    pause();
    SDL_FreeSurface(zozor);
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
