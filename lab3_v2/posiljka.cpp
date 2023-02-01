#include "posiljka.h"
#include "rukovalac.h"


int Posiljka::ID = 0;


void Posiljka::izracunajDetalje() {
	izracunato = true;
	for (int i = 1; i <= lista.dohvBr(); i++) {
		lista[i]->obradi(this);
	}
}

Posiljka& Posiljka:: operator+=(Rukovalac* r) {
	if (izracunato) throw GVecIzracunato();
	lista += r;
	return *this;
}