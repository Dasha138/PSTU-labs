#pragma once
#include"Object.h"
class List
{
public:
	List(int);
	List(void);
public:
	void HandleEvent(const TEvent& e);
	~List(void);
	void Add();
	void Del();
	void Show();
	int operator()();
protected:
	Object** beg;
	int size;
	int cur;
};