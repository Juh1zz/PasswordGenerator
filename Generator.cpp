//Password generator
//Juho Björkman 2021

#include <iostream>
#include <random>
#include <vector>
using namespace std;


void genPassword(int, vector<char>&);


int main() {
	setlocale(LC_ALL,"");
	int length = NULL;
	vector<char> password;
	bool run = true;
	char runChar = NULL;

	cout << "Welcome to the password generator.\nThe password must be atleast eight characters long.\n";
	
	do {
		agane:
		try {
			cout << "Enter the length of the password you want to generate: ";
			cin >> length;
			if (!cin || length < 8)
				throw(length);
		}
		catch (int length) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (length < 8)
				cout << "Password must be longer than " << length << ".\n";
			else
				"Enter the length of the password you want to generate as a whole number.\n";
			goto agane;
		}
		genPassword(length, password);
		cout << "Your password is: ";
		for (int i = 0; i < length; i++)
			cout << password[i];
		cout << endl << endl;
		runAgain:
		try {
			cout << "Would you like to generate another password? y/n: ";
			cin >> runChar;
			if(runChar != 'Y' && runChar != 'y' && runChar != 'N' && runChar != 'n' || cin.fail())
				throw(runChar);
		}
		catch (char runChar) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Wrong input. Enter 'y' for yes or 'n' for no. \n";
			goto runAgain;
		}
		if (runChar == 'N' || runChar == 'n')
			run = false;
	} while (run == true);

	return 0;
}


void genPassword(int length, vector<char> &password) {
	string characters = "abcdefghijklmopqrstuwxyzABCDEFGHIJKLMNOPQRSTUWXYZ0123456789.,-";
	// Initialize RNG.
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(0, characters.size() - 1);

	// Generate password.
	int randomNum = 0;
	for (int i = 0; i < length; i++) {
		randomNum = distrib(gen);
		password.push_back(characters[randomNum]);
	}
}