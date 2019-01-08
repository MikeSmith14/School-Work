#include <iostream>
#include <algorithm>
#include "multiply.h"


using namespace std;

int main()
{

    double num1;
    double num2;
    string mult;
    double product;
    Multiply multi;
    Print p;

    cout << "Please enter the word \"Multiply\" followed by the two numbers you wish to multiply." << endl;
    cin >> mult;
    cin >> num1;
    cin >> num2;
    cout << endl;

    if (!cin.good())
    {
        cout << "There was an error with your numbers, please enter correct numbers." << endl;
        exit(0);
    }

    transform(mult.begin(), mult.end(),mult.begin(),::tolower);

    if (mult == "multiply" )
    {
       product =  multi.multiply(num1, num2);
    }
    else
    {
         cout << "There was an error with your input, please enter Multiply with a capital 'M'." << endl;
         exit(1);
    }



    p.print(product);


    return 0;
}
