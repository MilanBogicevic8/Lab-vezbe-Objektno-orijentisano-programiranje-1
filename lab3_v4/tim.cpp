#include "tim.h"



void Tim::kopiraj(const Tim& tim) {
	naziv = tim.naziv; max = tim.max; br = tim.br;
	niz = new Igrac * [max];
	for (int i = 0; i < tim.max; i++) {
		niz[i] = tim.niz[i]!=nullptr ? new Igrac(*tim.niz[i]) : nullptr;
	}
}


void Tim::brisi() {
	for (int i = 0; i < max; i++) {
			delete niz[i];
	}
	delete [] niz;
	niz = nullptr;
}


double Tim::vrednostTima() const {
	double vr = 0;
	for (int i = 0; i < max; i++) {
		if (niz[i] != nullptr) {
			vr += niz[i]->dohvVrednost();
		}
	}

	return br ? vr / br : 0;
}



bool operator==(const Tim& t1, const Tim& t2) {
	if (t1.max != t2.max) return false;
	for (int i = 0; i < t1.max; i++) {
		if (t1.niz[i] != nullptr) {
			if (t2.niz[i] != nullptr) {
				if (!(*t1.niz[i] == *t2.niz[i])) {
					return false;
				}
			}
			else {
				return false;
			}
		}
	}
	return t1.naziv == t2.naziv;
}

ostream& operator<<(ostream& os, const Tim& tim) {
	int j = 0;
	os << tim.naziv;
	tim.minv(os);
	os<<"[";
	for (int i = 0; i < tim.max; i++) {
		if (tim.niz[i] != nullptr) {
			os << *tim.niz[i];
			if (j != tim.br-1) {
				os << ",";
			}
			j++;
		}

	}
	return os << "]";
}