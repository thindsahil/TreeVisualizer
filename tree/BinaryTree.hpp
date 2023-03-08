#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

#include "Node.hpp"

class BinaryTree {
public:
	BinaryTree(SDL_Renderer* renderer, int x, int y);
	~BinaryTree();

	void Update();
	void Render();
	void renderTree(Node* root, int x, int y);

	void addNode(int value);
	void addNodeHelper(int value, Node* root);
	
private:
	int xpos;
	int ypos;

	Node* root = nullptr;

	TTF_Font* textFont;
	SDL_Renderer* renderer;

	int columns = 1;
	int scale = 5;
};