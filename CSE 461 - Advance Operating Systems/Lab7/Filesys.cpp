#include "Filesys.h"
#include <iomanip>
#include <sstream>
#include <iostream>


using namespace std;

Filesys::Filesys() {
	rootsize = 0;           // maximum number of entries in ROOT
	int fatsize = 0;            // number of blocks occupied by FAT
	filename.push_back(" ");   // filenames in ROOT
	firstblock.push_back(0); // firstblocks in ROOT
	fat.push_back(0);
}
Filesys::Filesys(string diskname, int numberofblocks, int blocksize) : Sdisk(diskname, numberofblocks, blocksize){
	int blockSize = getblocksize();
	int numOfBlocks = getnumberofblocks();
	rootsize = blockSize / 12;
	fatsize = numOfBlocks * 6 / blocksize + 1;
	string check;
	getblock(0, check);
	if (check[0] != '#')
	{
		istringstream rstream1, fstream1;
		string rbuffer1, fbuffer1;
		getblock(0, rbuffer1);
		rstream1.str(rbuffer1);
		for (int i = 0; i < rootsize; i++)
		{
			string f;
			int n;
			rstream1 >> f >> n;
			filename.push_back(f);
			firstblock.push_back(n);
		}
		for (int i = 1; i <= fatsize; i++)
		{
			string s;
			getblock(i, s);
			fbuffer1 += s;
		}
		fstream1.str(fbuffer1);
		for (int i = 0; i < numOfBlocks; i++)
		{
			int n = 0;
			fstream1 >> n;
			fat.push_back(n);
		}
	}
	else
	{
		for (int i = 0; i < rootsize; i++)
		{
			filename.push_back("*****");
			firstblock.push_back(0);
		}
		fat.push_back(fatsize + 1);
		for (int i = 1; i <= fatsize; i++)
			fat.push_back(i);
		for (int i = fatsize + 1; i < numOfBlocks; i++)
			fat.push_back(i + 1);
		fat[fat.size() - 1] = 0;
		fssynch();
	}
}

int Filesys::fsclose() {
	return 1;
}

int Filesys::fssynch() {

	ostringstream rstream;
	ostringstream fstream;
	
	for (int i = 0; i < rootsize; i++) {
		rstream << filename[i] << " " << firstblock[i] << " ";
	}
	for (int i = 0; i < fat.size(); i++) {
		fstream << fat[i] << " ";
	}
	string rbuffer = rstream.str();
	string fbuffer = fstream.str();
	vector<string> rVec, fVec;
	rVec = block(rbuffer, getblocksize());
	fVec = block(fbuffer, getblocksize());
	putblock(0, rVec[0]);
	for (int i = 1; i <= fVec.size(); i++) {
		putblock(i, fVec[i - 1]);
		return 0;
	}
}

int Filesys::newfile(string file) {
	for (int i = 0; i < filename.size(); i++) {
		if (filename[i] == file)
			return 0;
		if (filename[i] == "*****") {
			filename[i] = file;
			firstblock[i] = 0;
			cout << "Adding new file " << file << endl;
			fssynch();
			return 1;
		}
	}
}

int Filesys::rmfile(string file) {
	for (int i = 0; i < filename.size(); i++) {
		if (firstblock[i] == 0) {
			filename[i] = "XXXXX";
			return fssynch();
		}
	}
}

int Filesys::getfirstblock(string file) {
	for (int i = 0; i < filename.size(); i++) {
		if (filename[i] == file) {
			return firstblock[i];
		}
	}
	return -1;
}

int Filesys::addblock(string file, string buffer){
	int fblock = getfirstblock(file);
	if (fblock < 0) {
		cout << "Error: file " << file << " is not found. \n";
		return -1;
	}
	int allocate = fat[0];
	if (allocate == 0) {
		cout << "No space left on device \n";
		return -1;
	}
	fat[0] = fat[allocate];
	fat[allocate] = 0;
	if (fblock == 0) {
		for (int i = 0; i < filename.size(); i++) {
			if (filename[i] == file) {
				firstblock[i] = allocate;
			}
		}
	} else {
		int block = fblock;
		while (fat[block] != 0)
			block = fat[block];
		fat[block] = allocate;
	}
	putblock(allocate, buffer);
	cout << "Adding new block successfully\n";
	fssynch();
	return allocate;
}

int Filesys::delblock(string file, int blocknumber) {
	if (blocknumber <= 0) {
		cout << file << " cannot be deleted because it is empty \n";
		return 0;
	}
	if (!checkblock(file, blocknumber)) {
		cout << "Cannot delete block " << blocknumber << endl;
		return 0;
	}
	if (getfirstblock(file) == blocknumber) {
		for (int i = 0; i < filename.size(); i++) {
			if (filename[i] == file) {
				firstblock[i] = fat[blocknumber];
				cout << "Deleting block " << blocknumber << endl;
			}
		}
	} else {
		int fblock = getfirstblock(file);
		while (fat[fblock] != blocknumber)
			fblock = fat[fblock];
		fat[fblock] = fat[blocknumber];
	}
	fat[blocknumber] = fat[0];
	fat[0] = blocknumber;
	fssynch();
	return 1;
}

int Filesys::readblock(string file, int blocknumber, string& buffer) {
	int fblock = getfirstblock(file);
	if (fblock == -1) {
		cout << "File was not found" << endl;
		return -1;
	}
	if (checkblock(file, blocknumber)) {
		getblock(blocknumber, buffer);
		return 0;
	}
	return -1;
}

int Filesys::writeblock(string file, int blocknumber, string buffer) {
	int fblock = getfirstblock(file);
	if (fblock == -1) {
		cout << "File was not found" << endl;
		return -1;
	}
	if (checkblock(file, blocknumber)) {
		putblock(blocknumber, buffer);
		return 0;
	}
	return -1;
}

int Filesys::nextblock(string file, int blocknumber) {
	int fblock = getfirstblock(file);
	if (fblock == -1) {
		cout << "File was not found" << endl;
		return -1;
	}
	if (checkblock(file, blocknumber)) {
		return fat[blocknumber];
	}
	return -1;
}

bool Filesys::checkblock(string file, int blocknumber) {
	int fblock = getfirstblock(file);
	if (fblock < 0) {
		return false;
	}
	while (fblock != 0) {
		if (fblock == blocknumber) {
			return true;
		}
		fblock = fat[fblock];
	}
	return false;
}

vector<string> Filesys:: block(string buffer, int b)
{
	// blocks the buffer into a list of blocks of size b

	vector<string> blocks;
	int numberofblocks = 0;

	if (buffer.length() % b == 0)
	{
		numberofblocks = buffer.length() / b;
	}
	else
	{
		numberofblocks = buffer.length() / b + 1;
	}

	string tempblock;
	for (int i = 0; i<numberofblocks; i++)
	{
		tempblock = buffer.substr(b*i, b);
		blocks.push_back(tempblock);
	}

	int lastblock = blocks.size() - 1;

	for (int i = blocks[lastblock].length(); i<b; i++)
	{
		blocks[lastblock] += "#";
	}

	return blocks;

}

vector<string> Filesys::ls() {
	vector<string> flist;
	for (int i = 0; i < filename.size(); i++) {
		if (filename[i] != "XXXXX"){
			flist.push_back(filename[i]);
		}
	}
	return flist;
}