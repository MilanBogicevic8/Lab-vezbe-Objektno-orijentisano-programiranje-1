#include "lista.h"
#include "tacka.h"
#include "put.h"
#include "obicnovozilo.h"
#include <iostream>
using namespace std;


int main() {
	try {
		/*Lista<int> lista;
		lista += 1;
		lista += 8;
		lista += 6;
		lista += 3;
		cout << lista.dohvBr() << endl;
		cout<< lista[4] << " " << lista[3] << " " << lista[2] << " " << lista[1];
		Lista<int> nova = lista;
		Lista<int> n;
		n = lista;
		cout << endl << n[3]<<" "<<nova[1];*/
		//cout << endl;
		Tacka t1(0, 0);
		Tacka t2(0, 3);
		Tacka t3(4, 0);
		Tacka t4(5,0);
		/*cout << udaljenost(t1, t2);
		cout << t1 << " " << t2;*/
		//<< " " << t1 << endl << t2;
		Put p;
		//cout << endl;
		p += t1;
		p += t2;
		p += t3;
		cout << p.duzinaPuta();
		cout << endl;
		cout << p;
		/*OVozilo ov("BMW");
		cout << ov.cenaPrevoza(p);*/

	}
	catch (const exception& e) {
		cout << e.what();
	}
}