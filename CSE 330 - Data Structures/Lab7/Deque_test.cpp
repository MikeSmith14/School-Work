/********************************************************************************
 * Michael Smith
 * Deque_test.cpp
 * 02/27/2017
 * Problem Description - Test the full functionality of the included Deque.h class
                         to prove that the class is able to execute required tasks
                         without errors.
 * Sketch of the solution - This file was provided in the Lab assignment in order to
                            test different functions and assert to make sure the functions
                            execute what is expected.
 * The file as a whole has the worst case time complexity of O(n).
 ********************************************************************************/

// Deque_test.cpp

#include <iostream>
#include <cassert>

#include "Deque.h"

using namespace std;

int main()
{
	Deque<int> d;

	d.push_back(10);
	d.push_back(20);
	assert(d.front() == 10);
	assert(d.back() == 20);

	d.push_front(1);
	d.push_front(2);
	d.push_front(3);
	assert(d.front() == 3);
	assert(d.back() == 20);

	d.pop_back();
	d.pop_back();
	d.pop_back();
	assert(d.front() == 3);
	assert(d.back() == 2);

	d.push_back(1);
	d.push_back(0);

	Deque<int>::iterator i;
	int counter = 3;
	for (i = d.begin(); i != d.end(); i++)
		assert(*i == counter--);

	for (counter = 0; counter < d.size(); counter++)
		assert(d[counter] == d.size()-counter-1);

	i = d.begin() + 3;
	Deque<int>::iterator j(i), k;
	k = j = i - 2;
	assert(*k == 2);

	for (i = d.begin(); not(i == d.end()); ++i)
		cout << *i << " ";
	cout << endl;


	d.erase(d.begin()+3);

	d.erase(d.begin(), d.begin()+2);

	assert(d.size() == 1);
	assert(d[0] == 1);


	Deque<int> c(d);
	c.front() = 3;
	assert(c.back() == 3);

	c.push_front(1);
	c.insert(c.begin(), 0);
	c.insert(c.begin()+2, 2);

	for (i = c.begin(); not(i == c.end()); ++i)
		cout << *i << " ";
	cout << endl;


	for (counter = 0; counter < c.size(); counter++)
		assert(c[counter] == counter);

 	cout << "SUCCESS\n";
}

