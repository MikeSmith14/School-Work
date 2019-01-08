/********************************************************************************
 * Michael Smith
 * main.cpp
 * 03/18/2017
 * Problem Description - Test program to ensure the functionality of the revised
                         pop_front() and pop_back() functions.
 * Sketch of the solution - Demonstrates that pop_back() and pop_front() now correctly
                            moves elements from one vector to the other if the
                            destination vector is empty.
 * The file as a whole has the worst case time complexity of O(n).
 ********************************************************************************/

#include <iostream>
#include "Deque.h"

using namespace std;

int main()
{
    Deque<int> d;

    d.push_front(1);
    d.push_front(2);
    d.push_front(3);
    d.push_back(50);
    d.push_back(20); // 3 2 1 50 20

    d.pop_back();
    d.pop_back();
    d.pop_back(); // 3 2

    Deque<int>::iterator i;
    for (i = d.begin(); i != d.end(); ++i)
        cout << *i << " ";
    cout << endl;

    d.push_back(60);
    d.push_back(70); // 3 2 60 70

    for (i = d.begin(); i != d.end(); ++i)
        cout << *i << " ";
    cout << endl;

    d.pop_front();
    d.pop_front();
    d.pop_front(); // 70

    for (i = d.begin(); i != d.end(); ++i)
        cout << *i << " ";
    cout << endl;
}
