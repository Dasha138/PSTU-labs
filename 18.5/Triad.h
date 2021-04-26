#pragma once
#include "Object.h"
#include <string> 
#include <iostream> 
using namespace std;
class TRIAD :
	public Object
{
public:
	TRIAD(void);
public:

	virtual ~TRIAD(void);
	void Show();
	TRIAD(int, int, int);
	TRIAD(const TRIAD&);

	int get_first() { return first; }
	int get_second() { return second; }
	int get_third() { return third; }

	void set_first(int);
	void set_second(int);
	void set_third(int);

	TRIAD& operator=(const TRIAD&);
	TRIAD operator++(int);

	friend istream& operator>>(istream& in, TRIAD& c);
	friend ostream& operator<<(ostream& out, const TRIAD& c);

protected:
	int first;
	int second;
	int third;

};