//Michael Smith
//CSE 570
//LAB 1  with the extra credit DFA checks

#include<iostream>
#include <string>
using namespace std;

void DFA(string str) {

	int state[4] = { 0,1,2,3 }; // all allowed states
	char allowed_char[2] = { 'a','b' }; //sets allowed characters for language
	int current_state = 0; //Initial state
						 
	cout << "Initial state " << current_state << endl;
	bool DFS_valid = false;
	bool DFA_valid = false;

	//dfs checking
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == allowed_char[0]) {
			cout << "state " << current_state << endl;
			cout << " Char : " << str[i] << " Position " << endl;
			current_state = state[1];

		}
		if (str[i] == allowed_char[1]) {
			if (current_state == state[0]) {

				cout << "state " << current_state << endl;
				cout << " Char : " << str[i] << " Position " << i << endl;
				current_state = state[0];
			}
			else if (current_state == state[1]) {

				cout << "state " << current_state << endl;
				cout << " Char : " << str[i] << " Position " << i << endl;
				current_state = state[2];
			}
			else if (current_state == state[2]) {
				cout << "state " << current_state << endl;
				cout << " Char : " << str[i] << " Position " << i << endl;
				current_state = state[3];
				if (i == str.length() - 1) {
					DFS_valid = true;			//Sets DFS to valide
					cout << "state " << current_state << endl;
				}
			}
			else if (current_state == state[3]) {
				cout << "state #" << current_state << endl;
				cout << " Char : " << str[i] << " Position " << i << endl;
				current_state = state[0];
			}
		}

	}
	cout << endl;
	
	//dfa checking
	current_state = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == allowed_char[1]) {
			cout << "state " << current_state << endl;
			cout << " Character : " << str[i] << " Position " << i << endl;
			current_state = state[1];

		}
		if (str[i] == allowed_char[0]) {
			if (current_state == state[0]) {

				cout << "state " << current_state << endl;
				cout << " Character : " << str[i] << " Position " << i << endl;
				current_state = state[0];
			}
			else if (current_state == state[1]) {

				cout << "state " << current_state << endl;
				cout << " Character : " << str[i] << " Position " << i << endl;
				current_state = state[2];
			}
			else if (current_state == state[2]) {
				cout << "state " << current_state << endl;
				cout << " Character : " << str[i] << " Position " << i << endl;
				current_state = state[3];
				if (i == str.length() - 1) {
					DFA_valid = true;			//Sets DFA to valid
					cout << "state " << current_state << endl;
					cout << " Character : " << str[i] << " Position " << i << endl;
				}
			}
			else if (current_state == state[3]) {
				cout << "state #" << current_state << endl;
				cout << " Character : " << str[i] << " Position " << i << endl;
				current_state = state[0];
			}
		}

	}

	//Solutions of aboved checks

	if (DFS_valid == true && DFA_valid == true) {
		cout << "DFA 1 and DFA 2 are valid. " << endl;
	}
	else if (DFS_valid == true && DFA_valid == false) {
		cout << "DFA 1 is valid, DFA 2 is not valid." << endl;
	}
	else if (DFS_valid == false && DFA_valid == true) {
		cout << "DFA 2 is valid, DFA 1 is not valid." << endl;
	}
	else {
		cout << "DFA 1 and DFA 2 are not valid. " << endl;
	}
}
int main() {

	string L;
	//Tested with L = (a|b)*abb
	cout << "Enter the string " << endl;
	cin >> L;
	DFA(L);
	cin >> L;
	return 0;
	
}