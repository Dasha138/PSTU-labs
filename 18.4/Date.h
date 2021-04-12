#pragma once
#include "TRIAD.h"
class DATE :
    public TRIAD
{
public:
    DATE(void);
public:
    ~DATE(void);
    DATE(int, int, int);
    DATE(const DATE&);

    void year(int);
    void month(int);
    void day(int);

    DATE operator++(int);
    DATE operator+(int);

    DATE& operator=(const DATE&);
    friend istream& operator>>(istream& in, DATE& l);
    friend ostream& operator<<(ostream& out, const DATE& l);
};