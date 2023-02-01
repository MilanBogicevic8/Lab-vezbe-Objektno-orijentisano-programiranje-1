#include "igrac.h"
#include "tim.h"
#include "ptim.h"
#include "par.h"
#include "mec.h"

int main() {
	try {
		//Igrac i1("Milan", 1000);
		//Igrac i2("Nikola", 900);
		///*cout << i;
		//cout << endl;
		//i.promeniVrednost(100);
		//cout << i;*/

		//Tim t("juventus", 10);
		//t.prikljuci(0, i2);
		//t.prikljuci(8, i1);
		//Tim t2("milano", 10);
		////t2.prikljuci(5, i1);
		////t2 = t;
		//t2 = t;
		//t2.prikljuci(3, i1);
		//t2.prikljuci(4, i2);
		//Ptim p("ajaks", 10, 899);
		//p.prikljuci(0, i1);
		//cout << p;
		////cout <<endl<< t2 << t2.br << " " << &t2 << endl << t << t.br << " " << &t;
		//Tim* ti = &t;
		//cout << endl << *ti;
		////cout << (t == t2);
		//Par<int> p;
		//Mec m;


		Igrac i1("Milan", 900);
		Igrac i2("Nikola", 895);
		Igrac i3("Nemanja", 950);
		Igrac i4("Nigor");
		Tim t1("Juventus", 10);
		Tim t2("Ajaks", 15);
		PTim t3("Olimpijakos", 20,890);

		t1.prikljuci(0, i1);
		t1.prikljuci(1, i2);
		t1.prikljuci(8, i3);
		t1.prikljuci(9, i4);

		t2.prikljuci(4, i1);
		t2.prikljuci(8, i4);

		t3.prikljuci(0, i2);
		
		cout << t1 << " " << t1.vrednostTima() << endl << t2 << " " << t2.vrednostTima() << endl << t3 << " " << t3.vrednostTima() << endl;
		Mec m1(t1, t2);
		Mec m2(t1, t3);
		t2 = t3;
		Mec m3(t2, t3);
		//cout << endl << "-------------------";
		m1.odigraj();
		cout << m1.dohvishodMeca() << endl << m1;
		cout << endl;
		//cout << t1 << " " << t1.vrednostTima() << endl << t2 << " " << t2.vrednostTima() << endl << t3 << " " << t3.vrednostTima() << endl;
		m2.odigraj();
		cout << m2.dohvishodMeca() << endl << m2;
		cout << endl;
		m3.odigraj();
		cout << m3.dohvishodMeca() << endl << m3;
		cout << endl;
		/*m1 = m2;
		cout << (m1.dohvatiPar() == m2.dohvatiPar());*/

	}
	catch(const exception& e){
		cout << e.what();
	}
	
}