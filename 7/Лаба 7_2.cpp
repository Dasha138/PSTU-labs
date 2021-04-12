#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;
///находит угол треугольника по сторонам
void Ygol(int x, int y, int z)
{
    double L =acos(((x*x)+(y*y)-(z*z))/(2*x*y));
    cout << "Угол= " << L;
}
//находит углы n-угольника по заданным сторонам
double angles(double s)
{
    int i, n;
    cout << "Количество сторон n-угольника= ";
    cin >> n;
    for (i = 0; i <=n; i++)
    {
        if (n>2)
        {
            s = (180 * (n - 2)) / n;
        }
        else
        {
            cout << "Такого многоугольника не существует!";
        }
    }
    cout << "Углы многоугольника=  " << s << endl;
    return 0;
}

int main()
{
    setlocale(LC_ALL, "rus");
    double s=0;
    int menu;
    cout << "\nМеню:\n1. Угол треугольника\n2. Углы n-угольника по заданным сторонам\nВаш выбор: ";
    cin >> menu;
    switch (menu)
    {
    case 1:
    {
        cout << "Введите длины сторон: ";
        double x, y, z;
        cout << "\nx=";
        cin >> x;
        cout << "\ny=";
        cin >> y;
        cout << "\nz=";
        cin >> z;
        Ygol(x, y, z);
        break;
    }
    case 2:
    {
        angles(s);
        break;
    }
    }
    cout << endl;
    return 0;
}