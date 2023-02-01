#ifndef _lista_h_
#define _lista_h_

#include <exception>
using namespace std;

class GNemaPod: public exception {
public:
	GNemaPod() :exception("*** Nema podatka na zadatoj poziciji!***") {}
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
	//mutable Elem* tek,*pret;

	void premesti(Lista& l) {
		prvi = l.prvi; posl = l.posl; br = l.br;
		l.prvi = l.posl = nullptr;
	}
	void kopiraj(const Lista& l);
	void brisi();

public:
	Lista() {
		prvi = posl = nullptr;
		br = 0;
	}

	Lista(const Lista& l) { kopiraj(l); }
	Lista(Lista&& l) { premesti(l); }
	~Lista() { brisi(); }
	Lista& operator=(const Lista& l) {
		if (this != &l) {
			brisi(); kopiraj(l);
		}
		return *this;
	}
	Lista& operator=(Lista&& l) {
		if (this != &l) {
			brisi(); premesti();
		}
		return *this;
	}

	Lista& operator+=(const T& pod) {
		posl = (prvi ? posl->sled : prvi) = new Elem(pod);
		br++;
		return *this;
	}

	int dohvBr() const { return this->br; }

	T& operator[](int i);
	const T& operator[](int i) const {
		return const_cast<Lista&>(*this)[i];
	}
};


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
void Lista<T>::kopiraj(const Lista& l){
	prvi = posl = nullptr;
	for (Elem* pom = l.prvi; pom; pom = pom->sled) {
		posl = (prvi?posl->sled : prvi) = new Elem(pom->pod);
	}
	br = l.br;
}

template<typename T>
T& Lista<T>::operator[](int i){
	if (i <= 0 || i > br) throw GNemaPod();
	int j = 1;
	Elem* pom = prvi;
	while (j < i) {
		pom = pom->sled;
		j++;
	}
	return pom->pod;
}


#endif