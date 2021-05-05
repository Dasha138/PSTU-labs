#include "Plenty.h"

Plenty::Plenty(int s, int k) 
{
    size = s;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = k;

    beg.elem = &data[0];
    end.elem = &data[size];
}

Plenty::Plenty(const Plenty& a) 
{
    size = a.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = a.data[i];

    beg = a.beg;
    end = a.end;
}

Plenty::~Plenty() 
{
    delete[] data;
    data = 0;
}

Plenty& Plenty::operator=(const Plenty& a) 
{
    if (this == &a) return *this;
    size = a.size;
    if (data != 0) delete[]data;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = a.data[i];

    beg = a.beg;
    end = a.end;
    return *this;
}

int& Plenty::operator[](int index) 
{
    if (index < size) return data[index];
    cerr << "\nError! Index > size";
}

Plenty Plenty::operator-(Plenty& a) 
{
    Plenty temp(size);
    for (int i = 0; i < size; i++)
    {
        if (i < a.size)
        {
            temp.data[i] = a.data[i] - data[i];
        }
        else
        {
            temp.data[i] = -data[i];
        }
    }
    return temp;
}

int Plenty::operator()() 
{
    return len();
}

ostream& operator<<(ostream& out, const Plenty& a) 
{
    for (int i = 0; i < a.size; i++) 
    {
        out << a.data[i] << endl;
    }
    return out;
}

istream& operator>>(istream& in, Plenty& a) 
{
    for (int i = 0; i < a.len(); i++) 
    {
        in >> a.data[i];
    }
    return in;
}