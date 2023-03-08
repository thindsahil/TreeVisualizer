#include "Node.hpp"

Node::Node(int value, Node* left, Node* right)
{
	this->value = value;
	this->left = left;
	this->right = right;
}

Node::~Node()
{
}
