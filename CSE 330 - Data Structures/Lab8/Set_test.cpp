/********************************************************************************
 * Michael Smith
 * Set_test.cpp
 * 03/06/2017
 * Problem Description - Test the full functionality of the included Set.h class
                         to prove that the class is able to execute required tasks
                         without errors.
 * Sketch of the solution - This file was provided in the Lab assignment in order to
                            test different functions and assert to make sure the functions
                            execute what is expected.
 * The file as a whole has the worst case time complexity of O(1).
 ********************************************************************************/

#include <iostream>
#include <cassert>

#include "Set.h"

using namespace std;

main()
{
   Set<int> s;

   assert(s.size() == 0);
   assert(s.empty());

   s.insert(10);

   Set<int>::iterator iter = s.begin();
   assert(*iter == 10);

   s.insert(6);
   s.insert(6);

   assert(s.count(6) == 1);
   assert(s.count(10) == 1);
   assert(s.count(12) == 0);

   iter = s.begin();
   assert(*iter == 6);
   ++iter;
   assert(*iter == 10);
   ++iter;
   assert(iter == s.end());

   s.insert(7);
   s.insert(9);
   s.insert(9);
   s.insert(8);
   s.insert(11);
   iter = s.begin();
   assert(*iter == 6);
   ++iter;
   assert(*iter == 7);
   ++iter;
   assert(*iter == 8);
   ++iter;
   assert(*iter == 9);
   ++iter;
   assert(*iter == 10);
   ++iter;
   assert(*iter == 11);

   Set<int> s2;
   s2.insert(3);
   s2.insert(7);
   s2.insert(-1);
   s2.insert(16);
   s2.insert(11);
   s2.insert(4);

   iter = s2.find(3);
   assert(*iter == 3);
   iter = s2.find(888);
   assert(iter == s2.end());

   s2.erase(7);
   iter = s2.begin();
   assert(*iter == -1);
   ++iter;
   assert(*iter == 3);
   ++iter;
   assert(*iter == 4);
   ++iter;
   assert(*iter == 11);
   ++iter;
   assert(*iter == 16);
   ++iter;
   assert(iter == s2.end());

   s2.erase(16);
   iter = s2.begin();
   assert(*iter == -1);
   ++iter;
   assert(*iter == 3);
   ++iter;
   assert(*iter == 4);
   ++iter;
   assert(*iter == 11);
   ++iter;
   assert(iter == s2.end());

   s2.erase(3);
   iter = s2.begin();
   assert(*iter == -1);
   ++iter;
   assert(*iter == 4);
   ++iter;
   assert(*iter == 11);
   ++iter;
   assert(iter == s2.end());

   s2.erase(11);
   iter = s2.begin();
   assert(*iter == -1);
   ++iter;
   assert(*iter == 4);
   ++iter;
   assert(iter == s2.end());

   s2.erase(-1);
   iter = s2.begin();
   assert(*iter == 4);
   ++iter;
   assert(iter == s2.end());

   s2.erase(4);
   iter = s2.begin();
   assert(iter == s2.end());

   cout << "All tests passed." << endl;
}

