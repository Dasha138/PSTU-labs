#include "Print.h"
#include <iostream>
using namespace std;

Print::Print(void)
{
	title = "";
	author = "";
}

Print::~Print(void)
{
}

Print::Print(string T, string A)
{
	title = T;
	author = A;
}

Print::Print(const Print& print)
{
	title = print.title;
	author = print.author;
}

void Print::Set_title(string T)
{
	title = T;
}
void Print::Set_author(string A)
{
	author = A;
}

Print& Print::operator=(const Print& c)
{
	if (&c == this)return *this;
	title = c.title;
	author = c.author;
	return *this;
}

void Print::Show()
{
	cout << "\ntitle : " << title;
	cout << "\nauthor : " << author;
	cout << "\n";
}

void Print::Input()
{
	cout << "\ntitle:";
	cin >> title;
	cout << "\nauther:";
	cin >> author;
}

void Print::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		switch (e.command)
		{
		case cmGet:cout << "title=" << Get_title() << endl; break;
		}
	}
}