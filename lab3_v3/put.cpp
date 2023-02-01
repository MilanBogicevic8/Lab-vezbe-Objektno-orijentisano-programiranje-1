#include "put.h"


Put& Put::operator+=(Tacka& t) {
	int flag = 0;
	for (int i = 1; i <= lista.dohvBr(); i++) {
		if (*lista[i] == t) {
			flag = 1;
			break;
		}
	}
	if (!flag) {
		lista += new Tacka(t);
		return *this;
	}
	else {
		throw GVecPostoji();
	}
}


double Put::duzinaPuta() const {
	double duzina = 0.0;
	for (int i = 1; i <= lista.dohvBr() - 1; i++) {
		duzina += udaljenost(*lista[i], *lista[i + 1]);
	}
	return duzina;
}

Put::~Put() {
	for (int i = 1; i <= lista.dohvBr(); i++) {
		delete lista[i];
	}
}