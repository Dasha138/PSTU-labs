#include "Plenty.h"
#include "Money.h"
#include <iostream>
using namespace std;

void main()
{
	Plenty<int>A(5, 0);
	cout << "A: ";
	cin >> A;
	cout << "A: " << A << endl;
	Plenty <int>B(10, 1);
	cout << "B: " << B << endl;
	B = A;
	cout << "B=A: " << B << endl;
	cout << "A[2]: " << A[2] << endl;
	cout << "size A()= " << A() << endl;
	B = A - 10;
	cout << "B=A-10: " << B << endl;
	Money t;
	cin >> t;
	cout << "t: " << t;
	int k;
	cout << endl << "k?";
	cin >> k;
	Money d(k, k);
	Money p;
	p = t - d;
	cout << "p: " << p;

	Money q;
	cout << endl << "Enter q: ";
	cin >> q;
	cout << "q: " << q;
	Plenty<Money>C(5, q);
	cout << endl << "Enter C: ";
	cin >> C;
	cout << "C: " << C << endl;
	Plenty <Money>D(10, q);
	cout << "D: " << D << endl;
	D = C;
	cout << "D: " << D << endl;
	cout << "C[2]: " << C[2] << endl;
	cout << "size C()=" << C() << endl;
	D = C - q;
	cout << "D=C-q: " << D << endl;
}