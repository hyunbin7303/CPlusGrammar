


#include <iostream>
#include <algorithm>	
#include <vector>

int main()
{
	int myints[] = { 10,20,30,40,50,60,70 };
	std::vector<int> myVector(7);


	std::copy(myints, myints + 7, myVector.begin());
	std::cout << "My Vector contains : " << std::endl;
	
	for (auto it : myVector)
	{
		std::cout << it << std::endl;
	}

	return 0;
}