#ifndef _vozilo_h_
#define _vozilo_h_

#include <string>
#include "put.h"
#include <iostream>
using namespace std;



class Vozilo {
	string model;
public:
	Vozilo(string naziv) :model(naziv) {}

	virtual double startnaCena() const = 0;

	double cenaPrevoza(const Put& put) const {
		return startnaCena() + 0.1 * put.duzinaPuta();
	}

protected:

	virtual void pisi(ostream& os) const {
		os << model;
	}

	friend ostream& operator<<(ostream& os, const Vozilo& v) {
		v.pisi(os);
		return os;
	}

};



#endif