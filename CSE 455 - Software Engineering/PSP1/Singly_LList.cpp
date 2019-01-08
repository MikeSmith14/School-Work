#include "Singly_LList.h"
#include <iostream>

using namespace std;

//Inserts values to the list, checks if empty and adds first element
void Singly_llist::insert()
{
	float value;
	Node *temp;
	Node *new_node = new Node;

	cout << "Please enter a value to add to the list: ";
	cin >> value;

	//Creates the first value if the list is empty
	if (first == NULL)
	{
		first = new Node();
		first->data = value;
		first->forward = NULL;
	}
	else
	{
		temp = search(value);
		if (temp == first)
		{
			if (temp->data >= value) {     //since this is first node, have to check if its before or after..
				new_node->data = value;
				new_node->forward = first;
				first = new_node;
			}
			else {
				new_node->data = value;
				new_node->forward = first->forward;
				first->forward = new_node;
			}
		}
		else
			if (temp == NULL) {
				temp->forward = new_node;
				new_node->data = value;
				new_node->forward = NULL;
			}
			else
			{
				if (temp->data < value) {
					new_node->data = value;
					new_node->forward = temp->forward;
					temp->forward = new_node;
				}
				else {
					new_node->data = value;
					new_node->forward = temp;
					temp->forward = NULL;
				}
			}
	}


}

void Singly_llist::delete_node()
{
	Node *temp;
	float value;

	cout << "Please enter a value to remove from the list: ";
	cin >> value;

	temp = search(value);	//passes the value to search
	if (temp == first) {
		if (temp->data == value) {
			first = temp->forward;
			return;
		}
	}
	if (temp->forward != NULL) {
		if (temp->forward->data == value) {
			temp->forward->data = NULL;			// Nulls the data in the element in front of temp
			temp->forward = temp->forward->forward; //points forward to the forward of the next element
		}
		else {
			cout << "Value not in List!\n";
		}
	}
	else {
		cout << "Value not in List!\n";
	}

}

//Searches for the passed value in the list.
//Since this is a single linked list and we cant go backward,
//we have to always find the node BEFORE the insert or delete point...
Node* Singly_llist::search(float value)
{
	Node *temp;

	temp = first;
	while (temp != NULL)
	{
		if (temp->data >= value) {			//first lets see if the first node is a hit.
			return temp;
		}
		if (temp->forward != NULL) {		//Now, lets peek forward 1 node if it exists.
			if (temp->forward->data >= value)
				return temp;
		}
		else
		{
			return temp;					//return if forward doesnt
		}

		temp = temp->forward;
	}
	return temp;							//this will return base node if list is empty 
}



//Reads out the sorted list
void Singly_llist::read()
{
	Node *temp = first;

	//Empty Check
	if (temp == NULL)
	{
		cout << "The list is currently empty." << endl;
		return;
	}

	//Transverses the list and prints out values
	cout << "The list is as follows:\n";
	while (temp != NULL)
	{
		cout << temp->data << "\n";
		temp = temp->forward;
	}
}
