#include <iostream>
#include "DoublyLInkedList.h"
using namespace std;

List<float> list;
void InitData()
{
	list.PushBack(1.1f);	
	list.PushBack(2.2f);
	list.PushBack(3.3f);
	list.PushBack(4.4f);

}


void PrintData()
{
	cout << "NUMBER : " << list.Count() << endl;
	for (List<float>::Node* p = list.Begin(); p != list.End(); p = list.Next())
	{
		cout << p->data << endl;
	}
	system("pause");
	cout << endl;
}

void ClearData()
{
	while (list.Count() > 0)
	{
		list.PopFront();
	}
}


void main()
{
	InitData();
	PrintData();

	list.Remove(2.2f);
	PrintData();

	list.PopBack();
	PrintData();

	ClearData();
	PrintData();
}