#pragma once
//key
// type : saxophone, trumpet, flute, recorder
//range : tenor, bass, alto, batirone, soprano

#include "Instrument.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef string note;

class Brass : public Instrument {
protected:
	static vector<string> rangeTypes;
	string rangeType;
	note tuneNote;

public:
	Brass();

	Brass(string instrumentType, string rangeType, note tuneNote,
		bool electric, string brand, string model,
		string color, float weight, float price);


	// Override methods

	string createWarrantyNumber() const override;
	virtual void printData(ostream& out) const override;



};