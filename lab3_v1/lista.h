#ifndef _lista_h_
#define _lista_h_
#include <iostream>
#include <exception>
using namespace std;


class GNemaTek:public exception {

public:
	GNemaTek() :exception("*** Nema tekuceg elementa! ***") {}
};

template <typename T>
class Lista {

	struct Elem {
		T pod;
		Elem* sled;
		Elem(const T& t, Elem* sled = nullptr) :pod(t), sled(sled) {}
	};

	Elem* prvi, * posl;
	mutable Elem* tek, * pret;

	void premesti(Lista& l) {
		prvi = l.prvi; posl = l.posl; // tek = l.tek; pret = l.pret;
		l.prvi = l.posl = l.tek = l.pret = nullptr;
	}

	void kopiraj(const Lista& l);
	void brisi();

public:
	Lista() {
		prvi = posl = tek = pret = nullptr;
	}
	Lista(const Lista& l) { kopiraj(l); }
	Lista(Lista&& l) { premesti(l); }
	~Lista() { brisi(); }
	Lista& operator=(const Lista& l) {
		if (this != &l) {
			brisi();
			kopiraj(l);
		}
		return *this;
	}

	Lista operator=(Lista&& l) {
		if (this != &l) {
			brisi();
			premesti(l);
		}
		return *this;
	}
	int dohv_br() const;
	Lista& dodaj(const T& t) {
		posl = (prvi ? posl->sled : prvi) = new Elem(t);
		return *this;
	}

	Lista& naPrvi() {
		tek = prvi; pret = nullptr; return *this;
	}

	const Lista& naPrvi() const {
		tek = prvi; pret = nullptr; return *this;
	}

	Lista& naSled() {
		pret = tek;
		if (tek) tek = tek->sled;
		return *this;
	}

	const Lista& naSled() const {
		pret = tek;
		if (tek) tek = tek->sled;
		return *this;
	}

	bool imaTek() const {
		return tek != nullptr;
	}

	T& dohvTek() {
		if (!tek) throw GNemaTek();
		return tek->pod;
	}

};


template <typename T>
int Lista<T>::dohv_br() const {
	Elem* pom = prvi;
	int i = 0;
	while (pom) {
		pom = pom->sled;
		i++;
	}
	return i;
}


template <typename T>
void Lista<T>::kopiraj(const Lista& l) {
	prvi = posl = tek = pret = nullptr;
	for (Elem* pom = l.prvi; pom; pom = pom->sled) {
		Elem* novi = new Elem(pom->pod);
		posl = (!prvi ? prvi : posl->sled) = novi;
		if (pom == l.tek) tek = novi;
		if (pom == l.pret) pret = novi;
	}

}

template <typename T>
void Lista<T>::brisi() {
	while (prvi) {
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
	posl = tek = pret = nullptr;
}

#endif