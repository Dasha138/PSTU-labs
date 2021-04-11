#include <iostream>
using namespace std;
struct point
{
	int key;
	point* pred, * next;
}*head;
//Создание двунаправленного списка
point* make_list()
{
	int n;
	cout << "Количество элементов= ";
	cin >> n;
	point* p, * r, * beg;
	p = new (point);
	beg = p;
	cin >> p->key;

	p->pred = 0; p->next = 0;

	for (int i = 1; i < n; i++)
	{
		r = new(point);
		cin >> r->key;
		p->next = r;
		r->pred = p;
		r->next = 0;
		p = r;
	}
	return beg;
}
//Печать двунаправленного списка
void print_list(point* beg)
{
	if (beg == 0)
	{
		cout << "Список пуст\n";
		return;
	}
	point* p = beg;
	while (p)
	{
		cout << p->key << "\t";
		p = p->next;
	}
	cout << "\n";
}
//Удаление из двунаправленного списка все четные элементы
point* del_point(point* beg)
{
	if (beg == 0)
	{
		cout << "Список пуст\n";
		return beg;
	}
	point* p = beg;
	point* prev = NULL;
	while (p)
	{
		if (p->key % 2 == 0)
		{
			if (prev)
			{
				prev->next = p->next;
				p = p->next;
				continue;
			}
			else
				head = p->next;
		}
		prev = p;
		p = p->next;
	}
}
void main()
{
	setlocale(LC_ALL, "rus");
	point* beg = 0;
	int i;
	for (int i = 0; i < 1; i++)
		beg = make_list();

	del_point(beg);
	print_list(beg);
}
