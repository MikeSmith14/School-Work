/********************************************************************************
 * Michael Smith
 * test.cpp
 * 02/27/2017
 * Problem Description - Test the simple functionality of the included Deque.h class
                         to prove that the class is able to execute required tasks
                         without errors.
 * Sketch of the solution - This file was provided in the Lab assignment in order to
                            test different functions print out the Deque to see if the
                            push functions execute as intended.
 * The file as a whole has the worst case time complexity of O(n).
 ********************************************************************************/

// test.cpp

#include <iostream>
#include <cassert>
//#include <queue>
#include "Deque.h"

using namespace std;

int main()
{
	Deque<int> d;

	d.push_back(10);
	d.push_back(20);
	d.push_front(1);
	d.push_front(2);
	d.push_front(3);

	Deque<int> c;
	c = d;

    Deque<int>::iterator i;
	for (i = c.begin(); i != c.end(); ++i)
		cout << *i << " ";
	cout << endl;

}
