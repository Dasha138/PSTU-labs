#include <iostream>
using namespace std;
int key;
struct List 
{
    int data;
    List* next;
};
List* make(int n, List*& first, List*& last) 
{
    if (n == 0)
    {
        cout << "Пустой";
        return 0;
    }
    List* p = new List;
    int a;
    cout << "Введите элементы:" << endl;
    cin >> a;
    p->data = a;
    p->next = NULL;
    first = p;
    last = p;
    for (int i = 2; i <= n; i++)
    {
        List* h = new List;
        cin >> a;
        h->data = a;
        h->next = p;
        last = h;
        p = last;
    }
    return first;
}
void print(List* last) 
{
    List* p = last;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int del(List*& first, List*& last)
{
    List* p = last;
    int k = 0;
    while (p != NULL)
    {
        k++;
        p = p->next;
    }
    p = last;
    if (k == 1)
    {
        int h = last->data;
        delete p;
        last = NULL;
        first = NULL;
        return h;
    }
    else
    {
        while (p->next->next != NULL)
        {
            p = p->next;
        }
        List* h = p;
        int q = p->next->data;
        p = p->next;
        h->next = NULL;
        first = h;
        delete p;
        return q;
    }
}
List* push(int n, List*& last)
{
    List* p = new List;
    p->data = n;
    p->next = last;
    last = p;
    return last;
}
int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Введите размер очереди: " << endl;
    int n;
    cin >> n;
    List* first, * last;
    make(n, first, last);
    print(last);
    int* mas = new int[n];
    int i = 0;
    while (i < n)
    {
        int t = del(first, last);
        if (t % 2 != 0)
        {
            mas[i] = t;
            i++;
        }
        else 
        {
            n--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        push(mas[i], last);
    }
    cout << "Очередь: " << endl;
    print(last);
}