#include "Stat.h"
#include <iostream>

using namespace std;

int main() {

	int stop;

	Singly_llist x, y;
	stats corr;	
	float correlation;

	//(LOC, Hours)
	x.insert(200, 30.0);
	x.insert(800, 118.7);
	x.insert(260, 13);
	x.insert(450, 40.8);
	x.insert(1500, 144.6);
	x.insert(450, 26.6);
	x.insert(1850, 95.5);
	x.insert(900, 77.60);
	x.insert(1650, 140.6);
	x.insert(1400, 140.8);

	x.read();

	correlation = corr.correlation(x);

	cout << "The r of the list is " << correlation << endl;
	cout << "The correlation of the list is " << (correlation * correlation) << endl;
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

	cin >> stop;
	return 0;
}