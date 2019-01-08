/********************************************************************************
 * Michael Smith
 * Map.h
 * 03/18/2017
 * Problem Description - Create a custom Map class that provides functionality
                         needed in order to run the test.cpp and Test_map.cpp
                         programs until completion and passing all the asserts.
 * Sketch of the solution - Map provides a default constructor for the parent Set
                            class. As well as provides a find and erase function.
                            As well as overloaded indexing operator.
 * This file has a worst case O(1)
 ********************************************************************************/

 #ifndef MAP_H
 #define MAP_H

 #include "../lab8/Set.h"
 #include "Pair.h"

 using namespace std;

 template <class key, class value>
 class Map: public Set< Pair<key, value> >
 {
 public:
     typedef Set < Pair < key, value > > parent;
     typedef Set_iterator < Pair < key, value > > iterator;

     Map(): parent() {}

     //Returns a iterator after finding a specific value in the Map - 0(1)
     iterator find(const key & k) { return parent::find(Pair<key, value>(k,value()));}
     //Overloaded indexing operator that returns the value - 0(1)
     value & operator[](const key & k) {iterator it = parent::insert(Pair<key,value>(k,value()));  return (*it).second;}
     //Erases a key within the Map - 0(1)
     void erase(const key & k) {parent::erase(Pair<key,value>(k,value()));}
 } ;
 #endif // MAP_H
