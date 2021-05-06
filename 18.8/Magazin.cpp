#include "Magazin.h"
#include<iostream>
Magazin::Magazin(void) :Print()
{
	list = 0;
}
Magazin::~Magazin(void)
{
}
Magazin::Magazin(string T, string A, int L) :Print(T, A)
{
	list = L;
}
Magazin::Magazin(const Magazin& M)
{
	title = M.title;
	author = M.author;
	list = M.list;
}
void Magazin::Set_list(int L)
{
	list = L;
}
Magazin& Magazin::operator=(const Magazin& l)
{
	if (&l == this)return *this;
	title = l.title;
	author = l.author;
	return *this;
}
void Magazin::Show()
{
	cout << "\ntitle : " << title;
	cout << "\nauthor : " << author;
	cout << "\nlist : " << list;
	cout << "\n";
}
void Magazin::Input()
{
	cout << "\ntitle:";
	cin >> title;
	cout << "\nauthor:";
	cin >> author;
	cout << "\nlist:";
	cin >> list;
}