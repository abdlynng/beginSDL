#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

void pause();

int main(){

    SDL_Surface *ecran = NULL;
    SDL_Surface *imageFond = NULL;
    SDL_Rect positionImageFond;

    positionImageFond.x = 0;
    positionImageFond.y = 0;

    SDL_Init(SDL_INIT_VIDEO);

    /* charcgement de l'icone juste avant l'ouverture de la surface */
    SDL_WM_SetIcon(SDL_LoadBMP("sdl_icone.bmp"), NULL);

    ecran = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);
    SDL_WM_SetCaption("chargement image de fond", NULL);

    imageFond = SDL_LoadBMP("lac_en_montagne.bmp");
    SDL_BlitSurface(imageFond,NULL,ecran,&positionImageFond);

    SDL_Flip(ecran);
    pause();
    SDL_FreeSurface(imageFond);

    SDL_Quit();
    return EXIT_SUCCESS;
}

/* pour mettre en pause notre programme
*  et fquitter la fenetre par le clic du bouton quitter
*/
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
        }
    }
}
