#include <iostream>
#include "Doubly.h"


using namespace std;

int main() {

	Doubly list;

	cout << "Creating the list with specified elements. \n";
	cout << "\n";
	list.insert(54.15);
	list.insert(11.42);
	list.insert(12.19);
	list.insert(83.40);
	list.insert(15.27);
	list.insert(60.17);
	list.insert(-63.81);
	list.insert(54.15);
	list.insert(-1.394);
	list.insert(-22.60);
	list.read();
	cout << "\n";
	cout << "Deleting the specified elements. \n";
	cout << "\n";
	list.delete_node(12.19);
	list.delete_node(27.33);
	cout << "\n";
	list.read();
	int aint;
	cin >> aint;
	return 0;
}