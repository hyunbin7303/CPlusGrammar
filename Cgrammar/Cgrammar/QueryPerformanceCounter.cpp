#include <windows.h>
#include <iostream>
double frequency = 0.0f;
__int64 CounterBegin = 0;

void CounterStart()
{
	LARGE_INTEGER LargeInt;
	if (!QueryPerformanceFrequency(&LargeInt))
	{
		std::cout << "Query Frequency Query fail!" << std::endl;
	}
	frequency = double(LargeInt.QuadPart) / 1000.0;
	QueryPerformanceCounter(&LargeInt);
	CounterBegin = LargeInt.QuadPart;


}

double GetCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterBegin) / frequency;
}
int main()
{
	CounterStart();
	Sleep(1000);
	std::cout << GetCounter() << std::endl;



	system("pause");
	return 0;
}