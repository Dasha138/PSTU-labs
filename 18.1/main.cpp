#include<iostream>
#include"fraction.h"
using namespace std;

fraction make_fraction(double F, double S)
{
	fraction t;
	t.Init(F, S);
	return t;
}

int main()
{
	fraction A;
	A.Init(0.4, 0.3);
	A.Show();
	cout << "A.hipotenuse(" << A.first << "," << A.second << ")=" << A.hipotenuse() << endl << endl;
	fraction B;
	B.Read();
	B.Show();
	cout << "B.hipotenuse(" << B.first << "," << B.second << ")=" << B.hipotenuse() << endl << endl;
	fraction* X = new fraction;
	X->Init(2.0, 5);
	X->Show();
	X->hipotenuse();
	cout << "X.hipotenuse(" << X->first << "," << X->second << ") = " << X->hipotenuse() << endl << endl;
	fraction mas[3];
	for (int i = 0; i < 3; i++)
		mas[i].Read();
	for (int i = 0; i < 3; i++)
		mas[i].Show();
	for (int i = 0; i < 3; i++)
	{
		mas[i].hipotenuse();
		cout << "mas[" << i << "].hipotenuse(" << mas[i].first << "," << mas[i].second << ")=";
		cout << mas[i].hipotenuse() << endl;
	}
	cout << endl;
	fraction* p_mas = new fraction[3];
	for (int i = 0; i < 3; i++)
		p_mas[i].Read();
	for (int i = 0; i < 3; i++)
		p_mas[i].Show();
	for (int i = 0; i < 3; i++)
	{
		p_mas[i].hipotenuse();
		cout << "p_bass[" << i << "].hipotenuse(" << p_mas[i].first << "," << p_mas[i].second;
		cout << ")=" << p_mas[i].hipotenuse() << endl;
	}
	cout << endl;
	double y; double z;
	cout << "first?"; cin >> y;
	cout << "second?"; cin >> z;
	fraction F = make_fraction(y, z);
	F.Show();
	cout << "F.hipotenuse(" << F.first << "," << F.second << ") = " << F.hipotenuse() << endl;
	return 0;
}