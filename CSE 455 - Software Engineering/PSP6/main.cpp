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
	float correlation, b1, b0;
	float std, var;

	//Test Case 1
	x.insert(130, 186);
	x.insert(650, 699);
	x.insert(99, 132);
	x.insert(150, 272);
	x.insert(128, 291);
	x.insert(302, 331);
	x.insert(95, 199);
	x.insert(945, 1890);
	x.insert(368, 788);
	x.insert(961, 1601);

	x.read();

	correlation = corr.correlation(x);
	b1 = corr.betaOne();
	b0 = corr.betaZero();
	var = corr.variance(x);
	std = corr.standardDeviation();

	cout << "This is the correlation: " << correlation << endl;
	cout << "This is the beta one: " << b1 << endl;
	cout << "This is the beta zero: " << b0 << endl;
	cout << "This is the variance: " << var << endl;
	cout << "This is the standard deviation: " << std << endl;
	corr.range(x);

	cin >> stop;
	return 0;
}