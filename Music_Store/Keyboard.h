#pragma once
#include "Instrument.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef string note;

class Keyboard : public Instrument
{
protected:
	// number of keys
	int numKeys;
	// notes that in the keyboard [minNote; maxNote]
	note minNote, maxNote;
	// number of sounds effect(if it's synthesizer/organ)
	int numSounds;

public:
	Keyboard();

	Keyboard(string instrumentType, int numKeys, note minNote, note maxNote, int numSounds,
			 bool electric, string brand, string model,
			 string color, float weight, float price);

	// calculate the number of registers using minNote and maxNote
	int calculateRegisters() const;

	string createWarrantyNumber() const override;
	void printData(ostream &out) const override;
};