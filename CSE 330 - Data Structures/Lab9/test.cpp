/********************************************************************************
 * Michael Smith
 * test.cpp
 * 03/13/2017
 * Problem Description -  Create a class for Priority Queue that provides functionality
                          in order to successfully constructor, print and pop out a 
                          Priority Queue.
 * Sketch of the Solution - Create the class Priority Queue with the essential 
                            functions to create, test if empty, print the tops, and pop
                            the top of the values.
 * Worst Case O(n) for entire class
 ********************************************************************************/
 
 // test.cpp to test Priority_queue

#include <iostream>
#include <cassert>

#include "Priority_queue.h"

using namespace std;

int main()
{
   Priority_queue<int> p, q, pq;

   int x;
   while (cin >> x)
	p.push(x);

   pq = q = p;

   while (!pq.empty()) {
	cout << pq.top() << " ";
	pq.pop();
   }
   cout << endl;
}
