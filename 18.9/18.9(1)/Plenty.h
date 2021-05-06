#pragma once
#include <iostream>
using namespace std;
class Plenty
{
	int size;
	int* beg;
public:
	Plenty() { size = 0; beg = 0; }
	Plenty(int s);
	Plenty(int s, int* mas);
	Plenty(const  Plenty& v);
	~Plenty();
	const  Plenty& operator=(const  Plenty& v);
	int operator[](int i);
	Plenty operator+(int a);
	Plenty operator--();
	friend ostream& operator<<(ostream& out, const  Plenty& v);
	friend istream& operator>>(istream& in, Plenty& v);
};
