#include "Program.hpp"
#include "BinaryTree.hpp"

BinaryTree* tree;


Program::Program()
{
}

Program::~Program()
{
}

void Program::init(const char* title, int xpos, int ypos, int width, int height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Initilized properly..." << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		if (window) {
			std::cout << "Window created..." << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			std::cout << "Renderer created..." << std::endl;
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}

	tree = new BinaryTree(renderer, 300,100);

}


void Program::handleEvents()
{
	SDL_Event event;
	SDL_WaitEvent(&event);
	switch (event.type) {
		case SDL_QUIT: 
			isRunning = false;
			break;
		case SDL_MOUSEBUTTONDOWN:
			//int value;
			//std::cout << "Enter a node to insert into tree: ";
			//std::cin >> value;
			render();
			//std::cout << value << " inserted into the tree" << std::endl;
			break;
		case SDL_KEYDOWN:
			int value;
			std::cout << "Enter a node to insert into tree: ";
			std::cin >> value;
			tree->addNode(value);
			std::cout << value << " inserted into the tree" << std::endl;
		default: 
			break;
	}
}

void Program::update()
{
	counter++;
	std::cout << counter << std::endl;
}

void Program::render()
{	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	tree->Render();
	SDL_RenderPresent(renderer);
}

void Program::chean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Program::running()
{
	return isRunning;
}
