#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

void pause();

int main(){

    SDL_Surface *ecran = NULL;
    SDL_Surface *rectangle = NULL;
    SDL_Rect position;

    if (SDL_Init(SDL_INIT_VIDEO) == 0){
        // ( largeur, hauteur, nombre de pixel:32 est la valeur max, option:HWSURFACE chargement par le memoire video)
        ecran = SDL_SetVideoMode(500,500,32,SDL_HWSURFACE);
        SDL_WM_SetCaption("Ma premiere Fenetre C",NULL);
        // on colorie toute la fenetre en vert clair
        SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,100,250,100));

        rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE,250,250,32,0,0,0,0);
        SDL_FillRect(rectangle,NULL,SDL_MapRGB(rectangle->format,100,0,100));

        position.x = 125;
        position.y = 125;
        // collage de la surface rectangle dans la surface ecran avec les coordonnees position
        SDL_BlitSurface(rectangle,NULL,ecran,&position);

        SDL_Flip(ecran); // on met a jour le fenetre
        pause();

    }
    else{
        // #Linux : la sortie d'erreur sera le console
        printf("erreur");
        // #Windows : la sortie d'eereur vers un fichier temporaire stderr
        fprintf(stderr,"Erreur de SDL %s\n",SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_FreeSurface(rectangle); //liberer la memoire occupée par la surface rectangle
    // pour sortir proprement de SDL
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
