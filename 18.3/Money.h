#pragma once
#include <iostream>
using namespace std;

class Money
{
	long ryb;
	int cop;
public:
	Money() { ryb = 0; cop = 0; };
	Money(long r, int c) { ryb = r; cop = c; }
	Money(const Money& t) { ryb = t.ryb; cop = t.cop; }
	~Money() {};
	int get_ryb() { return ryb; }
	int get_cop() { return cop; }
	void set_ryb(int r) { ryb = r; }
	void set_cop(int c) { cop = c; }
	Money& operator=(const Money&);
	Money& operator--();
	Money operator--(int);
	bool operator==(const Money&);
	friend istream& operator>>(istream& in, Money& t);
	friend ostream& operator<<(ostream& out, const Money& t);
};