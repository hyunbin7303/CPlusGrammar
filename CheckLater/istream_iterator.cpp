	#include <iostream>
#include <iterator>

int main(void)
{
	double value1, value2;
	std::cout << "Please, insert two values : ";
	std::istream_iterator<double> eos;
	std::istream_iterator<double> iit(std::cin); 

	if (iit != eos)
	{
		value1 = *iit;
	}
	++iit;

	if (iit != eos)
	{
		value2 = *iit;
	}
	std::cout << value1 << "*" << value2 << "=" << (value1*value2) << '\n';
	return 0;
}