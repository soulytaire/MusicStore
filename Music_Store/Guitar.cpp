#include "Guitar.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


//vector<string> Guitar::guitarTypes = { "guitar", "bass", "ukulele"};

Guitar::Guitar()
	: Instrument() { 
	numFrets = 20;
	numStrings = 4;
	hasFrets = true;
}

Guitar::Guitar(string instrumentType, int numFrets, int numStrings, bool hasFrets,
	bool electric, string brand, string model,
	string color, float weight, float price)
	: Instrument(instrumentType, electric, brand, model, color, weight, price) {

    this->numFrets = numFrets;
	this->numStrings = numStrings;
	this->hasFrets = hasFrets;
}


string Guitar::createWarrantyNumber() const {
	return instrumentType.substr(0, 2) + brand.substr(0, 3) + model.substr(0, 3) + to_string(numStrings);
}

void Guitar::printData(ostream& out) const {
	out << "[Guitar]: " << (electric ? "Electric " : "Acoustic")
		<< instrumentType << endl; 
	Instrument::printData(out);
	out << " Strings: " << numStrings << (hasFrets ? "" : ", Fretless");
	out << ", Frets: " << numFrets << endl;
	
}

