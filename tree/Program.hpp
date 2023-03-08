#pragma once
#include <SDL.h>

#include <stdio.h>
#include <iostream>

class Program {
public:
	Program();
	~Program();

	void init(const char* title, int xpos, int ypos, int width, int height);
	void handleEvents();
	void update();
	void render();
	void chean();

	bool running();

private:
	int counter = 0;
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;


};