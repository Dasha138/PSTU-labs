#include "Exam.h" 
#include <iostream> 
#include <string> 
using namespace std;

Exam::Exam()
{
	fio = ""; subject = ""; evaluation = 0;
	cout << "Constructor bez parametrov dlia objecta" << this << endl;
}

Exam::Exam(string N, string K, int S)
{
	fio = N;
	subject = K;
	evaluation = S;
	cout << "Constructor s parametrami dlia objecta" << this << endl;
}

Exam::Exam(const Exam& t)
{
	fio = t.fio;
	subject = t.subject;
	evaluation = t.evaluation;
	cout << "Constructor copirovania dlia objecta" << this << endl;
}

Exam::~Exam()
{
	cout << "Destructor dlia objecta" << this << endl;
}

string Exam::get_fio()
{
	return fio;
}
string Exam::get_subject()
{
	return subject;
}
int Exam::get_evaluation()
{
	return evaluation;
}

void Exam::set_fio(string N)
{
	fio = N;
}
void Exam::set_subject(string K)
{
	subject = K;
}
void Exam::set_evaluation(int S)
{
	evaluation = S;
}

void Exam::show()
{
	cout << "fio :" << fio << endl;
	cout << "subject :" << subject << endl;
	cout << "evaluation :" << evaluation << endl;
}