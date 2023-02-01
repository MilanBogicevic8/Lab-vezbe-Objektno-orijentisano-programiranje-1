#include "korisnik.h"
#include "vremenskaoznaka.h"
#include "elektronskaporukasatekstom.h"
#include "lista.h"

int main() {

	/*Korisnik k("milan", "@miki");
	cout << k << endl << k.dohvAdresu() << " " << k.dohvIme();

	VremenskaOznaka v(2022,1,3, 8, 41);
	cout << endl;
	cout << v;
	cout << endl;*/

	try {
		//Korisnik milan("milan", "@milan");
		//Korisnik nikola("nikola", "@nikola");
		//EpTekst ep(&milan, &nikola, "Poruka");
		//ep.postaviTekst("Dragi Nikola,uci!");
		//cout << ep;
		////ep.posaljiPoruku();
		//ep.postaviTekst("Ipak nemoj.");
		//cout <<endl<< ep;
		//cout << *ep.kopija();

		//ospitivanje funkcionalnosti liste
		/*Lista<int> p;
		cout << p.dohv_br();
		p.dodaj(1);
		p.dodaj(2);
		Lista<int> lista = p;
		p = lista;
		lista = p;
		for (lista.naPrvi(); lista.imaTek(); lista.naSled()) {
			cout << endl;
			cout << (lista.dohvTek());
		}*/

		Korisnik milan("milan", "@milan");
		Korisnik nikola("nikola", "@nikola");
		EpTekst ep(&milan, &nikola, "Poruka od Milana");
		ep.postaviTekst("Zdravo.");
		ep.posaljiPoruku();
		cout << ep;


		//ispitivanje klasa EpTekst i ElektronskaPoruka
		//cout << milan;
		//cout << endl;
		//VremenskaOznaka v(2022, 1, 9, 22, 00);
		//cout << v;
		//EpTekst ep(&milan, &nikola, "Poruka za Nikolu");
		//ep.postaviTekst("Dragi Nikola,Srecna Nova godina:)");
		//
		//cout << ep.dohvStanje();
		//cout << endl << endl;
		//ep.posaljiPoruku();
		//cout << ep << ep.dohvStanje();
		//cout << endl << endl << endl;
		////cout << *ep.dohvPrimalac();
		//cout << *ep.kopija();


		//cout << "-----------------------------" << endl;
		//Lista<ElektronskaPoruka*> lista;
		//lista.dodaj(ep.kopija());
		//cout << *lista.naPrvi().dohvTek();
		//
	}
	catch (const exception& e) {
		cout << e.what();
	}


}