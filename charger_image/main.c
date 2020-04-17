#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

void pause();

int main(){

    SDL_Surface *ecran = NULL;
    SDL_Surface *imageFond = NULL, *zozor = NULL;
    SDL_Rect positionImageFond, positionZozor;

    positionImageFond.x = 0;
    positionImageFond.y = 0;
    positionZozor.x = 500;
    positionZozor.y =  260;

    SDL_Init(SDL_INIT_VIDEO);

    /* charcgement de l'icone juste avant l'ouverture de la surface */
    SDL_WM_SetIcon(SDL_LoadBMP("sdl_icone.bmp"), NULL);

    ecran = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);
    SDL_WM_SetCaption("chargement image de fond", NULL);

    imageFond = SDL_LoadBMP("lac_en_montagne.bmp");
    SDL_BlitSurface(imageFond,NULL,ecran,&positionImageFond);

    /* On charge l'image : */
    zozor = SDL_LoadBMP("zozor.bmp");
    /* On rend le bleu derrière Zozor transparent : */
    SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 0, 0, 255));
    /* On blitte l'image maintenant transparente sur le fond : */
    SDL_BlitSurface(zozor, NULL, ecran, &positionZozor);

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
