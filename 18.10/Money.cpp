#include "Money.h"
Money::Money()
{
	ryb = 0;
	cop = 0;
}
Money::Money(int R, int C)
{
	ryb = R;
	cop = C;
}
Money::Money(const Money& p)
{
	ryb = p.ryb;
	cop = p.cop;
}
Money Money::operator =(const Money& p)
{
	if (&p == this) return *this;
	ryb = p.ryb;
	cop = p.cop;
	return*this;
}
Money::~Money()
{
}

ostream& operator<<(ostream& out, const Money& p)
{
	out << "Рубли: " << p.ryb << " Копейки: " << p.cop << "\n";
	return out;
}

istream& operator>>(istream& in, Money& p)
{
	cout << "Рубли? "; in >> p.ryb;
	cout << "Копейки? "; in >> p.cop;
	return in;
}

fstream& operator>>(fstream& fin, Money& p)
{
	fin >> p.ryb;
	fin >> p.cop;
	return fin;
}

fstream& operator<<(fstream& fout, const Money& p)
{
	fout << p.ryb << "\n" << p.cop << "\n";
	return fout;
}
