#include "Drumkit.h"
#include <iostream>
#include <string>

using namespace std;

// itemTypes = { "snare", "tom", "floor tom", "bass drum", "footpedal", "cymbal", "hi-hat","crash","ride", "drumrack"};
int itemSize;

Drumkit::Drumkit()
	: Instrument()
{
	itemSize = 10;
}

Drumkit::Drumkit(string instrumentType, int itemSize,
				 bool electric, string brand, string model,
				 string color, float weight, float price)
	: Instrument(instrumentType, electric, brand, model,
				 color, weight, price)
{

	this->itemSize = itemSize;
}

string Drumkit::createWarrantyNumber() const
{
	return "DRM" + instrumentType.substr(0, 2) + brand.substr(0, 3) + model.substr(0, 3);
}

void Drumkit::printData(ostream &out) const
{
	out << "[Drumkit]: " << (electric ? "Electric " : "Acoustic ") << instrumentType << endl;
	Instrument::printData(out);
	out << ", " << itemSize << " ft" << endl;
}
