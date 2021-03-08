#include<iostream>
#include<stack>
using namespace std;
int a;//символ в стеке
void print(stack<int>st) 
{
	int p = st.size();
	if (p == 0)
	{
		cout << "Стек пуст";
	}
	else
	{
		for (int i = 0; i < p; i++)
		{
			cout << st.top() << " ";
			st.pop();
		}
	}
	cout << endl;
}
int main()
{
	setlocale(LC_ALL, "rus");
	stack<int>st;//создание пустого стека
	int n;
	cout << "Введите кол-во элементов стека: "<<endl;
	cin >> n;
	cout << "Введите элементы: "<<endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		st.push(a);
	}
	cout << "Стек: ";
	print(st);//вывод стека
	
	stack<int>st2;
	int k = 0;
	cout << "Сколько элементов добавить?"<<endl;
	cin >> k;
	int s = 0;
	cout << "Введите номер элемента после которого добавить элементы: ";
	cin >> s;
	for (int i = 0; i < n - s + 1; i++)
	{
		st2.push(st.top());
		st.pop();
	}
	cout << "Введите элементы: ";
	for (int i = 0; i < k; i++)
	{
		cin >> a;
		st.push(a);
	}
	for (int i = 0; i < n-s+1; i++)
	{
		st.push(st2.top());
		st2.pop();
	}
	print(st);
	return 0;
}