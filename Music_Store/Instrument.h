#pragma once
#include <iostream>
#include <string>
using namespace std;

class Instrument
{
protected:
    string instrumentType; // guitar: bass, ukulele, etc; bowed: violin, cello, etc; brass: sax, flute, etc; keyboard: piano, midi, etc.; drumkit: "snare", "tom", etc;
    string brand, model, color;
    float price, weight;
    bool electric; //electric || acoustic

public:
    Instrument();
    Instrument(string instrumentType, bool electric, string brand, string model, string color, float weight, float price);

    // pure virtual functions
    virtual string createWarrantyNumber() const = 0;
    virtual void printData(ostream &out) const;
    //implemented
    virtual float calculateDeliveryCost();

    bool operator<(const Instrument &other) const;
    bool operator==(const Instrument &other) const;

    virtual ~Instrument() = default;

    static unique_ptr<Instrument> createInstrument(string instrumentType, string brand, string model, string color, float weight, float price, bool electric);

    friend ostream &operator<<(ostream &out, const Instrument &inst)
    {
        inst.printData(out);
        return out;
    }

    string getType() const { return instrumentType; }
    string getBrand() const { return brand; }
    string getModel() const { return model; }
    string getColor() const { return color; }

    float getPrice() const { return price; }
    float getWeight() const { return weight; }
    bool isElectric() const { return electric; }
};
