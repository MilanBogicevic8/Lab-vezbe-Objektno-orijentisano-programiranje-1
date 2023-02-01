#ifndef _par_h_
#define _par_h_

#include <iostream>
using namespace std;

template <typename T>
class Par {
	T* p1;
	T* p2;
	void kopiraj(const Par<T>& p) {
		p1 = new T(*p.p1);
		p2 = new T(*p.p2);
	}
	void premesti(Par<T>& p) {
		p1 = p.p1;
		p2 = p.p2;
		p.p1 = p.p2 = nullptr;
	}
	void brisi() {
		delete p1;
		delete p2;
	}
public:
	Par() = default;
	Par(const Par& p) { kopiraj(p); }
	Par(Par&& p) { premesti(p); }
	~Par() { brisi(); }

	Par<T>& operator=(const Par<T>& p) {
		if (this != &p) {
			brisi();
			kopiraj(p);
		}
		return *this;
	}

	Par<T>& operator=(Par<T>&& p) {
		if (this != &p) {
			brisi();
			premesti(p);
		}
		return *this;
	}


	

	T& dohvPar1() { return *p1; }
	const T& dohvPar1() const { return *p1; }
	T& dohvPar2() { return *p2; }
	const T& dohvPar2() const { return *p2; }
	
	void postaviPar1(const T& p) { p1 = new T(p); }
	void postaviPar2(const T& p) { p2 = new T(p); }
	friend bool operator==(const Par& t1, const Par& t2) {return (t1.p1!=nullptr && t2.p1!=nullptr && t1.p2!=nullptr && t2.p2!=nullptr)?*t1.p1 == *t2.p1 && *t1.p2==*t2.p2:false;}


	void pisi(ostream& os) const {
		os << "[";
		if (p1) { os << *p1; }
		else { os << "nullptr"; } os << ",";
		if (p2 != nullptr) { os << *p2; }
		else { os << "nullptr"; }
		os << "]";
	}


	friend ostream& operator<<(ostream& os, const Par& par) {
		par.pisi(os);
		return os;
	}
	
};


#endif