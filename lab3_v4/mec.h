#ifndef _mec_h_
#define _mec_h_

#include "par.h"
#include "tim.h"
#include <exception>
using namespace std;

class GNeodigranMec:public exception {
public:
	GNeodigranMec() :exception("*** Greska mec nije odigran!***") {}
};




class Mec {
public:
	enum Ishod { POBEDA_DOMACIN = 1, NERESENO, POBEDA_GOST };
private:
	Par<Tim> par;
	Ishod ishod;
	int odigran;
	Par<int> poeni;

public:
	

	Mec(const Tim& t1, const Tim& t2) {
		
		par.postaviPar1(t1);
		par.postaviPar2(t2);
		poeni.postaviPar1(0);
		poeni.postaviPar2(0);
		odigran = 0;
	}

	const Par<Tim>& dohvatiPar() const { return par; }

	void odigraj();

	bool odigranMec() const { return odigran ? true : false; }

	const Par<int>& dohvishodMeca() const{
		if (!odigran) throw GNeodigranMec();
		return poeni;
	}

	friend ostream& operator<<(ostream& os, const Mec& mec);
};

#endif