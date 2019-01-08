//Michael Smith 
//CSE 570
//Lab5

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>

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

typedef multimap<char, string> SetOfItems;
typedef std::multimap<char, string>::iterator MMAPIterator;

class GParser
{
public:

	void readingG(string filename);							//function to store productions and 
															//terminals into a multimap and set, respectively.
	SetOfItems closure(SetOfItems I);						//CLOSURE Function
	SetOfItems go_to(SetOfItems i, char x);					//GOTO Function
	void items();											//ITEMS function

	bool IsInSet(SetOfItems C, char first, string second);	//helper function to test if item in set
	void PrintSet(SetOfItems C, int state, char symbol);	//Prints a set with the LEFT SIDE char its for

private:
	SetOfItems productions;
	SetOfItems Result{};
	SetOfItems startset{};
	set<char> terms;
};


void GParser::readingG(string filename)
{
	string line;
	string temp;
	ifstream file(filename);
	if (!file.good()) {
		cout << "Error! File may not exist.\n";
		exit(1);
	}
	int count = 0;
	while (getline(file, line))
	{
		if (line != "$" && count == 0)
		{
			terms.insert(line[0]);
		}
		if (line != "$" && count == 1)
		{
			int dot = line.find('>') + 1;
			line.insert(dot, 1, '.');//adding '.' to the line read
			productions.insert(pair<char, string>(line[0], line.substr(3)));

			//If first item, set as the ARGUMENT item..
			if (productions.size() == 1)
			{
				startset.insert(pair<char, string>(line[0], line.substr(3)));
			}
		}
		if (line == "$")
		{
			count++;
		}
	}
	for (auto i : terms)
	{
		cout << i << endl;
	}
	cout << "productions\n";
	for (auto j : productions)
	{
		cout << j.first << " " << j.second << endl;
	}
	cout << "\n";
}


//Loops thru supplied set testing if ITEM is in it. 
//Returns TRUE if it is, FALSE if not.
bool GParser::IsInSet(SetOfItems C, char first, string second) {
	bool result = false;

	for (auto A : C) {
		if ((A.first == first) && (A.second == second)) {
			result = true;
			break;
		}
	}
	return result;
}


//Simply prints out a set with a header of STATE# and LEFT CHAR its for.
void GParser::PrintSet(SetOfItems C, int state, char symbol) {

	cout << "State: " << state << "  Symbol: " << symbol << "\n";
	for (auto i : C) {
		cout << i.first << " " << i.second << "\n";
	}
	cout << "\n";
}





SetOfItems GParser::closure(SetOfItems I)
{
	int count;

	//Setup the set to be built
	SetOfItems J = I;
	count = J.size();
	bool added = false;

	//main loop	
	do {
		bool added = false;
		for (auto K : J) {
			//Find the DOT
			string base = K.second;
			unsigned int indx = base.find('.');

			//If there is a DOT, and its NOT at the end..
			if ((indx != string::npos) && (indx < base.length() - 1))
			{
				//Get New Grammer Part
				string part = base.substr(indx + 1, 1);
				//Get all the grammers that have left side = PART
				pair<MMAPIterator, MMAPIterator> result = productions.equal_range(part.at(0));
				for (MMAPIterator it = result.first; it != result.second; it++)
				{
					//First, lets check if the returned item is the origianl Argumented item, if it is, dont include.
					if (!IsInSet(startset, it->first, it->second)) {
						//lets see if its been used before in this results set...
						if (!IsInSet(J, it->first, it->second))
						{
							added = true;
							//J.insert(pair<char, string>(part.at(0), aline));
							J.insert(pair<char, string>(it->first, it->second));
						}
					}
				}
			}
		}
		//if the orignal size is not equal to the current size of J
		//Then call clorsure again recursivly..
		if (count != J.size())
			J = closure(J);
	} while (added);
	return J;

}

SetOfItems GParser::go_to(SetOfItems i, char x)
{
	SetOfItems ret{};
	//create the search pattern needed -> .X
	string bline = ".";
	bline += x;

	//loop thru supplied set for a pattern match
	for (auto I : i) {
		string aline = I.second;
		unsigned int apos = aline.find(bline);
		//if you find one, move DOT to the right...
		if (apos != string::npos)
			ret.insert(pair<char, string>(I.first, I.second.substr(1, 1) + "." + I.second.substr(2)));
	}
	return closure(ret);
}

void GParser::items()
{
	set<char> used;							//a set of USED left side chars, you can only use a char once!
	int state = 0;							//State ID Counter
	pair<set<char>::iterator, bool> ret;	//Needed as a test if I used left cahr before
	string aline, bline;					//utility strings..

											//First, create and print STATE 0 set, closure of argumented item.
	SetOfItems C = closure(startset);
	PrintSet(C, state, startset.begin()->first);
	state++;

	//main loop thru STATE 0 set
	for (auto A : C) {
		//test right side for a DOT
		aline = A.second;
		unsigned int apos = aline.find(".");
		//If there is a dot and not at end, get teh CHAR 1 char to the right of it.
		if ((apos != string::npos) && (apos < aline.length() - 1)) {
			bline = aline.substr(apos + 1, 1);
		}
		else {
			bline = "";
		}
		//okk, if I have a good char, lets GOTO into it and build/print STATE
		if (bline != "") {
			ret = used.insert(bline.at(0));	//Try to add left CHAR to used set..
											//only if TRUE (meaning it successfully added the char to the set, false means already in set)
			if (ret.second == true) {
				SetOfItems temp = go_to(C, bline.at(0));	//trace into set
				PrintSet(temp, state, bline.at(0));			//print set
				state++;
			}
		}
	}
}

int main() {

	GParser lab5;
	lab5.readingG("g419.txt");
	
	lab5.items();
	
	int temp;
	cin >> temp;
	return 0;
}
