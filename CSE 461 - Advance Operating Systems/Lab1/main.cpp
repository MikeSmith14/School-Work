// Michael Smith
// 005467289
// April 17, 2018

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class PasswordFile
{
public:
	PasswordFile(string filename);
	void addpw(string newuser, string newpassword);
	bool findUser(string check);
	bool checkpw(string user, string passwd);
	static void newsalt(int ns);
	
private:
	string filename; // the file that contains password information
	vector<string> user; // the list of usernames
	vector<string> password; // the list of passwords
	void synch(); //Updates the file
	string encrypt(string pw);
	string decrypt(string pw);
	static int salt;
};

int PasswordFile::salt = 1;

void PasswordFile::newsalt(int ns) {
	salt = ns;
}

string PasswordFile::encrypt(string pw) {
	for (int i = 0; i < pw.size(); i++) {
		pw[i] += salt;
	}
	return pw;
}

string PasswordFile::decrypt(string pw) {
	for (int i = 0; i < pw.size(); i++) {
		pw[i] -= salt;
	}
	return pw;
}

PasswordFile::PasswordFile(string filename) {
	string usr, pw;
	this->filename = filename;
	ifstream infile(filename.c_str());
	infile >> usr >> pw;
	while (infile.good()) {
		user.push_back(encrypt(usr));
		password.push_back(encrypt(pw));
		infile >> usr >> pw;
	}
	synch();
	infile.close();
}

void PasswordFile::synch() {
	ofstream outfile(filename.c_str());
	for (int i = 0; i < user.size(); i++) {
		outfile << user[i] << " " << password[i] << endl;
	}
	outfile.close();
}

bool PasswordFile::findUser(string check) {
	for (int i = 0; i < user.size(); i++) {
		if (user[i] == encrypt(check)) {
			return true;
		}
		else if (user[i] == check) {
			return true;
		}
	}
	return false;
}

bool PasswordFile::checkpw(string usr, string pw) {
	for (int i = 0; i < user.size(); i++) {
		if (user[i] == (encrypt(usr)) && password[i] == (encrypt(pw))) {
			return true;
		}
		return false;
	}
}

void PasswordFile::addpw(string newuser, string pw) {
	if (findUser(newuser)) {
		printf("This user already exists");
		cout << endl;
		return;
	}
	user.push_back(encrypt(newuser));
	password.push_back(encrypt(pw));
	synch();
	printf("User was successfully made");
	cout << endl;
	return;
}

int main() {
	int value;
	PasswordFile passfile("password.txt");
	passfile.addpw("dbotting", "123qwe");
	passfile.addpw("egomez", "qwert");
	passfile.addpw("tongyu", "liberty");
	passfile.addpw("dbotting", "DOH!");
	if (passfile.checkpw("dbotting", "123qwe")) {
		cout << "That password matches that user" << endl;
	}
	cin >> value;
}