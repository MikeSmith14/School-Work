#include "Sdisk.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Sdisk::Sdisk(string disk_name, int numberOfblocks, int block_size) {
	this->diskname = disk_name;
	this->numberofblocks = numberOfblocks;
	this->blocksize = block_size;
	fstream iofile(diskname.c_str(), ios::in | ios::out);
	if (!iofile) {
		iofile.open(diskname.c_str(), ios::out);
		iofile.close();
		iofile.open(diskname.c_str(), ios::in | ios::out);
	}
	for (int i = 0; i < (numberofblocks * blocksize); i++) {
		iofile << '#';
	}
	iofile.close();
}

int Sdisk::getblock(int blocknumber, string& buffer) {
	char c;
	int i = 0;
	fstream iofile(diskname.c_str(), ios::in);
	if (iofile.bad())
		return 1;
	iofile.seekg(blocksize * blocknumber);
	iofile.get(c);

	while (iofile.good() && i < blocksize) {
		buffer += c;
		iofile.get(c);
		i++;
	}
	iofile.close();
	return 0;
}

int Sdisk::putblock(int blocknumber, string buffer) {
	int i = 0;
	fstream iofile(diskname.c_str(), ios::in | ios::out);
	if (buffer.size() > blocksize || iofile.bad())
		return 1;
	iofile.seekg(blocknumber * blocksize);
	while (i < blocksize) {
		iofile.put(buffer[i]);
		i++;
	}
	iofile.close();
	return 0;
}

int Sdisk::getblocksize() {
	return this->blocksize;
}

int Sdisk::getnumberofblocks() {
	return this->numberofblocks;
}