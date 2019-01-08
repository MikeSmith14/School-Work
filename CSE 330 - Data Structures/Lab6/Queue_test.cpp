/********************************************************************************
 * Michael Smith
 * Stack.h
 * 02/26/2017
 * Problem Description - Create a main that is able to test the functionality of the
                         Queue class from Queue.h
 * Sketch of the Problem - This main is able to test the Queue class in order to verify
                           that the class is able to provide required functionality.
 * As a whole the program has a O(1).
 ********************************************************************************/

#include <iostream>
#include <cassert>
#include "Queue.h"
#include "../Lab3/String.h"
#include "../Lab4/Lab4/Vector.h"
#include "../Lab5/List.h"

using namespace std;

int main()
{
   Queue<int, Vector> s1;
   assert(s1.size() == 0);
   assert(s1.empty());

   s1.push(21);
   assert(s1.size() == 1);
   assert(s1.top() == 21);

   s1.pop();
   assert(s1.size() == 0);

   s1.push(92);
   assert(s1.size() == 1);
   assert(s1.top() == 92);

   s1.push(12);
   assert(s1.size() == 2);
   assert(s1.top() == 12);

   s1.push(30);
   assert(s1.size() == 3);
   assert(s1.top() == 30);

   s1.pop();
   assert(s1.size() == 2);
   assert(s1.top() == 12);

   Queue<String, List> s2;
   s2.push("abc");
   s2.push("de");
   s2.pop();
   assert(s2.top() == "abc");

   cout << "SUCCESS\n";


}
