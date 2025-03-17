#pragma once
#include "Instrument.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Bowed : public Instrument {
protected:
	static vector<string> bowedSizes;
	string bowedSize;  // Instrument size (e.g., "4/4", "3/4")
public:
	Bowed();
	Bowed(string instrumentType, string bowedSize,
		bool electric, string brand, string model,
		string color, float weight, float price);

	string createWarrantyNumber() const override;
	virtual void printData(ostream& out) const override;


};
