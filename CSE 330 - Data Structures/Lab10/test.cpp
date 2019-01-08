/********************************************************************************
 * Michael Smith
 * test.cpp
 * 03/18/2017
 * Problem Description - Simple test for the Map class to ensure functionality of the
                         class.
 * Sketch of the solution - Creates a Map, assigns some keys and values and prints out
                            the values after assignments.
 * This file has a worst case O(1)
 ********************************************************************************/

// Small test.cpp to test Map

#include <iostream>
#include <cassert>

#include "Map.h"

using namespace std;

int main()
{
   Map<double, long> counts;

   counts[2.1] = 5;
   counts[-4] = 2;
   counts[.35] = 3;
   counts[-4] = 7;
   cout << counts[2.1] << " " << counts[-4] << " " << counts[.35] << endl;
}
