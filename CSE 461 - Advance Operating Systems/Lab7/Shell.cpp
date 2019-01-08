#include "Shell.h"
#include "Filesys.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

Shell::Shell(string diskname, int blocksize, int numberofblocks):Filesys(diskname, numberofblocks, blocksize){}

//list files
int Shell::dir() {
	vector<string> fList = ls();
	for (int i = 0; i < fList.size(); i++) {
		cout << fList[i] << " ";
	}
	cout << endl;
	return 1;
}

//add a new file using input from the keyboard
int Shell::add(string file) {
	string typing;
	int isGood = newfile(file);
	if (isGood == -1) {
		return 0;
	}
	cout << "Please enter text: ";
	getline(cin, typing);
	if (typing == "~") return 1;
	vector<string> blocks = block(typing, this->getblocksize());
	for (int i = 0; i < blocks.size(); i++) {
		addblock(file, blocks[i]);
	}
	return 1;
}

// deletes the file
int Shell::del(string file) {
	int fblock = getfirstblock(file);
	if (fblock == -1) return 0;
	while (fblock != -1) {
		delblock(file, fblock);
		fblock = getfirstblock(file);
	}
	return 1;
}


//lists the contents of file
int Shell::type(string file) {
	int fblock = getfirstblock(file);
	if (fblock == -1)
		return 0;
	string buffer;
	while (fblock > 0) {
		readblock(file, fblock, buffer);
		fblock = nextblock(file, fblock);
		cout << buffer;
		buffer.erase(buffer.begin(), buffer.end());
	}
	cout << endl;
	return 1;
}

//copies file1 to file2
int Shell::copy(string file1, string file2) {
	int firstFile = getfirstblock(file1);
	int secondFile = getfirstblock(file2);
	if (firstFile == -1) {
		cout << file1 << " doesn't exist\n";
		return 0;
	}
	if (secondFile != -1) {
		cout << file2 << " already exists\n";
		return 0;
	}
	// create file 
	newfile(file2);
	if (firstFile == 0)
		return 0;
	string buff;
	while (firstFile > 0) {
		readblock(file1, firstFile, buff);
		addblock(file2, buff);
		firstFile = nextblock(file1, firstFile);
	}
	return 0;
}
