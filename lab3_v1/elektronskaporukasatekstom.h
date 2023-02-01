#ifndef _elektronskaporukasatekstom_h_
#define _elektronskaporukasatekstom_h_


#include "elektronskaporuka.h"
#include <iostream>
#include <string>
#include <exception>
using namespace std;

class GPoslata:public exception {
public:
	GPoslata() :exception("*** Pokusano menajanje poslate poruke!***") {}
};


class EpTekst :public ElektronskaPoruka {

	string tekst;

public:

	EpTekst(Korisnik* posiljalac, Korisnik* primalac, string naslov) :ElektronskaPoruka(posiljalac, primalac, naslov) {}

	EpTekst& postaviTekst(const string& st) {
		if (stanje == POSLATA) throw GPoslata();
		tekst = st;
		return *this;
	}

	void posaljiPoruku() override {
		stanje = POSLATA;
	}

	virtual EpTekst* kopija() const override { return new EpTekst(*this); }


	void pisi(ostream& os) const override {
		ElektronskaPoruka::pisi(os);
		os << endl << tekst;
	}
	friend ostream& operator<<(ostream& os, const EpTekst& ep) {
		ep.pisi(os);
		return os;
	}

};



#endif