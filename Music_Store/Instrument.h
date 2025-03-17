#pragma once
#include <iostream>
#include <string>
using namespace std;

class Instrument {
protected:
    string instrumentType;  // New field for all instrument categories
    string brand, model, color;
    float price, weight;
    bool electric;


public:
    Instrument();
    Instrument(string instrumentType, bool electric, string brand, string model, string color, float weight, float price);
        
    virtual string createWarrantyNumber() const = 0;  // Must be implemented by subclasses
    virtual float calculateDeliveryCost();
    virtual void printData(ostream& out) const = 0;  // Allow subclasses to override

    // Common operators for all instruments
    bool operator<(const Instrument& other) const;
    bool operator==(const Instrument& other) const;


    virtual ~Instrument() = default;  // Proper virtual destructor


    static Instrument* createInstrument(string instrumentType, string brand, string model, string color, float weight, float price, bool electric);



    friend ostream& operator<<(ostream& out, const Instrument& inst) {
        inst.printData(out);
        return out;
    }

};
