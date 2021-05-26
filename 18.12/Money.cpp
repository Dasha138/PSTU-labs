#include "Money.h"
#include<iostream>
using namespace std;
Money::Money()
{
    r = 0;
    k = 0;
    dop = 0;
}
Money::Money(float r, float k, int dop)
{
    this->r = r;
    this->k = k;
    this->dop = dop;
}
Money:: ~Money() {}
void Money::SetRub()
{
    float val;
    cout << "Введите рубли: ";
    cin >> val;
    while (val < 0)
    {
        cout << "Введите другое число: ";
        cin >> val;
    }
    this->r = val;
}
long Money::GetRub() { return r; }
void Money::SetKop()
{
    float tmp;
    cout << "Введите копейки: ";
    cin >> tmp;
    while (tmp > 99 || tmp < 0)
    {
        cout << "Введите другое число: ";
        cin >> tmp;
    }
    this->k = tmp;
}
int Money::GetKop() { return k; }
void Money::SetDop()
{
    int tmp1;
    cin >> tmp1;
    while (tmp1 > 99 || tmp1 < 0)
    {
        cin >> tmp1;
    }
    this->dop = tmp1;
}
int Money::GetDop() { return dop; }
void Money::PrintClass()
{
    cout <<this->r << "," << this->k << endl;
}
void Money::GetRazn()
{
    if (k >= dop)
        k-= dop;
    else {
        r--;
        k = 100 + k - dop;
    }
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
ostream& operator<<(ostream& out, const Money& m)
{
    out << m.r;
    out << ",";
    out << m.k;
    return out;
}
istream& operator>>(istream& in, Money& m)
{
    cout << "Введите рубли:   ";
    in >> m.r;
    cout << "Введите копейки:   ";
    in >> m.k;
    return in;
}
fstream& operator>>(fstream& fin, Money& m)
{
    fin >> m.r;
    fin >> m.k;
    return fin;
}
fstream& operator<<(fstream& fout, const Money& m)
{
    fout << m.r << endl;
    fout << m.k << endl;
    return fout;
}
bool Money::operator!=(Money secondOperand)
{
    return r != secondOperand.r && k != secondOperand.k;
}