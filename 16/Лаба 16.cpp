#include <iostream>
#include<time.h>
using namespace std;
int n;
void mergeSortRec(int* v, int r, int t)
{
	int p = 1;
	int k = 1;
	int i = 0;
	bool flag = false;
	while (v[i] <= v[i + 1] && i < r - 1)
	{
		p++;
		i++;
	}
	if (v[i] > v[i + 1] && i < r - 1)
	{
		i++;
		flag = true;
		while (v[i] <= v[i + 1] && i < r - 1)
		{
			k++;
			i++;
		}
	}
	int num = i + 1;
	int* a = new int[p];
	int* b = new int[k];
	for (i = 0; i < p; i++)
	{
		a[i] = v[i];

	}
	int g = 0;
	if (flag == true)
	{
		for (i = p; i < p + k; i++)
		{
			b[g] = v[i];
			g++;
		}
	}
	int j = 0;
	int l = 0;
	if (flag == true)
	{
		for (i = 0; i < num; i++)
		{
			if ((a[l] < b[j] || j >= k) && l < p)
			{
				v[i] = a[l];
				l++;
			}
			else
				if (a[l] > b[j] || l >= p && j < k)
				{
					v[i] = b[j];
					j++;

				}
				else
					if (a[l] == b[j] && j < k && l < p)
					{
						v[i] = a[l];
						v[i + 1] = b[j];
						l++;
						j++;
						i++;

					}
		}
	}
	delete[] a;
	delete[] b;
}
void mergeSort1(int* v, int r, int i)
{
	if (i < r)
	{
		mergeSortRec(v, r, i);
		mergeSort1(v, r, i + 1);
	}
}
void Merge(int* A, int first, int last)
{
	int middle, start, final, j;
	int* mas = new int[100];
	middle = (first + last) / 2;
	start = first;
	final = middle + 1;
	for (j = first; j <= last; j++)
	{
		if ((start <= middle) && ((final > last) || (A[start] < A[final])))
		{
			mas[j] = A[start];
			start++;
		}
		else
		{
			mas[j] = A[final];
			final++;
		}
	}
	for (j = first; j <= last; j++)
		A[j] = mas[j];
	delete[]mas;
}
void MergeSort(int* A, int first, int last)
{
	if (first < last)
	{
		MergeSort(A, first, (first + last) / 2);
		MergeSort(A, (first + last) / 2 + 1, last);
		Merge(A, first, last);
	}
};

void sort(int* a, int k)
{
	int b = 0;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				b = a[j];
				a[j] = a[j + 1];
				a[j + 1] = b;
			}
		}
	}
}
void MergeSort3(int* A)
{
	int a = 1, b = 1, k1 = 0, k2 = 0, k3 = 0;
	while (a + b <= n / 2)
	{
		if (a > b)
		{
			b = a + b;
		}
		else
		{
			a = a + b;
		}
		if (n % (a + b) == 0)
		{
			k1 = a;
			k2 = b;
		}
	}
	int* F1 = new int[n];
	int* F2 = new int[n];
	int* F3 = new int[n];
	if ((k1 == 0) && (k2 == 0))
	{
		k1 = 1;
	}
	int s = n / (k1 + k2);
	for (int i = 0; i < k1 * s; i++)
	{
		F1[i] = A[i];
	}
	sort(F1, k1 * s);
	for (int i = k1 * s; i < (k1 + k2) * s; i++)
	{
		F2[(i - (k1 * s))] = A[i];
	}
	sort(F2, k2 * s);
	int s1 = s, s2 = s, s3 = s;
	for (int j = 0; j < n; j++)
	{
		if ((k1 * s1 != n) && (k2 * s2 != n) && (k3 * s3 != n))
		{
			if (k1 == 0)
			{
				if (k2 > k3)
				{
					k1 = k3;
					s1 = s2 + s3;
					for (int i = 0; i < k1 * s1; i++)
					{
						if (i < k3 * s3)
						{
							F1[i] = F3[i];
						}
						else
						{
							F1[i] = F2[i - k3 * s3];
						}
					}
					sort(F1, k1 * s1);
					for (int i = 0; i < (k2 * s2 - k3 * s3); i++)
					{
						F2[i] = F2[(i + (k3 * s3))];
					}
					k2 = k2 - k3;
					k3 = 0;
					s3 = 0;
				}
				else
				{
					k1 = k2;
					s1 = s2 + s3;
					for (int i = 0; i < k1 * s1; i++)
					{
						if (i < k2 * s2)
						{
							F1[i] = F2[i];
						}
						else
						{
							F1[i] = F3[i - k2 * s2];
						}
					}
					sort(F1, k1 * s1);
					for (int i = 0; i < (k3 * s3 - k2 * s2); i++)
					{
						F3[i] = F3[(i + (k2 * s2))];
					}
					k3 = k3 - k2;
					k2 = 0;
					s2 = 0;
				}
			}
			else if (k2 == 0)
			{
				if (k1 > k3)
				{
					k2 = k3;
					s2 = s1 + s3;
					for (int i = 0; i < k2 * s2; i++)
					{
						if (i < k3 * s3)
						{
							F2[i] = F3[i];
						}
						else
						{
							F2[i] = F1[i - k3 * s3];
						}
					}
					sort(F2, k2 * s2);
					for (int i = 0; i < (k1 * s1 - k3 * s3); i++)
					{
						F1[i] = F1[(i + (k3 * s3))];
					}
					k1 = k1 - k3;
					k3 = 0;
					s3 = 0;
				}
				else
				{
					k2 = k1;
					s2 = s3 + s1;
					for (int i = 0; i < k2 * s2; i++)
					{
						if (i < k1 * s1)
						{
							F2[i] = F1[i];
						}
						else
						{
							F2[i] = F3[i - k1 * s1];
						}
					}
					sort(F2, k2 * s2);
					for (int i = 0; i < (k3 * s3 - k1 * s1); i++)
					{
						F3[i] = F3[(i + (k1 * s1))];
					}
					k3 = k3 - k1;
					k1 = 0;
					s1 = 0;
				}
			}
			else if (k3 == 0)
			{
				if (k1 > k2)
				{
					k3 = k2;
					s3 = s1 + s2;
					for (int i = 0; i < k3 * s3; i++)
					{
						if (i < k2 * s2)
						{
							F3[i] = F2[i];
						}
						else
						{
							F3[i] = F1[i - k2 * s2];
						}
					}
					sort(F3, k3 * s3);
					for (int i = 0; i < (k1 * s1 - k2 * s2); i++)
					{
						F1[i] = F1[(i + (k2 * s2))];
					}
					k1 = k1 - k2;
					k2 = 0;
					s2 = 0;
				}
				else
				{
					k3 = k1;
					s3 = s1 + s2;
					for (int i = 0; i < k3 * s3; i++)
					{
						if (i < k1 * s1)
						{
							F3[i] = F1[i];
						}
						else
						{
							F3[i] = F2[i - k1 * s1];
						}
					}
					sort(F3, k3 * s3);
					for (int i = 0; i < (k2 * s2 - k1 * s1); i++)
					{
						F2[i] = F2[(i + (k1 * s1))];
					}
					k2 = k2 - k1;
					k1 = 0;
					s1 = 0;
				}
			}
		}
		else {
			if (k1 * s1 == n)
			{
				for (int i = 0; i < n; i++)
				{
					A[i] = F1[i];
				}
			}
			if (k2 * s2 == n)
			{
				for (int i = 0; i < n; i++)
				{
					A[i] = F2[i];
				}
			}
			if (k3 * s3 == n)
			{
				for (int i = 0; i < n; i++)
				{
					A[i] = F3[i];
				}
			}
			j = n;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите количество элементов: ";
	cin >> n;
	srand(time(NULL));
	int* arr = new int[n];
	cout << "Массив: " << endl;
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() / 100;
		cout << arr[i] << " ";
	}
	int menu = -1;
	cout << endl << "Методы: " << endl;
	cout << "1 - сортировка методом естественного слияния" << endl;
	cout << "2 - сортировка сбалансированным слиянием" << endl;
	cout << "3 - сортировка многофазным слиянием" << endl;
	cout << "Выберите метод для сортировки: ";
	while (menu < 1 || menu > 3)
	{
		cin >> menu;
	}
	if (menu == 1) mergeSort1(arr, n, 0); ;
	if (menu == 2) MergeSort(arr, 0, n - 1);
	if (menu == 3) MergeSort3(arr);
	cout << endl << "Массив после сортировки: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}