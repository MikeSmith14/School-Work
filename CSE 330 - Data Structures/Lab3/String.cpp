/********************************************************************************
 * Michael Smith
 * String.cpp
 * 01/30/2017
 * This is the String Class, containing the default constructors, overloaded
 * constructors, deconstructor, and overload operators. This String class will
 * be used in the test.cpp and the String_test.cpp to run the code and successfully
 * manipulate the Strings.
 * O(n)
 ********************************************************************************/

#include "String.h"
#include <cstring>
#include <cassert>

// Default Constructor
String::String()
{
    buffer = 0;
    size = 0;
}

//Overloaded Constructors
//Takes in a series of chars and creates a String class
String::String(const char *p)
{
    size = strlen(p);
    buffer = new char[size];
    for(int i = 0; i < size; i++){
        buffer[i] = p[i];
    }
}

//Takes an existing String and creates a replica
String::String(const String &source)
{
    size = source.size;
    buffer = new char[size];
    for(int i = 0; i < size; i++){
        buffer[i] = source.buffer[i];
    }
}

//Deconstructor
String::~String()
{
    delete[] buffer;
}


//Returns the size of the String
int String::length()
{
    return size;
}


// Overloaded Operators
//Allows the return of a specific location in the String
char String::operator[](const int i) const
{
    assert(i<size && i >= 0);
    return buffer[i];
}

//Allows one String to be set equal to another String
String& String::operator=(const String &source)
{
    delete[] buffer;
    size = source.size;
    buffer = new char[size];
    for(int i = 0; i < size; i++){
        buffer[i] = source.buffer[i];
    }
    return *this;
}

//Allows a String to be set equal to a char
String& String::operator=(const char *p)
{
    delete[] buffer;
    size = strlen(p);
    buffer = new char[size];
    for(int i = 0; i < size; i++){
        buffer[i] = p[i];
    }
    return *this;
}

//Allows chars to be added on to the end of the string
String& String::operator+=(const char *p)
{
    char *temp;
    int totalsize;
    int apos, i;
    int strsize = strlen(p);

    totalsize = size + strsize;
    temp = new char[totalsize];      //creates tmp array to the new total size

    apos = 0;

    for(i = 0; i<size; i++){        //copies THIS's buffer into the new temp;
        temp[apos] = buffer[i];
        apos++;
    }

    for(i = 0; i<strsize; i++){     //puts the char string into String
        temp[apos] = p[i];
        apos++;
    }

    delete[] buffer;
    buffer = new char[totalsize];
    size = totalsize;

    for(i = 0; i < size; i++){
        buffer[i] = temp[i];
    }

    delete[] temp;

    return *this;
}

//Returns true/false if the Strings are equal to each other
bool operator==(const String& source_a, const String& source_b)
{
    if(source_a.size != source_b.size){
        return false;
    }
    for(int i = 0; i < source_a.size && i < source_b.size; i++){
        if(source_a[i] == source_b[i]){
            continue;
        }
        else{
            return false;
        }
    }

    return true;
}

//Returns true/false if the String and the char are equal to each other
bool operator==(const String& source_a, const char *p)
{
    if(source_a.size != (int) strlen(p)){
        return false;
    }

    for(int i = 0; i < source_a.size && i < (int) strlen(p); i++){
        if(source_a[i]==p[i]){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}

//Returns if the source a is less then equal to source b
bool operator<=(const String& source_a, const String& source_b)
{
    for(int i = 0; i < source_a.size && i < source_b.size; i++){
        if (source_a[i] <=source_b[i]){
            continue;
        }
        else{
            return false;
        }
    }

    return true;
}

//Returns if the source a is less then source b
bool operator<(const String& source_a, const String& source_b)
{
    for(int i = 0; i < source_a.size && i < source_b.size; i++){
        if (source_a[i] <source_b[i]){
            continue;
        }
        else{
            return false;
        }
    }

    return true;
}

//Returns if the source a is greater then source b
bool operator>(const String& source_a, const String& source_b)
{
    for(int i = 0; i < source_a.size && i < source_b.size; i++){
        if (source_a[i] >source_b[i]){
            continue;
        }
        else{
            return false;
        }
    }

    return true;
}

//Returns if the source a is greater then equal to source b
bool operator>=(const String& source_a, const String& source_b)
{
    for(int i = 0; i < source_a.size && i < source_b.size; i++){
        if (source_a[i] >=source_b[i]){
            continue;
        }
        else{
            return false;
        }
    }

    return true;
}

//Overloads system input to allow String to be assigned into ostream.
ostream& operator<<(ostream& s, const String& source_a)
{
    for(int i = 0; i < source_a.size; i++){
        s << source_a.buffer[i];
    }

    return s << "\0";   //put null at the end of the string since ostream requires a true string.
}
