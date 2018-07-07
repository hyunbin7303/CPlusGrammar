/*
http://en.cppreference.com/w/cpp/utility/optional
The class template Optional manages an optional contained value.
A common use case for optional is the return value of a function that may fail.
*/


#include <string>
#include <functional>
#include <iostream>
#include <optional>
#include <map>


class Kevin
{
public:
	int value;
	int value2;
};
std::map < std::string, Kevin > testing;

std::optional<Kevin> Optionaltesting(const char * stdNum)
{
	auto match = testing.find(stdNum);
	if (match != testing.end())
	{
		return match->second;
	}
	else
	{
		return {};
	}
}



std::optional<std::string> OptionalTest(bool get)
{
	if (get)
	{
		return "SUCCESS";
	}
	else
	{
		return {};
	}
}

int main()
{
	testing["7594435"] = { 20,30 };
	testing["1234567"] = { 30,40 };
	testing["2222222"] = { 40,30 };

	std::map<std::string, Kevin>::iterator it = testing.begin();
	while (it != testing.end())
	{
		std::cout << "Student number : " << it->first <<  ", value 1 : " << it->second.value << ", value 2 : " << it->second.value2 << std::endl;
		it++;
	}


	auto getValue = Optionaltesting("7594435");
	int num = getValue->value;
	std::cout << OptionalTest(true).value_or("Empty") << std::endl;
	std::cout << num << std::endl;
	std::cout << (Optionaltesting("7594435")->value) << std::endl;
	system("pause");
	return 0;
}