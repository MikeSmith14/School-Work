#include "Sdisk.h"
#include "Filesys.h"
#include <iostream>

using namespace std;

int main()
{
	int temp;

	Sdisk disk1("test1", 16, 32);
	Filesys initial("test", 16, 32);
	cout << "File system was initialized correctly\n";
	cin >> temp;

	return 0;
}