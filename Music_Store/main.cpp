#include <iostream>
#include "Instrument.h"
using namespace std;

int main() {

	//vector <Guitar> guitars;


	try {
		Instrument* violin = Instrument::createInstrument("violin", "Yamaha", "V5", "Brown", 1.2, 350, false);
		cout << *violin;

		Instrument* saxophone = Instrument::createInstrument("saxophone", "Selmer", "Super Action 80", "Gold", 3.5, 4000, false);
		cout << *saxophone;

		delete violin;
		delete saxophone;
	}
	catch (const exception& e) {
		cerr << "Error: " << e.what() << endl;
	}

	return 0;
}