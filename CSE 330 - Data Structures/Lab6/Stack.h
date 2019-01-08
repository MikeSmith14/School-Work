/********************************************************************************
 * Michael Smith
 * Stack.h
 * 02/26/2017
 * Problem Description - Create a Stack class that is able to perform the functionality
                         needed in order to run the test code of Stack_test.cpp and
                         test.cpp.
 * Sketch of the Problem - This class is a template class that uses a container from
                           another class. IE List or Vector. It has private variable for
                           container. And functions that are in-lined and use the container's
                           original function.
 * As a whole the program has a O(1).
 ********************************************************************************/

#ifndef STACK_H
#define STACK_H

#include "../Lab5/List.h"
#include "../Lab4/Lab4/Vector.h"
#include <iostream>

using namespace std;

template <class T, template <class T> class Container = List>
class Stack
{
public:

   //Uses containers empty function to return bool - O(1)
   bool empty() const {return container.empty();}
   //Returns the size from contains size function - O(1)
   unsigned int size() const {return container.size();}
   //Uses the containers push_back to push a value - O(1)
   void push(const T & x){return container.push_back(x);}
   //Uses the containers pop to pop the back of the Stack - O(1)
   void pop() {return container.pop_back();}
   //Uses containers back function to return the top of the Queue - O(1)
   T & top(){return container.back();}

private:
   Container<T> container;
};

#endif
