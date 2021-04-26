#include "TRIAD.h"

TRIAD::TRIAD(void)
{
	first = 0;
	second = 0;
	third = 0;
}

TRIAD::~TRIAD(void)
{
}

TRIAD::TRIAD(int First, int Second, int Third)
{
	first = First;
	second = Second;
	third = Third;
}

TRIAD::TRIAD(const TRIAD& triad)
{
	first = triad.first;
	second = triad.second;
	third = triad.third;
}

void TRIAD::Show() {
	cout << endl << "First: " << first;
	cout << endl << "Second: " << second;
	cout << endl << "Third: " << third;
	cout << endl;
}

void TRIAD::set_first(int Num)
{
	first = Num;
}

void TRIAD::set_second(int Num)
{
	second = Num;
}

void TRIAD::set_third(int Num)
{
	third = Num;
}

TRIAD& TRIAD::operator=(const TRIAD& t)
{
	if (&t == this)return *this;
	first = t.first;
	second = t.second;
	third = t.third;
	return *this;
}

istream& operator>>(istream& in, TRIAD& t)
{
	cout << "First: "; in >> t.first;
	cout << "Second: "; in >> t.second;
	cout << "Third: "; in >> t.third;
	return in;
}

ostream& operator<<(ostream& out, const TRIAD& t)
{
	out << endl << "First: " << t.first;
	out << endl << "Second: " << t.second;
	out << endl << "Third: " << t.third;
	out << endl;
	return out;
}

TRIAD TRIAD::operator++(int)
{
	first++;
	second++;
	third++;
	TRIAD t(first, second, third);
	return t;
}

