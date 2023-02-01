#ifndef _prodavac_h_
#define _prodavac_h_

#include "lista.h"
#include "rukovalac.h"
#include "artikal.h"
#include <string>
using namespace std;

class Prodavac :public Rukovalac {
public:
	struct Trojka {
		Artikal artikal;
		double marza;
		int daniNabavke;
		Trojka(Artikal a, double mar, int d) :artikal(a), marza(mar), daniNabavke(d) {}
	};
private:
	string naziv;
	Lista<Trojka*> katalog;
public:
	Prodavac(string naziv) :naziv(naziv) {}
	Prodavac& dodajTrojku(const Artikal& a, double mar, int d) {
		katalog += new Trojka(a, mar, d); return *this;
	}
	string dohvNazivProdavca() const { return this->naziv; }
	
	void obradi(Posiljka* p) override;

	~Prodavac() {
		for (int i = 1; i < katalog.dohvBr(); i++) {
			delete katalog[i];
		}
	}


};


#endif
