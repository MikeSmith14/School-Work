// test.cpp - a simple test program for Stack.h

#include <iostream>

#include "../Lab4/Lab4/Vector.h"
#include "Stack.h"

using namespace std;

main()
{
	Stack<int> s;      // uses List as the default container
	s.push(5);
	s.push(6);
	cout << s.top() << endl;

	Stack<double, Vector> v; // uses Vector as the container
	v.push(1.5);
	v.push(2.3);
	v.pop();
	cout << v.top() << endl;
}
