#include <iostream>
#include "Money.h"
using namespace std;
Money::Money()
{
    r = 0;
    k = 0;
}
Money::Money(long rub, int kop)
{
    this->r = rub;
    this->k = kop;
}
Money:: ~Money() {}
void Money::SetRub()
{
    long val;
    cin >> val;
    while (val < 0)
    {
        cin >> val;
    }
    this->r = val;
}
long Money::GetRub() { return r; }
void Money::SetKop()
{
    int tmp;
    cin >> tmp;
    while (tmp > 99 || tmp < 0)
    {
        cin >> tmp;
    }
    this->k = tmp;
}
int Money::GetKop() { return k; }
void Money::PrintClass()
{
    cout<< this->r << "," << this->k << endl;
}
Money& Money::operator++()
{
    r++;
    return *this;
}
Money& Money::operator++(int a)
{
    Money tmp(*this);
    this->r++;
    return tmp;
}
istream& operator>>(istream& stream, Money& element)
{
    stream >> element.r;
    stream >> element.k;
    return stream;
}
ostream& operator<<(ostream& stream, Money element)
{
    stream << element.r << "," << element.k;
    return stream;
}