//comments please

// test.cpp - a simple test program for List.h

#include <iostream>
#include "List.h"

using namespace std;

int main()
{
   List<int> l;

   l.push_back(44);  // list = 44
   l.push_back(33);  // list = 44, 33
   l.push_back(11);  // list = 44, 33, 11
   l.push_back(22);  // list = 44, 33, 11, 22

   List<int> m(l);

   List<int>::iterator itr(m.begin());
   while (itr != m.end()) {
        cout << *itr << endl;
        itr++;
   }
}
