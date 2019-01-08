/*
This is the header for the Singly Linked List class. Defines specific attributes and functions that are completely inclusive to
this class. Functions will include a Sort(), Read(), Search(), Insert(), and Delete_node(). The list is made up of nodes that contain a
floating point data, and a single pointer pointing to the next link in the list. Therefore the list will only have one way
transverses.

Singly_LList.h

*/

#include <iostream>

//Header for the singly_llist class
class Node
{
public:
	float data;
	float data2;
	Node* forward;
	Node* backward;
};

class Singly_llist :public Node
{

public:

	Node *first;
	Node *last;

	Singly_llist()
	{
		first = NULL;
		last = NULL;
	}
	void insert(float num);
	void delete_node();
	void read();
	Node* search(float value);
	Node operator++(int);
	Node* begin();
	void insert(float num1, float num2);
};