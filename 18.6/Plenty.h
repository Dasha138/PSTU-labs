#pragma once
#include <iostream> 
using namespace std;
class Iterator 
{
    friend class Plenty;
    int* elem;
public:
    Iterator() { elem = 0; }
    Iterator(const Iterator& it) { elem = it.elem; }
    bool operator==(const Iterator& it) { return elem == it.elem; }
    bool operator!=(const Iterator& it) { return elem != it.elem; }
    void operator++() { ++elem; }
    void operator++(int) { ++elem; }
    void operator--() { --elem; }
    void operator--(int) { --elem; }
    int& operator*()const { return *elem; }
};
class Plenty 
{
private:
    int size;
    int* data;
    int len() { return size; }

    Iterator beg;
    Iterator end;
public:
    Plenty(int s, int k = 0);
    Plenty(const Plenty& a);
    ~Plenty();
    Plenty& operator=(const Plenty& a);
    int& operator[](int index);
    Plenty operator-(Plenty& a);
    int operator()();
    friend ostream& operator<<(ostream& out, const Plenty& a);
    friend istream& operator>>(istream& in, Plenty& a);
    Iterator first() { return beg; }
    Iterator last() { return end; }
};
