

#include "Counter.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main() {

	counter count;
	int lines;
	int objects;
	int methods;

	lines = count.countLines();
	cout << "The Total lines of code are " << lines << endl;;
	
	objects = count.countObjects(); //Method writes to console

	methods = count.countMethods(); //Method writes to console

	cin >> methods;

	return 0;

}

