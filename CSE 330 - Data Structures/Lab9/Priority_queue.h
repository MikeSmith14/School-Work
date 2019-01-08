/********************************************************************************
 * Michael Smith
 * PriorityQueue.h
 * 03/13/2017
 * Problem Description -  Create a Priorirty Queue class that is able to successfully
                          run the test.cpp and the Priority_Queue_test.cpp to 
                          completion. 
 * Sketch of the Solution - Develop the class that offers constructors and 
                            functions needed to perform the tests successfully 
                            without error.
 * Worst Case O(log(n)) for entire class
********************************************************************************/
 
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
 
#include <vector>
using namespace std;

template <class T>
class Priority_queue
{
 public:
    
    //Constructors
    Priority_queue() : c() { }
    Priority_queue(const Priority_queue & p): c(p.c) { } 
    Priority_queue & operator=(const Priority_queue & p){ c = p.c; return *this; }
       
    //Functions
    bool empty() { return c.empty(); }
    unsigned int size() { return c.size(); }
    T & top() { return c.front(); }
    void push(const T & x);
    void pop();
private:
    
    vector<T> c;

};

//Percolates the heap as needed to correctly organize it - O(log(n))
template <class Iterator>
void push_heap(Iterator start, Iterator stop)
{
    unsigned int position = (stop - start) - 1;
    unsigned int parent = (position - 1) / 2;
    while(position > 0 && start[position] > start[parent]){
        swap(start[position], start[parent]);
        position = parent;
        parent = (position - 1) / 2;
    }
}

//Adjusts the heap in order to have it correctly organized - O(log(n))
template <class Iterator>
void adjust_heap(Iterator start, unsigned int heapSize, unsigned int position)
{
    while(position < heapSize){
        unsigned int childpos = position * 2 + 1;
        if(childpos < heapSize){
            if((childpos + 1 < heapSize) && (start[childpos + 1] > start[childpos]))
                childpos++;
            if(start[position] > start[childpos])
                return;
            else
                swap(start[position], start[childpos]);
        }
        position = childpos;
    }
}

// Swaps the root to the last position then adjusts the heap - O(log(n))
template <class Iterator>
void pop_heap(Iterator start, Iterator stop)
{
    unsigned int lastPosition = (stop - start) - 1;
    swap(start[0], start[lastPosition]);
    adjust_heap(start, lastPosition, 0);
}


//Pushes a element to the back of the heap and percolates it into the correct
//position - O(log(n))
template <class T>
void Priority_queue<T>::push(const T & x)
{
    c.push_back(x);
    push_heap(c.begin(), c.end());
}

//Swaps the root to the back and pops it. And reorganizes the heap. - O(log(n))
template <class T>
void Priority_queue<T>::pop()
{
    pop_heap(c.begin(), c.end());
    c.pop_back();
}



#endif
