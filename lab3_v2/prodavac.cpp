#include "prodavac.h"
#include "posiljka.h"



void Prodavac::obradi(Posiljka* p){
	for (int i = 1; i <= katalog.dohvBr(); i++) {
		if (p->dohvArtikal() == (*katalog[i]).artikal) {
			p->agr.daniCekanja += (*katalog[i]).daniNabavke;
			p->agr.cenaPosiljke += p->artikal.dohvCena() * (*katalog[i]).marza;
		}
	}
}