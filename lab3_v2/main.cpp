#include "lista.h"
#include "artikal.h"
#include "posiljka.h"
#include "prodavac.h"

int main() {


	try {
		/*Lista<int> li;
		li += 1;
		li += 2;
		li += 3;
		Lista<int> lista = li;
		for (int i = 1; i <= lista.dohvBr(); i++) {
			cout << lista[i];
		}
		Artikal a1("cokolada", 123, 100);
		Posiljka posiljka(a1);*/
		Artikal a1("cokolada", 123, 100);
		Artikal a2("mleko", 124, 100);
		Posiljka p1(a1);
		Posiljka p2(a2);
		Prodavac prodavac("Milan");
		prodavac.dodajTrojku(a1, 1.1, 10);
		prodavac.dodajTrojku(a2, 1.2, 15);
		p1 += new Prodavac(prodavac);
		p1.izracunajDetalje();
		cout << p1 << " " << p1.dohvAgregat().cenaPosiljke <<" "<< p1.dohvAgregat().daniCekanja;
		cout << endl;
		/*p2 += new Prodavac(prodavac);
		p2.izracunajDetalje();
		cout << p2 << " " << p2.dohvAgregat().cenaPosiljke << " " << p2.dohvAgregat().daniCekanja;
		cout << endl;
		p2 = p1;
		cout << p2 << " " << p2.dohvAgregat().cenaPosiljke << " " << p2.dohvAgregat().daniCekanja;*/

	}
	catch (const exception& e) {
		cout << e.what();
	}

}