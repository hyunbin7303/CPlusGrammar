#include <iostream>
#include <windows.h>
#include <functional>
#include "RedBlackTree.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	RedBlackTree<int> rbt;

	function<int(int&, int&)> comp = [](int& a, int& b)->int
	{
		if (a > b) return 1;
		else if (a < b) return -1;
		return 0;
	};
	while (true)
	{
		int data = 0;
		cout << "INSERT : ";
		cin >> data;

		if (data == 0)
		{
			break;
		}
		rbt.insert(data, comp);
		rbt.print(); fflush(stdin);
	}
	return 0;
}