#ifndef _korisnik_h_
#define _korisnik_h_

#include <iostream>
#include <string>
using namespace std;

class Korisnik {
	string ime;
	string adresa;

public:

	Korisnik(string ime, string adresa) :ime(ime), adresa(adresa) {}
	string dohvIme() const { return this->ime; }
	string dohvAdresu() const { return this->adresa; }

	Korisnik(const Korisnik& k) = delete;
	Korisnik& operator=(const Korisnik& k) = delete;

protected:
	void pisi(ostream& os) const {
		os << '(' << ime << ')' << adresa;
	}

	friend ostream& operator<<(ostream& os, const Korisnik& k) {
		k.pisi(os); return os;
	}

};



#endif