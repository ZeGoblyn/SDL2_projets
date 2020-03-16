#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
//#include "SDL2/SDL_image.h"
#include "voidCarrés.h"

int main(int argc, char *argv[])    //arguments obligatoire pour compiler en SDL
{

    SDL_Window *pWindow=NULL;           //Pointeur sur la fenêtre, ref d'un window win32
    SDL_Renderer *pRenderer=NULL;       //Pointeur sur le Rendus, ref rendu encapsulé dans window
    SDL_Texture *pTexture=NULL;         //Pointeur sur la texture, qui possède l'image à afficher, ref image/texture/materiel


    //Requis pour utiliser la SDL
    if(SDL_Init(SDL_INIT_EVERYTHING)>=0)    //INIT_EVERYTHING = initialise l'audio, la vidéo, les contrôles,... cf; SDL wiki/API by name/SDL_Init
    {
        //succès, créer window
        pWindow=SDL_CreateWindow("SDL_Application",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 780, SDL_WINDOW_SHOWN);//x,y,width,eight

        //si succès, créer window et renderer
        if(pWindow!=NULL)
        {
            pRenderer=SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_PRESENTVSYNC);
           /* }
            else
            {*/

            SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderPresent(pRenderer);   //afficher le Renderer



            SDL_Delay(2000);

            SDL_SetRenderDrawColor(pRenderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderClear(pRenderer);
            SDL_RenderPresent(pRenderer);


            SDL_Rect rect;
            rect.x = 250;
            rect.y = 150;
            rect.w = 200;
            rect.h = 200;

            SDL_Rect rectP;
            rectP.x = 600;
            rectP.y = 150;
            rectP.w = 200;
            rectP.h = 200;


            carreVide(pRenderer, &rect);

            carrePlain(pRenderer, &rectP);

            cercleVide(pRenderer, 350, 500, 100, 1000);

            cerclePlein(pRenderer, 700, 500, 100, 1000);
    /*
            //----------------------------------------------------------------------------//
            //Dessein d'un carré vide
            SDL_Rect rect;
            rect.x = 250;
            rect.y = 150;
            rect.w = 200;
            rect.h = 200;

            SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
            SDL_RenderDrawRect(pRenderer, &rect);

            SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);

            SDL_RenderPresent(pRenderer);
            //----------------------------------------------------------------------------//


            //----------------------------------------------------------------------------//
            //Dessein d'un carré plain
            SDL_Rect rectP;
            rectP.x = 600;
            rectP.y = 150;
            rectP.w = 200;
            rectP.h = 200;

            SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
            SDL_RenderDrawRect(pRenderer, &rectP);

            SDL_RenderFillRect(pRenderer, &rectP);

            SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);

            SDL_RenderPresent(pRenderer);
            //----------------------------------------------------------------------------//
    */

            //----------------------------------------------------------------------------//
            //Dessein d'un cercle vide
             SDL_SetRenderTarget(pRenderer, NULL);


            //----------------------------------------------------------------------------//


             //----------------------------------------------------------------------------//
            //Création d'une texture
            pTexture = SDL_CreateTexture(pRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 100, 100);

            SDL_Rect rectT = {150, 0, 100, 100}; //création d'un carré acceuillant la texture
            SDL_SetRenderDrawColor(pRenderer, 0, 0, 255, 255); //mise en place du dessein dans la texture
            SDL_RenderFillRect(pRenderer, &rectT);

            SDL_SetRenderTarget(pRenderer, pTexture);
            SDL_Rect dst = {0, 0, 100, 100};
            SDL_Rect src = {10, 10, 100, 100};
            SDL_RenderCopy(pRenderer, pTexture, &src, &dst);
            SDL_RenderPresent(pRenderer);

            //----------------------------------------------------------------------------//


            //----------------------------------------------------------------------------//
            //Création d'une texture à partir d'un BMP
            SDL_SetRenderTarget(pRenderer, NULL); //redéfinitions de la zone de travail
            SDL_Surface* pBmp = SDL_LoadBMP("Sprite_Gimli2.bmp");
            SDL_Texture* Image = SDL_CreateTextureFromSurface(pRenderer,pBmp);

            SDL_FreeSurface(pBmp);

            if (Image == NULL)
              printf("erreur");

            SDL_Rect myRect;
            myRect.x = 0;
            myRect.y = 0;
            SDL_QueryTexture(Image, NULL, NULL, &myRect.w, &myRect.h);//Récupère le format de l'image

            SDL_RenderCopy(pRenderer, Image, NULL, &myRect);
            SDL_RenderPresent(pRenderer);
            //----------------------------------------------------------------------------//


            SDL_Delay(10000);

            SDL_DestroyRenderer(pRenderer); //On supprime tout ce qui à été créer
            SDL_DestroyWindow(pWindow);
            SDL_Quit();

        }
    }



    return 0;
}


