#ifndef _tacka_h_
#define _tacka_h_

#include <iostream>
#include <cmath>
using namespace std;

class Tacka {
	int x, y;
public:
	Tacka(int x, int y) :x(x), y(y) {}

	friend double udaljenost(const Tacka& t1,const Tacka& t2) {
		return sqrt(pow((t2.x - t1.x), 2) + pow((t2.y - t1.y), 2));
	}

	friend bool operator==(const Tacka& t1, const Tacka& t2) {
		return t1.x == t2.x && t1.y == t2.y;
	}

	friend ostream& operator<<(ostream& os, const Tacka& t) {
		return os << "(" << t.x << "," << t.y << ")";
	}
};




#endif