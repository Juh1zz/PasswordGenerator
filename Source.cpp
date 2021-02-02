//Salasanageneraattori
//Juho Björkman 2020

#include <iostream>
#include <random>
#include <vector>
using namespace std;


void luoSalasana(int, vector<char>&);


int main() {
	setlocale(LC_ALL,"");
	int pituus = NULL;
	vector<char> salasana;
	bool ajetaanko = true;
	char ajetaankoChar = NULL;

	do {
		uudelleen:
		try {
			cout << "Tämä on salasanageneraattori.\nSyötä salasanan pituus kokonaislukuna: ";
			cin >> pituus;
			if (!cin || pituus < 5)
				throw(pituus);
		}
		catch (int pituus) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (pituus < 5)
				cout << "Salasana on liian lyhyt.\n";
			else
				"Syötä salasanan pituus kokonaislukuna.\n";
			goto uudelleen;
		}
		luoSalasana(pituus, salasana);
		cout << "Salasanasi on: ";
		for (int i = 0; i < pituus; i++)
			cout << salasana[i];
		cout << endl << endl;
		ajetaankoUudelleen:
		try {
			cout << "Haluatko luoda toisenkin salasanan? k/e: ";
			cin >> ajetaankoChar;
			if (!cin || ajetaankoChar != 'k' || ajetaankoChar != 'e')
				throw(ajetaankoChar);
		}
		catch (...) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Virheellinen syöte. Vastaa joko 'k' (kyllä) tai 'e' (ei). \n";
			goto ajetaankoUudelleen;
		}
		if (ajetaankoChar == 'e')
			ajetaanko = false;
	} while (ajetaanko == true);

	return 0;
}


void luoSalasana(int pituus, vector<char> &salasana) {
	char chars[] = "abcdefghijklmnopqrstuvwxyzåäö,.-;:_*!@#¤$%&/()=?`";
	for (int i = 0; i < pituus; i++) {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> distrib(1,59);
		int numero = distrib(gen);
		if (numero < 10)
			salasana.push_back(numero);
		else {
			numero = numero - 10;
			salasana.push_back(chars[numero]);
		}
	}
}