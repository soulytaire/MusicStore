#include "Instrument.h"

#include "Guitar.h"
#include "Keyboard.h"
#include "Drumkit.h"
#include "Bowed.h"
#include "Brass.h"

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <memory>

using namespace std;
using std::unique_ptr;

// default
Instrument::Instrument()
{
    instrumentType = "generic";
    electric = true;
    brand = "brand";
    model = "model";
    color = "black";
    weight = 2.5;
    price = 100.0;
}

Instrument::Instrument(string instrumentType, bool electric, string brand, string model, string color, float weight, float price)
{
    if (price < 0)
        throw invalid_argument("Instrument price cannot be negative!");

    this->instrumentType = instrumentType;
    this->electric = electric;
    this->brand = brand;
    this->model = model;
    this->color = color;
    this->weight = weight;
    this->price = price;
}

// create instrument based on the instrument type
unique_ptr<Instrument> Instrument::createInstrument(string instrumentType, string brand, string model, string color, float weight, float price, bool electric)
{
    static vector<string> bowedTypes = {"violin", "viola", "cello", "double bass"};
    static vector<string> brassTypes = {"saxophone", "trumpet", "flute", "recorder"};
    static vector<string> guitarTypes = {"guitar", "bass", "ukulele"};
    static vector<string> keyTypes = {"piano", "midi", "synthesizer", "organ"};
    static vector<string> drumTypes = {"snare", "tom", "floor tom", "bass drum", "footpedal",
                                       "cymbal", "hi-hat", "crash", "ride", "drumrack"};

    // write default arguments for the instrument type
    if (find(bowedTypes.begin(), bowedTypes.end(), instrumentType) != bowedTypes.end())
    {
        return make_unique<Bowed>(instrumentType, "4/4", electric, brand, model, color, weight, price);
    }
    else if (find(brassTypes.begin(), brassTypes.end(), instrumentType) != brassTypes.end())
    {
        return make_unique<Brass>(instrumentType, "alto", "C", electric, brand, model, color, weight, price);
    }
    else if (find(guitarTypes.begin(), guitarTypes.end(), instrumentType) != guitarTypes.end())
    {
        return make_unique<Guitar>(instrumentType, 22, 6, true, electric, brand, model, color, weight, price);
    }
    else if (find(keyTypes.begin(), keyTypes.end(), instrumentType) != keyTypes.end())
    {
        return make_unique<Keyboard>(instrumentType, 88, "C1", "C8", 1, electric, brand, model, color, weight, price);
    }
    else if (find(drumTypes.begin(), drumTypes.end(), instrumentType) != drumTypes.end())
    {
        return make_unique<Drumkit>(instrumentType, 10, electric, brand, model, color, weight, price);
    }
    else
    {
        throw invalid_argument("Unknown instrument type: " + instrumentType);
    }
}

// delivery cost on the weight and price
float Instrument::calculateDeliveryCost()
{
    // the delivery is free
    if ((weight <= 5 && price > 250) || price >= 1200)
        return 0;
    // weight: [5,+] and price: [250; 1200], the delivery cost is 50 + 1% of the price
    else if (weight > 5 && (price > 250 && price < 1200))
        return 50 + price * 0.01 * weight;
    // weight: [0;5] and price: [0;250], the delivery cost is 15% of the price
    else if (weight <= 5 && price <= 250)
        return price * 0.15;
    // weight: [0;5] and price: [250;1200], the delivery cost is 50eur
    else
        return 50;
}

// default print of instrument data
void Instrument::printData(ostream &out) const
{
    out << "[" << brand << " " << model << "] " << color
        << ", Price: " << price << " EUR"
        << ", Weight: " << weight << " kg";
}
// comparison of price
bool Instrument::operator<(const Instrument &other) const
{
    return price < other.price;
}
// comparison of brand and model
bool Instrument::operator==(const Instrument &other) const
{
    return brand == other.brand && model == other.model;
}
