#include <iostream>
#include <vector>
#include <fstream>

#include <algorithm>
#include <memory>

#include "Guitar.h"
#include "Keyboard.h"
#include "Drumkit.h"
#include "Bowed.h"
#include "Brass.h"
#include "Instrument.h"
using namespace std;

int main()
{

	// dynamically allocate
	vector<unique_ptr<Instrument>> store;

	// add instruments to store
	store.push_back(make_unique<Bowed>("violin", "3/4", false, "Yamaha", "V5", "Brown", 1.2, 350));
	store.push_back(make_unique<Keyboard>());
	store.push_back(make_unique<Guitar>("bass", 22, 4, true, true, "Yamaha", "TRBX-40", "White", 5.4, 550));

	// sort by price in ascending order
	sort(store.begin(), store.end(), [](const unique_ptr<Instrument> &a, const unique_ptr<Instrument> &b)
		 { return a->getPrice() < b->getPrice(); });
	// print store
	for_each(store.begin(), store.end(), [](const unique_ptr<Instrument> &instrument)
			 { instrument->printData(cout); });

	// save data of inst to file
	ofstream outFile("c:\\temp\\instruments.txt");
	for_each(store.begin(), store.end(), [&outFile](const unique_ptr<Instrument> &instrument)
			 {
		outFile << instrument->createWarrantyNumber() << endl;
		outFile << instrument->calculateDeliveryCost() << endl; });

	for (const auto &instrument : store)
	{
		outFile << instrument->getType() << " "
				<< instrument->getBrand() << " "
				<< instrument->getModel() << " "
				<< instrument->getColor() << " "
				<< instrument->getWeight() << " "
				<< instrument->getPrice() << " "
				<< (instrument->isElectric() ? "1" : "0") << endl;
	}
	outFile.close();

	// load from file
	ifstream inFile("c:\\temp\\instruments.txt");
	string warrantyNumber;
	string deliveryCost;

	while (getline(inFile, warrantyNumber) && getline(inFile, deliveryCost))
	{
		cout << "Loaded warranty number: " << warrantyNumber << endl;
		cout << "Loaded delivery cost: " << deliveryCost << endl;
	}
	inFile.ignore(numeric_limits<streamsize>::max(), '\n'); // skip empty lines

	// reconstruct instruments from file data
	string type, brand, model, color;
	float weight, price;
	int electricInt;
	bool electric;
	while (inFile >> type >> brand >> model >> color >> weight >> price >> electricInt)
	{
		electric = static_cast<bool>(electricInt);
		try
		{
			store.push_back(Instrument::createInstrument(type, brand, model, color, weight, price, electric));
		}
		catch (const exception &err)
		{
			cout << "Error with loading instruments: " << err.what() << endl;
		}
	}
	inFile.close();

	return 0;
}