#ifndef _tim_h_
#define _tim_h_

#include "igrac.h"
#include <string>
using namespace std;

class Tim {
protected:
	string naziv;
	int max;
	Igrac** niz;
	int br;

	void kopiraj(const Tim& tim);

	void premesti(Tim& tim) {
		naziv = tim.naziv; max = tim.max; br = tim.br;
		niz = tim.niz; tim.niz = nullptr;
	}

	void brisi();

public:
	
	Tim(string naziv, int max) :naziv(naziv), max(max),niz(new Igrac* [max]),br(0) {
		for (int i = 0; i < max; i++) niz[i] = nullptr;
	}

	Tim(const Tim& t) { kopiraj(t); }
	Tim(Tim&& t) { premesti(t); }
	virtual ~Tim() { brisi(); }

	Tim& operator=(const Tim& t) {
		if (this != &t) {
			brisi(); kopiraj(t);
		}
		return *this;
	}

	Tim& operator=(Tim&& t) {
		if (this != &t) {
			brisi(); premesti(t);
		}
		return *this;
	}

	Tim& prikljuci(int i,const Igrac& igrac) {
		if (i >= 0 && i < max && niz[i] == nullptr) {
			niz[i] = new Igrac(igrac); br++;
		}
		return *this;
	}

	Igrac* operator[](int i) {
		if (niz[i]) {
			return niz[i];
		}
		return nullptr;
	}

	const Igrac* operator[](int i) const {
		if (niz[i]) {
			return niz[i];
		}
		return nullptr;
	}
	int dohvtrenutniBroj() const { return br; }
	virtual void minv(ostream& os) const {}

	double vrednostTima() const;

	friend bool operator==(const Tim& t1, const Tim& t2);

	friend ostream& operator<<(ostream& os, const Tim& tim);



};


#endif