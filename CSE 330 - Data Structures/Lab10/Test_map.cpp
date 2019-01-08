/********************************************************************************
 * Michael Smith
 * Test_map.cpp
 * 03/18/2017
 *  Problem Description - An in depth test for the Map class to ensure functionality of the
                         class. Ensure passing the asserts and runs the tests until completion
 * Sketch of the solution - Map class has the functionality to create, assign, remove,
                            and manipulate the data structure to provide the functionality
                            for the test.
 * This file has a worst case O(1)
 ********************************************************************************/

// Test_map.cpp

#include <iostream>
#include <cassert>
//#include < map >
#include "Map.h"
#include <string>
//#include "String.h"

using namespace std;

int main()
{
   Map <string, int> m;

   assert(m.size() == 0);
   assert(m.empty());

   m["abby"] = 9;
   assert(m["abby"] == 9);

   m["billy"] = 6;
   assert(m["billy"] == 6);
   assert(m["abby"] == 9);

   m["katie"] = -2;
   assert(m["katie"] == -2);
   assert(m["billy"] == 6);
   assert(m["abby"] == 9);

   m["bobby"] = -4;
   assert(m["bobby"] == -4);
   assert(m["katie"] == -2);
   assert(m["billy"] == 6);
   assert(m["abby"] == 9);

   m["binky"] = 100;
   m["abby"] = -100;
   assert(m["binky"] == 100);
   assert(m["bobby"] == -4);
   assert(m["katie"] == -2);
   assert(m["billy"] == 6);
   assert(m["abby"] == -100);

   assert(m["charles"] == 0);

   assert((*m.find("katie")).second == -2);

   assert(m.find("katie") != m.end());

   Map<string, int>::iterator i;
   for (i = m.begin(); i != m.end(); i++)
        cout << (*i).first << " " << (*i).second << endl;

   m.erase("katie");
   assert(m.find("katie") == m.end());

   cout << "Success!" << endl;
}

