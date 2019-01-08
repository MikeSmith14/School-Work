/*
	This is the main program to test the functionality of the Stats class developed in the Stat.cpp and Stat.h
	We create two lists and insert values. The first list is provided as the test case. The second list is a 
	custom set that I inputted to test the functionality further.

*/

#include "Stat.h"
#include <iostream>

using namespace std;

int main() {

	int stop;

	Singly_llist x, y;
	stats corr;	
	float correlation, significance;

	//(LOC, Hours)
	x.insert(400, 26.6);
	x.insert(450, 30.2);
	x.insert(1700, 36.6);
	x.insert(1600, 48.8);
	x.insert(1958, 58.5);
	x.insert(2030, 55.6);
	x.insert(125, 32.3);


	x.read();

	correlation = corr.correlation(x);

	cout << "The r of the list is " << correlation << endl;
	cout << "The correlation of the list is " << (correlation * correlation) << endl;
	significance = corr.significance();
	if (significance == 0) {
		cout << endl;
	} else {
		cout << "The significance of the list is " << significance << endl;
	}
	cout << endl;

	y.insert(2400, 40.0);
	y.insert(1800, 964.2);
	y.insert(2360, 78);
	y.insert(1200, 12.4);
	y.insert(1500, 965.2);
	y.insert(1470, 26.6);
	y.insert(895, 75.2);
	y.insert(785, 134.2);
	y.insert(4556, 645.1);
	y.insert(6843, 134.5);

	y.read();

	correlation = corr.correlation(y);

	cout << "The r of the list is " << correlation << endl;
	cout << "The correlation of the list is " << (correlation * correlation) << endl;
	significance = corr.significance();
	if (significance == 0) {
		cout << endl;
	}
	else {
		cout << "The significance of the list is " << significance << endl;
	}

	cin >> stop;
	return 0;
}