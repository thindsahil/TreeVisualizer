#include "BinaryTree.hpp"
#include <iostream>

BinaryTree::BinaryTree(SDL_Renderer* renderer, int x, int y)
{
	this->renderer = renderer;
	TTF_Init();
	this->textFont = TTF_OpenFont("cambria.ttc", 48);
	xpos = x;
	ypos = y;

	this->addNode(12);
	this->addNode(24);
	this->addNode(8);
	this->addNode(10);
	this->addNode(30);
	this->addNode(45);
	this->addNode(-1);
	this->addNode(-23);
	this->addNode(-10);

}

BinaryTree::~BinaryTree()
{
}

void BinaryTree::Update()
{
}

void BinaryTree::Render()
{
	SDL_SetRenderDrawColor(renderer, 100, 0, 0, 255);

	this->renderTree(this->root, xpos, ypos);
}

void BinaryTree::renderTree(Node* node, int x, int y) {
	if (node == nullptr) {
		return;
	}
	this->scale = 300 / (10*this->columns);
	SDL_Rect nodeSquare = { x,y, 20, 20};

	if (node->left) {
		SDL_RenderDrawLine(renderer, x, y + 10, x - (scale + 30), y + 6 * scale);
	}
	if (node->right) {
		SDL_RenderDrawLine(renderer, x + 20, y + 10, x + 20 + (scale + 35), y + 6 * scale);
	}

	// TODO
	// VERY UGLY 
	std::string temp1 = std::to_string(node->value);
	const char* temp = temp1.c_str();
	SDL_Surface* surfaceMessage =
		TTF_RenderText_Solid(this->textFont, temp, {255,255,255});
	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	SDL_RenderDrawRect(renderer, &nodeSquare);
	SDL_RenderCopy(renderer, Message, NULL, &nodeSquare);

	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);

	std::cout << "Rendered node: " << node->value << std::endl;

	renderTree(node->left, x - (scale + 40), y + 6 * scale);
	renderTree(node->right, x + (scale + 40), y + 6 * scale);

}

void BinaryTree::addNode(int value)
{	
	if (this->root == nullptr) {
		this->root = new Node(value, nullptr, nullptr);
	}
	else {
		addNodeHelper(value, this->root);
	}
	
}

void BinaryTree::addNodeHelper(int value, Node* node) {
	if (value == node->value) {
		return;
	}
	if (value < node->value) {
		if (node->left == nullptr) {
			node->left = new Node(value, nullptr, nullptr);
			this->columns++;
			return;
		}
		
		addNodeHelper(value, node->left);
	}
	else {
		if (node->right == nullptr) {
			node->right = new Node(value, nullptr, nullptr);
			this->columns++;
			return;
		}
		addNodeHelper(value, node->right);
	}
}
