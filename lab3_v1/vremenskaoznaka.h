#ifndef _vremenskaoznaka_h_
#define _vremenskaoznaka_h_

#include <iostream>
#include <iomanip>
using namespace std;

class VremenskaOznaka {
	short gg, mm, dd, sat, min;
public:
	VremenskaOznaka(short gg, short mm, short dd, short sat, short min) :gg(gg), mm(mm), dd(dd), sat(sat), min(min) {}


	friend ostream& operator<<(ostream& os, const VremenskaOznaka& vo) {
		os << vo.dd << '.' << vo.mm << '.' << vo.gg << '-' << vo.sat << ":" <<setw(2)<<setfill('0')<< vo.min;
		return os;
	}
};


#endif