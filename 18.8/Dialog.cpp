#include "Dialog.h"
#include<iostream>
using namespace std;
Dialog::Dialog(void) : List()
{
	EndState = 0;
}
Dialog::~Dialog(void)
{
}
void Dialog::GetEvent(TEvent& event)
{
	string OpInt = "+-?/qam";
	string s;
	string param;

	char code;
	cout << "m,+,-,?,q" << endl << '>';
	cin >> s;
	code = s[0];
	if (OpInt.find(code) >= 0)
	{
		event.what = evMessage;
		switch (code)
		{
		case 'm':event.command = cmMake; break;
		case '+': event.command = cmAdd; break;
		case '-': event.command = cmDel; break;
		case '?': event.command = cmShow; break;
		case '/': event.command = cmGet; break;
		case'q': event.command = cmQuit; break;
		}
		if (s.length() > 1)
		{
			param = s.substr(1, s.length() - 1);

			int A = atoi(param.c_str());
			event.a = A;
		}
	}
	else event.what = evNothing;
}
int Dialog::Execute()
{
	TEvent event; do 
	{
		EndState = 0;
		GetEvent(event);
		HandleEvent(event);

	} while (!Valid()); return EndState;
}
int Dialog::Valid()
{
	if (EndState == 0) return 0; else return 1;
}
void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing;
}
void Dialog::EndExec()
{
	EndState = 1;
}
void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake:
			size = event.a;
			cin >> size;
			beg = new Object * [size];
			size = event.a;
			cur = 0;
			ClearEvent(event);
			break;
		case cmAdd:
			Add(); ClearEvent(event); break;
		case cmDel:Del();
			ClearEvent(event); break;
		case cmShow:Show();
			ClearEvent(event);
			break;
		case cmQuit:EndExec(); 
			ClearEvent(event);
			break;
		default:List::HandleEvent(event);
		};
	};
}