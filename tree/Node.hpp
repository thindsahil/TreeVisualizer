#pragma once

class Node {
public:
	Node(int value, Node* left, Node* right);
	~Node();

	int value;
	Node* left;
	Node* right;
};