#pragma once
#include "Object.h"
#include "Event.h"
#include<string>
using namespace std;
class Print :
    public Object
{
public:
    Print(void);
public:
    virtual ~Print(void);
    void Show();
    void Input();
    Print(string, string);
    Print(const Print&);
    string Get_title() { return title; }
    string Get_author() { return author; }
    void Set_title(string);
    void Set_author(string);
    Print& operator=(const Print&);
    void HandleEvent(const TEvent& e);
protected:
    string title;
    string author;
};
