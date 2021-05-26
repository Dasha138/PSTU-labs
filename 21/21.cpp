#include <iostream>
#include <vector>
#include <windows.h>
#include <queue>
#include <algorithm>
using namespace std;
int x;
int a = 6;
int result[6] = { 1000,1000,1000,1000,1000,1000 };
bool flag[6] = { false,false,false,false,false,false };
vector <vector<int>> matrix = { {0 ,12,18, 5,0 ,34 },
                                {12, 0 ,16 ,0,53 ,45 },
                                {18,16 ,0 ,3 ,21,0 },
                                {5 ,0 ,3 ,0 ,0 ,0 },
                                {0 ,53,  21 ,0,0 ,0 },
                                {34,45 , 45 , 0 ,0 ,0 } };
bool comp(int a, int b)
{
    return matrix[x][a] < matrix[x][b];
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    queue <int> QUEUE;
    cout << "Введите нужную вершину: ";
    cout << endl;
    cin >> x;
    x--;
    result[x] = 0;
    QUEUE.push(x);
    while (true)
    {
        x = QUEUE.front();
        vector <int> v;
        for (int i = 0; i < a; i++) if (matrix[x][i] != 0 && !flag[i]) v.push_back(i);
        if (v.size() == 0)
        {
            flag[x] = true;
            QUEUE.pop();
            if (QUEUE.size() == 0) break;
            continue;
        }
        sort(v.begin(), v.end(), comp);
        for (int i = 0; i < v.size(); i++)
        {
            result[v[i]] = min(result[v[i]], matrix[x][v[i]] + result[x]);
            QUEUE.push(v[i]);
        }
        flag[x] = true;
        QUEUE.pop();
        if (QUEUE.size() == 0) break;
    }
    cout << "Кратчайшие пути к вершине:\n";
    for (int i = 0; i < a; i++)
    {
        if (result[i] == 1000) cout << i + 1 << " - недоступен\n";
        else cout << i + 1 << " - " << result[i] << endl;
    }
}