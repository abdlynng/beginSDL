#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

void pause();

int main(){

    SDL_Surface *ecran = NULL;
    SDL_Surface *ligne[256] = {NULL};
    int i = 0;
    SDL_Rect position;
    int hauteur = 512;

    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(600,hauteur,32,SDL_HWSURFACE);
    SDL_WM_SetCaption("fenetre degrade", NULL);

    for (i=0; i<256; i++){
        position.x = 0;
        position.y = i;

        *(ligne+i)= SDL_CreateRGBSurface(SDL_SWSURFACE,600,1,32,0,0,0,0);
        SDL_FillRect(ligne[i],NULL,SDL_MapRGB(ecran->format,i,i,i));
        SDL_BlitSurface(ligne[i],NULL,ecran,&position);
    }

    for (i=255; i>=0; i--){
        position.x = 0;
        position.y = hauteur-i;

        *(ligne+i)= SDL_CreateRGBSurface(SDL_SWSURFACE,600,1,32,0,0,0,0);
        SDL_FillRect(ligne[i],NULL,SDL_MapRGB(ecran->format,i,i,i));
        SDL_BlitSurface(ligne[i],NULL,ecran,&position);
    }

    SDL_Flip(ecran);

    pause();

    for (i = 0 ; i < hauteur ; i++) //libérer les 256 surfaces
        SDL_FreeSurface(ligne[i]);

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
