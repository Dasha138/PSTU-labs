#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <clocale>
#include <cstdlib>
using namespace std;
ifstream input("CarsInput.txt");
struct Information
{
    string marka;
    string sernomer;
    string regnomer;
    string year;
};
void vivod(Information infof)
{
    cout << "Носитель: " << infof.marka << endl;;
    cout << "Объём: " << infof.sernomer << endl;
    cout << "Название: " << infof.regnomer << endl;;
    cout << "Автор: " << infof.year << endl;
    cout << endl;
}
Information fileinput(Information infof)
{
    getline(input, infof.marka);
    getline(input, infof.sernomer);
    getline(input, infof.regnomer);
    getline(input, infof.year);
    return infof;
}
int main()
{
    bool f = false;
    int i = 1;
    int l;
    string k;
    string a;
    int n = 8;
    if (input.is_open())
    {
        Information info[20];
        setlocale(LC_ALL, "rus");
        for (int i = 1; i < n; i++)
        {
            info[i] = fileinput(info[i]);
        }
        for (int i = 1; i < n; i++)
        {
            vivod(info[i]);
        }
        cout << "Структуры после удаления первых трех элементов ";
        cout << endl;
        for (i = 1; i < n - 3; i++)
        {
            info[i] = info[i + 3];
        }

        for (int i = 1; i < n - 3; i++)
        {
            vivod(info[i]);
        }
        cout << "Введите регистрационный номер машины, после которой нужно добавить новый элемент(Е420НН69,К559КС59,О777ОО777,У512КР13)  ";
        cin >> a;
        cout << endl;
        while (f == false)
        {
            for (i = 1; i < n - 3; i++)
            {
                if (info[i].regnomer == a) { f = true; l = i; }
            }
            if (f == false) { cout << "Данный номер не найден, введите другой: "; getline(cin, a); }
        }
        cout << endl;
        for (i = n - 3; i > l; i--)
        {
            info[i] = info[i + 1];
        }
        cout << endl;
        info[l] = fileinput(info[l]);
        cout << "Итоговые структуры";
        for (int i = 1; i < n; i++)
        {
            vivod(info[i]);
        }
        input.close();
    }
    else { cout << "Файл с данными отсутствует или закрыт"; }
    input.close();
}