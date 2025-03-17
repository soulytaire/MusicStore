#include "Instrument.h"

#include "Guitar.h"
#include "Keyboard.h"
#include "Drumkit.h"
#include "Bowed.h"
#include "Brass.h"

#include <iostream>
#include <string>
//#include <map>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;


Instrument::Instrument() {
    instrumentType = "generic";
    electric = true;
    brand = "brand";
    model = "model";
    color = "black";
    weight = 2.5;
    price = 100.0;
}

Instrument::Instrument(string instrumentType, bool electric, string brand, string model, string color, float weight, float price) {
    this->instrumentType = instrumentType;
    this->electric = electric;
    this->brand = brand;
    this->model = model;
    this->color = color;
    this->weight = weight;
    this->price = price;
}

Instrument* Instrument::createInstrument(string instrumentType, string brand, string model, string color, float weight, float price, bool electric) {
    static vector<string> bowedTypes = { "violin", "viola", "cello", "double bass" };
    static vector<string> brassTypes = { "saxophone", "trumpet", "flute", "recorder" };
    static vector<string> guitarTypes = { "guitar", "bass", "ukulele" };
    static vector<string> keyTypes = { "piano", "midi", "synthesizer", "organ" };
    static vector<string> drumTypes = { "snare", "tom", "floor tom", "bass drum", "footpedal", 
                                            "cymbal", "hi-hat","crash","ride", "drumrack" };

    if (find(bowedTypes.begin(), bowedTypes.end(), instrumentType) != bowedTypes.end()) {
        return new Bowed(instrumentType, "4/4", electric, brand, model, color, weight, price);
    }
    else if (find(brassTypes.begin(), brassTypes.end(), instrumentType) != brassTypes.end()) {
        return new Brass(instrumentType, "alto", "C", electric, brand, model, color, weight, price);
    }
    else if (find(guitarTypes.begin(), guitarTypes.end(), instrumentType) != guitarTypes.end()) {
        return new Guitar(instrumentType, 22, 6, true, electric, brand, model, color, weight, price);
    }
    else if (find(keyTypes.begin(), keyTypes.end(), instrumentType) != keyTypes.end()) {
        return new Keyboard(instrumentType, 88, "C1", "C8", 1, electric, brand, model, color, weight, price);
    }
    else if (find(drumTypes.begin(), drumTypes.end(), instrumentType) != drumTypes.end()) {
        return new Drumkit(instrumentType, 10, electric, brand, model, color, weight, price);
    }
    else {
        throw invalid_argument("Unknown instrument type: " + instrumentType);
    }
}




float Instrument::calculateDeliveryCost() {
    int diff = round(weight) - 5;

    if (diff <= 0 && price > 250.0) return 0.0;
    else if (price <= 250.0) return price * 0.15;

    else return 50 + price * 0.01 * diff; // Ensures a return value in all cases
}

   

void Instrument::printData(ostream& out) const{
    out << "[" << brand << " " << model << "] " << color
        << ", Price: " << price << " EUR"
        << ", Weight: " << weight << " kg";
}

bool Instrument::operator<(const Instrument& other) const {
    return price < other.price;
}

bool Instrument::operator==(const Instrument& other) const {
    return brand == other.brand && model == other.model;
}

