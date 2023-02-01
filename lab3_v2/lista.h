#ifndef _lista_h_
#define _lista_h_

#include <iostream>
#include <exception>
using namespace std;

class GNemaPodatka :public exception {
public:
	GNemaPodatka() :exception("*** Nema podatka na zadatoj poziciji!***") {}
};

template <typename T>
class Lista {

	struct Elem {
		T pod;
		Elem* sled;
		Elem(T pod, Elem* sled = nullptr) :pod(pod), sled(sled) {}
	};

	Elem* prvi, * posl;
	int br;
	void kopiraj(const Lista& l);
	void brisi();
	void premesti(Lista& l) {
		prvi = l.prvi; posl = l.posl; br = l.dohvBr();
		l.prvi = l.posl = nullptr;
	}

public:

	Lista() { prvi = posl = nullptr; br = 0; }
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
	Lista& operator=(Lista&& l) {
		if (this != &l) {
			brisi();
			premesti(l);
		}
		return *this;
	}


	Lista& operator+=(const T& t) {
		posl = (prvi ? posl->sled : prvi) = new Elem(t); br++;
		return *this;
	}

	int dohvBr() const { return br; }

	T& operator[] (int i);

	const T& operator[](int i) const {
		return const_cast<Lista&>(*this)[i];
	}

};



template <typename T>
void Lista<T>::kopiraj(const Lista& l) {
	prvi = posl = nullptr;
	for (Elem* pom = l.prvi; pom; pom = pom->sled) {
		posl = (prvi ? posl->sled : prvi) = new Elem(pom->pod);
	}
	br = l.dohvBr();
}

template <typename T>
void Lista<T>::brisi() {
	while (prvi) {
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
	posl = nullptr; br = 0;
}

template <typename T>
T& Lista<T>::operator[] (int i) {
	int j = 1;
	Elem* pom = prvi;
	if (i <= 0 || i > br) throw GNemaPodatka();
	while (j < i) {
		pom = pom->sled;
		j++;
	}
	return pom->pod;
}


#endif