/********************************************************************************
 * Michael Smith
 * Pair.h
 * 03/18/2017
 * Problem Description - Design a Pair class that allows the map to use two variable
                         types and allows comparisons between keys
 * Sketch of the solution - Pair has a default constructor. An overload constructor
                            that assigns a given first and second value for the pair.
                            Overloads operators to provide comparison functionality
                            between different pairs.
 * This file has a worst case O(1)
 ********************************************************************************/
#ifndef PAIR_H
#define PAIR_H

using namespace std;

template <class T1, class T2>
class Pair
{

public:
    //Default Constructor
    Pair(): first(), second() {}
    //Overloaded Constructor
    Pair(const T1 & first, const T2 & second): first(first), second(second) { }

    //Overloaded Comparison Operators - O(1)
    bool operator==(const Pair & rhs) const { return first == rhs.first;}
    bool operator<=(const Pair & rhs) const { return first <= rhs.first;}
    bool operator<(const Pair & rhs) const { return first < rhs.first;}
    bool operator>(const Pair & rhs) const { return first > rhs.first;}

    T1 first;
    T2 second;


};
#endif
