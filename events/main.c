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

    int largeurEcran = 800;
    int hauteurEcran = 600;

    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(largeurEcran,hauteurEcran,32,SDL_HWSURFACE | SDL_DOUBLEBUF |SDL_RESIZABLE);
    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format, 255, 255, 255));
    SDL_WM_SetCaption("les evenements",NULL);

    zozor = SDL_LoadBMP("zozor.bmp");
    /* On centre Zozor à l'écran */
    positionZozor.x = ecran->w / 2 - zozor->w / 2;
    positionZozor.y = ecran->h / 2 - zozor->h / 2;
    SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 0, 0, 255));
    SDL_BlitSurface(zozor,NULL,ecran,&positionZozor);
    SDL_Flip(ecran);

    int continuer = 1;
    SDL_Event event;
    //pour enfoncer une touche du clavier
    SDL_EnableKeyRepeat(10, 10);
    //masquer la position de la souris
    SDL_ShowCursor(SDL_DISABLE); //enable pour la demasquer
    //placer le curseur de la souris manuellemnt
    SDL_WarpMouse(ecran->w / 2, ecran->h / 6);
    //programme prncipale du deplacement de zozor
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
                    case SDLK_LEFT:
                        positionZozor.x = positionZozor.x - 3;
                        break;

                    case SDLK_RIGHT:
                        if(positionZozor.x < largeurEcran)
                            positionZozor.x = positionZozor.x + 3;
                        else
                            positionZozor.x = 0;
                        break;

                    case SDLK_UP:
                        positionZozor.y = positionZozor.y - 3;
                        break;

                    case SDLK_DOWN:
                        if (positionZozor.y < hauteurEcran)
                            positionZozor.y = positionZozor.y + 3;
                        else
                            positionZozor.y = 0;
                        break;
                }
                break;

            case SDL_MOUSEBUTTONUP:
                if(event.button.button == SDL_BUTTON_LEFT){
                    positionZozor.x = event.button.x;
                    positionZozor.y = event.button.y;
                }
                else if(event.button.button == SDL_BUTTON_RIGHT)
                    continuer = 0;
                else;
                break;

            case SDL_MOUSEMOTION:
                positionZozor.x = event.motion.x;
                positionZozor.y = event.motion.y;
                break;

            case SDL_VIDEORESIZE:
                positionZozor.x = event.resize.w/2;
                positionZozor.y = event.resize.h/2;
                break;

        }
        SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format, 255, 255, 255));
        SDL_BlitSurface(zozor,NULL,ecran,&positionZozor);
        SDL_Flip(ecran);
    }

    SDL_FreeSurface(zozor);
    SDL_Quit();
    return EXIT_SUCCESS;
}
