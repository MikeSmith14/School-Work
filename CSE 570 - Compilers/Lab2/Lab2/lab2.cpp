//Michael Smith 
//CSE 570
//Lab2

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class gramReader
{
public:
	void readGram(string filename);
	bool is_term(char x);
	bool is_nonterm(char x);
	void first();
	void printFirst();
	void follows();
	void printFollows();
private:
	set<char> goFirst(char x);
	vector<char> terms;
	vector<char> nonterms;
	vector<string> gram;
	vector<char> allPos;
	vector< set<char> > firsts;
	vector< set<char> > Follow;
};

//Reads grammar in from a specified text file in main
void gramReader::readGram(string filename) {
	string line;
	ifstream file(filename);
	if (!file.good()) {
		cout << "Error! File does not exist.\n";
		exit(1);
	}
	int count = 0;
	getline(file, line);
	if (count == 0) {
		while (count != 1) {
			terms.push_back(line[0]);
			getline(file, line);
			if (line == "$") {
				count = 1;
			}
		}
	}
	getline(file, line);
	int index_nont = 0;
	while (line != "$") {
		gram.push_back(line);
		if (index_nont > 0) {
			if (nonterms[index_nont - 1] != line[0]) {
				nonterms.push_back(line[0]);
				index_nont++;
			}
		}
		if (index_nont == 0) {
			nonterms.push_back(line[0]);
			index_nont++;
		}
		getline(file, line);
	}
	allPos = terms;
	for (int i = 0; i < nonterms.size(); i++) {
		allPos.push_back(nonterms[i]);
	}
}

//Checks to make sure character is a terminal
bool gramReader::is_term(char x) {
	for (int i = 0; i < terms.size(); i++) {
		if (x == terms[i]) {
			return true;
		}
	}
	return false;
}

//Checks if the character is a non-terminal
bool gramReader::is_nonterm(char x) {
	for (int i = 0; i < nonterms.size(); i++) {
		if (x == nonterms[i]) {
			return true;
		}
	}
	return false;
}

void gramReader::first() {
	set<char> temp;
	int start = 0;
	int end = 0;
	for (int i = 0; i < allPos.size(); i++) {
		firsts.push_back(temp);
	}
	do {
		end = 0;
		start = 0;
		for (int i = 0; i < firsts.size(); i++) {
			start += firsts[i].size();
		}
		for (int i = 0; i < allPos.size(); i++) {
			temp = goFirst(allPos[i]);
			firsts[i] = temp;
		}
		for (int i = 0; i<firsts.size(); i++) {
			end += firsts[i].size();
		}
	} while (start != end);
}

set<char> gramReader::goFirst(char x) {
	set<char> temp;
	string t;
	if (is_term(x)) {
		temp.insert(x);
	}
	if (is_nonterm(x)) {
		for (int i = 0; i < gram.size(); i++) {
			t = gram[i];
			if (t[0] == x) {
				if (t[3] == 'e') {
					temp.insert(t[3]);
				}
				else if (is_term(t[3])) {
					temp.insert(t[3]);
				}
				else if (is_nonterm(t[3])) {
					for (int i = 0; i < allPos.size(); i++) {
						if (allPos[i] == t[3]) {
							temp.insert(firsts[i].begin(), firsts[i].end());
						}
					}
				}
			}
		}
	}
	return temp;
}

//Ouputs First
void gramReader::printFirst() {
	cout << "FIRSTS\n";
	for (int i = 0; i < firsts.size(); i++) {
		cout << allPos[i] << " = ";
		for (set<char>::iterator iter = firsts[i].begin(); iter != firsts[i].end(); iter++) {
			cout << *iter;
		}
		cout << endl;
	}
}

void gramReader::follows() {
	set<char> temp;
	for (int i = 0; i < nonterms.size(); i++) {
		Follow.push_back(temp);
	}
	Follow[0].insert('$');
	int index_nonterm;
	int index_firsts;

	for (int k = 0; k<gram.size(); k++) {
		for (int i = 3; i <gram[k].size() - 1; i++) {
			if (is_nonterm(gram[k][i])) {
				for (int j = 0; j < nonterms.size(); j++) {
					if (gram[k][i] == nonterms[j]) {
						index_nonterm = j; break;
					}
				}
				for (int j = 0; j<allPos.size(); j++) {
					if (gram[k][i + 1] == allPos[j]) {
						index_firsts = j; break;
					}
				}
				temp = firsts[index_firsts];
				Follow[index_nonterm].insert(temp.begin(), temp.end());
				Follow[index_nonterm].erase('e');
			}
		}
	}

	int index_follow;
	for (int k = 0; k<gram.size(); k++) {
		for (int i = 0; k<gram.size(); k++) {
			if (is_nonterm(gram[k][gram[k].size() - 1])) {
				for (int j = 0; j < nonterms.size(); j++) {
					if (gram[k][i] == nonterms[j]) {
						index_nonterm = j; break;
					}
				}
				for (int j = 0; j<nonterms.size(); j++) {
					if (gram[k][0] == nonterms[j]) {
						index_follow = j; break;
					}
				}
				temp = Follow[index_follow];
				Follow[index_nonterm].insert(temp.begin(), temp.end());
			}
		}
	}

	bool found = false;
	for (int k = 0; k<gram.size(); k++) {
		for (int i = 3; i <gram[k].size(); i++) {
			if (is_nonterm(gram[k][i])) {
				for (int j = terms.size(); j<allPos.size(); j++) {
					if (gram[k][i + 1] == allPos[j]) {
						for (set<char>::iterator itr = firsts[j].begin(); itr != firsts[j].end(); itr++) {
							if (*itr == 'e') {
								found = true; break;
							}
						}
					}
					if (found == true) {
						for (int h = 0; h<nonterms.size(); h++) {
							if (nonterms[h] == gram[k][i]) { index_nonterm = h; break; }
						}
						break;
					}
				}
				for (int j = 0; j<nonterms.size(); j++) {
					if (gram[k][0] == nonterms[j]) {
						index_follow = j; break;
					}
				}
				temp = Follow[index_follow];
				Follow[index_nonterm].insert(temp.begin(), temp.end());
			}
		}
	}
}

//Outputs Follows
void gramReader::printFollows() {
	cout << "FOLLOWS\n";
	for (int i = 0; i < Follow.size(); i++) {
		cout << nonterms[i] << " = ";
		for (set<char>::iterator iter = Follow[i].begin(); iter != Follow[i].end(); iter++) {
			cout << *iter;
		}
		cout << endl;
	}
}

int main() {

	gramReader gram;
	//cout << "This is grammar g417:" << endl;
	//gram.readGram("g417.txt");
	
    cout << "This is grammar g419:" << endl;
	gram.readGram("g419.txt");
	
	gram.first();
	gram.printFirst();
	gram.follows();
	gram.printFollows();
	
	int temp;
	cin >> temp;
	return 0;
}
