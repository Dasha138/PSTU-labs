#include <iostream>
#include <iterator>
#include <vector>
#include "Money.h"
#include <map>
#include <queue>
#include<algorithm>
using namespace std;
int getCorrectNumber()
{
    int num;
    cout << "Введите размер:  ";
    while (!(cin >> num) || (cin.peek() != '\n') || num < 0)
    {
        cin.clear();
        while (cin.get() != '\n');
    }
    return num;
}
typedef vector<Money> MVector;
MVector make_vector(int n)
{
    Money a;
    MVector m;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        m.push_back(a);
    }
    return m;
}
void Print(MVector m)
{
    for (int i = 0; i < m.size(); i++)
    {
        cout << m[i] << "  ";
    }
    cout << endl;
}
void Print(priority_queue<int> qu)
{
    for (int i = qu.size(); i > 0; i--)
    {
        cout << qu.top() << " ";
        qu.pop();
    }
    cout << endl;
}
void Print(multimap<int, int> col)
{
    multimap<int, int>::iterator it = col.begin();
    for (; it != col.end(); it++)
    {
        cout << it->second << " ";
    }
    cout << endl;
}
void Task1()
{
    cout << "Задача 1" << endl << endl;
    int size;
    size = getCorrectNumber();
    vector<Money> col;
    for (int i = 0; i < size; i++)
    {
        Money newEl(rand() % 1000 / 10.0, rand() % 1000 / 10.0);
        col.push_back(newEl);
    }
    Print(col);
    Money max = col[0];
    vector<Money>::iterator it = col.begin();
    for (it = col.begin(); it != col.end(); it++)
        for (auto n : col)
        {
            if (n > max)
                max = n;
        }
    cout << "Максимальный элемент = " << max << endl;
    int pos;
    cout << "Введите позицию для добавления:\t";
    cin >> pos;
    col.emplace(col.begin() + pos - 1, max);
    Print(col);
}
void Task2()
{
    cout << "Задача 2" << endl << endl;
    priority_queue<int> qu;
    int size = 0;
    size = getCorrectNumber();
    for (int i = 0; i < size; i++)
    {
        int newEl;
        cin >> newEl;
        qu.push(newEl);
    }
    cout << "Получившийся контейнер" << endl;
    Print(qu);
    priority_queue<int> newQu;
    float sr = 0;
    for (int i = 0; i < size; i++)
    {
        newQu.push(qu.top());
        sr += qu.top();
        qu.pop();
    }
    sr /= size;
    cout << "Среднее арифметическое = " << endl;
    cout << sr << endl;

    priority_queue<int> newQu2;
    for (int i = 0; i < size; i++)
    {
        if (newQu.top() <= sr)
            newQu2.push(newQu.top());
        newQu.pop();

    }
    cout << "Контейнер после удаления" << endl;
    Print(newQu2);
}
void Task3()
{
    cout << "Задача 3" << endl << endl;
    typedef pair<int, int> Int_Pair;
    multimap<int, int> col;
    int size;
    size = getCorrectNumber();
    for (int i = 0; i < size; i++)
        col.insert(Int_Pair(i, rand() % 100));
    Print(col);
    multimap<int, int> newCol;
    multimap<int, int>::iterator it = col.begin();
    int max = it->second;
    for (; it != col.end(); it++)
    {
        if (it->second > max)
        {
            max = it->second;
        }
    }
    cout << "Максимальный элемент = " << max << endl;
    multimap<int, int>::iterator it2 = col.begin();
    int i = 0;
    for (; it2 != col.end(); it2++)
    {
        it2->second = it2->second * max;
    }
    cout << endl;
    cout << "Контейнер после домножения на макс.элемент: ";
    Print(col);
}
int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));
    Task1();
    Task2();
    Task3();
}