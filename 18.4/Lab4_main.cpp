#include <iostream>
#include "TRIAD.h"
#include "DATE.h"
using namespace std;
void main()
{
	TRIAD a;
	cin >> a;
	a++;
	cout << endl << "First + 1; Second + 1; Third +1: ";
	cout << a;

	DATE b(24, 04, 2013);
	cout << b;

	b.set_first(4);
	b.set_second(9);
	b.set_third(2005);
	cout << b;

	b++;
	cout << endl << "Day + 1; Mount + 1; Year +1: ";
	cout << b;

	b + 33;
	cout << endl << "Day + 33:";
	cout << b;

}