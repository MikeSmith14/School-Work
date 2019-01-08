/********************************************************************************
 * Michael Smith
 * test.cpp
 * 03/06/2017
 * Problem Description - Test the full functionality of the included Set.h class
                         to prove that the class is able to execute required tasks
                         without errors.
 * Sketch of the solution - This file was provided in the Lab assignment in order to
                            test different functions and assert to make sure the functions
                            execute what is expected.
 * The file as a whole has the worst case time complexity of O(n).
 ********************************************************************************/

#include <iostream>
#include <cassert>

#include "Set.h"

using namespace std;

main()
{
   Set<int> s;

   s.insert(10);
   s.insert(7);
   s.insert(6);
   s.insert(9);
   s.insert(8);
   s.insert(11);

   Set<int>::iterator i = s.find(7);
   s.erase(i);

   for (i = s.begin(); i != s.end(); i++)
	cout << *i << endl;

   cout << "All tests passed." << endl;
}
