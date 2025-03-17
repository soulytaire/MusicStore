#include "Brass.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef string note;

//vector<string> Brass::brassTypes = { "saxophone", "trumpet", "flute", "recorder" };
vector<string> Brass::rangeTypes = { "bass", "baritone", "alto", "tenor", "soprano" };

Brass::Brass()
	: Instrument() {

	rangeType = "alto";
	tuneNote = "F#";
}

Brass::Brass(string instrumentType, string rangeType, note tuneNote,
	bool electric, string brand, string model,
	string color, float weight, float price)
	: Instrument(instrumentType, electric, brand, model, color, weight, price) {

	if (find(rangeTypes.begin(), rangeTypes.end(), rangeType) == rangeTypes.end()) {
		throw invalid_argument("Invalid range type: " + rangeType);
	}
	this->rangeType = rangeType;
	this->tuneNote = tuneNote;
}


string Brass::createWarrantyNumber() const {
	return instrumentType.substr(0, 2) + rangeType.substr(0,2) + brand.substr(0, 3) + model.substr(0, 3);
}

void Brass::printData(ostream& out) const {
	out << "[Brass]: " << (electric ? "Electric " : "") << rangeType << " "<< tuneNote
		<< " " << instrumentType << endl;
	Instrument::printData(out);
	out << endl;

}
