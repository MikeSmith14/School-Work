/*
	Counts the total number of lines of code, object lines of code and object
	methods in a provide file. This is the header file to the Counter.cpp. It
	holds the declarations of private variables and public functions.

*/
#ifndef COUNTER_H
#define COUNTER_H
#include <fstream>
#include <string>

using namespace std;

class counter {

private:

	int objects;
	int methods;
	int lines;

public:
	
	counter() :lines(0), objects(0), methods(0){};
	int countLines();
	int countObjects();
	int countMethods();
	bool testline(string line);

};


#endif // !COUNTER_H
