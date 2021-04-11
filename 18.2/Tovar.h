#pragma once
#include <iostream>
#include<string>
using namespace std;
class Cars
{
	string marka;
	string model;
	int stoimost;
public:
	Cars();
	Cars(string N, string K, int S);
	Cars(string, int, double);
	Cars(const Cars&);
	~Cars();
	string get_marka();
	void set_marka(string);
	string get_model();
	void set_model(string);
	int get_stoimost();
	string set_marka();
	string set_model();
	int set_stoimost();
	void set_stoimost(int);
	void show();
};