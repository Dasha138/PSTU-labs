#pragma once
#include "object.h" 
#include <string> 
#include <iostream>

using namespace std;
class Vector
{
public:
	Vector(void);//êîíñòðóêòîð áåç ïàðàìåòðîâ
	Vector(int);//êîíñòðóêòîð êîïèðîâàíèÿ
public:
	~Vector(void);//äåñòðóêòîð
	void Add(Object*);//äîáàâëåíèå ýëåìåíòà â âåêòîð
	friend ostream& operator<<(ostream& out, const Vector&);//îïåðàöèÿ âûâîäà
private:
	Object** beg;//óêàçàòåëü íà ïåðâûé ýëåìåíò âåêòîðà
	int size;//ðàçìåð
	int cur;//òåêóùàÿ ïîçèöèÿ
};