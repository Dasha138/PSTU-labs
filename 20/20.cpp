#include <iostream>
#include "Header.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    btree t;
    int n;
    cout << "Кол-во элементов = ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        t.insert(a);
    }
    t.print();
    t.kol();
}