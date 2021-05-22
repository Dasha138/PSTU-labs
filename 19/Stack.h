#pragma once
#include <iostream>
using namespace std;
template <class T>
class node 
{
public:
	T data;
	node<T>* next;
};

template <class T>
class Stack
{
private:
	node<T>* top;
public:
	Stack() 
	{
		top = nullptr;
	}
	bool isEmpty() 
	{
		if (top == nullptr)
			return false;
		else
			return true;
	}
	T Top() 
	{
		if (top)
			return top->data;
		else
			cout << "Stack is empty" << endl;
	}
	void push(const T& val) 
	{
		if (top == NULL) 
		{
			top = new node<T>;
			top->next = NULL;
			top->data = val;
		}
		else 
		{
			node<T>* temp = new node<T>;
			temp->data = val;
			temp->next = top;
			top = temp;
		}
	}
	void pop() 
	{
		if (top == nullptr) 
		{
			cout << "Stack is empty" << endl;
			return;
		}
		else 
		{
			cout << top->data << " is popped" << endl;
			node<T>* temp = top;
			top = top->next;
			delete temp;
		}
	}
	void print() 
	{
		node<T>* temp = top;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};