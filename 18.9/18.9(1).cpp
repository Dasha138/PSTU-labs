#include "Plenty.h"
#include <iostream> 
using namespace std;
int main()
{
	try
	{
		Plenty x(2);
		Plenty y;
		cout << x;
		cout << "Номер?";
		int i; cin >> i;
		cout << x[i] << endl;
		y = x + 3;
		cout << y;
		--x;
		cout << x;
		--x;
		cout << x;
		--x;
	}
	catch (int)
	{
		cout << "Ошибка" << endl;
	}
	return 0;
}