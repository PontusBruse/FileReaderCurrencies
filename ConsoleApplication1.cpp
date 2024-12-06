#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Definiera en struktur som representerar en valuta
struct Currency {
	string currency;
	double value;
};

int main() {
	const char* filename = "currencies.txt"; // Namnet p� textfilen
	const int maxCurrencies = 100; // Max antal valutor som strukturarrayen kan ta in

	Currency currencies[maxCurrencies]; // H�r skapar vi en strukturarray

	ifstream file(filename);

	if (!file) {
		cerr << "Kunde inte �ppna filen: " << filename << endl;
		return 1; // Avslutar programmet om filen inte kunde �ppnas
	}

	int count = 0; // R�knar antalet inl�sa valutor

	// L�gger till valuta och kurs i v�r strukturarray
	while (count < maxCurrencies && file >> currencies[count].currency >> currencies[count].value) {
		count++;
	}

	file.close();

	// Loopar igenom strukturarrayen & skriver ut valutan med tillh�rande v�rde
	for (int i = 0; i < count; i++) {
		cout << currencies[i].currency << " " << currencies[i].value << endl;
	}
	return 0;
}