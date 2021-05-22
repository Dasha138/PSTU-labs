#include "Stack.h"
#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    Stack<int>s;
    bool flag = true;
    while (flag)
    {
        cout << "1. Добавить    2. Удалить    3. Печать    4. Выход" << endl;
        int choice;
        cin >> choice;
        switch (choice) 
        {
        case(1):
            cout << "Какое число добавить в стек?";
            int n;
            cin >> n;
            s.push(n);
            break;
        case(2):
            s.pop();
            break;
        case(3):
            s.print();
            break;
        case(4):
            return 1;
        default:
            cout << "Неверный выбор" << endl;
            break;
        }
    }
    return 0;
}