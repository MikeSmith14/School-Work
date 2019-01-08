#include "Shell.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	//
	//This main program inputs commands to the shell.
	//It inputs commands as : command op1 op2
	//You should modify it to work for your implementation.
	string s;
	string command = "go";
	string op1, op2;
	Shell terminal("disk1", 128, 256);

	while (command != "quit")
	{
		command.clear();
		op1.clear();
		op2.clear();
		cout << "$";
		getline(cin, s);
		int firstblank = s.find(' ');
		if (firstblank < s.length()) s[firstblank] = '#';
		int secondblank = s.find(' ');
		command = s.substr(0, firstblank);
		if (firstblank < s.length())
			op1 = s.substr(firstblank + 1, secondblank - firstblank - 1);
		if (secondblank < s.length())
			op2 = s.substr(secondblank + 1);
		if (command == "dir")
		{
			terminal.dir();
		}
		if (command == "add")
		{
			if (terminal.add(op1) == 0)
				cout << "File already exists\n";
			else
				cout << "File " << op1 << " was created\n";
		}
		if (command == "del")
		{
			if (terminal.del(op1) == 0)
				cout << op1 << " doesn't exist\n";
			else
				cout << op1 << " was deleted\n";
		}
		if (command == "type")
		{
			terminal.type(op1);
		}
		if (command == "copy")
		{
			terminal.copy(op1, op2);
		}

	}

	return 0;
}