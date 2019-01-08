#include "Sdisk.h"
#include "Filesys.h"
#include "Table.h"
#include <iostream>
#include <vector>
#include <string>

// You can use this to test your Filesys class 

int main()
{
	Table tab("disk1", 256, 128, "file1", "file2");

	int check = tab.Build_Table("data.txt");
	if (check == 1) {
		tab.Search("Rome");
	}
	else
		cout << "Failed to find in table\n";

	int temp;
	cin >> temp; 
}