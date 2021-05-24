#include <iostream>
#include"Vector.h"
#include"Money.h"
#include<vector>
#include<queue>
#include<iterator>
using namespace std;
template<typename T>
void Print(vector<T> l)
{
    int j = 1;
    typename vector<T>::iterator i = l.begin();
    for (; i != l.end(); i++)
    {
        cout << j << ")\t";
        cout << *i << endl;
        j++;
    }
    cout << endl;
}
template <typename T>
void Print(Vector<T> l)
{
    for (int i = 0; i < l.size(); i++)
    {
        cout << i + 1 << ")\t";
        cout << l[i] << endl;
    }
    cout << endl;
}
template<typename T>
void Print(priority_queue<T> qu)
{
    for (int i = qu.size(); i > 0; i--)
    {
        cout << i << ")\t";
        cout << qu.top() << endl;
        qu.pop();
    }
    cout << endl;
}
template<typename T>
priority_queue<T> DeleteRange(priority_queue<T> qu, float sred)
{
    priority_queue<T> res;
    while (!qu.empty())
    {
        if (qu.top() > sred)
            qu.pop();
        else
        {
            res.push(qu.top());
            qu.pop();
        }
    }
    while (!res.empty())
    {
        qu.push(res.top());
        res.pop();
    }

    return qu;
}
template<typename T>
float Average(priority_queue<T> qu)
{
    float res = 0.0;
    while (!qu.empty())
    {
        res += qu.top();
        qu.pop();
    }
    res = res / 10.00;
    return res;
}
template<typename T>
T max(priority_queue<T> qu)
{
    T m = 0.0;
    for (int i = 0; i < 10; i++)
    {
        if (qu.top() > m)
        {
            m = qu.top();
            qu.pop();
        }
    }
    return m;
}
void Task1()
{
    cout << "Задача 1" << endl;
    vector<float> l1;
    for (int i = 0; i < 10; i++)
        l1.push_back(rand() % 10000 / 100.0);
    Print(l1);
}
void Task2()
{
    cout << endl << "Задача 2" << endl;
    vector<Money> L;
    for (int i = 0; i < 10; i++)
        L.push_back(Money(666, 66));
    Print(L);
}
void Task3()
{
    cout << endl << "Задача 3" << endl;
    Vector<float> l;
    float min = 101.01;
    int pos;
    for (int i = 0; i < 10; i++)
        l.Insert(rand() % 10000 / 100.00, i);
    Print(l);
    for (int i = 0; i < l.size(); i++)
    {
        if (l[i] < min)
            min = l[i];
    }
    cout << "Минимальный элемент = ";
    cout << min << endl;
    cout << "На какую позицию добавить? (1-10)  ";
    cin >> pos;
    l.Insert(min, pos - 1);
    Print(l);
}
void Task4()
{
    cout << endl << "Задача 4" << endl;
    priority_queue<float> qu;
    for (int i = 0; i < 10; i++)
        qu.push(rand() % 10000 / 100.0);
    Print(qu);
    float aver = Average(qu);
    cout << "Среднее арифметическое = ";
    cout << aver << endl;
    qu = DeleteRange(qu, aver);
    Print(qu);
}
void Task5()
{
    cout << endl << "Задача 5" << endl;
    priority_queue<float> qu;
    for (int i = 0; i < 10; i++)
        qu.push(rand() % 10000 / 100.0);
    Print(qu);
    float maxim = max(qu);
    cout << "Максимальный элемент = ";
    cout << maxim << endl;
    priority_queue<float> tmp;
    while (!qu.empty())
    {
        tmp.push(qu.top() * maxim);
        qu.pop();
    }
    Print(tmp);
}
int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));
    Task1();
    Task2();
    Task3();
    Task4();
    Task5();
}