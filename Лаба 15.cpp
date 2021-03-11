#include <iostream>
#include<string>
using namespace std;
struct items
{
	string name;
	int size;
};
void Shell(items* ar, int n)
{
	int b = n / 2;
	while (b > 0)
	{
		for (int i = 0; i < n - b; i++)
		{
			int j = i;
			while (j >= 0)
			{
				if (ar[j].size > ar[j + b].size)
				{
					int d = ar[j].size;
					ar[j].size = ar[j + b].size;
					ar[j + b].size = d;
					string f = ar[j].name;
					ar[j].name = ar[j + b].name;
					ar[j + b].name = f;
					j -= b;
				}
				else
					j = -1;
			}
		}
		b /= 2;
	}
}
void Hoara(items* ar, int left, int right)
{
	int d;
	string f;
	int i = left;
	int j = right;
	while (i <= j)
	{
		while (ar[i].size < ar[(left + right) / 2].size && i < right)
			i++;
		while (ar[j].size > ar[(left + right) / 2].size && j > left)
			j--;
		if (i <= j)
		{
			d = ar[i].size;
			ar[i].size = ar[j].size;
			ar[j].size = d;
			f = ar[i].name;
			ar[i].name = ar[j].name;
			ar[j].name = f;
			i++;
			j--;
		}
		if (i < right)
		{
			Hoara(ar, i, right);
		}
		if (j > left)
		{
			Hoara(ar, left, j);
		}
	}
}
int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "Введите количество элементов списка: ";
	cin >> n;
	cout << "Введите список: " << endl;
	cin.ignore();
	items* st = new items[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Название маршрута: ";
		cout << " ";
		getline(cin, st[i].name);
		cout << "Длина маршрута: ";
		cin >> st[i].size;
		cin.ignore();
	}
	int a;
	cout << "1.Сортировка методом Шелла\n2.Сортировку методом Хоара" << endl;
	cin >> a;
	switch (a)
	{
	case 1: Shell(st, n); break;
	case 2: Hoara(st, 0, n - 1);; break;
	default: cout << "Сортировка не выполнена" << endl;
	}
	cout << endl << "После сортировки: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Название маршрута: " << st[i].name << endl;
		cout << "Длина маршрута: " << st[i].size << endl;
	}
}