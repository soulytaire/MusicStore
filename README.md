![scheme](https://github.com/user-attachments/assets/587dfc19-dfd6-4d16-9357-f802a64e6a94)

Musical instrument store.
It supports various instrument types (guitars, keyboards, drums, bowed, and brass instruments), allowing you to:

- Create and manage a catalog of instruments

- Calculate delivery costs

- Create warranty numbers

- Save/load instruments from a file

- Sort(by ascending price) and display instrument data


Instrument (Abstract)
Common base class for all instruments.

instrumentType	string	Instrument type (e.g. "guitar")
brand | string | Brand name
model | string | Model name
color | string | Color
weight | float |	Weight in kilograms
price	| float |	Price in EUR
electric | bool | Electric or acoustic

Method:

createWarrantyNumber() — generates unique warranty info (pure virtual)

calculateDeliveryCost() — computes delivery fee based on weight and price

printData(ostream&) — outputs instrument info

createInstrument() — factory method for constructing derived objects


Instruments are saved to a file 'instruments.txt' in this format:
Warranty number
Delivery cost
Instrument details:
type brand model color weight price isElectric
