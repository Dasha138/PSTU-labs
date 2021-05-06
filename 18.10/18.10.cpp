#include "Money.h"
#include <iostream> 
#include <fstream>
#include <string> 
#include "file_work.h"
using namespace std;
void main()
{
	setlocale(LC_ALL, "rus");
	Money p, p1, p2;
	int k, c;
	char file_name[30];
	do
	{
		cout << "\n1. Создание файла"; cout << "\n2. Печать файла";
		cout << "\n3. Удалить запись из файла";
		cout << "\n4. Добавить запись в файл";
		cout << "\n5. Изменить запись в файле";
		cout << "\n0. Выйти\n";
		cin >> c;
		switch (c)
		{
		case 1: cout << "Имя файла?"<<endl;
			cin >> file_name; k = make_file(file_name);
			if (k < 0)cout << "Нельзя создать файл";
			break;
		case 2: cout << "Имя файла?"<<endl;
			cin >> file_name; k = print_file(file_name);
			if (k == 0)cout << "Пустой файл\n";
			if (k < 0)cout << "Нельзя прочитать файл\n";
			break;
		case 3: cout << "Имя файла?"<<endl;
			cin >> file_name; int nom; cout << "Номер?"<<endl;
			cin >> nom;
			k = del_file(file_name, nom);
			if (k < 0)cout << "Нельзя прочитать файл";
			break;
		case 4: cout << "Имя файла?"<<endl;
			cin >> file_name;
			cout << "Номер?"<<endl;
			cin >> nom;
			cout << "Новые деньги: ";
			cin >> p1;
			k = add_file(file_name, nom, p1);
			if (k < 0) cout << "Нельзя прочитать файл";
			if (k == 0) k = add_end(file_name, p1);
			break;
		case 5: cout << "Имя файла?"<<endl;
			cin >> file_name; cout << "Номер?"<<endl;
			cin >> nom; cout << "Новые деньги: ";
			cin >> p2;
			k = change_file(file_name, nom, p2);
			if (k < 0) cout << "\nНельзя прочитать файл";
			if (k == 0) cout << "\nНеправильная запись";
			break;
		}
	} while (c != 0);
}