#pragma once
#include<iostream>
#include "Money.h"
#include <typeinfo>
using namespace std;
template <class T>
class Vector
{
	T* data;
	int _size;
public:
	Vector()
	{
		data = nullptr;
		_size = 0;
	}
	Vector(int size)
	{
		_size = size;
		data = new T[_size];
	}
	Vector(Vector& vec)
	{
		_size = vec._size;
		data = new T[vec._size];
		for (int i = 0; i < vec.size(); i++)
			data[i] = vec.data[i];
	}
	Vector(int i, T k)
	{
		_size = i;
		data = new T[_size];
		for (int i = 0; i < _size; i++)
			data[i] = k;
	}
	~Vector()
	{
		delete[] data;
		data = nullptr;
		_size = 0;
	}
	int size() { return _size; }
	Vector<T>& operator=(Vector<T>& tmp)
	{
		delete[] data;
		_size = tmp.size();
		data = new T[_size];
		for (int i = 0; i < _size; i++)
		{
			data[i] = tmp[i];
		}
		return *this;
	}
	T operator[] (int index)
	{
		if (index < _size)
			return data[index];
		else
			cout << "\nÎøèáêà!!!" << endl;
	}
	Vector<T>& operator * (T k)
	{
		Vector <T> tmp(_size, k);
		for (int i = 0; i < _size; i++)
			tmp.data[i] = data[i] * k;
		return tmp;
	}
	Vector<T>& operator-(Vector<T>& tmp)
	{
		if (_size >= tmp.size())
		{
			for (int i = 0; i < tmp.size(); i++)
			{
				data[i] = data[i] - tmp[i];
			}
		}
		else
		{
			for (int i = 0; i < _size; i++)
			{
				data[i] = data[i] - tmp[i];
			}
		}
		return *this;
	}
	void Insert(T element, int position)
	{
		T* oldArr = data;
		data = new T[_size + 1];
		for (int i = 0; i < position; i++)
			data[i] = oldArr[i];

		data[position] = element;
		_size++;
		for (int i = position + 1; i < _size; i++)
			data[i] = oldArr[i - 1];
	}

public:
	template <typename T> friend ostream& operator<< (ostream& out, Vector<T>& a);
	friend ostream& operator<< (ostream& out, const Vector<Money>& tmp);
};
template <typename T>
istream& operator>>(istream& in, Vector<T>& tmp)
{
	for (int i = 0; i < tmp._size; i++)
	{
		cout<< i + 1;
		in >> tmp.data[i];
	}
	return in;
}
template <typename T>
ostream& operator<<(ostream& out, const Vector<T>& tmp)
{
	for (int i = 0; i < tmp._size; i++)
		out << tmp.data[i] << "  ";
	return out;
}