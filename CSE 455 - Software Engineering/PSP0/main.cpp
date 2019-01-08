#include <iostream>
#include "Singly_LList.h"

using namespace std;

int main() {

	Singly_llist list;
	int opt;

		cout << "Welcome to Ordered Singly Linked List" << endl;
		cout << "1.) Insert the values (list starts empty). \n2.)Delete a value from the list. \n3.)Read out the list \n4.) Press 4 to quit." << endl;

	while (true)
	{
		cout << "Enter a value to continue: ";
		cin >> opt;

		switch (opt)
		{
		case 1:
			list.insert();
			break;
		case 2:
			list.delete_node();
			break;
		case 3:
			list.read();
			break;
		case 4:
			return 0;
		}
	}
	return 0;
}