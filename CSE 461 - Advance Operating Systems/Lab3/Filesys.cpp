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
Filesys::Filesys(string diskname, int numberofblocks, int blocksize) {
	Sdisk(diskname, numberofblocks, blocksize);
	rootsize = getblocksize() / 11;
	fatsize = (getnumberofblocks() * 5) / (getblocksize() + 1);
	string temp;
	getblock(1, temp);

	//If system does not exist then build
	if (temp[0] == '#') {
		ostringstream output;
		string build;
		for (int i = 0; i < rootsize; ++i) {
			output << "XXXXX" << " " << 0 << " ";
			filename.push_back("XXXXXX");
			firstblock.push_back(0);
		}
		build = output.str();
		while (build.length() < getblocksize()) {
			build += "#";
		}
		putblock(1, build);

		//build FAT
		output.str("");
		output.clear();
		output << fatsize + 2 << " ";
		fat.push_back(fatsize + 2);
		for (int i = 1; i < fatsize + 2; ++i) {
			output << 0 << " ";
			fat.push_back(0);
		}
		for (int i = fatsize + 2; i < getnumberofblocks() - 1; ++i) {
			output << i + 1 << " ";
			fat.push_back(i + 1);
		}
		output << 0 << " ";
		fat.push_back(0);

		build = output.str();
		while (build.length() % getblocksize() != 0) {
			build += '#';
		}
		putblock(2, build);
	} else {
		istringstream input;
		string file;
		int block1, fatblock;
		input.str(temp);

		for (int i = 0; i < rootsize; ++i) {
			input >> file >> block1;
			filename.push_back(file);
			firstblock.push_back(block1);
		}
		string grab_fat;
		for (int i = 2; i < fatsize + 2; ++i) {
			getblock(i, grab_fat);
		}
		input.clear();
		input.str(grab_fat);
		for (int i = 0; i < getnumberofblocks(); ++i) {
			input >> fatblock;
			fat.push_back(fatblock);
		}
	}


}

int Filesys::fsclose() {
	return 1;
}

int Filesys::fssynch() {
	
	if (filename.empty() || firstblock.empty() || fat.empty()) {
		cout << "No Root or Fat in memory." << endl;
		return 0;
	}
	ostringstream output;
	for (int i = 0; i < rootsize; ++i) {
		output << filename[i] << " " << firstblock[i] << " ";
	}
	string buffer = output.str();
	while (buffer.length() < getblocksize()) {
		buffer += '#';
	}
	putblock(1, buffer);
	output.str("");
	output.clear();
	for (int i = 0; i < fat.size(); ++i) {
		output << fat[i] << " ";
	}
	buffer = output.str();
	while (buffer.length() % getblocksize() != 0) {
		buffer += '#';
	}
	putblock(2, buffer);
	return 1;
}

int Filesys::newfile(string file) {
	//Checks if there is room on the disk
	if (fat[0] == 0) {
		cout << "Failed to create new file. \nDisk does not have enough space\n";
			return -1;
	}
	//Check if file is too long
	if (file.length() > 5) {
		cout << "Could not create new file. " << file << " is too long" << endl;
		return -1;
	}

	//Check if file name exists already
	for (int i = 0; i < filename.size(); i++) {
		if (filename[i] == file) {
			cout << "Could not create, file already exists." << endl;
			return -1;
		}
	}

	//Creates file
	for (int i = 0; i < filename.size(); i++) {
		if (filename[i] == "xxxxxx") {
			filename[i] = file;
			firstblock[i] = 0;
			cout << "File " << file << " was created successfully" << endl;
			fssynch();
			return 0;
		}
	}
	cout << "File failed to be created" << endl;
	return -1;
}

int Filesys::rmfile(string file) {
	int fblock = getfirstblock(file);
	if (fblock == -1) {
		cout << "File was not found" << endl;
		return -1;
	}
	if (fblock == 0) {
		for (int i = 0; i < filename.size(); i++) {
			if (filename[i] == file) {
				filename[i] = "xxxxxx";
				return 0;
			}
		}
	}
	return -1;
}

int Filesys::getfirstblock(string file) {
	for (int i = 0; i < filename.size(); i++) {
		if (filename[i] == file) {
			return firstblock[i];
		}
	}
	return -1;
}

int Filesys::addblock(string file, string block){
	//Adds block to end of file and returns block number
	int allocate = fat[0];
	if (allocate = 0) {
		cout << "There is no space on device" << endl;
		return -1;
	}
	fat[0] = fat[fat[0]];
	fat[allocate] = 0;
	int fblock = getfirstblock(file);
	if (fblock = -1) {
		cout << "No file";
		return -1;
	}
	if (fblock == 0) {
		for (int i = 0; i < filename.size(); i++) {
			if (filename[i] == file) {
				firstblock[i] = allocate;
			}
		}
	} else {
		while (fat[fblock] != 0) {
			fblock = fat[fblock];
		}
		fat[fblock] = allocate;
	}
	fssynch();
	putblock(allocate, block);
	return allocate;
}

int Filesys::delblock(string file, int blocknumber) {
	if (not checkblock(file, blocknumber)) {
		cout << "No can do" << endl;
		return 0;
	}
	
	int fblock = getfirstblock(file);
	
	if (fblock == blocknumber) {
		for (int i = 0; i < filename.size(); i++) {
			if (filename[i] == file) {
				firstblock[i] = fat[firstblock[i]];
				break;
			}
		}
	} else {
		while (fat[fblock] != blocknumber) {
			fblock = fat[fblock];
		}
		fat[fblock] = fat[fat[fblock]];
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
	if (fblock == 0) {
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