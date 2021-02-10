#include <iostream>
#include <utility>
#include <string>
#include <sstream>
using namespace std;
int n;
int counter(int* a)
{
    int c = 0;
    for (int i = 0; i <=n; i++) 
    {
        if (a[i]<0) 
        {
            c = c + 1;
        }
    } 
    return c;
}
int main() 
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    int k = 0;
    string s, word;
    cout << "Строка: ";
    getline(cin, s);
    stringstream words(s);
    while (words >> word)
    {
        if (word[0] == word[word.size() - 1])
        {
            k=k+1;
        }
    }
    cout << "Количество слов= " << k;
    cout << endl;
    cout << "Введите длинну массива n= ";
    cin >> n;
    int a[200];
    cout << "Массив: ";
    for (int i = 0; i < n; i++) 
    {
        a[i] = rand() % 100 - 50;
        cout << a[i] << " ";
    } 
    cout << endl;
    cout << "Количество отрицательных чисел= " << counter(a)-1 << endl;
    return 0;
}