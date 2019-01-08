
/********************************************************************************
 * Michael Smith
 * selection.cpp
 * 01/23/2017
 * This program will use the selection sort method in order to sort random numbers
 *     generated through rand in numerical order. And time the execution time in seconds.
 * The main will ask user for number of numbers wanting to sort. Will declare a vector
 *     and fill with randomly generated numbers. The vector is then passed to selection_sort()
 *     method to sort the numbers in numerical order. In order to measure the constant from the
 *     time complexity of the program.
 * O(n^2)
 ********************************************************************************/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

void selection_sort(vector<int> &v, int n);

// The main that asks user for the number input of wanting to sort
// then creates a vector of n numbers. Then randomly generates and fills
// the vector. Then passes the vector to the selection_sort() method for sorting.
int main()
{

    int n;

    cout << "Enter the number of numbers you want to sort"<< endl;
        cin >> n;

    vector <int> v(n);

    srand(time(0));

    for(int i = 0; i < n; i++)
        v[i] = rand()%1000000;

    selection_sort(v, n);

    return 0;
}

// This function will receive the vector and n. It processes through the
// vector to sort the numbers in numerical order using the selection sort method.
void selection_sort(vector<int> &v, int n)
{
    int i, j;

    for (i = 0; i < n-1; i++){
        for (j = i+1; j < n; j++){
            if (v[i] > v[j])
                swap(v[i], v[j]);
        }
    }



}

