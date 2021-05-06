#include "List.h"
#include "Print.h"
#include "Magazin.h"
#include<iostream>
using namespace std;
List::~List(void)
{
	if (beg != 0)delete[] beg;
	beg = 0;
}
List::List(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}
List::List(void)
{
	int n;
	cin >> n;
	beg = new Object * [n];
	cur = 0;
	size = n;
}
void List::Add()
{
	Object* p = 0;
	cout << "1.Print" << endl;
	cout << "2.Magazin" << endl;
	int y;
	cin >> y;
	if (y == 1)
	{
		Print* a = new (Print);
		a->Input();
		p = a;

		if (cur < size)
		{
			beg[cur] = p;
			cur++;
		}
	}
	else
		if (y == 2)
		{

			Magazin* b = new Magazin;
			b->Input();
			p = b;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else return;
}
void List::Show()
{
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();
		p++;
	}


}
int List::operator ()()
{
	return cur;
}
void List::Del()
{
	if (cur == 0)return;
	cur--;
}
void List::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < size; i++)
		{
			(*p)->HandleEvent(e); 
			p++;
		}
	}
}
