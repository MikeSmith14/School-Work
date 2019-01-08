/*
	This is the cpp file that defines the functions for the Counter class.
	Functions include: countLines, countObjects and countMethods.
*/
#include "Counter.h"
#include <string>
#include <iostream>
#include <algorithm>


using namespace std;

//This helper function is to test for a valid line...
bool counter::testline(string line) {
	if (line.back() == ';' || line.back() == '{' || line.back() == '(' || line.front() == '}' ||
		line.back() == ')' || line.front() == '#' || (line.find(":") != string::npos)) {
		return true;
	}
	else {
		return false;
	}
}

//This function will count the total lines of code from the opened file
//inputted by the user. 
int counter::countLines() {
	//this works
	string line;
	string file;
	ifstream myfile;

	cout << "Please enter the full name of the file: \n";
	cin >> file;

	myfile.open(file.c_str());

	if (!myfile) {
		cout << "File failed to open \n";
		exit(1);
	}

	if (myfile.is_open()) {
		while (getline(myfile, line)) {

			line = line.substr(0, line.find("//")); //Strip off comments
			line = line.substr(0, line.find("/*")); //Strip off comments
			line.erase(std::remove(line.begin(), line.end(), '\t'), line.end()); //remove leading TABs

			if (line != "") {
				if (testline(line))
					lines++;
			}
		}
	}

	myfile.close();
	return lines;
}

//This function will count the total lines of code of each object within the
//file. And output the name of the class and the total lines of that class.
int counter::countObjects() {
	string word, line;
	string file, classname = "";
	ifstream myfile;
	int temp = 0;

	cout << "Please enter the full name of the file: \n";
	cin >> file;
	cout << "Number of LOC per Object Class: \n";

	myfile.open(file.c_str());

	if (myfile.is_open()) {
		while (getline(myfile, line)) {

			line = line.substr(0, line.find("//")); //Strip off comments
			line = line.substr(0, line.find("/*")); //Strip off comments
			line.erase(std::remove(line.begin(), line.end(), '\t'), line.end()); //remove leading TABs

			if (line.substr(0, line.find(' ')) == "class") {

				if (temp > 0) {				//class name changing, write out total lines of previous class
					cout << temp << endl;
					temp = 0;
				}

				classname = line.substr(line.find(' ') + 1, line.find(':') - line.find(' ') - 1);
				cout << classname << "\t";
				temp++;

				while (line != "};") {			//now loops thru until we find the end of the functions block
					getline(myfile, line);
					if (temp > 0) {
						if (line != "") {
							if (testline(line))
								temp++;
						}
					}
				}
			}

			if (classname != "") {
				if (line.find(classname + "::" ) != string::npos) {  //Ok, found another part of current class, so count them up.
					while (line != "}") {			//now loops thru until we find the end of the functions block
						getline(myfile, line);
						if (temp > 0) {
							if (line != "") {
								if (testline(line))
									temp++;
							}
						}
					}
				}
			}
		}
	}
	if (temp > 0)				//write out last classes line LOC
		cout << temp << endl;

	myfile.close();
	return objects;

}

//This function will count the total number of methods in a class. And will
//output the number of methods and the class name
int counter::countMethods() {

	string line, classname = "";
	string file;
	ifstream myfile;
	int temp = 0;

	cout << "Please enter the full name of the file: \n";
	cin >> file;
	cout << "Number of Methods per Object Class: \n";

	myfile.open(file.c_str());
	while (getline(myfile, line)) {

		if (line.substr(0, line.find(' ')) == "class") {

			if (temp > 0) {				//class name changing, write out total number of methods
				cout << temp-1 << endl;
				temp = 0;
			}

			classname = line.substr(line.find(' ') + 1, line.find(':') - line.find(' ') - 1);
			cout << classname << "\t";
			classname += "::";     //Modify the class name for faster finding...
			temp++;

		}

		if (classname != "") {
			if (line.find(classname ) != string::npos) {  //Ok, found another part of current class, so count them up.
				temp++;
			}
		}
	}
	if (temp > 0)
		cout << temp-1 << endl;
	myfile.close();
	return methods;


}
