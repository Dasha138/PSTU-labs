#include <iostream>
#include <string>
using namespace std;
struct info
{
	string fio;
	string date;
	string number;
};

bool knut_morris_pratt(string str, string obr)
{
	int i, j, k;
	bool res = 0;
	int d = str.size();
	int e = obr.size();
	if (d == 0)
		cout << "Неверно задана строка\n";
	else if (e == 0)
		cout << "Неверно задана подстрока\n";
	else
	{
		j = 0;
		k = -1;
	}
	int* pf = new int[1000];
	pf[0] = -1;
	while (j < e - 1) {
		while (k >= 0 && obr[j] != obr[k])
			k = pf[k];
		j++;
		k++;
		if (obr[j] == obr[k])
			pf[j] = pf[k];
		else
			pf[j] = k;
	}
	i = 0;
	j = 0;
	while (j < e && i < d) {
		while (j >= 0 && str[i] != obr[j])
			j = pf[j];
		i++;
		j++;
	}
	delete[] pf;
	if (j == e)
		res = 1;
	return res;
}
bool boyer_moor(string str, string obr) 
{
	int d = str.size();
	int e = obr.size();

	if (d == 0)
		cout << "Неверно задана строка\n";

	else if (e == 0)
		cout << "Неверно задана подстрока\n";

	else
		int  i, Pos;
	int  bmt[256];

	for (int i = 0; i < 256; i++)
		bmt[i] = e;

	for (int i = e - 1; i >= 0; i--)

		if (bmt[(short)(obr[i])] == e)
			bmt[(short)(obr[i])] = e - i - 1;
	int pos = e - 1;

	while (pos < d)

		if (obr[e - 1] != str[pos])
			pos += bmt[(short)(str[pos])];

		else

			for (int i = e - 2; i >= 0; i--) {

				if (obr[i] != str[pos - e + i + 1]) {
					pos += bmt[(short)(str[pos - e + i + 1])] - 1;
					break;
				}

				else

					if (i == 0)
					{
						return true;
					}
			}

	return false;
}
void boyer(info* st, string key, int n)
{
	bool l;
	bool p = 0;
	for (int i = 0; i < n; i++)
	{
		l = boyer_moor(st[i].date, key);
		if (l != 0)
		{
			cout << "Элемент найден под номером: " << i << endl;
			cout << "ФИО: " << st[i].fio << endl;
			cout << "Дата рождения: " << st[i].date << endl;
			cout << "Номер телефона: " << st[i].number << endl;
			p = 1;
		}
	}
	if (p == 0)
	{
		cout << "Нет такого" << endl;
	}
}
void knut(info* st, string key, int n)
{
	bool l;
	bool p = 0;
	for (int i = 0; i < n; i++)
	{
		l = knut_morris_pratt(st[i].date, key);
		if (l != 0)
		{
			cout << "Элемент найден под номером: " << i << endl;
			cout << "ФИО: " << st[i].fio << endl;
			cout << "Дата рождения: " << st[i].date << endl;
			cout << "Номер телефона: " << st[i].number << endl;
			p = 1;
		}
	}
	if (p == 0)
	{
		cout << "Нет такого" << endl;
	}
}
int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	string key;
	cout << "Кол-во элементов: ";
	cin >> n;
	cin.ignore();
	cout << "Ключ: ";
	getline(cin, key);
	info* st = new info[n];
	for (int i = 0; i < n; i++)
	{
		cout << "ФИО: ";
		getline(cin, st[i].fio);
		cout << "Дата рождения: ";
		getline(cin, st[i].date);
		cout << "Номер телефона: ";
		getline(cin, st[i].number);

	}
	bool a;
	cout << "1-поиск алгоритмом Бойера-Мура.\n2-поиск алгоритмом Кнута-Морриса-Пратта." << endl;
	cin >> a;
	switch (a)
	{
	case 1: boyer(st, key, n); break;
	case 2: knut(st, key, n); break;
	default: cout << "Поиск не выполнен." << endl;
	}
	return 0;
}