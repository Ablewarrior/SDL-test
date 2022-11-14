#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "../header_files/main.h"
#include "../header_files/draw_grille.h"
//test 14/11

#define WINDOW_WDTH 640
#define WINDOW_HEIGHT 480

//  Limit à 60 FPS
#define FPS_LIMIT 16

//cd C:\Users\maxim\OneDrive - GROUPE 3IL\CPi2\Algorithmique 2\Projet Morpion\Code>
//gcc src/source_files/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2

//cd bin
//prog.exe

int main(int argc, char **argv)
{
	/*--------------------------------------------------------------------------*/

	SDL_version nb;
	SDL_VERSION(&nb);
	printf("\nBienvenue sur SDL %d.%d.%d. !\n\n", nb.major, nb.minor, nb.patch);

	/*--------------------------------------------------------------------------*/

	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	// Lancement SDL
	if(SDL_Init(SDL_INIT_VIDEO) != 0){
		SDL_ExitWithError("Initialisation SDL");
	}

	// Creer Fenetre et Rendu
	if(SDL_CreateWindowAndRenderer(600,600, 0, &window, &renderer) != 0){
		SDL_ExitWithError("Impossible de creer la fenetre et le rendu");
	}
	
	SDL_SetWindowTitle(window, "Morpion");

	// SDL_RenderDrawLine(renderer, 200, 0, 200, 600);
	// SDL_RenderDrawLine(renderer, 400, 0, 200, 600);

	if(SDL_SetRenderDrawColor (renderer, 197, 123, 40, SDL_ALPHA_OPAQUE) != 0){
		SDL_ExitWithError("Impossible de changer la couleur pour le rendu");
	}

	// SDL_Rect rectangle1;
	// SDL_Rect rectangle2;
	// SDL_Rect rectangle3, rectangle4, rectangle5, rectangle6, rectangle7, rectangle8, rectangle9;

	// rectangle1.x = 0;
	// rectangle1.y = 0;
	// rectangle1.w = 200;
	// rectangle1.h = 200;

	// rectangle2.x = 200;
	// rectangle2.y = 0;
	// rectangle2.w = 200;
	// rectangle2.h = 200;

	// rectangle3.x = 400;
	// rectangle3.y = 0;
	// rectangle3.w = 400;
	// rectangle3.h = 200;

	// rectangle4.x = 0;
	// rectangle4.y = 200;
	// rectangle4.w = 200;
	// rectangle4.h = 200;

	// rectangle5.x = 200;
	// rectangle5.y = 200;
	// rectangle5.w = 200;
	// rectangle5.h = 200;

	// rectangle6.x = 400;
	// rectangle6.y = 200;
	// rectangle6.w = 200;
	// rectangle6.h = 200;

	// rectangle7.x = 0;
	// rectangle7.y = 400;
	// rectangle7.w = 200;
	// rectangle7.h = 200;

	// rectangle8.x = 200;
	// rectangle8.y = 400;
	// rectangle8.w = 200;
	// rectangle8.h = 200;

	// rectangle9.x = 400;
	// rectangle9.y = 400;
	// rectangle9.w = 200;
	// rectangle9.h = 200;

	// // Rectangle CONTOUR
	// if(
	// 	(SDL_RenderDrawRect(renderer, &rectangle1) != 0) &&
	// 	(SDL_RenderDrawRect(renderer, &rectangle2) != 0) && 
	// 	(SDL_RenderDrawRect(renderer, &rectangle3) != 0) &&
	// 	(SDL_RenderDrawRect(renderer, &rectangle4) != 0) && 
	// 	(SDL_RenderDrawRect(renderer, &rectangle5) != 0) && 
	// 	(SDL_RenderDrawRect(renderer, &rectangle6) != 0) && 
	// 	(SDL_RenderDrawRect(renderer, &rectangle7) != 0) &&
	// 	(SDL_RenderDrawRect(renderer, &rectangle8) != 0) && 
	// 	(SDL_RenderDrawRect(renderer, &rectangle9) != 0)
	// )
	// {
	// 	SDL_ExitWithError("Impossible de dessiner un des rectangle");
	// }

	// SDL_Surface *image = NULL;
	// image = SDL_LoadBMP("images/grille");
	
	// SDL_Rect position;
	// position.x = 0;
	// position.y = 0;

	// SDL_BlitSurface(image, NULL, window, &position);


	// if(!image)
	// {
	// 	SDL_ExitWithError("Impossible d'afficher l'image");
	// }

	// https://www.youtube.com/watch?v=ZJrXO8hKpS8 -> permet l'affichage d'une image

	SDL_RenderPresent(renderer);
	// SDL_Delay(3000);
	// SDL_RenderClear(renderer); //CLEAR LE RENDU DE LA PAGE

	/*--------------------------------------------------------------------------*/
	SDL_bool program_lanched = SDL_TRUE;
	
	// BOUCLE DE MON PROGRAMME
	while(program_lanched)
	{
		SDL_Event event;
		//Attend un evenement
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				// POSITION de la souris dans la fenetre
				case SDL_MOUSEMOTION:
					printf("Position : %d / %d\n", event.motion.x, event.motion.y);
					break;
				// POSITION de la souris !! AU CLIC dans la fenetre
				case SDL_MOUSEBUTTONDOWN:
					printf("Clic en %d / %d\n", event.button.x, event.button.y);
					break;
				// SI une touche est enfoncé
				case SDL_KEYDOWN:
					printf("Touche enfonce :\n");
					switch (event.key.keysym.sym)
					{
						// Cas de la touche b enfoncé
						case SDLK_b:
							printf("Vous avez appuye su b \n");
							break;
						case SDLK_n:
							printf("Vous avez appuye sur n \n");
							break;
						case SDLK_LEFT:
							printf("Vous avez appuye su left \n");
							break;
						// Si une autre touche est enfoncé : continué le programme
						default:
							continue;
					}
					break;
				// Cas où la croix en haut à droite est appuyé, fermer l'app
				case SDL_QUIT:
					program_lanched = SDL_FALSE;
					break;
				default:
					break;
			}
		}
	}
	
	/*--------------------------------------------------------------------------*/

	unsigned int frame_limit = 0;

	// GESTION DE LA FENETRE A 60FPS
	frame_limit = SDL_GetTicks() + FPS_LIMIT;
	SDL_LimitFPS(frame_limit);
	frame_limit = SDL_GetTicks() + FPS_LIMIT;

	/*--------------------------------------------------------------------------*/

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
	/*--------------------------------------------------------------------------*/
}

void SDL_LimitFPS(unsigned int limit){
	unsigned int ticks = SDL_GetTicks();
	if(limit < ticks) return;
	else if(limit > ticks + FPS_LIMIT) SDL_Delay(FPS_LIMIT);
	else SDL_Delay(limit - ticks);
}

	// EXIT  en affichant une erreur dans la console
void SDL_ExitWithError(const char *message){
	SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError()); // affiche une erreur dans la console
	SDL_Quit(); // Quitte la SDL
	exit(EXIT_FAILURE); // Ferme la SDL
}







	// window = SDL_CreateWindow(
	// 	"Ma Fenêtre",
	// 	SDL_WINDOWPOS_CENTERED,
	// 	SDL_WINDOWPOS_CENTERED,
	// 	800,600,
	// 	0
	// );

	// if(window == NULL){
	// 	SDL_ExitWithError("Creation Fenetre = NULL");
	// }

	// renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

	// if(renderer == NULL)
	// 	SDL_ExitWithError("Creation rendu echoue");

