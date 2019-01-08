/********************************************************************************
 * Michael Smith
 * String.h
 * 01/30/2017
 * This is the header file for class String. Containing the private variables,
 * public functions, and the overloaded operators within the class.
 ********************************************************************************/

#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <string>

using namespace std;

class String {
        int size;
        char * buffer;
public:
        //Default Constructor
        String();
        //Overload Constructors
        String(const String &);
        String(const char *);
        //Deconstructor
        ~String();

        // other methods
        int length();
        //Overloaded Operators
        char operator[](const int) const;
        String& operator=(const String &source);
        String& operator=(const char *p);
        String& operator+=(const char *);
        friend bool operator==(const String &source_a, const String &source_b);
        friend bool operator==(const String &source_a, const char *p);
        friend bool operator<=(const String &, const String &);
        friend bool operator<(const String &, const String &);
        friend bool operator>(const String &, const String &);
        friend bool operator>=(const String &, const String &);
        friend ostream & operator<<(ostream &, const String &);
};

#endif
