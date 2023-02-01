#ifndef _rukovalac_h_
#define _rukovalac_h_

#include "artikal.h"
#include "posiljka.h"

class Rukovalac {
public:


	virtual void obradi(Posiljka* p) = 0;
	virtual ~Rukovalac() {}
};

#endif