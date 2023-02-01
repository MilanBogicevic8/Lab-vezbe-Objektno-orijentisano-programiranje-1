#ifndef _ptim_h_
#define _ptim_h_

#include "tim.h"
#include <exception>
using namespace std;

class GManjeMin :public exception {
public:
	GManjeMin() :exception("***Greska vrednost manja od minimalne!***") {}
};
class PTim :public Tim {
	int minvr;
public:
	PTim(string naziv, int max, int minvr) :Tim(naziv, max), minvr(minvr) {}
	PTim& prikljuci(int i, const Igrac& igrac);
	void minv(ostream& os) const override { os << "(" << minvr << ")"; }
};


#endif