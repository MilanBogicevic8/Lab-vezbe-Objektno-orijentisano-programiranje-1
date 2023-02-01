#ifndef _elektronsakporuka_h_
#define _elektronskaporuka_h_

#include "korisnik.h"
#include <iostream>
#include <string>
using namespace std;

class ElektronskaPoruka {

	string naslov;
	Korisnik* posiljalac;
	Korisnik* primalac;


public:
	enum Stanje { U_PRIPREMI, POSLATA, PRIMLJENA };
	Stanje stanje;
	ElektronskaPoruka(Korisnik* posiljalac, Korisnik* primalac, string naslov) {
		this->stanje = U_PRIPREMI;
		this->naslov = naslov;
		this->posiljalac = posiljalac;
		this->primalac = primalac;
	}

	auto dohvStanje() const { return stanje; }
	string dohvNaslov() const { return this->naslov; }
	Korisnik* dohvPosiljalac() const { return this->posiljalac; }
	Korisnik* dohvPrimalac() const { return this->primalac; }



	virtual void posaljiPoruku() = 0;

	virtual ElektronskaPoruka* kopija() const = 0;

protected:

	virtual void pisi(ostream& os) const{

		os << naslov << endl << *posiljalac << endl << *primalac;
	}


	friend ostream& operator<<(ostream& os, const ElektronskaPoruka& ep) {
		ep.pisi(os); return os;
	}

	virtual ~ElektronskaPoruka() {}
};


#endif