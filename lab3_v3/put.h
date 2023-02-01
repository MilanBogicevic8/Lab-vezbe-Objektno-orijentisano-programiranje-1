#ifndef _put_h_
#define _put_h_

#include "tacka.h"
#include "lista.h"
#include <iostream>
#include <exception>
using namespace std;

class GVecPostoji:public exception {
public:
	GVecPostoji() :exception("*** Data tacka vec postoji! ***") {}
};
class Put {
	Lista<Tacka*> lista;

public:
	Put() :lista() {}

	Put& operator+=(Tacka& t);


	double duzinaPuta() const;

	
	
	friend ostream& operator<< (ostream& os, const Put& p) {
		for (int i = 1; i <= p.lista.dohvBr(); i++) {
			os << *p.lista[i] << endl;
		}
		return os;
	}

	~Put();
};



#endif