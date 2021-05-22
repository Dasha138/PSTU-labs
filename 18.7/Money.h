#pragma once
#include <iostream> 
#include <string>
using namespace std;
class Money
{
public:
	Money(void);
	Money(int, int);
	Money(const Money&);
	Money operator-(Money k);
	Money& operator=(const Money&);
	friend ostream& operator<< (ostream& out, const Money&);
	friend istream& operator>> (istream& in, Money&);
public:
	virtual ~Money(void) {};
private:
	int ryb, cop;
};
