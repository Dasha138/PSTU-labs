#include <iostream>
#include <time.h>
using namespace std;
void Left(int* a, int n, int k)
{
    int i = k;
    while (true)
    {
        cout << a[i] << "\t";
        i--;
        if (i == -1) i = n - 1;
        if (i == k) 
            break;
    }
}

void Right(int* a, int n, int k)
{
    int i = k;
    while (true)
    {
        cout << a[i] << "\t";
        i++;
        if (i == n) i = 0;
        if (i == k) 
            break;
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    srand(time(0));

    int n;
    while (true)
    {
        cout << "Введите размер массива: " << endl;
        cin >> n;
        if (n >= 2)
            break;
        else cout << "Введите другой размер" << endl;
    }

    int a[100];

    for (int i = 0; i < n; i++)
    {
        a[i] = rand() / 100;
    }

    for (int i = 0; i < n; i++)
    {
        cout<< a[i] << "\t";
    }
    cout << endl;

    int k;
    while (true)
    {
        cin >> k;
        if (k >= 0 && k < n) break;
        else cout << "Введите другое значение k" << endl;
    } 
    //массив с К-ого элемента и по К-1 (по кольцу влево)
    cout << "Массив по кольцу влево: \t";
    Left(a, n, k);
    cout << endl;
    
    //добавление первого и 3 последних элементов
   
    for (int  i= n; i > -1; i--)
    {
        a[i] = a[i - 1];
    }
    cout << endl;
    a[0] = rand() % 100;
    a[n + 1] = rand() % 100;
    a[n + 2] = rand() % 100;
    a[n + 3] = rand() % 100;
    cout << endl;
    for (int i = 0; i < n + 4; i++)
    {
        cout << a[i] << "  ";
    }
    cout << "\nМассив по кольцу вправо (после добавления элементов): \t";
    Right(a, n, k);

    
    return 0;
}
