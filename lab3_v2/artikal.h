#ifndef _artikal_h_
#define _artikal_h_

#include <string>
using namespace std;


class Artikal {

	string naziv;
	int barkod;
	double cena;

public:

	Artikal(string naziv, int barkod, double cena) :naziv(naziv), barkod(barkod), cena(cena) {}

	string dohvNaziv() const { return this->naziv; }
	int dohvBarkod() const { return this->barkod; }
	double dohvCena() const { return this->cena; }

	friend bool operator==(const Artikal& a1, const Artikal& a2) {
		return a1.dohvBarkod() == a2.dohvBarkod();
	}


};


#endif