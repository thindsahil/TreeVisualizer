#include <SDL.h>
#include "program.hpp"
#include <iostream>


Program* program;

int main(int argc, char* argv[]) {

	program = new Program();
	program->init("tree", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600);

	while (program->running()) {
		program->handleEvents();
		/*program->update();
		program->render();*/
	}

	program->chean();

	//if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
	//	std::cout << "SDL is not initilized: " << SDL_GetError() << std::endl;
	//}
	//SDL_Window* window = SDL_CreateWindow("tree", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
	//SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	//SDL_SetRenderDrawColor(renderer, 0, 0,255, 255);
	//SDL_RenderClear(renderer);
	//SDL_RenderPresent(renderer);
	//SDL_Delay(1000);

	return 0;
}