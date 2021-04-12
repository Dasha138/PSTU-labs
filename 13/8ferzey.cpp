//Цифрой 1 обозначается ферзь
#include <iostream> 
using namespace std;
int board[8][8];
int rcount = 0;
void doska()
{
	for (int i = 0; i < 8; i++) 
	{
		for (int j = 0; j < 8; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
bool check(int a, int b)
{
	for (int i = 0; i < a; i++) 
	{
		if (board[i][b]) 
			return false; 
	}
	for (int i = 1; i <= a && b - i >= 0; i++) 
	{
		if (board[a - i][b - i]) 
			return false;
	}
	for (int i = 1; i <= a && b + i < 8; i++) 
	{
		if (board[a - i][b + i]) 
			return false;
	}
	return true;
}

void var(int a) 
{
	if (a == 8) 
	{
		doska();
		cout << "Вариант решения задачи: " << ++rcount << endl;
	}
	for (int i = 0; i < 8; i++) 
	{
		if (check(a, i)) 
		{
			board[a][i] = 1;
			var(a + 1);
			board[a][i] = 0;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	var(0);
	system("pause");
	return 0;
}
