#include "Bowed.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> Bowed::bowedSizes = {"1/4", "1/2", "3/4", "4/4"};

Bowed::Bowed()
	: Instrument()
{
	bowedSize = "4/4";
}

Bowed::Bowed(string instrumentType, string bowedSize,
			 bool electric, string brand, string model,
			 string color, float weight, float price)
	: Instrument(instrumentType, electric, brand, model, color, weight, price)
{
	// check if the bowed size is valid
	if (find(bowedSizes.begin(), bowedSizes.end(), bowedSize) == bowedSizes.end())
	{
		throw invalid_argument("Invalid bowed size: " + bowedSize);
	}

	this->bowedSize = bowedSize;
}

string Bowed::createWarrantyNumber() const
{
	return "STR" + bowedSize.substr(0, 3) + brand.substr(0, 3) + model.substr(0, 3);
}

void Bowed::printData(ostream &out) const
{
	out << "[Classical string]: " << (electric ? "Electric " : "Acoustic ")
		<< instrumentType << endl;
	Instrument::printData(out);
	out << " Size: " << bowedSize << endl;
}
