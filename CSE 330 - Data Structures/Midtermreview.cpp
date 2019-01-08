#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

bool anagrams(string a, string b);

int main()
{
	//------------------------------------------------------Exercise 7 main
	//string test = "rescue";
	//string test2 = "secu1re";

	//if (anagrams(test, test2))
	//	cout << "they are anagrams" << endl;
	//else
	//	cout << "they are not anagrams" << endl;

	//-------------------------------------------------------Exercise 9 main
	//string temp;

	//cin >> temp;
	//int wordCount = 0;
	//int sentCount = 0;
	//
	//
	//while (temp != "d")
	//{
	//	wordCount++;
	//	if (temp.back() == '.')
	//		sentCount++;
	//	cin >> temp;

	//}

	//double average;
	//average = (wordCount / sentCount);

	//cout << average;

	//----------------------------------------------------------Exercise 11 page 152
	//string one = "collision";
	//string removed = "lisi";

	//string two = one - removed;

	//cout << two << endl;

	//	//---------------------------------------------------------------Exercise 9 page 183
	// Sorts that are stable are insertion sort, bubble sort and merge sort.
/*
	vector<int> list = { 15, 88, 15, 9, 88, 15, 2 };
	int n = 7;

	for (int i = 1; i < n; i++) {
		for (int elem = list[i], j = i - 1; j >= 0 && elem < list[j]; j--) {
			list[j + 1] = list[j];
			list[j + 1] = elem;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << list[i];
	}*/

	//	//---------------------------------------------------------------Exercise 11 page 183
	//T(n) = T(n/2) + T(n/2) + cn + cn  (simplify the 2 cns to just cn) 
	/*= 2T(n / 2) + cn
		T(n / 2) = 2(2T(n / 4) + c(n / 2) + cn
			4T(n / 4) + cn + cn
			4T(n / 4) + 2cn
			T(n / 4) = 2T(n / 4 / 2) + cn / 4
			4(2T(n / 8) + cn / 4) + 2cn
			8T(n / 8) + cn + 2cn
			8T(n / 8) + 3cn
			If n = 8 then T(n) = nT(1) + logncn
			O(nlogn)*/


			//	//---------------------------------------------------------------Exercise 16 page 183
			// The worst case algorithm complexity for insertion of the vector is O(n) due to the possibility
			// that vector needs to be pushed thru to a new vector location


			//	//---------------------------------------------------------------Exercise 3 page 215
	//A doubly linked list is a series of links that have three nodes, one which holds the value for the link
	// the other two house a pointer to the previous link and another that points to the next link in the list.


	//	//---------------------------------------------------------------Exercise 4 page 215




}

//--------------------------------------------------------Exercise 7 page 152
bool anagrams(string a, string b)
{

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	if (a.length() != b.length())
		return false;

	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == b[i])
			continue;
		else
			return false;
	}

	return true;

}

//----------------------------------------------------------Exercise 11 page 152
string operator-(string main, string remove)
{
	for (int i = 0; i < main.length(); i++)
	{
		for (int j = 0; j < remove.length(); j++)
		{
			if (main[i] == remove[j])
				main.erase(i);
		}
	}

	return main;



}



//	//---------------------------------------------------------------Exercise 8 page 215

list<int> append(list<int> one, list<int> two)
{

	list<int> newList;
	for (link<int> * ptr = one.begin(); ptr != one.end(); ptr++) {
		newList.push_back(ptr.value());
	}
	for (link<int> * ptr = two.begin(); ptr != two.end(); ptr++) {
		newList.push_back(ptr.value());
	}

}


// 
//	//---------------------------------------------------------------Exercise 7 page 236

		//I dont know this one :/

//	//---------------------------------------------------------------Exercise 8 page 236

// The idea of two stacks for one array can be space efficient if the two stacks start from extreme corners of the array. 
// Stack 1 starts from the left most elements and the first element in stack 1 is pushed at index 0. Stack2 starts from right most corner, first
// element in stack 2 is puushed at index n-1. Both stacks grow and shrink in opposite directions. 

#include<iostream>
#include<stdlib.h>

using namespace std;

class twoStacks
{
	int *arr;
	int size;
	int top1, top2;
public:
	twoStacks(int n)  // constructor
	{
		size = n;
		arr = new int[n];
		top1 = -1;
		top2 = size;
	}

	// Method to push an element x to stack1
	void push1(int x)
	{
		// There is at least one empty space for new element
		if (top1 < top2 - 1)
		{
			top1++;
			arr[top1] = x;
		}
		else
		{
			cout << "Stack Overflow";
			exit(1);
		}
	}

	// Method to push an element x to stack2
	void push2(int x)
	{
		// There is at least one empty space for new element
		if (top1 < top2 - 1)
		{
			top2--;
			arr[top2] = x;
		}
		else
		{
			cout << "Stack Overflow";
			exit(1);
		}
	}

	// Method to pop an element from first stack
	int pop1()
	{
		if (top1 >= 0)
		{
			int x = arr[top1];
			top1--;
			return x;
		}
		else
		{
			cout << "Stack UnderFlow";
			exit(1);
		}
	}

	// Method to pop an element from second stack
	int pop2()
	{
		if (top2 < size)
		{
			int x = arr[top2];
			top2++;
			return x;
		}
		else
		{
			cout << "Stack UnderFlow";
			exit(1);
		}
	}
};
