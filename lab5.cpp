#include <iostream> 
using namespace std;

void main()
{
	int& same_max(int**, int, int);
    int found, i, j, m, n;
	setlocale(LC_ALL, "rus");
	int str, stb, i, j;
	cout << "Введите количество строк: "; 
	cin >> str;
	cout << "Введите количество столбцов: "; 
	cin >> stb;
	int** a = new int* [str];
	for (i = 0; i < str; i++)
		a[i] = new int[stb];
	for (i = 0; i < str; i++) 
	{


		for (j = 0; j < stb; j++)
		{
			a[i][j] = rand() % 50;
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "Максимальный повторяющийся элемент: " << same_max(a, str, stb) << endl;
	delete[]a;
}
int& same_max(int** a, int str, int stb)
{
	int max = -999;
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stb; j++)
		{
			found = 0;
			for (int m = i; m < str && !found; m++)
			{
				for (int n = 0; n < stb && !found; n++)
				{
					if ((a[i][j] == a[m][n]) && (&a[i][j] != &a[m][n])) {
						if (a[i][j] > max)
							max = a[i][j];
						found = 1;
					}
				}
			}
		}
	}
	return max;
}