#pragma once
#include "Instrument.h"
#include <iostream>
#include <string>

class Drumkit : public Instrument {
protected:

	int itemSize;

public:

	Drumkit();

	Drumkit(string instrumentType, int itemSize,
		bool electric, string brand, string model,
		string color, float weight, float price);

	string createWarrantyNumber() const override;
	virtual void printData(ostream& out) const override;
    
};
