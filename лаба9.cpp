#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    ifstream in("f1.txt");
    ofstream out("f2.txt");
    string line, firstWord, word;
    while (getline(in, line))
    {
        stringstream ss(line);
        bool a = false;
        ss >> firstWord;
        while (ss >> word)
        {
            if (word == firstWord)
            {
                a = true;
                break;
            }
        }
        if (a) out << line << endl;
    }
    string consonants("bcdfghjklmnpqrstvwxz");
    int consCount = 0;
    for (auto it = line.begin(); it != line.end(); it++)
        if (consonants.find(*it) != string::npos)
            consCount++;
    cout << "Количество согласных= " << consCount;
    in.close();
    out.close();
    return 0;
}