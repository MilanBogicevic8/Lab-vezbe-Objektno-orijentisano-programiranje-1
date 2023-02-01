#include "mec.h"



void Mec::odigraj() {
	odigran = 1;
	double vr1 = par.dohvPar1().vrednostTima();
	double vr2 = par.dohvPar2().vrednostTima();
	if (vr1 == vr2) {
		ishod = NERESENO;
		int po1 = poeni.dohvPar1(); poeni.postaviPar1(po1 + 1);
		int po2 = poeni.dohvPar2(); poeni.postaviPar2(po2 + 1);
	}
	else if (vr1 > vr2) {
		int num1 = par.dohvPar1().dohvtrenutniBroj();
		int j = 0;
		int ii = 0;
		while (j != num1) {
			if (par.dohvPar1()[ii] != nullptr) {
				par.dohvPar1()[ii]->promeniVrednost(10);
				j++;
			}
			ii++;
		}

		int num2 = par.dohvPar2().dohvtrenutniBroj();
		j = 0;
		ii = 0;
		while (j != num2) {
			if (par.dohvPar2()[ii] != nullptr) {
				par.dohvPar2()[ii]->promeniVrednost(-10);
				j++;
			}
			ii++;
		}

		ishod = POBEDA_DOMACIN;
		int po1 = poeni.dohvPar1(); poeni.postaviPar1(po1 + 3);
	}
	else {
		int num1 = par.dohvPar1().dohvtrenutniBroj();
		int j = 0;
		int ii = 0;
		while (j != num1) {
			if (par.dohvPar1()[ii] != nullptr) {
				par.dohvPar1()[ii]->promeniVrednost(-10);
				j++;
			}
			ii++;
		}

		int num2 = par.dohvPar2().dohvtrenutniBroj();
		j = 0;
		ii = 0;
		while (j != num2) {
			if (par.dohvPar2()[ii] != nullptr) {
				par.dohvPar2()[ii]->promeniVrednost(10);
				j++;
			}
			ii++;
		}
		ishod = POBEDA_GOST;
		int po2 = poeni.dohvPar2(); poeni.postaviPar2(po2 + 3);
	}

}


ostream& operator<<(ostream& os, const Mec& mec) {
	os << mec.par;
	if (mec.odigranMec()) os << (mec.ishod == Mec::POBEDA_DOMACIN ? "POBEDA_DOMACINA" : mec.ishod == Mec::NERESENO ? "NERESENO" : "POBEDA_GOST");
	return os;
}