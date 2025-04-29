#include "Keyboard.h"
#include <iostream>
#include <string>

using namespace std;

typedef string note;

//keyTypes = { "piano", "midi", "synthesizer", "organ"};

Keyboard::Keyboard()
	: Instrument() {
	numKeys = 88;
	minNote = "C1";
	maxNote = "C8";
	numSounds = 1;
}

Keyboard::Keyboard(string instrumentType, int numKeys, note minNote, note maxNote, int numSounds,
	bool electric, string brand, string model,
	string color, float weight, float price)
	: Instrument(instrumentType, electric, brand, model, color, weight, price) {

	this->numKeys = numKeys;
	this->minNote = minNote;
	this->maxNote = maxNote;
	this->numSounds = numSounds;
}

int Keyboard::calculateRegisters() const {
	int minOctave = minNote.back() - '0';
	int maxOctave = maxNote.back() - '0';
	return maxOctave - minOctave + 1;
}

string Keyboard::createWarrantyNumber() const {
	return "KEY" + instrumentType.substr(0, 2) + to_string(numSounds) + brand.substr(0, 3) + model.substr(0, 3);
}

void Keyboard::printData(ostream& out) const {
	out << "[Keyboard]: " << (electric ? "Electric " : "")<< instrumentType << endl;
	Instrument::printData(out);
	out	<< ", Keys: " << numKeys << ", Registers: " << calculateRegisters() 
		<< "(" << minNote << " - " << maxNote << ")" 
		<< ", Sounds: " << numSounds << endl;
}


