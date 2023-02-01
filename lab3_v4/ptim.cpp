#include "ptim.h"


PTim& PTim::prikljuci(int i, const Igrac& igrac) {
	if (igrac.dohvVrednost() < minvr) throw GManjeMin();
	if (i >= 0 && i < max && niz[i] == nullptr) {
		niz[i] = new Igrac(igrac); br++;
	}
	return *this;
}