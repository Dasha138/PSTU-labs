#pragma once
#include<iostream>
using namespace std;
class Money
{
    long r;
    int k;
public:
    Money();
    Money(long rub, int kop);
    ~Money();
    void SetRub();
    long GetRub();
    Money& operator++();
    Money& operator++(int a);
    void SetKop();
    int GetKop();
    void PrintClass();
    friend istream& operator>>(istream& stream, Money& element);
    friend ostream& operator<<(ostream& stream, Money element);
};
