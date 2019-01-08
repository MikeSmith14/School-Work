/****************************
 * Michael Smith
 * expr.cpp
 * 01/09/2017
 * This program converts infix expression to a postfix expression.
 * This file contains two functions. The main function which holds the
 *     algorithm for the converting of the infix expressions to the
 *     post fix expression. The second function is a precedence checker
 *     which checks operators and gives them a precedence level to evaluate
 *     their order.
****************************/

#include <stack>
#include <iostream>

int prec(char,int);

using namespace std;

stack<char> operators;


// Main file. Holds algorithm to convert infix to postfix expressions while
// using function prec to check operator precedence.
int main () {

    char ch;


    cin.get(ch);

    while ( !cin.eof() ) {

        while ( ch != '\n' ) {                                                      //Loop Through Input Line

            if ( ch == ' ') {                                                       //Skip white Spaces
                cin.get(ch);
                continue; }

            if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                cout << ch; }
            else if (ch == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    cout << operators.top();
                    operators.pop(); }
            if (!operators.empty())
                    operators.pop();
            else
                cout << "There was an error no matching '(' was found" << endl; }
            else if (ch == '+' || ch =='-' || ch == '*' || ch == '/' || ch == '(') {
                if (operators.empty() || prec(operators.top(),0) < prec(ch,1))
                    operators.push(ch);
                else {
                    while (!operators.empty() && (prec(operators.top(),0) >= prec(ch,1))) {
                        cout << operators.top();
                        operators.pop(); }
                    operators.push(ch); } }
            else {
                if (ch != '\n' ) {
                    cout << "There was an error with the input" << endl;
                        } }
            cin.get(ch);}


        while (!operators.empty()) {
            cout << operators.top();
            operators.pop(); }

        cout << endl;

        cin.get(ch);

    }

    return 0; }


// Checks the precedence of the operators to determine order of operations and whether were testing
// the stack or a passed input char.
int prec(char input,int flag) {

    int output;

    if (input == '*' || input == '/')                                                       //Sets * and / as the highest precedence at 2
        output = 2;
    else if (input == '+' || input == '-')                                                  //Sets + and - as the middle precedence at 1
        output = 1;
    else if ( input == '(' ) {                                                              //Sets the ( as the lowest precedence when inside the stack and sets it to the highest outside of the stack
        if ( flag == 1 )
            output = 3;
        else
            output = 0; }
    else
        cout << "There was an invalid operator" << endl;
    return output;

}
