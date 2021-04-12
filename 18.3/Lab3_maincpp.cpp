#include "Money.h" 
#include <iostream> 
using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");
	Money a;
	Money b;
	cin >> a;
	cin >> b;
	--a;
	cout << a << endl;
	a--;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	if (a == b)
	{
		cout << "a == b" << endl;
	}
	else
	{
		cout << "a != b" << endl;
	}
}