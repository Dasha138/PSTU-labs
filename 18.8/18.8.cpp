#include"Print.h"
#include"Magazin.h"
#include"Object.h"
#include"List.h"
#include"Dialog.h"
#include<iostream>
using namespace std;
void main()
{
	/*Print* a = new Print;
	a->Input();
	a->Show();
	Magazin* b = new Magazin;
	b->Input();
	b->Show();*/
	Print* a = new Print;
	a->Input();
	Magazin* b = new Magazin;
	b->Input();
	List v(10);
	Object* p = a;
	v.Add();
	p = b;
	v.Add();
	v.Show();
	v.Del();
	cout << "\nVector size=" << v();
	Dialog D;
	D.Execute();
}