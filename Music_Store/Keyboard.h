#pragma once
#include "Instrument.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef string note;

class Keyboard : public Instrument {
protected:
	
	int numKeys;
	note minNote, maxNote;
	int numSounds;

public:
	Keyboard();

	Keyboard(string instrumentType, int numKeys, note minNote, note maxNote, int numSounds,
		bool electric, string brand, string model,
		string color, float weight, float price);

	int calculateRegisters() const;

	// Override methods

	string createWarrantyNumber() const override;
	virtual void printData(ostream& out) const override;



};