#include <iostream>
using namespace std;
struct list
{
	int num;
	char data;
	list* next;
};
void vvod(int size, list** head)
{
	if (size > 0) 
	{
		(*head) = new list;
		cout << "Введите элемент списка: ";
		cin >> (*head)->data;
		(*head)->next = NULL;
		vvod(size - 1, &((*head)->next));
	}
}
void dob(int D, list* head)
{
	list* p = head;
	list* n = new list;
	list* l = new list;
	while (p != 0)
	{
		if (p->data == D) 
		{
			list* o = new list;
			n = p->next;
			p->next = o;
			p = p->next;
			cout << "Введите элемент, который нужно добавить: ";
			cin >> p->data;
			p->next = n;
		}
		p = p->next;
	}
}
void print(list* head)
{
	if (head == NULL)
	{
		cout << "Список пуст";
		cout << endl;
	}
	else {
		list* p = head;
		while (p != 0)
		{
			cout << p->data << "\t";
			p = p->next;
		}
		cout << endl;
	}
	cout << endl;
}
void clean(list* head) 
{
	list* elem = head;
	elem = head;
	head = head->next;
	delete elem;
}
int main()
{
	setlocale(LC_ALL, "ru");
	int size = -1, n = 0;
	char x;
	cout << "Введите количество элементов списка: ";
	while (size <= 0)
	{
		cin >> size;

		if (size <= 0)
			cout << "Неверный ввод";
	}
	list* head;
	vvod(size, &head);
	print(head);
	cout << endl;
	cout << "Укажите элемент, после которого нужно добавить: ";
	cin >> x;
	cout << endl;
	dob(x, head);
	print(head);
	cout << endl;
	clean(head);
	return(0);
}