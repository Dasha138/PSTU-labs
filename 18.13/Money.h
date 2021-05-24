#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Money
{
    long rub;
    int kop;
    int dop;
public:
    Money();
    Money(double rub, double kop);
    ~Money();
    void SetRub();
    float GetRub();
    Money& operator++();
    Money& operator++(int a);
    void SetKop();
    float GetKop();
    void SetDop();
    int GetDop();
    void PrintClass();
    void GetRazn();

    bool operator!=(Money secondOperand);
    bool operator>(Money secondOperand)
    {
        return(this->GetRub() >= secondOperand.GetRub() && this->GetKop() >= secondOperand.GetKop());
    }
    friend ostream& operator<<(ostream& out, const Money& m);
    friend istream& operator>>(istream& in, Money& m);
    friend fstream& operator<<(fstream& fout, const Money& m);
    friend fstream& operator>>(fstream& fin, Money& m);
};