#include "Doubly.h"
#include <iostream>

using namespace std;

void Doubly::insert(float num)
{
	float value = num;
	Node *temp;
	Node *new_node = new Node;

	if (first == NULL)
	{
		first = new Node();
		first->data = value;
		first->forward = NULL;
		first->backward = NULL;
	}

	else
	{
		temp = search(value);
		if (temp == first)
		{
			if (temp->data >= value)		//Verifies that the new node is either before or after and corrects pointers
			{
				new_node->data = value;
				new_node->forward = first;
				first->backward = new_node;
				new_node->backward = NULL;
				first = new_node;
			}
			else
			{
				new_node->data = value;
				new_node->forward = first->forward;
				new_node->backward = first;
				first->forward = new_node;
			}
		}
		else
		{
			if (temp == NULL)
			{
				temp = new_node;
				new_node->forward = first;
				new_node->backward = NULL;
				new_node->data = value;
				first = new_node;
			}
			else
			{
				if (temp->data < value)
				{
					new_node->data = value;
					new_node->forward = temp->forward;
					new_node->backward = temp;
					temp->forward = new_node;
				}
				else
				{
					new_node->data = value;
					new_node->forward = temp;
					new_node->backward = temp->backward;
					temp->backward = new_node;
					temp->forward = NULL;
				}
			}
		}
	}
}

void Doubly :: delete_node(float num)
{
	Node *temp;
	float value = num;

	temp = search(value);
	if (temp == first)
	{
		if (temp->data == value)
		{
			first = temp->forward;
			return;
		}
	}
	if (temp->forward != NULL)
	{
		if (temp->forward->data == value)
		{
			temp->forward->data = NULL;		//nulls the data in the element in front of the returned node
			temp->forward = temp->forward->forward;		//points the forward to the foward of the next element
			temp->forward->forward->backward = temp;	//points the backward of the next element to the temp
		}
		else
		{
			cout << "Value is not in the list! \n";
		}
	}
	else
	{
		cout << "Value is not in the list! \n";
	}
}