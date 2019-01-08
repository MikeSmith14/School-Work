#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>
#include "Filesys.h"
#include "Table.h"

using namespace std;

Table::Table(string diskname, int blocksize, int numberofblocks, string flatfile, string indexfile) :Filesys(diskname, numberofblocks, blocksize), flatfile(flatfile), indexfile(indexfile) {
	newfile(flatfile);
	newfile(indexfile);
}

int Table::Build_Table(string input_file) {
	string rec, key;
	ostringstream ostream;
	int blockid;
	ifstream infile;
	getline(infile, rec);
	while (infile.good()) {
		key = rec.substr(0, 3);
		vector<string> blocks = block(rec, getblocksize());
		blockid = addblock(flatfile, blocks[0]);
		ostream << key << " " << blockid << " ";
		getline(infile, rec);
	}
	string buffer1 = ostream.str();
	vector<string> blocks = block(buffer1, getblocksize());
	for (int i = 0; i < getblocksize(); i++) {
		addblock(indexfile, blocks[i]);
	}
	return 1;
}

int Table::Search(string value) {
	return IndexSearch(value);
}

int Table::IndexSearch(string value) {
	int fblock = getfirstblock(indexfile);
	if (fblock == -1)
		return 0;
	int block_num, index;
	string buffer1, buffer2;
	while (fblock > 0) {
		readblock(indexfile, fblock, buffer1);
		buffer2 += buffer1;
		fblock = nextblock(indexfile, fblock);
	}

	istringstream temp(buffer2);
	while (temp.good()) {
		temp >> index >> block_num;
		if (stoi(value) == index)
			return block_num;
	}
	return 0; //if nothing is found, error check
}