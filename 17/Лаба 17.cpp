#include <iostream>
#include<string>
#include <windows.h>
#include <ctime>
#include <math.h>
using namespace std;
struct info
{
	struct Date
	{
		int Day, Month, Year;
	};
	string fio;
	Date date;
	string number;
	string pasnum;
	void Show()
	{
		cout << "\nФИО: " << fio
	    	 << "\nДата рождения: " << date.Day << "." << date.Month << "." << date.Year
			 << "\nТелефон: " << number
		     << "\nНомер паспорта: " << pasnum << endl;

	}
	void Random()
	{
		string names[] = { "Антонов", "Поздеев","Николаев","Худяков", "Иванов", "Птичкин","Соколов", "Воронин", "Макаров" };
		string secnames[] = { "Андрей","Иван", "Сергей", "Макар", "Олег", "Петр", "Антон", "Алексей" };
		string thirdnames[] = { "Львович","Антонович","Петрович","Николаевич", "Олегович", "Викторович" };
		fio = names[rand() % 7] + " " + secnames[rand() % 6] + " " + thirdnames[rand() % 5];
		date.Day = 1 + rand() % 31;
		date.Month = 1 + rand() % 12;
		date.Year = 1000 + rand() % 1000;
		string phone;
		for (int i = 0; i < 10; i++) 
		{
			phone.push_back(rand() % 10 + 48);
		}
		number = phone;
		string pasport;
		for (int i = 0; i < 6; i++) 
		{
			pasport.push_back(rand() % 10 + 48);
		}
		pasnum = pasport;
	}
};
int get(string str) 
{
	int value = 0;
	int j = 1;
	for (auto i : str) 
	{
		value += i * j;
		j++;
	}
	return value;
}
int hash_t(string str, int size)
{
	double f;
	return int(size * modf(get(str) * 0.803523421, &f));
}
void make_table(int n, int size, info* st2)
{
	int* table = new int[size];
	int hashn = size;
	for (int i = 0; i < size; i++)
	{
		table[i] = -1;
	}
	int collis = 0;
	for (int k = 0; k < n; k++)
	{
		int num;
		int hash = hash_t(st2[k].number, hashn);
		if (table[hash] == -1)
		{
			table[hash] = k;
		}
		else
		{
			num = hash;
			while (num < size && table[num] != -1)
			{
				collis++;
				num++;
			}
			if (num >= size)
			{
				size *= 2;
				int* table2 = new int[size];
				for (int i = 0; i < size / 2; i++)
				{
					table2[i] = table[i];
				}
				for (int i = size / 2; i < size; i++)
				{
					table2[i] = -1;
				}
				delete[]table;
				table = table2;
			}
			if (table[num] == -1)
			{
				table[num] = k;
			}
		}
	}
	cout << "Число колизий: " << collis << endl;
	cout << "Введите ключ для поиска (номер телефона): ";
	string key;
	cin.ignore();
	getline(cin, key);
	int hashkey = hash_t(key, hashn);
	if (st2[table[hashkey]].number == key)
	{
		cout << "Элемент найден: " << endl;
		st2[table[hashkey]].Show();
	}
	else
	{
		while (st2[table[hashkey]].number != key && hashkey < size)
		{
			hashkey++;
		}
		if (st2[table[hashkey]].number == key)
		{
			cout << "Элемент найден: " << endl;
			st2[table[hashkey]].Show();
		}
		else
			cout << "Такого элемента не найдено";
	}
	bool p = 0;
	cout << "Если хотите удалить данный элемент нажмите 1, если нет-0" << endl;
	cin >> p;
	if (p)
	{
		info* st = new info[n - 1];
		for (int i = 0; i < table[hashkey]; i++) 
		{
			st[i] = st2[i];

		}
		for (int i = table[hashkey]; i < n - 1; i++) 
		{
			st[i] = st2[i + 1];
		}
		delete[]st2;
		cout << "После удаления: " << endl;
		for (int i = 0; i < n - 1; i++)
		{
			st[i].Show();
		}
	}
}
int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	int n, size;
	string key;
	cout << "Введите количество элементов: ";
	cin >> n;
	cout << "Введите размер таблицы: ";
	cin >> size;
	info* st = new info[n];
	int* table = new int[size];
	for (int i = 0; i < n; i++)
	{
		st[i].Random();
		st[i].Show();
	}
	make_table(n, size, st);

}