#ifndef _obicnovozilo_h_
#define _obicnovozilo_h_

#include "vozilo.h"
#include <string>
using namespace std;

class OVozilo : public Vozilo {
	const double SCENA = 120.0;
public:
	OVozilo(string naziv) :Vozilo(naziv) {}
	double startnaCena() const override { return SCENA; }


};



#endif