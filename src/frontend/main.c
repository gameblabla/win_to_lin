#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

SDL_Window* game_screen;
SDL_Renderer* renderer;

SDL_Surface* surface;
SDL_Texture *tex;

int main (int argc, char *argv[]) 
{
	SDL_Rect rct;
	SDL_Event event;
	int quit = 0;
	int width = 0;
	int height = 0;
	
	SDL_Init( SDL_INIT_VIDEO );
	game_screen = SDL_CreateWindow("TEST", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, 0);  
	if (!game_screen)
	{
		printf("SDL_Init failed Window: %s\n", SDL_GetError());
		return 0;
	}
	
	/* Create renderer, its resolution, set to HARDWARE aceleration and Vsync turned on */
	renderer = SDL_CreateRenderer(game_screen, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_RenderSetLogicalSize(renderer, 3840*2, 2160*2);
	
	/* Clear everything on screen */
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	
	/* Hide the mouse and grab it */
	//SDL_SetRelativeMouseMode(SDL_TRUE);
	
	SDL_GetWindowSize(game_screen, &width, &height);
	surface = SDL_CreateRGBSurface(SDL_SWSURFACE, width, height, 32, 0,0,0,0);

	while(!quit)
	{
		while (SDL_PollEvent(&event)) 
		{
			switch(event.type) 
			{
				case SDL_KEYUP:
					switch(event.key.keysym.sym) 
					{
						case SDLK_HOME:
						case SDLK_3:
						case SDLK_RCTRL:
						case SDLK_ESCAPE:
							quit = 1;
						break;
						default:
						break;
					}
				break;
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym) 
					{
						case SDLK_LCTRL:
						break;
						default:
						break;
					}
				break;
				case SDL_QUIT:
					quit = 1;
				break;
			}
		}

		memset(surface->pixels, 5080801, (width * height) * 4);
		SDL_RenderCopy(renderer, SDL_CreateTextureFromSurface(renderer, surface), NULL, NULL);
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(game_screen);
	SDL_Quit();
}
