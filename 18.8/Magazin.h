#pragma once
#include "Print.h"
class Magazin :
    public Print
{
public:
    Magazin(void);
public:
    ~Magazin(void);
    void Show();
    void Input();
    Magazin(string, string, int);
    Magazin(const Magazin&);
    int Get_list() { return list; }
    void Set_list(int);
    Magazin& operator=(const Magazin&);
protected:
    int list;

};