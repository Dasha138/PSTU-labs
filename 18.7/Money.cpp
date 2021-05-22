#include "Money.h"
Money::Money(void)
{
	ryb = cop = 0;
}
Money::Money(int R, int C)
{
	ryb = R; cop = C;
}
Money::Money(const Money& t)
{
	ryb = t.ryb; cop = t.cop;
}
Money& Money::operator =(const Money& t)
{
	ryb = t.ryb; cop = t.cop; return*this;
}
ostream& operator<<(ostream& out, const Money& t)
{

	out << t.ryb << " . " << t.cop << " ; "; return out;
}
istream& operator>>(istream& in, Money& t)
{
	cout << "\nryb?"; in >> t.ryb;
	cout << "\ncop?"; in >> t.cop;
	return in;
}
Money Money::operator -(Money k)
{
	int t = ryb * 100 + cop;
	int kt = k.ryb * 100 + k.cop;
	t -= kt;
	Money temp(t / 100, t % 100);
	return temp;
}