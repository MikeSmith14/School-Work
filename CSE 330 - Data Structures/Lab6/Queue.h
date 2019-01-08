/********************************************************************************
 * Michael Smith
 * Stack.h
 * 02/26/2017
 * Problem Description - Create a Queue class that is able to perform the functionality
                         needed in order to run the test code of Queue_test.cpp.
 * Sketch of the Problem - This class is a template class that uses a container from
                           another class. IE List It has private variable for
                           container. And functions that are in-lined and use the container's
                           original function.
 * As a whole the program has a O(1).
 ********************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include "../Lab5/List.h"

using namespace std;

template <class T, template <class T> class Container = List>
class Queue
{

public:

    //Functions
    //Returns True/False if the Queue is empty - O(1)
    bool empty() {return container.empty();}
    //Returns the size of the Queue - O(1)
    int size() {return container.size();}
    //Pushes a value to the back of the Queue - O(1)
    void push(const T & x){container.push_back(x);}
    //Pops the top value off the Queue - O(1)
    void pop() {container.pop_back();}
    //Returns the top value of the Queue - O(1)
    T & top() {return container.back();}

protected:
    Container<T> container;

};

#endif
