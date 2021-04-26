#include "Object.h"
#include "TRIAD.h" 
#include "DATE.h"
#include "Vector.h" 
using namespace std;
void main()
{
	/*TRIAD a;
	cin >> a;
	cout << a << endl;
	Object* p = &a;
	p->Show();
	DATE b;
	cin >> b;
	cout << b << endl;
	p = &b;
	p->Show();*/

	Vector v(5);
	TRIAD a;
	cin >> a;
	DATE b;
	cin >> b;
	Object* p = &a;
	v.Add(p);
	p = &b;
	v.Add(p);
	cout << v;

}