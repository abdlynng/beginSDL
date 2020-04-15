#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

void pause();

int main(){

    if (SDL_Init(SDL_INIT_VIDEO) == 0){
        // ( largeur, hauteur, nombre de pixel:32 est la valeur max, option:HWSURFACE chargement par le memoire video)
        SDL_SetVideoMode(500,500,32,SDL_HWSURFACE);
        SDL_WM_SetCaption("Ma premiere Fenetre C",NULL);
        pause();
    }
    else{
        // #Linux : la sortie d'erreur sera le console
        printf("erreur");
        // #Windows : la sortie d'eereur vers un fichier temporaire stderr
        fprintf(stderr,"Erreur de SDL %s\n",SDL_GetError());
        exit(EXIT_FAILURE);
    }

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
