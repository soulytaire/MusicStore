#pragma once
#include "Instrument.h"
#include <iostream>
#include <string>

using namespace std;

class Guitar : public Instrument {
protected:

	int numFrets;
	int numStrings;
	bool hasFrets;
public:
	Guitar();
	Guitar(string instrumentType, int numFrets, int numStrings, bool hasFrets,
		bool electric, string brand, string model,
		string color, float weight, float price);

	// Override methods
	string createWarrantyNumber() const override;
	virtual void printData(ostream& out) const override;

};