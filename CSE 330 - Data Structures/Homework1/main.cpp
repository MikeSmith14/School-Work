/********************************************************************************
 * Michael Smith
 * main.cpp
 * 1/26/17
 * This program illustrates indentation and other conventions in this course.
********************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

double average(double *d, int size);
double variance(double *d, int size);

int main()
{
    double arr[100];
    int size = 0;

    cout << "Enter a list of numbers, no more then 100 numbers:" << endl;

    while(!cin.eof())
    {

        if(cin >> arr[size])
        {
            size++;
        }


        if (size > 100)
        {
            cout << "Too many numbers were entered." << endl;
            exit(0);
        }
    }

    if (size == 0 || size == 1)
    {
        cout << "Unable to return average or variance due to too few numbers." << endl;
        exit(0);
    }

    cout << endl;
    cout << "The average is : " << average(arr,size) << endl;
    cout << "The variance is : " << variance(arr, size);


    return 0;
}

double average(double *d, int size)
{
    double sum = 0;

    for(int i = 0; i <size; i++)
    {
        sum = sum + d[i];
    }

    double average = sum/size;

    return average;
}


double variance(double *d, int size)
{
    double m = average(d, size);
    double sum = 0;
    double var = 0;

    for(int i = 0; i<size; i++)
    {
        sum = sum + ((d[i]-m)*(d[i]-m));
    }

    var = (sum)/(size-1);

    return var;

}

