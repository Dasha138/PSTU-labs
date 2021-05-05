#include "Plenty.h"
void main()
{
    Plenty a(5);
    cout << "a:" << endl;
    cout << a << endl;
    cout << endl << "Enter a:" << endl;
    cin >> a;
    cout << endl << "a:" << endl;
    cout << a << endl;
    cout << endl << "a[2] = 100" << endl;
    a[2] = 100;
    cout << endl << "a:" << endl;
    cout << a << endl;

    cout << "b:" << endl;
    Plenty b(10, 3);
    cout << endl << "b:" << endl;
    cout << b << endl;
    cout << "c:" << endl;
    Plenty c(10);
    cout << endl << "c = a-b:" << endl;
    c = b - a;
    cout << endl << "c:" << endl;
    cout << c << endl;
    cout << endl << "a.length = " << a() << endl;

    cout << "a.first=" << *(a.first()) << endl;
    Iterator i = a.first();
    i++;
    cout << "i++" << endl << "*i = " << *i << endl;
    i--;
    cout << "i--" << endl << "*i = " << *i << endl;
    cout << endl << "Iterator a:" << endl;
    for (i = a.first(); i != a.last(); i++)
    {
        cout << *i << endl;
    }
}