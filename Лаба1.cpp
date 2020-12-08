#include <iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int a[100];
	int n, b, i;
	cout << "Введите размер массива: ";
	cin >> n;
	srand(time(NULL));
	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 20 - 10;
	}
	for (i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	//удаление  элемента с заданным номером.
	cout << "Введите номер для удаления элемента: ";
	cin >> b;
	n--;
	for (i = b; i <= n; i++)
	{
		a[i] = a[i + 1];
	}
	for (i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	n++;
	//добавление K элементов в начало массива.
	int k;
	cout << "\nВведите количество добавляемых элементов: ";
	cin >> k;
	int d[100];
	int j;
	cout << "Введите добавляемые элементы: ";
	n--;
	for (j = 0; j < k + n; j++)
	{
		if (j < k)
		{
			
			cin >> d[j];

		}
		else
			d[j] = a[j - k];
	}
	for (j = 0; j < k + n; j++)
	{
		cout << d[j] << ' ';
	}
	//перестановка положительных элементов в начало массива, а отрицательные в конец.
	n++;
	
	for (j = 0; j < n-1 ; j++)
	{
		for (int c = n - 2; c >= j; c--)
		{
			if (d[c] <= d[c + 1] && d[c] < 0)
			{
				int x = d[c];
				d[c] = d[c + 1];
				d[c + 1] = x;
			}
		}
	}
	cout << endl;
	cout << "Перестановка элементов: " << endl;
	for (j = 0; j < n; j++)
	{
		cout << d[j] << " ";
	}
	cout << endl;
	bool flag=false;
	system("pause");
	//поиск первого четного элемента массива.
	for (j = 0; j < n; j++)
	{
		if (d[j] % 2 == 0)
		{
			flag = true;
			cout << "Первый чётный элемент: " << d[j];
			break;
		}
	}
	if (flag==false)
	{
		cout << "Чётного элемента в массиве нет!";
	}
	cout << endl;
	//сортировка простым включением.
	for (int j = 1; j <= n; j++)
	{
		int m = d[j];
		int u = j;
		while ((u > 0) && (d[u - 1] > m))
		{
			d[u] = d[u - 1];
			u--;
			d[u] = m;
		}
	}
	cout << "Получившийся массив: ";
	for (int j = 1; j <= n; j++)
	{
		cout << d[j] << " ";
	}
	cout << endl;
}

   