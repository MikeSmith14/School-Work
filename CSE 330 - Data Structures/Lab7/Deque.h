/********************************************************************************
 * Michael Smith
 * Deque.h
 * 02/27/2017
 * Problem Description - Create a Deque class that provides the functionality to
                         run the test files: Deque_test.cpp and test.cpp. Should
                         compile, run and execute without errors without using the
                         STL Deque
 * Sketch of the solution - This file has two classes within it. It has template
                            class Deque that provides the required constructors,
                            overloaded operators, and functions need for the tests.
 * The file as a whole has the worst case time complexity of O(n).
 * Revision - 03/18/2017 - Modders Name: Michael Smith. Revised the pop_front()
                           and the pop_back() functions to move elements from
                           one vector to the other if the one vector is empty
                           allowing for future pops to be more efficient. This
                           modification made the big-Oh of the functions change
                           from O(1) to O(log(n)) due to having to move half of
                           the elements from one and to the other.
 ********************************************************************************/

#ifndef DEQUE_H
#define DEQUE_H

// Deque.h - an implementation of double ended queues

#include <vector>

using namespace std;

template <class T> class DequeIterator;

template <class T>
class Deque{

public:
    typedef DequeIterator<T> iterator;

    //Default Constructor
    Deque(): vecOne(), vecTwo() { }
    //Overloaded Constructors
    Deque(const unsigned int size, const T& initial): vecOne(size/2, initial), vecTwo(size - (size/2), initial) { }
    Deque(const Deque<T> & d): vecOne(d.vecOne), vecTwo(d.vecTwo) { }
    //Deconstructor
    ~Deque() { } //Destructors for vecOne and vecTwo are auto called. Dont call explicitly

    //Overloading Operators
    Deque & operator=(const Deque<T> & d);
    T & operator[](unsigned int);

    //Functions
    T & front();
    T & back();
    bool empty();
    iterator begin();
    iterator end();
    void erase(const iterator &);
    void erase(const iterator &, const iterator &);
    void insert(const iterator &, const T &);
    int size();
    void push_front(const T & value);
    void push_back(const T & value);
    void pop_front();
    void pop_back();

protected:
    vector<T> vecOne;
    vector<T> vecTwo;

};

//Overloaded Assignment operator. Deque is set equal to an existing Deque - O(1)

template <class T>
Deque<T> & Deque<T>::operator=( const Deque<T> & d)
{
    vecOne = d.vecOne;
    vecTwo = d.vecTwo;
    return *this;
}

//Overload the indexing operator to allow returning of specific indexes - O(1)
template <class T>
T & Deque<T>:: operator[](unsigned int index)
{
    unsigned int n = vecOne.size();
    if (index < n)
        return vecOne[(n-1) - index];
    else
        return vecTwo[index - n];
}

//Returns the front value of the Deque - O(1)
template <class T>
T & Deque<T>::front()
{
    if(vecOne.empty())
        return vecTwo.front();
    else
        return vecOne.back();
}

//Returns the back vlaue of the Deque - O(1)
template <class T>
T & Deque<T>::back()
{
    if(vecTwo.empty())
        return vecOne.front();
    else
        return vecTwo.back();
}

//Returns true/false if the Deque is empty - O(1)
template <class T>
bool Deque<T>::empty()
{
    return vecOne.empty() && vecTwo.empty();
}

//Returns an iterator to the beginning of the Deque - O(1)
template <class T>
DequeIterator<T> Deque<T>::begin()
{
    return DequeIterator<T>(this,0);
}

//Returns an iterator to the end of the Deque - O(1)
template <class T>
DequeIterator<T> Deque<T>::end()
{
    return DequeIterator<T>(this,size());
}

//Erases a Single value from the Deque at a specific iterator index - O(1)
template <class T>
void Deque<T>::erase( const iterator & itr)
{
    int index = itr.index;
    int n = vecOne.size();
    if(index < n)
        vecOne.erase(vecOne.begin() + ((n-1)-index));
    else
        vecTwo.erase(vecTwo.begin() + (index-n));
}

//Erases a range of values from the Deque from a starting iter to the ending iter - O(n)
template <class T>
void Deque<T>::erase(const iterator &start,const iterator &stop)
{
    int i;

	for (i = 1 ; i <= (stop.index - start.index); i++ )
        erase( start );
    //erase( stop );

}

//Inserts a value in front of a specific iterator index - O(1)
template <class T>
void Deque<T>::insert(const iterator &itr,const T & value)
{
    int index = itr.index;
    int n = vecOne.size();
    if(index < n)
        vecOne.insert(vecOne.begin() + (n-index), value);
    else
        vecTwo.insert(vecTwo.begin() + (index-n), value);
}

//Returns the size of the Deque - O(1)
template <class T>
int Deque<T>::size()
{
    return vecOne.size() + vecTwo.size();
}

//Pushes a value to the front of the Deque - O(1)
template <class T>
void Deque<T>::push_front(const T & value)
{
    vecOne.push_back(value);
}

//Pushes a value to the back of the Deque - O(1)
template <class T>
void Deque<T>::push_back(const T & value)
{
    vecTwo.push_back(value);
}

//Pops the value off the Front of the Deque - O(log(n))              //Modified 03/18/17 -MS
template <class T>
void Deque<T>::pop_front()
{
//    if(vecOne.empty())
//        vecTwo.erase(vecTwo.begin());
//    else
//        vecOne.pop_back();

    if(vecOne.empty()){
        vecOne.resize(vecTwo.size()/2);
        for(unsigned int i = 0; i < vecOne.size(); i ++){
            vecOne[i] = vecTwo[i];
        }
        for(unsigned int i = vecOne.size(); i < vecTwo.size(); i++){
            vecTwo[i-vecOne.size()] = vecTwo[i];
        }
        vecTwo.pop_back();  //Remove the last element to avoid duplicates
        vecOne.pop_back();
    }
    else
        vecOne.pop_back();
}

//Pops the value off the Back of the Deque - O(log(n))               //Modified 03/18/17 -MS
template <class T>
void Deque<T>::pop_back()
{
//    vecOne.end();
//    if(vecTwo.empty())
//        vecOne.erase( vecOne.begin()); //erase(vecOne.end());
//    else
//        vecTwo.pop_back();

    if(vecTwo.empty()){
        vecTwo.resize(vecOne.size()/2);
        for(unsigned int i = 0; i < (vecOne.size()/2); i++){
            vecTwo[i] = vecOne[i];
        }
        for(unsigned int i = vecTwo.size(); i < vecOne.size(); i++){
            vecOne[i-vecTwo.size()] = vecOne[i];
        }
        vecOne.pop_back();  //Remove the last element to avoid duplicates
        vecTwo.pop_back();
    }
    else
        vecTwo.pop_back();
}

//-------------------------------------------------------------------End of Deque

template <class T>
class DequeIterator{

    friend class Deque<T>;
    typedef DequeIterator<T> iterator;

public:

    //Default Constructor
    DequeIterator(): theDeque(0), index(0) { }
    //Overload Constructors
    DequeIterator(Deque<T> * d, int i): theDeque(d), index(i) { }
    DequeIterator(const iterator & d): theDeque(d.theDeque), index(d.index) { }

    //Overload Operators - All are O(1)
    T & operator *()
        { return (*theDeque)[index]; }
    iterator & operator++()
        { ++index; return *this; }
    iterator operator++(int)
        { iterator clone(theDeque,index); index++; return clone;}
    iterator & operator--()
        { --index; return *this; }
    iterator operator--(int)
        { iterator clone(theDeque,index); index--; return clone;}
    bool operator==(const iterator & r)
        { return theDeque == r.theDeque && index == r.index; }
    bool operator!=(const iterator & r)
        { return theDeque == r.theDeque && index != r.index; }
    bool operator<(const iterator & r)
        { return theDeque == r.theDeque && index < r.index;}
    bool operator>(const iterator & r)
        { return theDeque == r.theDeque && index > r.index;}
    T & operator[](unsigned int i)
        { return (*theDeque) [index + i]; }
    iterator operator=(const iterator & r)
        { theDeque = r.theDeque; index = r.index; return iterator(theDeque,index);}
    iterator operator+(int i)
        { return iterator(theDeque, index+i); }
    iterator operator-(int i)
        { return iterator(theDeque, index-i); }

protected:

    Deque<T> * theDeque;
    int index;
};
#endif
