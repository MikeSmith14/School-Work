/********************************************************************************
 * Michael Smith
 * List.h
 * 02/26/2019
 * Problem Description - Create a Linked List class that is able to compile and
                         run the code for the two test files test.cpp and
                         List_test.cpp.
 * Sketch of the Solution - This files holds three classes. First class is List
                            which has its constructors, functions and one overloaded
                            operator. Next is the Link class which has its in-line
                            constructor, protected data and is friend class to List
                            and List_iterator. Last class is List_iterator which has
                            its constructors, its overload operators, its protected
                            data and is friend class to List.
 * The file as a whole has a O(n). Each function is has it's own indicated big-Oh.
 ********************************************************************************/

#ifndef LIST_H
#define LIST_H

#include <algorithm>

using namespace std;

//forward declaration of classes in this header
template <class T> class Link;
template <class T> class List_iterator;

//List Class
template <class T>
class List
{
public:
    typedef List_iterator<T> iterator;

    //Default Constructor
    List();
    //Overload Constructor
    List(const List<T> & l);
    //Deconstructor
    ~List();

    //Functions
    bool empty() const;
    unsigned int size() const;
    T & back() const;
    T & front() const;
    void push_front(const T & x);
    void push_back(const T & x);
    void pop_front();
    void pop_back();
    iterator begin() const;
    iterator end() const;
    void insert(List_iterator<T> & pos, const T & x);  //insert x before pos
    void erase(iterator & pos);

    //Overload Operators
    void operator=(const List<T> & l);

protected:
    Link<T> * first_link;
    Link<T> * last_link;
    unsigned int my_size;

};

//Default Constructor - O(1)
template <class T>
List<T>::List()
{
    first_link = 0;
    last_link = 0;
    my_size = 0;
}

//Copy Constructor - O(n)
template <class T>
List<T>::List(const List & l)
{
    first_link = 0;
    last_link = 0;
    my_size = 0;
    for(Link<T> * current = l.first_link; current != 0; current = current -> next_link){
        push_back(current -> value);
    }
    my_size = l.my_size;
}

//Deconstructor- O(n)
template <class T>
List<T>::~List()
{
    Link<T> * first = first_link;
    while(first != 0) {
        Link<T> * next = first->next_link;
        delete first;
        first = next;
    }
}

//Functions
//Returns true if the List is empty- O(1)
template <class T>
bool List<T>::empty() const
{
    return first_link == 0;
}

//Returns the size of the List - O(1)
template <class T>
unsigned int List<T>::size() const
{
    return my_size;
}

//Returns the value of the back Link - O(1)
template <class T>
T & List<T>::back() const
{
    return last_link -> value;
}

//Returns the value of the front Link - O(1)
template <class T>
T & List<T>::front() const
{
    return first_link -> value;
}

//Pushes a new Link to the front of the List - O(1)
template <class T>
void List<T>::push_front(const T & x)
{
    Link<T> * new_link = new Link<T> (x);
    if(new_link == 0){
        cout << "Error creating a new link due to memory." << endl;
        exit(1);
    }
    if(empty())
        first_link = last_link = new_link;
    else {
        first_link->prev_link = new_link;
        new_link->next_link = first_link;
        first_link = new_link;
    }
    my_size++;
}

//Pushes a new Link to the back of the List - O(1)
template <class T>
void List<T>::push_back(const T & x)
{
    Link<T> * new_link = new Link<T>(x);
    if(new_link == 0){
        cout << "Error creating a new link due to memory." << endl;
        exit(2);
    }
    if(empty())
        first_link = last_link = new_link;
    else{
        new_link->prev_link = last_link;
        last_link->next_link = new_link;
        last_link = new_link;
        my_size++;
    }
}

//Pops the front link of the List - O(1)
template <class T>
void List<T>::pop_front()
{
    Link<T> * temp = first_link;
    first_link = first_link->next_link;
    if(first_link != 0)
        first_link->prev_link = 0;
    else
       last_link = 0;
    delete temp;
    my_size--;

}

//Pops the back Link of the List - O(1)
template <class T>
void List<T>::pop_back()
{
    Link<T> * temp = last_link;
    last_link = last_link->prev_link;
    if(last_link != 0)
        last_link->next_link = 0;
    else
        first_link = 0;
    delete temp;
    my_size--;

}

//Returns the beginning of the List - O(1)
template <class T>
typename List<T>::iterator List<T>:: begin() const
{
    return iterator(first_link);
}

//Returns the end of the List - O(1)
template <class T>
typename List<T>::iterator List<T>:: end() const
{
    return iterator(last_link->next_link);
}

//Inserts a new Link before a given position - O(1)
template <class T>
void List<T>::insert(List_iterator<T> & pos, const T & x)
{
    Link<T> * new_link = new Link<T>(x);
    if(new_link == NULL){
        cout << "Error creating a new link due to memory." << endl;
        exit(3);
    }
    Link<T> * current = pos.current_link;
    new_link->next_link = current;
    new_link->prev_link = current->prev_link;
    current->prev_link = new_link;
    current = new_link->prev_link;
    if ( new_link->prev_link == 0 ) {
       first_link = new_link;
    }
    if(current != 0)
        current->next_link = new_link;
    my_size++;
}

//Erases a link at a given position - O(1)
template <class T>
void List<T>::erase(iterator & pos)
{
    Link<T> * current = pos.current_link;
    Link<T> * next = current->next_link;
    Link<T> * prev = current->prev_link;

    if(next != NULL)
        prev -> next_link = next;
    else
        prev = 0;

    if(prev != NULL)
        next ->prev_link = prev;
    else
        next = 0;

    delete current;
    my_size--;
}

//Overloaded assignment operator - O(n)
template <class T>
void List<T>::operator=(const List<T> & l)
{

    List_iterator<T> *p,*p2;

    this.resize(l.size());
    p = l.first_link;
    p2 = this.firstlink;
    while ( p != NULL ) {
        p2->value = p->value;
        p2++;
        p = p->next_link;
    }
    my_size = l.my_size;
}


//*******************************************************************End of List


//Link Class
template <class T>
class Link
{
private:

    //Constructor - in-line - O(1)
    Link(const T & x): value(x), next_link(0), prev_link(0) {}

    T value;
    Link<T> * next_link;
    Link<T> * prev_link;

    friend class List<T>;
    friend class List_iterator<T>;
};

//*******************************************************************End of Link

//Class List_iterator
template <class T>
class List_iterator
{
public:
    typedef List_iterator<T> iterator;

    //Constructors - in-lines - O(1)
    List_iterator(Link<T> * source_link): current_link(source_link) { }
    List_iterator(): current_link(0) { }
    List_iterator(List_iterator<T> * source_iterator): current_link(source_iterator.current_link) { }

    //Overload Operators
    T & operator*();                                 //dereferencing operator
    void operator=(const iterator & rhs);
    bool operator==(const iterator & rhs) const;
    bool operator !=(const iterator & rhs) const;
    iterator & operator++();                         //Pre-increment
    iterator operator++(int);                        //Post Increment
    iterator & operator--();                         //Pre-decrement
    iterator operator--(int);                        //post-decrement

protected:
    Link<T> * current_link;
    List<T> * theList;
    friend class List<T>;

};

//Deferencing operator Overload - O(1)
template <class T>
T & List_iterator<T>::operator*()
{
    return current_link -> value;
}

//Assignment operator overload - O(1)
template <class T>
void List_iterator<T>::operator=(const iterator & rhs)
{
    theList   = rhs.theList;
    current_link = rhs.current_link;
}

//Equal to operator overload - O(1)
template <class T>
bool List_iterator<T>::operator==(const iterator & rhs) const
{
    return current_link == rhs.current_link;
}

//Not equal to operator overload - O(1)
template <class T>
bool List_iterator<T>::operator!=(const iterator & rhs) const
{
    return current_link != rhs.current_link;
}

//Pre-increment operator overload - O(1)
template <class T>
List_iterator<T> & List_iterator<T>::operator++()
{
    current_link = current_link -> next_link;
    return *this;
}

//Post-increment operator overload - O(1)
template <class T>
List_iterator<T> List_iterator<T>::operator++(int)
{
    List_iterator<T>copy(*this);
    current_link = current_link->next_link;
    return copy;
}

//Pre-decrement operator overload - O(1)
template <class T>
List_iterator<T> & List_iterator<T>::operator--()
{
    current_link = current_link -> prev_link;
    return *this;
}

//Post-decrement operator overload- O(1)
template <class T>
List_iterator<T> List_iterator<T>::operator--(int)
{
    List_iterator<T>copy(*this);
    current_link = current_link -> prev_link;
    return copy;
}
//**********************************************************End of List_iterator

#endif
