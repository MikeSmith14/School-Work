#include <iostream>
#include <string>
#include "display_message.h"

using namespace std;

void display_message(){

    string message;
    getline(cin, message);
    cout << message;

}
