#include "voidCarr�s.h"

//----------------------------------------------------------------------------//
//Dessein d'un carr� vide
int carreVide(SDL_Renderer *pRenderer, SDL_Rect*rect)
{

        /*SDL_Rect rect;
        rect.x = 250;
        rect.y = 150;
        rect.w = 200;
        rect.h = 200;*/

        SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
        SDL_RenderDrawRect(pRenderer, rect);

        SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);

        SDL_RenderPresent(pRenderer);

        return(pRenderer);
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
//Dessein d'un carr� plain
int carrePlain(SDL_Renderer *pRenderer, SDL_Rect*rectP)
{
        /*SDL_Rect rectP;
        rectP.x = 600;
        rectP.y = 150;
        rectP.w = 200;
        rectP.h = 200;*/

        SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
        SDL_RenderDrawRect(pRenderer, rectP);

        SDL_RenderFillRect(pRenderer, rectP);

        SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);

        SDL_RenderPresent(pRenderer);

        return(pRenderer);
}
//----------------------------------------------------------------------------//
