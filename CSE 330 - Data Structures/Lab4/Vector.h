/********************************************************************************
 * Michael Smith
 * Vector.h
 * 02/07/2017
 * Description- This is a template class called Vector, that provides functionality
                of vectors in order to successfully run the Vector_test.cpp provided
                in lab description.
 * Sketch - This template class is based on functionality of vectors without the use
            of vectors. It contains a default constructor, 3 overload constructors with
            different parameters, and a deconstructor. As well as several accessors,
            mutator functions, and two overload operators.
 * O(n)
 ********************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

// Vector.h

using namespace std;

template <class T>
class Vector
{
public:

    typedef T * iterator;

    //Constructors
    Vector();
    Vector(unsigned int size);
    Vector(unsigned int size, const T & initial);
    Vector(const Vector<T> & v);

    //Deconstructor
    ~Vector();

    //Accessors
    unsigned int capacity() const;
    unsigned int size() const;
    bool empty() const;
    iterator begin();
    iterator end();
    T & front();
    T & back();

    //Mutators
    void push_back(const T & value);
    void pop_back();
    void reserve(unsigned int capacity);
    void resize(unsigned int size);

    //Overload Operators
    T & operator[](unsigned int index);
    T & operator=(const Vector<T> &);

private:
    unsigned int my_size;
    unsigned int my_capacity;
    T * buffer;
};

//Default Constructor
template <class T>
Vector<T>::Vector()
{
    my_size = 0;
    my_capacity = 0;
	buffer = 0;
}

//Overloaded Constructors
//Assigns a starting size to the Vector, and matching the capacity to meet the size
//fills buffer with default of type of vector
template <class T>
Vector<T>::Vector(unsigned int size)
{
    my_size = size;
    my_capacity = size;
    buffer = new T[size];
    for(unsigned int i=0; i<size; i++){
        buffer[i] = T();
    }
}

//Assigns the starting size and capacity of the Vector, fills the Vector with initial value
template <class T>
Vector<T>::Vector(unsigned int size, const T & initial)
{
    my_size = size;
    my_capacity = size;
    buffer = new T[my_size];
    for(unsigned int i = 0; i < size; i++){
        buffer[i] = initial;
    }
}

//Copies an existing Vector into a new Vector
template <class T>
Vector<T>::Vector(const Vector<T> & v)
{
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    buffer = new T[my_size];
    for(unsigned int i = 0; i<my_size; i++){
        buffer[i] = v.buffer[i];
    }

}

//Deconstructor
//Deletes buffer
template <class T>
Vector<T>::~Vector()
{
    delete[] buffer;
}

//Accessors
//Returns capacity for the Vector
template <class T>
unsigned int Vector<T>::capacity() const
{
    return my_capacity;
}

//Returns size of the Vector
template <class T>
unsigned int Vector<T>::size() const
{
    return my_size;
}

//Returns true if Vector is empty
template <class T>
bool Vector<T>::empty() const
{
    return my_size==0;
}

//Returns the pointer to the beginning of the Vector
template <class T>
typename Vector<T>::iterator Vector<T>::begin()
{
        return buffer;
}

//Returns the pointer to the end of the Vector
template <class T>
typename Vector<T>::iterator Vector<T>::end()
{
    return begin() + my_size;
}

//Returns the front of the Vector
template <class T>
T& Vector<T>::front()
{
    return buffer[0];
}

//Returns the back of the Vector
template <class T>
T& Vector<T>::back()
{
    if (my_size > 0){
        return buffer[my_size-1];
    }
}

//Mutators
//Pushes a new element to the back of the Vector
template <class T>
void Vector<T>::push_back(const T & value)
{
    if(my_size >= my_capacity){
        reserve(my_capacity+5);
    }
    buffer[my_size++] = value;
}

//Pops last element off the Vector
template <class T>
void Vector<T>::pop_back()
{
    my_size--;
}

//Reserves more memory for the Vector. Copies Vector to a new location if needed
template <class T>
void Vector<T>::reserve(unsigned int new_capacity)
{
    if (new_capacity <= my_capacity){
        return;
    }
    T * new_Buffer = new T[new_capacity];
    for(unsigned int i=0; i<my_size; i++){
        new_Buffer[i] = buffer[i];
    }
    my_capacity = new_capacity;
    delete[] buffer;
    buffer = new_Buffer;
}

//Resizes the Vector to a given new size
template <class T>
void Vector<T>::resize(unsigned int new_size)
{
    reserve(new_size);
    my_size = new_size;
}

//Overloaded Operators
//Returns reference to a specific index in the Vector
template <class T>
T& Vector<T>::operator[](unsigned int index)
{
    return buffer[index];
}

//Allows = to set one Vector equal to the other
template <class T>
T& Vector<T>::operator=(const Vector<T> & v)
{
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    delete[] buffer;
    buffer = new T[my_size];
    for(int i = 0; i<my_size; i++){
        buffer[i] = v.buffer[i];
    }
}
#endif
