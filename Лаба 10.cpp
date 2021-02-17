#include <iostream>
#include <string>
#include<windows.h>
using namespace std;
const int N = 6;

int main()
{
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);// Вывод на консоль в кодировке 1251
    setlocale(LC_ALL, "rus");
    cout << "Введите строки:" << endl;
    string* matr = new string[N];
    for (int i = 0; i < N; i++)
        getline(cin, matr[i]);

    int num;
    cout << "Введите номер строки для удаления: ";
    cin >> num;
    num--;
    for (num; num < N - 1; num++) 
    {
        matr[num] = matr[num + 1];
    }
    cout << "Результат: " << endl;
    for (int i = 0; i < N - 1; i++)
    {
        cout << matr[i] << endl;
    }
    delete[] matr;
}