

#include <iostream>
#include "ArrayList.h"
using namespace std;

struct Data
{
	int value;
	Data(int v)
	{
		value = v;
	}
};


ArrayList<Data*> list;

void CreateData();
void PrintData();
void ClearData();

void CreateData()
{
	list.Add(new Data(1));
	list.Add(new Data(2));
	list.Add(new Data(3));
}

void PrintData()
{
	cout << "=== < Data Printout > === " << endl;
	cout << "Data How many ? : " << list.Count() << endl;

	for (int i = 0; i < list.Count(); i++)
	{
		cout << list.GetData(i)->value << endl;
	}
	cout << endl;
}

void ClearData()
{
	while (list.Count() > 0)
	{
		delete list.RemoveAt(0);
	}
}

void main()
{
	CreateData();
	PrintData();

	system("pause");
	delete list.RemoveAt(1);
	PrintData();
	
	system("pause");
	ClearData();
	PrintData();
}