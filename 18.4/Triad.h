#pragma once
#include <string> 
#include <iostream> 
using namespace std;
class TRIAD
{
public:
	int first;
	int second;
	int third;

	TRIAD(void);
	virtual ~TRIAD(void);
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
};