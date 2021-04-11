#include <iostream>
using namespace std;
#include "includes/exam.h"
avto make() 
{
    string marka;
    string model;
    int price;

    cout << "Введите марку: "; 
    cin >> marka;
    cout << "Введите модель: "; 
    cin >> model;
    cout << "Введите стоимость: "; 
    cin >> price;
    avto t(marka, model, price);
    return t;
}

void print(avto t) 
{
    t.show();
}

int main() 
{
    cout << "Конструктор без параметров" << endl;
    avto t1;
    t1.show();
    cout << endl;

    cout << "Конструктор с параметрами" << endl;
    avto t2("Kia", "История", 1379000);
    t2.show();
    cout << endl;

    cout << "Конструктор копирования" << endl;
    avto t3 = t2;
    t3.set_marka("BMW");
    t3.set_model("Математика");
    t3.set_price(6440000);
    print(t3);
    cout << endl;

    cout << "Конструктор ввода" << endl;
    avto t4 = make();
    t4.show();
    cout << endl;
}