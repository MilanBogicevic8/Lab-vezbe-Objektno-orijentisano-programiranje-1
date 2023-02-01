#ifndef _igrac_h_
#define _igrac_h_

#include <string>
#include <iostream>
using namespace std;

class Igrac {
	string ime;
	int vrednost;
public:
	Igrac(string ime, int vrednost = 1000) :ime(ime), vrednost(vrednost) {}
	int dohvVrednost() const {return this->vrednost; }
	int promeniVrednost(double procenat) { return vrednost = (int)((100 + procenat)/100 * vrednost); }
	friend bool operator==(const Igrac& i1, const Igrac& i2) {
		return i1.ime == i2.ime && i1.vrednost == i2.vrednost;
	}
	friend ostream& operator<<(ostream& os, const Igrac& i) {
		return os << i.ime << "#" << i.vrednost;
	}

};

#endif