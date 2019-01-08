/********************************************************************************
 * Michael Smith
 * Set.h
 * 03/06/2017
 * Problem Description - Create a Set class that is able to run test.cpp and
                         Set_test.cpp to completion without any errors
 * Sketch of the solution - The Set class, Set_iterator, and Node class have the
                            constructors, functions and overloaded operators required
                            to run the test programs and pass all the tests.
 * The file as a whole has the worst case time complexity of O(n).
********************************************************************************/

#ifndef SET_H
#define SET_H

using namespace std;

template <class T> class Set;
template <class T> class Set_iterator;

template<class T>
class Node
{
public:

    // Constructors
    Node(): value(0), parent(0), leftChild(0), rightChild(0) { }
    Node(const T & x, Node * p, Node * lc, Node * rc):
        value(x), parent(p), leftChild(lc), rightChild(rc) { }
    Node(const Node & n):
        value(n.value), parent(0), leftChild(0), rightChild(0) { }

    //Overloaded Assignment Operator
    Node & operator=(const Node & n) { value = n.value; return *this; }

    //Destructor
    ~Node() { delete leftChild; delete rightChild; }

    //Functions

    void insert( Node<T> * new_node);
    Node * find(const T & x);
    Node * merge(Node<T> * left, Node<T> * right);

protected:
    T value;
    Node * parent;
    Node * leftChild;
    Node * rightChild;

friend class Set<T>;
friend class Set_iterator<T>;

};

//Inserts a new node into the tree - Helper to Set::insert - O(1)
template<class T>
void Node<T>::insert( Node<T> * new_node)
{
    if (new_node->value <=value){
        if(leftChild != 0)
            leftChild->insert(new_node);
        else{
            new_node->parent = this;
            leftChild = new_node;
        }
    }
    else{
        if(rightChild != 0)
            rightChild->insert (new_node);
        else{
            new_node->parent = this;
            rightChild = new_node;
        }
    }
}

//Finds a specific node containing a value - Helper of Set::find - O(1)
template<class T>
Node<T> * Node<T>::find(const T & x)
{
    if(x == this-> value)
        return this;
    if(x < this->value){
        if(leftChild == 0)
            return 0;
        else
            return leftChild->find(x);
    }
    else{
        if(rightChild == 0)
            return 0;
        else
            return rightChild->find(x);
    }
}

//Merges a speific node and existing children into a new area- Helper of Set::merge - O(1)
template<class T>
Node<T> * Node<T>::merge(Node<T> * left, Node<T> * right)
{
    if(left == 0)
        return right;
    if(right == 0)
        return left;
    Node<T> * child = merge(left, right->leftChild);
    child->parent = right;
    right->leftChild = child;
    return right;
}

//----------------------------------------------------------------End of Node

template <class T>
class Set
{
public:

    typedef Set_iterator<T> iterator;

    //Constructors
    Set(): root(0), my_size(0) { }
    Set(const Set<T> &);

    //Destructor
    ~Set() { delete root; }

    //Overload Operator
    Set operator=(const Set & );

    //Functions
    bool empty() const { return root == 0; }
    unsigned int size() const { return my_size; }
    iterator insert(const T & x); //returns iterator to x if already exist
    void erase(const iterator & it);
    void erase(const T & x) { root = remove(root, x); }
    unsigned int count(const T & x) const; //returns 1 or 0 because set, not multi-set
    iterator find(const T & x) const;
    iterator begin() const;
    iterator end() const { return iterator(0); }

protected:
    Node<T> * root;
    unsigned int my_size;
    Node<T> * remove(Node<T> *, const T &);

};

//Copy Constructor - O(n)
template <class T>
Set<T>::Set(const Set<T> & op)
{
    root = 0;
    for(iterator i = op.begin(); i != op.end(); ++i)
        insert(*i);
}

//Overloaded Assignement Operator - O(n)
template<class T>
Set<T> Set<T>::operator=(const Set<T> & op)
{
    delete root;
    root = 0;
    for(iterator i = op.begin(); i != op.end(); ++i)
        insert(*i);
    return *this;
}

//Insert a new element into a set - O(1)
template<class T>
Set_iterator<T>  Set<T>::insert(const T & x )
{

    if(count(x) > 0)
        return find(x); //return itr to value already there

    Node<T> * new_node = new Node<T> (x, 0, 0, 0);
    my_size++;
    if (root == 0)
      root = new_node;
    else
      root->insert(new_node);

    return find(x); //return itr to value already there

}

//Erases a node at a specific iterator - 0(logn)
template <class T>
void Set<T>::erase(const iterator & it)
{
	if (root != 0 and it != end()) {
		Node<T> * p = it.n;
		Node<T> * left = p ->leftChild;
		Node<T> * right = p -> rightChild;
		if (right != 0) {
			// left slide
			Node<T> * left_slide = right;
			while (left_slide -> leftChild)
				left_slide = left_slide -> leftChild;
			// connect the subtrees after left slide
			left_slide -> leftChild = left;
			if (left != 0)
				left -> parent = left_slide;
			// now connect right subtree to bypass p
			right -> parent = p -> parent;
			if (p -> parent)
				if (p -> parent -> leftChild == p)
					p -> parent -> leftChild = right;
				else p -> parent -> rightChild = right;
			else // p was root
				root = right;
		} else {
			if (left == 0) {
				if (p -> parent)
					if (p -> parent -> leftChild == p)
						p -> parent -> leftChild = 0;
					else p -> parent -> rightChild = 0;
				else // p was root
					root = 0;
			} else {
				left -> parent = p -> parent;
				if (p -> parent)
					if (p -> parent -> leftChild == p)
						p -> parent -> leftChild = left;
					else p -> parent -> rightChild = left;
				else // p was root
					root = left;
			}
		}
		p -> leftChild = 0;
		p -> rightChild = 0;
		delete p;
		my_size--;
	}
}




//Counts a set for number of occurences on x - O(n)
template<class T>
unsigned int Set<T>::count(const T & x) const
{
    if ( find(x) == 0 )
        return 0;
    else
        return 1;

}

//Finds a value within the Set and returns iterator - O(1)
template<class T>
Set_iterator<T> Set<T>::find(const T & x) const
{
    Set_iterator<T> i = root;
    if ( root != 0 )
    {
        i = i.n->find(x);
    }
    return i;

}

//Returns an iterator to the beginning of the set - O(logn)
template<class T>
Set_iterator<T> Set<T>::begin() const
{
    Node<T> * current;
	current = root;

	while(current && current->leftChild)
		current = current->leftChild;

	return iterator(current);
}


//Remove all instances of x from Set - O(1)
template<class T>
Node<T> * Set<T>::remove(Node<T> * current, const T & x)
{
    if(current != 0){
        Node<T> * pa = current->parent;
        if(x < current->value){
            current->leftChild = remove(current->leftChild, x);
        }
        else if(current->value < x){
            current->rightChild = remove(current->rightChild, x);
        }
        else{
            Node<T> * result = current->merge(remove(current->leftChild, x), current->rightChild);
            current->leftChild = current->rightChild = 0;
            delete current;
            my_size--;
            if(result)
                result->parent = pa;
            return result;
        }
    }
    return current;
}

//--------------------------------------------------------------------End of Set

template<class T>
class Set_iterator
{
public:

    //Constructors
    Set_iterator(): n(0) { }
    Set_iterator(Node<T> * newNode): n(newNode) { }

    //Overload Operators
    bool operator==(Set_iterator it) const { return n == it.n; }
    bool operator!=(Set_iterator it) const { return n != it.n; }
    Set_iterator & operator++(); //Inorder traversal, pre-increment
    Set_iterator operator++(int); //Inorder traversal, post-increment
    T & operator*() { return n->value; }
    Set_iterator & operator=(Set_iterator<T> it) { n = it.n; return *this; }

protected:

    Node<T> * n;
friend class Set<T>;
};

//Overloaded the post increment operator - O(1)
template <class T>
Set_iterator<T> Set_iterator<T>::operator++(int)
{
	Set_iterator<T> clone(*this);
	operator ++();
	return clone;
}

//Overloaded the pre-increment operator - O(1)
template <class T>
Set_iterator<T> & Set_iterator<T>::operator++()
{
	if(n->rightChild){
		n = n->rightChild;
		while(n->leftChild){
			n = n->leftChild;
		}
	}
	else{
		Node<T> * tempChild = n;
		n = n->parent;
		while(n && n->rightChild == tempChild){
			tempChild = n;
			n = n->parent;
		}
	}
	return *this;
}

//-----------------------------------------------------------End Of Set_iterator





 #endif
