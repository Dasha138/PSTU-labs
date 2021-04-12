#include "Money.h" 
#include <iostream> 
using namespace std;
Money& Money::operator=(const Money& t)
{
	if (&t == this) return *this;
	ryb = t.ryb;
	cop = t.cop;
	return *this;
}
Money& Money::operator--()
{
	long temp = ryb * 100 + cop;
	temp--;
	ryb = temp / 100;
	cop = temp % 100;
	return *this;
}
Money Money::operator --(int)
{
	long temp = ryb * 100 + cop;
	temp--;
	Money t(ryb, cop);
	ryb = temp / 100;
	cop = temp % 100;
	return t;
}
bool Money::operator==(const Money& t)
{
	int temp1 = ryb * 100 + cop;
	int temp2 = t.ryb * 100 + t.cop;
	bool p = 0;
	if (temp1 == temp2)
	{
		p = 1;
	}
	return p;
}
istream& operator>>(istream& in, Money& t)
{
	cout << "Сколько рублей? "; in >> t.ryb;
	cout << "Сколько копеек? "; in >> t.cop;
	return in;
}
ostream& operator<<(ostream& out, const Money& t)
{
	return (out << t.ryb << " , " << t.cop);
}