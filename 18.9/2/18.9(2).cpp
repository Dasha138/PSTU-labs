#include "Plenty.h" 
#include "Error.h" 
#include <iostream> 
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	try
	{
		Plenty x(2);
		Plenty y;
		cout << x;
		cout << "Введите номер: ";
		int i;
		cin >> i;
		cout << x[i] << endl;
		y = x + 3;
		cout << y;
		--x;
		cout << x;
		--x;
		cout << x;
		--x;
	}
	catch (error e)
	{
		e.what();
	}
	return 0;
}