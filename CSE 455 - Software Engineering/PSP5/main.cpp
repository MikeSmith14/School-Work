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
	stats corr, corr2;	
	float correlation, b1, b0;

	//Test Case 1
	x.insert(130, 186);
	x.insert(650, 699);
	x.insert(99, 132);
	x.insert(150, 272);
	x.insert(128, 291);
	x.insert(302, 331);
	x.insert(95, 199);
	x.insert(945, 1890);

	x.read();

	correlation = corr.correlation(x);
	b1 = corr.betaOne();
	b0 = corr.betaZero();

	cout << "The Beta Zero is: " << b0 << endl;
	cout << "The Beta One is: " << b1 << endl;
	cout << endl;

	//Test Case 2
	y.insert(163, 186);
	y.insert(765, 699);
	y.insert(141, 132);
	y.insert(166, 272);
	y.insert(137, 291);
	y.insert(355, 331);
	y.insert(136, 199);
	y.insert(1206, 1890);
	
	y.read();

	correlation = corr2.correlation(y);
	b1 = corr2.betaOne();
	b0 = corr2.betaZero();

	cout << "The Beta Zero is: " << b0 << endl;
	cout << "The Beta One is: " << b1 << endl;
	cout << endl;

	cin >> stop;
	return 0;
}