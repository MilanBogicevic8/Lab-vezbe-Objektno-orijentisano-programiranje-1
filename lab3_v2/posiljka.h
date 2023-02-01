#ifndef _posiljka_h_
#define _posiljka_h_

#include "lista.h"
#include "artikal.h"
#include <exception>
using namespace std;


class GNeizracunato :public exception {
public:
	GNeizracunato() :exception("*** Nisu izracunati podaci od strane rukovalaca!***") {}
};

class GVecIzracunato :public exception {
public:
	GVecIzracunato() :exception("*** Greska podaci su vec izracunati!***") {}

};

class Rukovalac;

class Posiljka {
	struct Agregat {
		int daniCekanja=0;
		double cenaPosiljke=0;
	};

	Artikal artikal;
	static int ID;
	int ident{ ++ID };
	Lista<Rukovalac*> lista;
	Agregat agr;
	bool izracunato = false;

public:
	friend class Prodavac;

	Posiljka(const Posiljka& p) :artikal(p.artikal), agr(p.agr), izracunato(p.izracunato),lista(p.lista) {  }

	Posiljka& operator=(const Posiljka& p) {
		artikal = p.artikal;
		agr = p.agr;
		lista = p.lista;
		return *this;
	}

	Posiljka(const Artikal& a) :artikal(a) {}

	Posiljka& operator+=(Rukovalac* r);

	void izracunajDetalje();

	Artikal dohvArtikal() const {
		return artikal;
	}

	int dohvIdentifikator() const {
		return ident;
	}

	Agregat dohvAgregat() const {
		if (!izracunato) throw GNeizracunato();
		return agr;
	}

	friend ostream& operator<<(ostream& os, const Posiljka& p) {
		return os << "Posiljka[" << p.ident << "," << p.dohvArtikal().dohvNaziv() << "]";
	}

};





#endif