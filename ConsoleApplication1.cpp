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
	const char* filename = "currencies.txt"; // Namnet på textfilen
	const int maxCurrencies = 100; // Max antal valutor som strukturarrayen kan ta in

	Currency currencies[maxCurrencies]; // Här skapar vi en strukturarray

	ifstream file(filename);

	if (!file) {
		cerr << "Kunde inte öppna filen: " << filename << endl;
		return 1; // Avslutar programmet om filen inte kunde öppnas
	}

	int count = 0; // Räknar antalet inläsa valutor

	// Lägger till valuta och kurs i vår strukturarray
	while (count < maxCurrencies && file >> currencies[count].currency >> currencies[count].value) {
		count++;
	}

	file.close();

	// Loopar igenom strukturarrayen & skriver ut valutan med tillhörande värde
	for (int i = 0; i < count; i++) {
		cout << currencies[i].currency << " " << currencies[i].value << endl;
	}
	return 0;
}